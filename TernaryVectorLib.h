#ifndef TERNARYVECTORCLASS_H_
#define TERNARYVECTORCLASS_H_



#include <stdio.h>
#include <iostream>
#include <exception>
#include <ctime>
#include <string>


namespace TernaryVectorClass {


	// Шаблон функции проверки ввода любого типа данных (1 в случае неудачи, и 0 при успехе)
	template <class T>
	int getType(T& a, std::istream& stream) {
		int rc = 0;
		stream >> a;
		if (!stream.good())
			rc = 1;				// Обнаружена ошибка ввода
		stream.clear();
		stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return rc;
	};

	// Шаблон функции для ввода числа из входного потока
	template<class T>
	void input_Type(T& p, std::istream& istream, std::ostream& ostream) {
		while (getType(p, istream))
			ostream << "Пожалуйста, повторите ввод: --> ";
	}


	// Класс "Троичная функция"
	class TernaryVector {
	private:

		// Текущий размер вектора
		int SZ;

		// Троичный вектор
		// Значения: 0 - ложь; 1 - Истина; X - Неопределенное значение (ASCII код 88)
		char* vector;

	public:

		/* --------------------------------------------------------- */
		/*				    	  Конструкторы					 	 */
		/* --------------------------------------------------------- */


		// Пустой конструктор
		TernaryVector() : SZ(0), vector(nullptr) {};

		// Конструктор с инициализацией заданным кол-вом неопредленных значений (Оно же является размером вектора)
		explicit TernaryVector(int);

		// Конструктор с инициализацией значениями элементов вектора как строки символов
		TernaryVector(const std::string&);

		// Копирующий конструктор
		TernaryVector(const TernaryVector&) noexcept;

		// Копирующий оператор присваивания
		TernaryVector& operator = (const TernaryVector&) noexcept;

		// Перемещающий конструктор
		TernaryVector(TernaryVector&&) noexcept;

		// Перемещающий оператор присваивания
		TernaryVector& operator = (TernaryVector&&) noexcept;
		
		//Деструктор
		~TernaryVector() { delete[] vector; };

		/* --------------------------------------------------------- */
		/*				      Сеттеры - set'теры					 */
		/* --------------------------------------------------------- */

		// Выполнение поразрядной конъюнкции данного вектора с другим (унарная операция)
		TernaryVector& Conjunction(const TernaryVector&) noexcept;

		// Выполнение поразрядной конъюнкции данного вектора с другим (унарная операция)
		TernaryVector& operator &= (const TernaryVector&) noexcept;


		/* --------------------------------------------------------- */
		/*					 Геттеры - get'теры                      */
		/* --------------------------------------------------------- */

		// Чисто для Тестов

		int GetSize() { return SZ; };

		char* GetMasAdress() { return vector; };

		char GetValue(int i) { return vector[i]; };

		/* --------------------------------------------------------- */
		/*						 Другие методы						 */
		/* --------------------------------------------------------- */

		// Инвертирование вектора
		TernaryVector Invertion() const noexcept;

		// Инвертирование вектора
		TernaryVector operator ~() const noexcept;

		// Анализ неопределенности кода - возвращает индекс первой встреченной неопределенности, либо -1, если ее нет
		int Analysis() const noexcept;

		/* --------------------------------------------------------- */
		/*						 Друзья класса 						 */
		/* --------------------------------------------------------- */

		// Выполнение порязрядной дизъюнкции данного вектора с другим (бинарная операция)
		// Является объявлением именно ТОГО, что эта функция - друг класса, а не объявлением самой функции
		friend const TernaryVector Disjunction(const TernaryVector&, const TernaryVector&) noexcept;

		// Выполнение порязрядной дизъюнкции данного вектора с другим (бинарная операция)
		friend const TernaryVector operator | (const TernaryVector&, const TernaryVector&) noexcept;

		// Сравнение двух векторов (Возвращает индекс первого несовпадения, либо -1, если вектора совпадают и -2, если размеры векторов не совпадают)
		friend const int Compare(const TernaryVector&, const TernaryVector&) noexcept;

		// Сравнение двух векторов (Возвращает true, если вектора совпадают, и false в противном случае)
		friend const bool operator == (const TernaryVector&, const TernaryVector&) noexcept;

		// Вввод состояния вектора из входного потока (с возможным выбрасыванием исключения)
		friend std::istream& operator >> (std::istream&, TernaryVector&) noexcept;

		// Вывод текущего вектора в выходной поток
		friend std::ostream& operator << (std::ostream&, const TernaryVector&) noexcept;

	};

	// Само объявление функций
	// Чтобы код, подключаемый к библиотеке, видел функции в .cpp файле как внешние по отношению к нашему классу

	const TernaryVector Disjunction(const TernaryVector&, const TernaryVector&) noexcept;

	const TernaryVector operator | (const TernaryVector&, const TernaryVector&) noexcept;

	const int Compare(const TernaryVector&, const TernaryVector&) noexcept;

	const bool operator == (const TernaryVector&, const TernaryVector&) noexcept;
}

#endif // !TERNARYVECTORCLASS_H_

