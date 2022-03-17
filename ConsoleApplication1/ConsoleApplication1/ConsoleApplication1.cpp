#include <iostream>
#include<fstream>
#include <Windows.h>
#include<string>
#include"patient_card.h"

int main()
{
    setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали
    //patient_card PC = patient_card(10);
    Tqueue<int> s = Tqueue<int>(10);
    s.Push(1);
    s.Print();

}

