// LabaProga4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian_Russia.1251");
	const int matrSize = 3;
	double Matr[matrSize][matrSize];
	int whatStroka = 0, toStroka = 0;
	double mnojitel = 0, multiElemSumNumDiv3 = 1, maxMinusMin = 0, max = 0, min = 0;
	cout << "Введите номер строки, к которой прибавлять" << endl;
	cin >> toStroka;
	cout << "Введите номер строки, которую прибавлять" << endl;
	cin >> whatStroka;
	cout << "Введите число, на которое умножить прибавляемую строку" << endl;
	cin >> mnojitel;
	cout << "Введите матрицу" << endl;
	for (int numStolbca = 0; numStolbca < matrSize; numStolbca++) // i - numStolbca, j - numStroki
	{
		for (int numStroki = 0; numStroki < matrSize; numStroki++)
			cin >> Matr[numStolbca][numStroki];
	}
	cout << "Исходная матрица: " << endl;
	for (int numStolbca = 0; numStolbca < matrSize; numStolbca++)
	{
		for (int numStroki = 0; numStroki < matrSize; numStroki++)
			cout << Matr[numStolbca][numStroki] << " ";
		cout << endl;
	}



	for (int numStroki = 0; numStroki < matrSize; numStroki++) // идем по столбцам
	{
		for (int numStolbca = 0; numStolbca < matrSize; numStolbca++)
			if (numStolbca == whatStroka - 1) // пользователь начинает нумерацию элементов с [1][1]
				Matr[toStroka-1][numStroki] += Matr[whatStroka-1][numStroki]*mnojitel;
	}



	cout << "Преобразованная матрица: " << endl;
	for (int numStolbca = 0; numStolbca < matrSize; numStolbca++)
	{
		for (int numStroki = 0; numStroki < matrSize; numStroki++)
			cout << Matr[numStolbca][numStroki] << " ";
		cout << endl;
	}
	max = min = Matr[0][0];
	for (int numStolbca = 0; numStolbca < matrSize; numStolbca++)
	{
		for (int numStroki = 0; numStroki < matrSize; numStroki++)
		{
			if ((numStolbca + numStroki + 2) % 3 == 0) //пользователь начинает отсчет элементов с 1, а не с 0
				multiElemSumNumDiv3 *= Matr[numStolbca][numStroki];
			if (max < Matr[numStolbca][numStroki])
				max = Matr[numStolbca][numStroki];
			else if (min > Matr[numStolbca][numStroki])
				min = Matr[numStolbca][numStroki];
		}
	}
	maxMinusMin = max - min;
	cout << "Произведение элементов матрицы, сумма номера строки и столбца которых кратна 3 = " << multiElemSumNumDiv3 << endl;
	cout << "Разница между максимальным и минимальным элементом = " << maxMinusMin << endl;
	cout << "Сведения об авторе:" << endl;
	cout << "ФИО: Синицкая В.А." << endl;
	cout << "Вариант 5" << endl;
	cout << "ЛЭТИ, ФКТИ, 1 курс" << endl;
}

