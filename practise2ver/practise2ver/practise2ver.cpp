// practise2ver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "cmath"

using namespace std;

void Sortie(double *arr, const int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int max = 0;
		int maxnum = 0;
		for (int j = i; j < n; j++)
		{
			if (arr[j] > max)
			{
				max = arr[j];
				maxnum = j;
			}
		}
		arr[maxnum] = arr[i];
		arr[i] = max;
	}
}
void showarray(double *arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
int main()
{
	const int n = 5;
	double A = 0;
	double B[n];
	cout << "Enter the coordinate of point A" << endl;
	cin >> A;
	cout << "Enter coordinates of points B" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the coordinate of point B" << i + 1 << endl;
		cin >> B[i];
		if (B[i] == B[i - 1] && i > 0)
		{
			cout << "This is the same point, its wrong!" << endl;
			_getch();
			return -1;
		}
		B[i] = abs(A - B[i]);
	}//done
	Sortie(B, n);
	showarray(B, n);
	_getch();
    return 0;
}

