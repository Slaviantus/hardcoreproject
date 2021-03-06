// practise4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"

using namespace std;

void fillarrayA(double *arr, int col)
{
	for (int i = 0; i < col; i++)
	{
		cout << "Enter " << i + 1 << " element of array A" << endl;
		cin >> arr[i];
	}
}
void fillarrayB(double *arrA, int col, int m, double *arrB, int k)
{
	int i = 0;
	while (i != k)
	{
		arrB[i] = arrA[i];
		i++;
	}
	while (i != k + m)
	{
		arrB[i] = 0;
		i++;
	}
	while (i != col + m)
	{
		arrB[i] = arrA[i - m];
		i++;
	}
}
void showarray(double *arr, int col)
{
	for (int i = 0; i < col; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	int k = 0, m = 0, n = 0;
	cout << "Enter n" << endl;
	cin >> n;
	double *A = new double[n];
	cout << "Enter k" << endl;
	cin >> k;
	cout << "Enter m" << endl;
	cin >> m;
	if (k < 1 || k > n || m < 1 || m > 10)
	{
		cout << "Its wrong!" << endl;
		return -1;
		_getch();
	}
	k--;
	cout << "Fill the array A" << endl;
	fillarrayA(A, n);
	double *B = new double[n + m];
	fillarrayB(A, n, m, B, k);
	cout << "Array before changes" << endl;
	showarray(A, n);
	cout << "Array after changes" << endl;
	showarray(B, n + m);
	delete [] A;
	delete [] B;
	_getch();
	return 0;
}
