// AKProjectTwo.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Anastasiya Kiulo 2019

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

const int SIZE = 2147;

int main()
{
	ifstream inFile;
	inFile.open("D:\\ConcertData.txt");
	double first[SIZE];
	double second[SIZE];
	double third[SIZE];

	double maxMoney;//budget value
	double maxConsetrs;//number if conserts in scenario
	int count = 0;//total number of statements in the file
	
	int i = 0;
	bool a = true;
	//read infornation from file
	while (a)
	{
		if (inFile.eof()) {
			break;
		}
		inFile >> first[i];
		inFile >> second[i];
		if (first[i] < 0 || second[i] < 0) {
			cout << "\nYour file contain negative value!\nPleace change your file and start program again\n\n";
			exit(0);
		}
		count++;//size of all arrays with all scenarious
		i++;
	}

	inFile.close();

	/*ofstream file;
	file.open("D:\\ConcertData.txt", ios::app);
	for (int i = 0; i < 4; i++) {
		file << i;
	}*/

	maxMoney = first[0];	//add budget value
	maxConsetrs = second[0];	//add number of conserts in first scenario
	int start = 0;
	do {
		if (maxConsetrs >= 42) {
			cout << "\n\n\nSomething wrong with your file!!!";
			exit(0);
		}
			
		while (maxMoney >= 420) {//here we check budget value
			static double value = 0;
			cout << "\n\nEnter a corect value for budget amount(less then 420): ";
			cin >> value;
			maxMoney = value;
		}

		for (int i = (0 + 1); i < maxConsetrs; i++) {//third array for ratio of fun to cost
			third[i + start] = second[i + start] / first[i + start];
		}


		for (int i = 0; i < maxConsetrs - 1; i++) {	//sort third arrey 
			for (int j = 1; j < maxConsetrs - i - 1; j++) { //start sorting without elements, that contaain budget limit and possible concerts
				if (third[j + start] < third[j + 1 + start]) {
					
					double temp;

					temp = third[j + start];
					third[j + start] = third[j + 1 + start];
					third[j + 1 + start] = temp;

					temp = first[j + start];
					first[j + start] = first[j + 1 + start];
					first[j + 1 + start] = temp;

					temp = second[j + start];
					second[j + start] = second[j + 1 + start];
					second[j + 1 + start] = temp;
				}
			}
		}
		
		double yourMoney = 0;
		double yourConserts = 0;		

		for (int i = 0; (i < maxConsetrs); i++)
		{
			if ((yourMoney + first[i + start]) < maxMoney) {
				yourMoney += first[i + start];
				yourConserts += second[i + start];
			}
		}

		cout << "\n\nGiven a budget of " << maxMoney << " and considering " << maxConsetrs << " possible concerts.\n"
			<< "Total cost will be " << yourMoney << " and estimated fun will be " << yourConserts << ".";//scenario, my program should display
		double x = start += maxConsetrs + 1;
		if (x > count-1)
			break;
		yourMoney = 0;
		yourConserts = 0;
		maxMoney = first[start];//value for next scensrio
		maxConsetrs = second[start];//value for next scensrio

	} while (count >= start);
}



