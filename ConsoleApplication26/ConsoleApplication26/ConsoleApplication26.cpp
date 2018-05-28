// ConsoleApplication26.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "conio.h"


using namespace std;
void fillarray(double *arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the " << i + 1 << " element" << endl;
		cin >> arr[i];
	}
}
void showarray(double *arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void serianumber(int &i, double *array, int &seria)
{
	while (array[i] == array[i + 1])
	{
		seria++;
		i++;
	}
}
void cmpseria(int &k, int &s, double *array1, double *array2, int i, int &j)
{
	if (s <= k)
	{
		i = i - s + 1;
		for (int k = 0; k < s; k++)
		{
			array2[j] = array1[i];
			i++;
			j++;
		}
	}
}

void checkarray(double *arr1, double *arr2, const int n, int k)
{
	int s = 1;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr1[i] == arr1[i + 1])
		{
			serianumber(i, arr1, s);
			cmpseria(k, s, arr1, arr2, i, j);
			s = 1;
		}
		else
		{
			arr2[j] = arr1[i];
			j++;
		}
	}
}
int main()
{
	int k = 0;
	const int n = 10;
	double A[n];
	double B[n];
	cout << "Enter k:" << endl;
	cin >> k;
	fillarray(A, n);
	cout << "Before" << endl;
	showarray(A, n);
	checkarray(A, B, n, k);
	cout << "After" << endl;
	showarray(B, n);
	_getch();
	return 0;
}
