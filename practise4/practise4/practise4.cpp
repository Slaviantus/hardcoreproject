// practise4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"

using namespace std;

void fillarrayA(double *arr, int str)
{
	for (int i = 0; i < str; i++)
	{
		cout << "Enter " << i + 1 << " element of array A" << endl;
		cin >> arr[i];
	}
}
int main()
{
	int k = 0, m = 0;
	const int n = 9;
	double A[9];
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
	cout << "Fill the array A" << endl;
	fillarrayA(A, n);
    return 0;
}

