#include "Lab3_C.h"

const  std::vector<std::string> msgs = { "0. Выйти",
"1. Переопределить вектор",
"2. Вывести вектор",
"3. Выполнить поразрядную дизъюнкцию обоих векторов (сложить вектора)",
"4. Выполнить поразрядную конъюнкцию выбранного вектора с другим вестором (умножить вектор)",
"5. Сравнить выбранный вектор с другим",
"6. Инвертировать выбранный вектор (0 меняется на 1; 1 на 0)",
"7. Анализ определенности вектора - отсутствие неопределенных значений" };

void (*fptr[])(TernaryVectorClass::TernaryVector&, TernaryVectorClass::TernaryVector&) = { Lab3_C::SetVector, Lab3_C::GetVector, Lab3_C::Disjunction, Lab3_C::Conjunction, Lab3_C::Comparation, Lab3_C::Invertion, Lab3_C::Analysis };

int main() {
    setlocale(0, "");
    std::cout << "Пожалуйста, выберите способ инициализации 1-ого вектора:\n";
    TernaryVectorClass::TernaryVector vector_1 = Lab3_C::Input();
    std::cout << "Пожалуйста, выберите способ инициализации 2-ого вектора:\n";
    TernaryVectorClass::TernaryVector vector_2 = Lab3_C::Input();
    TernaryVectorClass::TernaryVector vectors[2] = { vector_1, vector_2 };
    int choose;
    while (true) {
        std::cout << "Пожалуйста, выберите вектор, с которым хотите работать:\n 1 - первый вектор;\n 2 - второй ветор;\n --> ";
        TernaryVectorClass::input_Type(choose, std::cin, std::cout);
        while (choose < 1 || choose > 2) {
            std::cout << "Пожалуйста, выберите число от 1 до 2: ==> ";
            TernaryVectorClass::input_Type(choose, std::cin, std::cout);
        }
        std::cout << "Вы выбрали " << choose << " вектор;\n";
        int rc;
        rc = Lab3_C::dialog(msgs);
        if (!rc)
            break;
        fptr[rc - 1](vectors[choose - 1], vectors[choose % 2]);
    }
    return 0;
}

