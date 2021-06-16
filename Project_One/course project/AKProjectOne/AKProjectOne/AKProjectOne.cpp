// AKProjectOne.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//Anastasiya Kiulo
#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;
const double GM = 0.68;		//gender constant for men
const double GF = 0.55;		//gender constant for women
const int SENTINEL = 999;	//sentinel value

void clear();
/*
	Документировать программу с другими значимыми комментариями
	Определить и правильно использовать значение дозорного/			•	Define and use a sentinel value correctly
*/
void inf(string, double, double, double, double);
void effects(double);


int main()
{
	double B;		//percentage of BAC
	double N;			//number of “standard drinks”
	double W;		//weight in pounds
	char g;			//gender constant
	double t;			//number of hours since the first drink
	double G;
	string name;



	int i;
	do {
		cout << "Please enter your name: ";
		cin >> name;
		cout << "\n\n\n\n\n" << setw(40) <<"Hello user " << name << " this is Blood Alcohol Content program\n";
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//													grnder
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		bool run_gender = true; 

		while (run_gender) {			//check gender
			run_gender = false;

			cout << "\n\nHello " << name << " please choose your gender(m or f)";
			cin >> g;

			switch (g)
			{
			case 'm': { G = GM;
				break; }
			case 'M': { G = GM; //if user forgot switch off caps lock
				break; }
			case 'f': { G = GF;
				break; }
			case 'F': { G = GM; //if user forgot switch off caps lock
				break; }
			default: { cout << "enter correct values";
				run_gender = true;
			}

			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//															drincs
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		cout << "Please enter number of standard drinks: ";

		while (!(cin >> N) || (cin.peek() != '\n') || (N < 0)) //peek() Looks at the next character in the stream(get function doesn't works with negative)
		{

			cin.clear();				//reset standard input stream error bits
			while (cin.get() != '\n');	//the read character is removed from the stream until the \n
			cout << "Error!		Value cannot be a character or a negative number" << endl;
			cout << "\nEnter 999 to exit!";	//sentinel
		}
		if (N == SENTINEL)
			break;
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//														  the weight
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		cout << "Enter your weight: ";
		while (!(cin >> W) || (cin.peek() != '\n') || (W <= 0))//peek() Looks at the next character in the stream(get function doesn't works with negative)
		{
			cin.clear();				//reset standard input stream error bits
			while (cin.get() != '\n');	//the read character is removed from the stream until the \n
			cout << "Error!		Value cannot be a character or a negative number" << endl;
			cout << "\nEnter 999 to exit!";	//sentinel
		}
		if (W == SENTINEL)
			break;
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//															time
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		cout << "Enter number of hours since the first drink: ";
		while (!(cin >> t) || (cin.peek() != '\n') || (t < 0))//peek() Looks at the next character in the stream(get function doesn't works with negative)
		{
			cin.clear();				//reset standard input stream error bits
			while (cin.get() != '\n');	//the read character is removed from the stream until the \n
			cout << "Error!		Value cannot be a character or a negative number" << endl;
			cout << "\nEnter 999 to exit!";	//sentinel
		}
		if (t == SENTINEL)
			break;
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//
		B = -0.015 * t + ((2.84*N) / (W * G));
		cout << "\nBAC: " << B;
		clear();
		inf(name, N, W, t, B);
		effects(B);
		cout << "\n\nEnter 1 to repeat calculations:";
		cin >> i;
		cout << "\x1B[2J\x1B[H\x1b[37m";
	} while (i == 1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																	functions
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void clear() {			//this function shifts the screen to make it "clean"
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner [33m red collor
	cout << "\x1B[2J\x1B[H\x1b[33m";
}
void inf(string name, double drink, double weigh, double time, double B) {//this function displays the values ​​entered by the user
	cout << "Hello user, " << name << ".\nYour number of standard drinks: " << drink << "\nYou weight in pounds is: "
		<< weigh << "\nAnd number of hours since the first drink is: " << time << "\n\nPercentage of BAC: " << B;

}
void effects(double BCA) {		//this function displays all possible effects according to users BCA
	if (BCA < 0.03)
		cout << "\nNormal behavior, no impairment";
	else if (BCA >= 0.03 && BCA < 0.06)
		cout << "\nMild euphoria and impairment";
	else if (BCA >= 0.06 && BCA < 0.08)
		cout << "\nEuphoric, increased impairment";
	else if (BCA >= 0.08) {
		cout << "\n\nOver the limit";
		if (BCA >= 0.08 && BCA < 0.10)		//Over the limit here
			cout << "\nEuphoric, increased impairment";
		else if (BCA >= 0.10 && BCA < 0.20)
			cout << "\nDrunk, loss of motor control";
		else if (BCA >= 0.20 && BCA < 0.30)
			cout << "\nConfused, possible blackout";
		else if (BCA >= 0.30 && BCA < 0.40)
			cout << "\nPossibly unconscious";
		else
			cout << "\nUnconscious, risk of death";
	}
}