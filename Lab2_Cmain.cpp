#include "Lab2_C.h"

extern const char* msgs[];

void (*fptr[])(TernaryVectorClass::TernaryVector&, TernaryVectorClass::TernaryVector&) = { Lab2_A::SetVector, Lab2_A::GetVector, Lab2_A::Disjunction, Lab2_A::Conjunction, Lab2_A::Comparation, Lab2_A::Invertion, Lab2_A::Analysis };

int main() {
	setlocale(0, "");
	std::cout << "����������, �������� ������ ������������� 1-��� �������:\n";
	TernaryVectorClass::TernaryVector vector_1 = Lab2_A::Input();
	std::cout << "����������, �������� ������ ������������� 2-��� �������:\n";
	TernaryVectorClass::TernaryVector vector_2 = Lab2_A::Input();
	TernaryVectorClass::TernaryVector vectors[2] = { vector_1, vector_2 };
	int choose;
	while (true) {
		std::cout << "����������, �������� ������, � ������� ������ ��������:\n 1 - ������ ������;\n 2 - ������ �����;\n --> ";
		TernaryVectorClass::input_Type(choose, std::cin, std::cout);
		while (choose < 1 || choose > 2) {
			std::cout << "����������, �������� ����� �� 1 �� 2: ==> ";
			TernaryVectorClass::input_Type(choose, std::cin, std::cout);
		}
		std::cout << "�� ������� " << choose << " ������;\n";
		int rc;
		rc = Lab2_A::dialog(msgs, NMsgs);
		if (!rc)
			break;
		fptr[rc - 1](vectors[choose - 1], vectors[choose % 2]);
	}
	return 0;
}