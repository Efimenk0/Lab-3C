#include "gtest/gtest.h"
#include "TernaryVectorLib/TernaryVectorLib.h"


/* --------------------------------------------------------- */
/*				    	  Конструкторы					 	 */
/* --------------------------------------------------------- */


// Пустой конструктор по умолчанию с выбрасыванием исключения
TEST(Constructors, EmptyConstructor) {
	TernaryVectorClass::TernaryVector v;
	EXPECT_EQ(0, v.GetSize());
	EXPECT_EQ(nullptr, v.GetMasAdress());
}

// Конструктор с инициализацией заданным кол-вом неопредленных значений с выбрасыванием исключений (Будут храниться в конце массива) 
TEST(Constructors, DefaultConstructor1) {
	TernaryVectorClass::TernaryVector v(10);
	EXPECT_EQ(10, v.GetSize());
	for (int i = 0; i < v.GetSize(); ++i)
		EXPECT_EQ('X', v.GetValue(i));
	// Инициализация вектора отрицательным числом 
	EXPECT_THROW(TernaryVectorClass::TernaryVector v(-5), std::exception);
}

// Констурктор с инициализацией значениями элементов вектора как строки символов
TEST(Constructors, DefaultConstructor2) {
	TernaryVectorClass::TernaryVector v("211wkd0a  rewjn2");
	EXPECT_EQ(8, v.GetSize());
	EXPECT_EQ('X', v.GetValue(0));
	EXPECT_EQ('1', v.GetValue(1));
	EXPECT_EQ('1', v.GetValue(2));
	EXPECT_EQ('X', v.GetValue(3));
	EXPECT_EQ('X', v.GetValue(4));
	EXPECT_EQ('X', v.GetValue(5));
	EXPECT_EQ('0', v.GetValue(6));
	EXPECT_EQ('X', v.GetValue(7));
	TernaryVectorClass::TernaryVector v2("");
	EXPECT_EQ(0, v2.GetSize());
	EXPECT_EQ(nullptr, v2.GetMasAdress());
}


// Тест копирующего конструктора
TEST(Constructors, CopyConstructor) {
	TernaryVectorClass::TernaryVector v1("1X00X1010X");
	TernaryVectorClass::TernaryVector v2(v1);
	EXPECT_EQ(false, v1.GetMasAdress() == v2.GetMasAdress());
	EXPECT_EQ(10, v2.GetSize());
	EXPECT_EQ('1', v2.GetValue(0));
	EXPECT_EQ('X', v2.GetValue(1));
	EXPECT_EQ('0', v2.GetValue(2));
	EXPECT_EQ('0', v2.GetValue(3));
	EXPECT_EQ('X', v2.GetValue(4));
	EXPECT_EQ('1', v2.GetValue(5));
	EXPECT_EQ('0', v2.GetValue(6));
	EXPECT_EQ('1', v2.GetValue(7));
	EXPECT_EQ('0', v2.GetValue(8));
	EXPECT_EQ('X', v2.GetValue(9));
}


// Тест копирующего присваивания
TEST(Constructions, CopyАssignment) {
	TernaryVectorClass::TernaryVector v1("1X00X1010X");
	TernaryVectorClass::TernaryVector v2("100218");
	char* ptr = v2.GetMasAdress();
	v2 = v1;
	EXPECT_EQ(false, ptr == v2.GetMasAdress());
	EXPECT_EQ(false, ptr == v1.GetMasAdress());
	EXPECT_EQ(false, v1.GetMasAdress() == v2.GetMasAdress());
	EXPECT_EQ(v2.GetSize(), v1.GetSize());
	EXPECT_EQ('1', v2.GetValue(0));
	EXPECT_EQ('X', v2.GetValue(1));
	EXPECT_EQ('0', v2.GetValue(2));
	EXPECT_EQ('0', v2.GetValue(3));
	EXPECT_EQ('X', v2.GetValue(4));
	EXPECT_EQ('1', v2.GetValue(5));
	EXPECT_EQ('0', v2.GetValue(6));
	EXPECT_EQ('1', v2.GetValue(7));
	EXPECT_EQ('0', v2.GetValue(8));
	EXPECT_EQ('X', v2.GetValue(9));
}

// Тест перемещающего конструктора
TEST(Constructors, MoveConstructor) {
	TernaryVectorClass::TernaryVector v1("1X00X1010X");
	char* ptr = v1.GetMasAdress();
	TernaryVectorClass::TernaryVector v2(std::move(v1));
	EXPECT_EQ(v2.GetMasAdress(), ptr);
	EXPECT_EQ(nullptr, v1.GetMasAdress());
	EXPECT_EQ(v2.GetSize(), v1.GetSize());
}


// Тест перемещающего присваивания
TEST(Constructors, MoveAssignment) {
	TernaryVectorClass::TernaryVector v1("1X00X1010X");
	TernaryVectorClass::TernaryVector v2("100218");
	char* ptr_v1 = v1.GetMasAdress();
	char* ptr_v2 = v2.GetMasAdress();
	int num_v1 = v1.GetSize();
	int num_v2 = v2.GetSize();
	v2 = std::move(v1);
	EXPECT_EQ(v1.GetMasAdress(), ptr_v2);
	EXPECT_EQ(v2.GetMasAdress(), ptr_v1);
	EXPECT_EQ(v1.GetSize(), num_v2);
	EXPECT_EQ(v2.GetSize(), num_v1);
	EXPECT_EQ('1', v2.GetValue(0));
	EXPECT_EQ('X', v2.GetValue(1));
	EXPECT_EQ('0', v2.GetValue(2));
	EXPECT_EQ('0', v2.GetValue(3));
	EXPECT_EQ('X', v2.GetValue(4));
	EXPECT_EQ('1', v2.GetValue(5));
	EXPECT_EQ('0', v2.GetValue(6));
	EXPECT_EQ('1', v2.GetValue(7));
	EXPECT_EQ('0', v2.GetValue(8));
	EXPECT_EQ('X', v2.GetValue(9));
}

/* --------------------------------------------------------- */
/*				      Сеттеры - set'теры					 */
/* --------------------------------------------------------- */

// // Выполнение порязрядной дизъюнкции данного вектора с другим
TEST(Setters, Disjunction) {
	// 1. Если первый вектор меньше по размеру
	TernaryVectorClass::TernaryVector v1("01X");
	TernaryVectorClass::TernaryVector v2("000111XXX");
	TernaryVectorClass::TernaryVector v3 = v1 | v2;
	EXPECT_EQ(v2.GetSize(), v3.GetSize());
	EXPECT_EQ('0', v3.GetValue(0));
	EXPECT_EQ('1', v3.GetValue(1));
	EXPECT_EQ('X', v3.GetValue(2));
	EXPECT_EQ('1', v3.GetValue(3));
	EXPECT_EQ('1', v3.GetValue(4));
	EXPECT_EQ('1', v3.GetValue(5));
	EXPECT_EQ('X', v3.GetValue(6));
	EXPECT_EQ('X', v3.GetValue(7));
	EXPECT_EQ('X', v3.GetValue(8));
	// 2. Если первый вектор больше по размеру
	v1 = (std::string)"01X01X01X";
	v2 = (std::string)"110";
	v3 = v1 | v2;
	EXPECT_EQ(v1.GetSize(), v3.GetSize());
	EXPECT_EQ('1', v3.GetValue(0));
	EXPECT_EQ('1', v3.GetValue(1));
	EXPECT_EQ('X', v3.GetValue(2));
	EXPECT_EQ('X', v3.GetValue(3));
	EXPECT_EQ('1', v3.GetValue(4));
	EXPECT_EQ('X', v3.GetValue(5));
	EXPECT_EQ('X', v3.GetValue(6));
	EXPECT_EQ('1', v3.GetValue(7));
	EXPECT_EQ('X', v3.GetValue(8));
	// 3. Если вектора равных размеров
	v1 = (std::string)"01X01X01X";
	v2 = (std::string)"000111XXX";
	v3 = v1 | v2;
	EXPECT_EQ(v1.GetSize(), v3.GetSize());
	EXPECT_EQ('0', v3.GetValue(0));
	EXPECT_EQ('1', v3.GetValue(1));
	EXPECT_EQ('X', v3.GetValue(2));
	EXPECT_EQ('1', v3.GetValue(3));
	EXPECT_EQ('1', v3.GetValue(4));
	EXPECT_EQ('1', v3.GetValue(5));
	EXPECT_EQ('X', v3.GetValue(6));
	EXPECT_EQ('1', v3.GetValue(7));
	EXPECT_EQ('X', v3.GetValue(8));
}



// Выполнение поразрядной конъюнкции данного вектора с другим 
TEST(Setters, Conjunction) {
	//1. Если выбранный вектор меньше по размеру
	TernaryVectorClass::TernaryVector v1("01X");
	TernaryVectorClass::TernaryVector v2("010111XXX");
	v1 &= v2;
	EXPECT_EQ(v2.GetSize(), v1.GetSize());
	EXPECT_EQ('0', v1.GetValue(0));
	EXPECT_EQ('1', v1.GetValue(1));
	EXPECT_EQ('0', v1.GetValue(2));
	EXPECT_EQ('X', v1.GetValue(3));
	EXPECT_EQ('X', v1.GetValue(4));
	EXPECT_EQ('X', v1.GetValue(5));
	EXPECT_EQ('X', v1.GetValue(6));
	EXPECT_EQ('X', v1.GetValue(7));
	EXPECT_EQ('X', v1.GetValue(8));
	// 2. Если выбранный вектор больше по размеру
	v1 = (std::string)"01X01X01X";
	int sz = v1.GetSize();
	v2 = (std::string)"111";
	v1 &= v2;
	EXPECT_EQ(sz, v1.GetSize());
	EXPECT_EQ('0', v1.GetValue(0));
	EXPECT_EQ('1', v1.GetValue(1));
	EXPECT_EQ('X', v1.GetValue(2));
	EXPECT_EQ('0', v1.GetValue(3));
	EXPECT_EQ('X', v1.GetValue(4));
	EXPECT_EQ('X', v1.GetValue(5));
	EXPECT_EQ('0', v1.GetValue(6));
	EXPECT_EQ('X', v1.GetValue(7));
	EXPECT_EQ('X', v1.GetValue(8));
	// 3. Если выбранный вектор равен по размеру
	v1 = (std::string)"01X01X01X";
	v2 = (std::string)"000111XXX";
	v1 &= v2;
	EXPECT_EQ(v2.GetSize(), v1.GetSize());
	EXPECT_EQ('0', v1.GetValue(0));
	EXPECT_EQ('0', v1.GetValue(1));
	EXPECT_EQ('0', v1.GetValue(2));
	EXPECT_EQ('0', v1.GetValue(3));
	EXPECT_EQ('1', v1.GetValue(4));
	EXPECT_EQ('X', v1.GetValue(5));
	EXPECT_EQ('0', v1.GetValue(6));
	EXPECT_EQ('X', v1.GetValue(7));
	EXPECT_EQ('X', v1.GetValue(8));
}


// Инвертирование вектора
TEST(Setters, Invertion) {
	TernaryVectorClass::TernaryVector v("000111XX");
	TernaryVectorClass::TernaryVector res = ~v;
	EXPECT_EQ('1', res.GetValue(0));
	EXPECT_EQ('1', res.GetValue(1));
	EXPECT_EQ('1', res.GetValue(2));
	EXPECT_EQ('0', res.GetValue(3));
	EXPECT_EQ('0', res.GetValue(4));
	EXPECT_EQ('0', res.GetValue(5));
	EXPECT_EQ('X', res.GetValue(6));
	EXPECT_EQ('X', res.GetValue(7));
	v = (std::string)"01X01X01X";
	res = ~v;
	EXPECT_EQ('1', res.GetValue(0));
	EXPECT_EQ('0', res.GetValue(1));
	EXPECT_EQ('X', res.GetValue(2));
	EXPECT_EQ('1', res.GetValue(3));
	EXPECT_EQ('0', res.GetValue(4));
	EXPECT_EQ('X', res.GetValue(5));
	EXPECT_EQ('1', res.GetValue(6));
	EXPECT_EQ('0', res.GetValue(7));
	EXPECT_EQ('X', res.GetValue(8));
}

// Сравнение двух векторов (Возвращает индекс первого несовпадения, либо -1, если вектора совпадают)
TEST(Setters, Compare) {
	// 1. Если вектор 1 меньше вектора 2
	TernaryVectorClass::TernaryVector v1("0001");
	TernaryVectorClass::TernaryVector v2("01X01X01");
	EXPECT_EQ(false, v1 == v2);
	EXPECT_EQ(-1, TernaryVectorClass::Compare(v1, v2));
	EXPECT_EQ(true, v1 == (std::string)"0001");
	// 2. Если вектор 1 больше вектора 2
	v1 = (std::string)"01101XX01";
	v2 = (std::string)"01X";
	EXPECT_EQ(false, v1 == v2);
	EXPECT_EQ(-1, TernaryVectorClass::Compare(v1, v2));
	// 3. Если вектора совпадают 
	v2 = v1;
	EXPECT_EQ(true, v1 == v2);
	v2 = (std::string)"01101XX00";
	EXPECT_EQ(8, TernaryVectorClass::Compare(v1, v2));
}

// Анализ неопределенности кода - возвращает индекс первой встреченной неопределенности, либо -1, если ее нет
TEST(Setters, Analysis) {
	TernaryVectorClass::TernaryVector v1("000111XX");
	TernaryVectorClass::TernaryVector v2("011010010");
	TernaryVectorClass::TernaryVector v3("");
	EXPECT_EQ(6, v1.Analysis());
	EXPECT_EQ(-1, v2.Analysis());
	EXPECT_EQ(-1, v3.Analysis());
}



