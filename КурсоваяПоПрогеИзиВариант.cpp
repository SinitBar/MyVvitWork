#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale (LC_ALL, "Rus" );
		int chooseSystemSchisl = 0;
		unsigned long long int boardForBin = 11111111111111111111, boardForDec = 1048575;
		unsigned long long int number = 0, otvet = 0;
		bool binError = false;
		cout << "Введите систему счисления исходного числа" << endl;
		cin >> chooseSystemSchisl;
		cout << "Введите число" << endl;
		cin >> number;
		if (chooseSystemSchisl == 10)
		{
			if (number <= boardForDec)
			{
				int degOfTen = 0; // перевод в двоичное
				while (number > 0)
				{
					unsigned long long int ost = (number % 2) * pow(10, degOfTen);
					otvet += ost;
					degOfTen++;
					number /= 2;
				}
				cout << "Двоичное число = ";
			}
			else
			{
				cout << "Ошибка! Введенное число выходит за границы допустимого значения" << endl;
				cout << "Перезапустите программу" << endl;
				break;
			}
		}
		else if (chooseSystemSchisl == 2)
		{
			if (number <= boardForBin)
			{
				int degOfTwo = 0; // степень двойки // перевод в десятичное
				while (number > 0)
				{
					if (number % 10 > 1)
					{
						cout << "Неверное двоичное число!"<< endl;
						binError = 1;
						break;
					}
					otvet += (number % 10) * pow(2, degOfTwo);
					number /= 10;
					degOfTwo++;
				}
				if (binError)
					break;
				cout << "Десятичное число = ";
			}
		}
		else
		{
			cout << "Ошибка! Не предусмотрено такой системы счисления" << endl;
			cout << "Перезапустите программу" << endl;
			break;
		}
		cout << otvet << endl;
		//cout << "Если хотите завершить работу в программе, введите Y, если хотите продолжить - любой другой символ" << endl;
		char choose;
		cout << "to be or not to be?" << endl;
		cin >> choose;
	return 0;
}
