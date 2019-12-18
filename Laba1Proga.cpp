//#define _CRT_SECURE_NO_WARNINGS // нужно, чтобы компилятор не считал scanf ошибкой
#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <clocale>

using namespace std;

void Naoborot();
void MultiplyNumbers();

int main()
{
		setlocale(LC_ALL, "Russian_Russia.1251");
		char choose = "Be!";	
		cout << "To be or not to be?" << endl;
		cout << choose << endl;
		Naoborot();
		MultiplyNumbers();
}

void Naoborot()
{
	int num = 0, otvet = 0;
	do
	{
		if (num != 0)
			printf("Неверные входные данные!\n"); // при избыточном вводе нулей в начале программа считает числом три последних цифры
		printf("Введите трехзначное число:\n");
		scanf_s("%d", &num); // без define нужно использовать scanf_s
	} while ((num >= 1000) || (num <= 99));
	for (int digit = 100; digit >= 1; digit /= 10)
		otvet += ((num % (digit * 10)) / digit) * (100 / digit); // первый шаг - сотни, второй - +десятки*10, третий - +единицы*100
	// 100/digit - разряд текущего числа
	/*hundred = num / 100;
	ten = (num % 100) / 10;
	one = num % 10;
	num = one * 100 + ten * 10 + hundred;*/
	printf("Число = %d", otvet);
}

void MultiplyNumbers()
{
	int num = 0, num_multiply = 1;
	do
	{
		if (num != 0)
			printf("Неверные входные данные!\n"); // при избыточном вводе нулей в начале программа считает числом три последние цифры
		printf("Введите четырехзначное число:\n");
		scanf_s("%d", &num); // без define нужно использовать scanf_s
	} while ((num >= 10000)||(num <= 999));
	for (int digit = 1000; digit >= 1; digit /= 10)
	{
		num_multiply *= ((num % (digit * 10)) / digit);
	}
	printf("Произведение цифр числа = %d", num_multiply);
}