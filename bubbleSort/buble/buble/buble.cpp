// buble.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;
void bubbleSort(int values[], int size);

int main()
{
	int numbers[6] = { 7,2,3,8,9,1 };

	cout << "Unsorted:\n";
	for (int i = 0; i < 6; i++) {
		cout << numbers[i] << ", ";
	}
	cout << endl <<"\nSorted:\n";
	bubbleSort(numbers, 6);

	for (int i = 0; i < 6; i++) {
		cout << numbers[i] << ", ";
	}
	cout << endl << endl;
}

void bubbleSort(int values[], int size) {
	int temp;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (values[j] < values[i]) {
				temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}
		}
	}
}