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
int fillpatients(ZNAK *arr, const int n)
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
		if (arr[i].date[1] < 1 || arr[i].date[1] > 12 || arr[i].date[0] < 1)
		{
			cout << "Its wrong!" << endl;
			_getch();
			return -1;
		}
		switch (arr[i].date[1])
		{
		case 1:
		{
			if (arr[i].date[0] > 31)
			{
				cout << "Its wrong!" << endl;
				_getch();
				return -1;
			}
			if (arr[i].date[0] <= 19)
			{
				strcpy_s(arr[i].zodiac, "Capricorn");
			}
			else
			{
				strcpy_s(arr[i].zodiac, "Aquarius");
			}
			break;
		}
		case 2:
		{
			if (arr[i].date[0] > 28)
			{
				cout << "Its wrong!" << endl;
				_getch();
				return -1;
			}
			if (arr[i].date[0] <= 18)
			{
				strcpy_s(arr[i].zodiac, "Aquarius");
			}
			else
			{
				strcpy_s(arr[i].zodiac, "Pisces");
			}
			break;
		}
		case 3:
		{
			if (arr[i].date[0] > 31)
			{
				cout << "Its wrong!" << endl;
				_getch();
				return -1;
			}
			if (arr[i].date[0] <= 20)
			{
				strcpy_s(arr[i].zodiac, "Pisces");
			}
			else
			{
				strcpy_s(arr[i].zodiac, "Aries");
			}
			break;
		}
		case 4:
		{
			if (arr[i].date[0] > 30)
			{
				cout << "Its wrong!" << endl;
				_getch();
				return -1;
			}
			if (arr[i].date[0] <= 20)
			{
				strcpy_s(arr[i].zodiac, "Aries");
			}
			else
			{
				strcpy_s(arr[i].zodiac, "Taurus");
			}
			break;
		}
		case 5:
		{
			if (arr[i].date[0] > 31)
			{
				cout << "Its wrong!" << endl;
				_getch();
				return -1;
			}
			if (arr[i].date[0] <= 20)
			{
				strcpy_s(arr[i].zodiac, "Taurus");
			}
			else
			{
				strcpy_s(arr[i].zodiac, "Gemini");
			}
			break;
		}
		case 6:
		{
			if (arr[i].date[0] > 30)
			{
				cout << "Its wrong!" << endl;
				_getch();
				return -1;
			}
			if (arr[i].date[0] <= 20)
			{
				strcpy_s(arr[i].zodiac, "Gemini");
			}
			else
			{
				strcpy_s(arr[i].zodiac, "Cancer");
			}
			break;
		}
		case 7:
		{
			if (arr[i].date[0] > 31)
			{
				cout << "Its wrong!" << endl;
				_getch();
				return -1;
			}
			if (arr[i].date[0] <= 22)
			{
				strcpy_s(arr[i].zodiac, "Cancer");
			}
			else
			{
				strcpy_s(arr[i].zodiac, "Leo");
			}
			break;
		}
		case 8:
		{
			if (arr[i].date[0] > 31)
			{
				cout << "Its wrong!" << endl;
				_getch();
				return -1;
			}
			if (arr[i].date[0] <= 22)
			{
				strcpy_s(arr[i].zodiac, "Leo");
			}
			else
			{
				strcpy_s(arr[i].zodiac, "Virgo");
			}
			break;
		}
		case 9:
		{
			if (arr[i].date[0] > 30)
			{
				cout << "Its wrong!" << endl;
				_getch();
				return -1;
			}
			if (arr[i].date[0] <= 23)
			{
				strcpy_s(arr[i].zodiac, "Virgo");
			}
			else
			{
				strcpy_s(arr[i].zodiac, "Libra");
			}
			break;
		}
		case 10:
		{
			if (arr[i].date[0] > 31)
			{
				cout << "Its wrong!" << endl;
				_getch();
				return -1;
			}
			if (arr[i].date[0] <= 23)
			{
				strcpy_s(arr[i].zodiac, "Libra");
			}
			else
			{
				strcpy_s(arr[i].zodiac, "Scorpio");
			}
			break;
		}
		case 11:
		{
			if (arr[i].date[0] > 30)
			{
				cout << "Its wrong!" << endl;
				_getch();
				return -1;
			}
			if (arr[i].date[0] <= 21)
			{
				strcpy_s(arr[i].zodiac, "Scorpio");
			}
			else
			{
				strcpy_s(arr[i].zodiac, "Sagittarius");
			}
			break;
		}
		case 12:
		{
			if (arr[i].date[0] > 31)
			{
				cout << "Its wrong!" << endl;
				_getch();
				return -1;
			}
			if (arr[i].date[0] <= 21)
			{
				strcpy_s(arr[i].zodiac, "Sagittarius");
			}
			else
			{
				strcpy_s(arr[i].zodiac, "Capricorn");
			}
			break;
		}
		}
		cout << endl;
		cout << "Year: ";
		cin >> arr[i].date[2];
		cout << endl;
		cout << "Patient name: " << arr[i].name << " Birth date: " << arr[i].date[0] << "." << arr[i].date[1] << "." << arr[i].date[2] << " Zodiak sigh: " << arr[i].zodiac << endl;
		while (getchar() != '\n');
	}
}
bool Search(ZNAK *arr, const int n, int month)
{
	bool cmp = false;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].date[1] == month)
		{
			cout << arr[i].name << " Birth date: " << arr[i].date[0] << "." << arr[i].date[1] << "." << arr[i].date[2] << " Zodiak sigh: " << arr[i].zodiac << endl;
			cmp = true;
		}
	}
	if (cmp)
	{
		return true;
	}
	else
	{
		return false;
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
	if (Search(Murkoff, n, month) == false)
	{
		cout << "There are no patients";
	}
	_getch();
	return 0;
}

