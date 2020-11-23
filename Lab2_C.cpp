#include "Lab2_C.h"

const char* msgs[] = { "0. �����",
"1. �������������� ������",
"2. ������� ������",
"3. ��������� ����������� ���������� ����� �������� (������� �������)",
"4. ��������� ����������� ���������� ���������� ������� � ������ �������� (�������� ������)",
"5. �������� ��������� ������ � ������",
"6. ������������� ��������� ������ (0 �������� �� 1; 1 �� 0)",
"7. ������ �������������� ������� - ���������� �������������� ��������" };

const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);

namespace Lab2_A {

	// ����� ������ ������������
	int dialog(const char* msgs[], int N) {
		const char* errmsgs = "";
		int rc, i;
		do {
			puts(errmsgs);
			errmsgs = "������! ��������� ����!";
			for (i = 0; i < N; ++i)					// ����� ������ �����������
				puts(msgs[i]);
			printf("��������: --> ");
		} while (TernaryVectorClass::getType(rc, std::cin) < 0 || rc >= N);
		return rc;
	}


	// ������ ������������� �������
	TernaryVectorClass::TernaryVector Input() {
		std::cout << "1. ������ ������\n2. ������ � n ���-��� �������������� ��������\n3. ������ �������� ������� (������ �������� � ���� ������)\n";
		int res;
		TernaryVectorClass::input_Type(res, std::cin, std::cout);
		while (res < 1 || res > 3) {
			std::cout << "����������, �������� ����� �� 1 �� 3: ==> ";
			TernaryVectorClass::input_Type(res, std::cin, std::cout);
		}
		if (res == 1) {
			TernaryVectorClass::TernaryVector vector;
			std::cout << "������ ������ ������� ���������������.\n";
			return vector;
		}
		else if (res == 2) {
			while (true) {
				std::cout << "����������, ������� ������ �������: ==> ";
				int n;
				TernaryVectorClass::input_Type(n, std::cin, std::cout);
				try {
					TernaryVectorClass::TernaryVector vector(n);
					std::cout << "������ ������� ���������������.\n" << vector << '\n';
					return vector;
				}
				catch (const std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
			}
		}
		else {
			while (true) {
				std::cout << "����������, ������� ������, �������������� ����� �������� ������.\n ������� \"�����������\":\n - �������\\��������� �� ��������� �� ������� �������;\n - ��� ��������� ������� (�� ����������� 0 � 1) ��������� �� ����������������;\n";
				std::string str;
				std::cin >> str;
				try {
					TernaryVectorClass::TernaryVector vector(str);
					std::cout << "������ ������� ���������������.\n" << vector << '\n';
					return vector;
				}
				catch (const std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
			}
		}
	}

	// �������������� ������ (� ������� �������������� ">>")
	void SetVector(TernaryVectorClass::TernaryVector& vector, TernaryVectorClass::TernaryVector&) {
		std::cout << "����������, ������� ������, �������������� ����� �������� ������.\n ������� \"�����������\":\n - ������� ��������� ��� ������� �� ������ ������� �������\\���������;\n - ��� ��������� ������� (�� ����������� 0 � 1) ��������� �� ����������������;\n";
		TernaryVectorClass::input_Type(vector, std::cin, std::cout);
		std::cout << "������ ������� ���������������.\n" << vector << '\n';
	}

	// ����� �������� �������
	void GetVector(TernaryVectorClass::TernaryVector& vector, TernaryVectorClass::TernaryVector&) {
		std::cout << vector;
	}

	// ���������� ������� ������� �� ������ ��������
	void Disjunction(TernaryVectorClass::TernaryVector& vector_1, TernaryVectorClass::TernaryVector& vector_2) {
		std::cout << "��������� ����������:\n" << vector_1 << vector_2 << (vector_1 | vector_2);
	}

	// ���������� ������� ������� �� ������ �������
	void Conjunction(TernaryVectorClass::TernaryVector& vector_1, TernaryVectorClass::TernaryVector& vector_2) {
		std::cout << "��������� ����������:\n" << vector_1 << vector_2;
		std::cout << (vector_1 &= vector_2);
	}

	// �������� ��� ������� ����� �����
	void Comparation(TernaryVectorClass::TernaryVector& vector_1, TernaryVectorClass::TernaryVector& vector_2) {
		int rc = Compare(vector_1, vector_2);
		if (rc == -1)
			std::cout << "������� ��������� ���������.\n";
		else if (rc == -2)
			std::cout << "������� �������� �� ���������; ��������� ����������";
		else
			std::cout << "������� �� ��������� �� ������� " << rc << '\n';
	}

	//�������������� ������� (1 �������� �� 0, 0 �� 1)
	void Invertion(TernaryVectorClass::TernaryVector& vector, TernaryVectorClass::TernaryVector&) {
		~vector;
		std::cout << "������ ������������:\n" << vector;
	}

	// ������ �������������� �������
	void Analysis(TernaryVectorClass::TernaryVector& vector, TernaryVectorClass::TernaryVector&) {
		int rc = vector.Analysis();
		if (rc == -1)
			std::cout << "������ ���������.\n";
		else
			std::cout << "������ �� ��������� � ������� " << rc << '\n';
	}



}