// ConsoleApplication26.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
void fillarray(double *arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the " << i + 1 << " element" << endl;
		cin >> arr[i];
	}
}
void checkarray(double *arr, const int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			checkserries(arr, k);
		}
	}
}
void checkserries(double *arr, int k)
{
	int s = 1;
	while (arr[i] == arr[i + 1])
	{
		s++;
	}
	if (s > k)
	{
		fillarray2(s);
	}
}
void fillarray2(int s)
{
	double B[10];
	for (int i = 0; i < s; i++)
	{

	}
}

int main()
{
	int k = 0;
	const int n = 10;
	double A[n];
	cout << "Enter k:" << endl;
	cin >> k;
	fillarray(A, n);
	return 0;
}
