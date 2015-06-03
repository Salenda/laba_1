// BubbleSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BubbleSort.h"

using namespace std;


int _tmain() //точка входа. Выполнение программ начинается с этой функции
{
	//кол-во элементов массива не может быть <0, никаких дополнительных требований в задании нет
	//объявляем длинное целое без знака
	unsigned long numberOfElements = 0; 
	cout << "Enter number of elements N\n";
	cin >> numberOfElements; //спрашиваем кол-во элементов в массиве

	//создаем в памятии пустой массив, куда это все будем пихать
	long* elements = new long[numberOfElements]; 

	//Спрашиваем у пользователя числа в массив
	cout << "Enter array elements\n";
	ReadArrayFromStdInput(elements, numberOfElements);
	cout << "\nOriginal array was:\n";
	PrintArray(elements, numberOfElements); //И для проверки тут же их выводим

	BubbleSort(elements, numberOfElements); //сортировка

	cout << "\nSorted array\n";
	PrintArray(elements, numberOfElements); //выводим результат
	cout << "\n\n";

	delete elements; //Не забываем удалить массив

	system("pause"); //Приостанавливаем программу чтобы увидеть результат, пока пользователь не нажмет что-то
	return 0;
}

//Считывание массива 
void ReadArrayFromStdInput(long* arr, unsigned long size)
{
	for (unsigned long i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

//Вывод массива
void PrintArray(long* arr, unsigned long size)
{
	for (unsigned long i = 0; i < size; i++){
		cout << arr[i]<<" ";
	}
}
 //Непосредственно сортировка
void BubbleSort(long* arr, unsigned long size)
{
	for (unsigned long i = 1; i < size; i++)
	{
		bool wasChanged = false;
		for (unsigned long j = 0; j < size - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				long tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				wasChanged = true;
			}
		}

		if (!wasChanged)
			return;
	}
}

