#ifndef TERNARYVECTORCLASS_H_
#define TERNARYVECTORCLASS_H_



#include <stdio.h>
#include <iostream>
#include <exception>
#include <ctime>
#include <string>


namespace TernaryVectorClass {


	// ������ ������� �������� ����� ������ ���� ������ (1 � ������ �������, � 0 ��� ������)
	template <class T>
	int getType(T& a, std::istream& stream) {
		int rc = 0;
		stream >> a;
		if (!stream.good())
			rc = 1;				// ���������� ������ �����
		stream.clear();
		stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return rc;
	};

	// ������ ������� ��� ����� ����� �� �������� ������
	template<class T>
	void input_Type(T& p, std::istream& istream, std::ostream& ostream) {
		while (getType(p, istream))
			ostream << "����������, ��������� ����: --> ";
	}


	// ����� "�������� �������"
	class TernaryVector {
	private:

		// ������� ������ �������
		int SZ;

		// �������� ������
		// ��������: 0 - ����; 1 - ������; X - �������������� �������� (ASCII ��� 88)
		char* vector;

	public:

		/* --------------------------------------------------------- */
		/*				    	  ������������					 	 */
		/* --------------------------------------------------------- */


		// ������ �����������
		TernaryVector() : SZ(0), vector(nullptr) {};

		// ����������� � �������������� �������� ���-��� ������������� �������� (��� �� �������� �������� �������)
		TernaryVector(int);

		// ����������� � �������������� ���������� ��������� ������� ��� ������ ��������
		TernaryVector(const std::string&);

		// ���������� �����������
		TernaryVector(const TernaryVector&);

		// ���������� �������� ������������
		TernaryVector& operator = (const TernaryVector&);

		// ������������ �����������
		TernaryVector(TernaryVector&&) noexcept;

		// ������������ �������� ������������
		TernaryVector& operator = (TernaryVector&&) noexcept;
		
		//����������
		~TernaryVector() { delete[] vector; };

		/* --------------------------------------------------------- */
		/*				      ������� - set'����					 */
		/* --------------------------------------------------------- */

		// �������������� �������
		TernaryVector& Invertion();

		// �������������� �������
		TernaryVector& operator ~();

		// ���������� ����������� ���������� ������� ������� � ������ (������� ��������)
		TernaryVector& Conjunction(const TernaryVector&);

		// ���������� ����������� ���������� ������� ������� � ������ (������� ��������)
		TernaryVector& operator &= (const TernaryVector&);

		/* --------------------------------------------------------- */
		/*						 ������ ������						 */
		/* --------------------------------------------------------- */

		// ������ ���������������� ���� - ���������� ������ ������ ����������� ����������������, ���� -1, ���� �� ���
		int Analysis() const;

		/* --------------------------------------------------------- */
		/*						 ������ ������ 						 */
		/* --------------------------------------------------------- */

		// ���������� ����������� ���������� ������� ������� � ������ (�������� ��������)
		// �������� ����������� ������ ����, ��� ��� ������� - ���� ������, � �� ����������� ����� �������
		friend const TernaryVector Disjunction(const TernaryVector&, const TernaryVector&);

		// ���������� ����������� ���������� ������� ������� � ������ (�������� ��������)
		friend const TernaryVector operator | (const TernaryVector&, const TernaryVector&);

		// ��������� ���� �������� (���������� ������ ������� ������������, ���� -1, ���� ������� ��������� � -2, ���� ������� �������� �� ���������)
		friend const int Compare(const TernaryVector&, const TernaryVector&);

		// ��������� ���� �������� (���������� true, ���� ������� ���������, � false � ��������� ������)
		friend const bool operator == (const TernaryVector&, const TernaryVector&);

		// ����� ��������� ������� �� �������� ������ (� ��������� ������������� ����������)
		friend std::istream& operator >> (std::istream&, TernaryVector&);

		// ����� �������� ������� � �������� �����
		friend std::ostream& operator << (std::ostream&, const TernaryVector&);

	};

	// ���� ���������� �������
	// ����� ���, ������������ � ����������, ����� ������� � .cpp ����� ��� ������� �� ��������� � ������ ������

	const TernaryVector Disjunction(const TernaryVector&, const TernaryVector&);

	const TernaryVector operator | (const TernaryVector&, const TernaryVector&);

	const int Compare(const TernaryVector&, const TernaryVector&);

	const bool operator == (const TernaryVector&, const TernaryVector&);
}

#endif // !TERNARYVECTORCLASS_H_

