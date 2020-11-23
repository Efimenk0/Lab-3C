#include "TernaryVectorlib.h"




namespace TernaryVectorClass {


	/* --------------------------------------------------------- */
	/*				    	  Конструкторы					 	 */
	/* --------------------------------------------------------- */

	// Конструктор с инициализацией заданным кол-вом неопределенных значений (Оно же является размером вектора)
	TernaryVector::TernaryVector(int X) {
		if (X < 0)
			throw std::exception("Кол-во неопреденных значений не может быть отрицательным. Попробуйте еще раз.\n");
		SZ = X;
		// Т.к. доступ к указателю на массив из 0 эл-тов будет иметь UB
		if (!SZ)
			vector = nullptr;
		else
			vector = new char[SZ];
		for (int i = 0; i < SZ; ++i)
			vector[i] = 'X';
	}


	// Конструктор с инициализацией значениями элементов вектора как строки символов
	TernaryVector::TernaryVector(const std::string& str) {
		// Проверка на пробелы нужна, если мы решим воспользоваться явным преобразованием типа через конструктор и применим ее к "неправильной" строке
		int size = 0, str_i = 0;
		// Ищем размер строки (до конца строки, либо до певого пробела/табуляции)
		while (str[str_i] != '\0' && str[str_i] != ' ' && str[str_i] != '\t') {
			if (str[str_i] != ' ' && str[str_i] != '\t')
				size++;
			++str_i;
		}
		SZ = size;
		str_i = 0;
		size = 0;
		if (!SZ)
			vector = nullptr;
		// Чтобы лишний раз не проверять while
		else {
			vector = new char[SZ];
			while (size < SZ) {
				while (str[str_i] == ' ' || str[str_i] == '\t')
					str_i++;
				if (str[str_i] == '0')
					vector[size] = '0';
				else if (str[str_i] == '1')
					vector[size] = '1';
				else
					vector[size] = 'X';
				str_i++;
				size++;
			}
		}
	}


	// Копирующий конструктор
	TernaryVector::TernaryVector(const TernaryVector& copy) : SZ(copy.SZ) {
		vector = new char[SZ];
		for (int i = 0; i < SZ; ++i)
			vector[i] = copy.vector[i];
	}

	// Копирующий оператор присваивания
	TernaryVector& TernaryVector::operator = (const TernaryVector& copy) {
		if (this != &copy) {
			SZ = copy.SZ;
			delete vector;
			vector = new char[SZ];
			for (int i = 0; i < SZ; i++)
				vector[i] = copy.vector[i];
		}
		return *this;
	}

	// Перемещающий конструктор
	TernaryVector::TernaryVector(TernaryVector&& move) noexcept : SZ(move.SZ), vector(move.vector) {
		move.vector = nullptr;
	};

	// Перемещающий оператор присваивания
	TernaryVector& TernaryVector::operator = (TernaryVector&& move) noexcept {
		int tmp = SZ;
		SZ = move.SZ;
		move.SZ = tmp;
		char* ptr = vector;
		vector = move.vector;
		move.vector = ptr;
		return *this;
	}

	/* --------------------------------------------------------- */
	/*				      Сеттеры - set'теры					 */
	/* --------------------------------------------------------- */

		// Инвертирование вектора
	TernaryVector& TernaryVector::Invertion() {
		for (int i = 0; i < SZ; ++i)
			if (vector[i] == '1')
				vector[i] = '0';
			else if (vector[i] == '0')
				vector[i] = '1';
		return *this;
	}

	// Инвертирование вектора
	TernaryVector& TernaryVector::operator ~() {
		return Invertion();
	}


	// Выполнение порязрядной конъюнкции данного вектора с другим (Унарная операция)
	TernaryVector& TernaryVector::Conjunction(const TernaryVector& con) {
		int corrent_size;
		if (SZ <= con.SZ)
			corrent_size = SZ;
		else
			corrent_size = con.SZ;
		for (int i = 0; i < corrent_size; ++i)
			if (vector[i] + con.vector[i] == 98)
				vector[i] = '1';
			else if (vector[i] + con.vector[i] == 137 || (vector[i] + con.vector[i]) == 176)
				vector[i] = 'X';
			else
				vector[i] = '0';
		for (int i = corrent_size; i < SZ; i++)
			if (vector[i] == '1')
				vector[i] = 'X';
		return *this;
	}


	// Выполнение поразрядной конъюнкции данного вектора с другим (унарная операция)
	TernaryVector& TernaryVector::operator&=(const TernaryVector& vector) {
		return Conjunction(vector);
	}



	/* --------------------------------------------------------- */
	/*						 Другие методы						 */
	/* --------------------------------------------------------- */


	// Выполнение порязрядной дизъюнкции данного вектора с другим (Бинарная операция)
	const TernaryVector Disjunction(const TernaryVector& left, const TernaryVector& right) {
		TernaryVectorClass::TernaryVector tmp;
		int corrent_size;
		if (left.SZ <= right.SZ) {
			corrent_size = left.SZ;
			tmp.SZ = right.SZ;
		}
		else {
			corrent_size = right.SZ;
			tmp.SZ = left.SZ;
		}
		tmp.vector = new char[tmp.SZ];
		for (int i = 0; i < corrent_size; ++i)
			if ((left.vector[i] + right.vector[i]) == 96)
				tmp.vector[i] = '0';
			else if ((left.vector[i] + right.vector[i]) == 136 || (left.vector[i] + right.vector[i]) == 176)
				tmp.vector[i] = 'X';
			else
				tmp.vector[i] = '1';
		if (corrent_size == right.SZ)
			for (int i = corrent_size; i < left.SZ; i++) {
				if (left.vector[i] != '1')
					tmp.vector[i] = 'X';
				else
					tmp.vector[i] = left.vector[i];
			}
		else
			for (int i = corrent_size; i < right.SZ; i++) {
				if (right.vector[i] != '1')
					tmp.vector[i] = 'X';
				else
					tmp.vector[i] = right.vector[i];
			}
		return tmp;
	}


	// Выполнение порязрядной дизъюнкции данного вектора с другим (бинарная операция)
	const TernaryVector operator | (const TernaryVector& vector_1, const TernaryVector& vector_2) {
		return Disjunction(vector_1, vector_2);
	}

	// Сравнение двух векторов (Возвращает индекс первого несовпадения, либо -1, если вектора совпадают и -2, если размеры векторов разные (сравнивать незачем))
	const int Compare(const TernaryVector& left, const TernaryVector& right) {
		if (left.SZ != right.SZ)
			return -1;				// Код "-1" - разные размеры векторов
		for (int i = 0; i < left.SZ; ++i)
			if (left.vector[i] != right.vector[i])
				return i;
		return -2;					// Код "-2" - вектора совпадают
	}


	// Сравнение двух векторов (Возвращает true, если вектора совпадают, и false в противном случае)
	const bool operator == (const TernaryVector& left, const TernaryVector& right) {
		int rc = Compare(left, right);
		if (rc == -2)
			return true;
		else
			return false;
	}


	// Анализ неопределенности кода - возвращает индекс первой встреченной неопределенности, либо -1, если ее нет
	int TernaryVector::Analysis() const {
		for (int i = 0; i < SZ; ++i)
			if (vector[i] == 'X')
				return i;
		return -1;
	}


	/* --------------------------------------------------------- */
	/*						 Друзья класса 						 */
	/* --------------------------------------------------------- */


	// Вввод состояния вектора из входного потока (с возможным setstate)
	std::istream& operator >> (std::istream& stream, TernaryVector& vector) {
		std::string str;
		stream >> str;
		vector.SZ = str.size();
		delete[] vector.vector;
		if (!vector.SZ)
			vector.vector = nullptr;
		else {
			vector.vector = new char[vector.SZ];
			for (int i = 0; i < vector.SZ; ++i)
				if (str[i] == '0')
					vector.vector[i] = '0';
				else if (str[i] == '1')
					vector.vector[i] = '1';
				else
					vector.vector[i] = 'X';
		}
		return stream;
	}



	// Вывод текущего вектора в выходной поток
	std::ostream& operator << (std::ostream& stream, const TernaryVector& vector) {
		if (vector.SZ > 0) {
			for (int i = 0; i < 2 * vector.SZ + 1; ++i)
				stream << "-";
			stream << '\n';
			for (int i = 0; i < vector.SZ; ++i)
				stream << "|" << vector.vector[i];
			stream << "|\n";
			for (int i = 0; i < 2 * vector.SZ + 1; ++i)
				stream << "-";
			stream << '\n';
		}
		else
			stream << "Вектор пуст.\n";
		return stream;
	}


}
