#ifndef LAB2_C_H_
#define LAB2_C_H_



#include "TernaryVectorLib/TernaryVectorLib.h"


extern const int NMsgs;

namespace Lab2_A {

	// ����� ������ ������������
	int dialog(const char* msgs[], int);

	// ������ ������������� �������
	TernaryVectorClass::TernaryVector Input();


	// �������������� ������ (� ������� �������������� ">>")
	void SetVector(TernaryVectorClass::TernaryVector&, TernaryVectorClass::TernaryVector&);

	// ����� �������� �������
	void GetVector(TernaryVectorClass::TernaryVector&, TernaryVectorClass::TernaryVector&);

	// ���������� ������� ������� �� ������ ��������
	void Disjunction(TernaryVectorClass::TernaryVector&, TernaryVectorClass::TernaryVector&);

	// ���������� ������� ������� �� ������ �������
	void Conjunction(TernaryVectorClass::TernaryVector&, TernaryVectorClass::TernaryVector&);

	// �������� ��� ������� ����� �����
	void Comparation(TernaryVectorClass::TernaryVector&, TernaryVectorClass::TernaryVector&);

	//�������������� ������� (1 �������� �� 0, 0 �� 1)
	void Invertion(TernaryVectorClass::TernaryVector&, TernaryVectorClass::TernaryVector&);

	// ������ �������������� �������
	void Analysis(TernaryVectorClass::TernaryVector&, TernaryVectorClass::TernaryVector&);

}

#endif // !LAB2_C_H_

