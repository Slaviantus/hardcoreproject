// practise 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "cstdio"
#include "cstring"
#include "cstdlib"

using namespace std;

struct ZNAK
{
	char name[20];
	char zodiac[20];
	int date[3];
};
void fillpatients(ZNAK *arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the patient name: ";
		gets_s(arr[i].name);
		cout << endl;
		cout << "Enter the patient's birth date: " << endl;
		cout << "Day: ";
		cin >> arr[i].date[0];
		cout << endl;
		cout << "Month: ";
		cin >> arr[i].date[1];
		cout << endl;
		cout << "Year: ";
		cin >> arr[i].date[2];
		cout << endl;
		cout << "Enter Zodiak sigh: ";
		while (getchar() != '\n');
		gets_s(arr[i].zodiac);
		cout << endl;
		cout << "Patient name: " << arr[i].name << " Birth date: " << arr[i].date[0] << "." << arr[i].date[1] << "." << arr[i].date[2] << " Zodiak sigh: " << arr[i].zodiac << endl;
	}
}
void Search(ZNAK *arr, const int n, int month)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i].date[1] == month)
		{
			cout << arr[i].name << " Birth date: " << arr[i].date[0] << "." << arr[i].date[1] << "." << arr[i].date[2] << " Zodiak sigh: " << arr[i].zodiac << endl;
		}
	}
}
int main()
{
	const int n = 2;
	int month = 0;
	ZNAK Murkoff[n];
	fillpatients(Murkoff, n);
	cout << "Enter the month: ";
	cin >> month;
	cout << endl;
	cout << "Patients month of birth" << endl;
	Search(Murkoff, n, month);
	_getch();
	return 0;
}

