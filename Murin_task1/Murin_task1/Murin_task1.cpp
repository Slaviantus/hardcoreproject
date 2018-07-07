// Murin_task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "cmath"
#include "conio.h"

using namespace std;

class cosinus
{
public:
	double x;
	int n;
	int i;
	void coscount()
	{
		for (i = 1; i <= n; i++)
		{
			s += pow(-1, i) * pow(x, 2 * i) / fact(2 * i);
		}
		cout << s << endl;
	}

private:
	double s = 1;
	int fact(int f)
	{
		if (f == 0)
		{
			return 0;
		}
		if (f == 1)
		{
			return 1;
		}
		return f * fact(f - 1);
	}
};

int main()
{
	cosinus a;
	cout << "Enter x" << endl;
	cin >> a.x;
	cout << "Enter n" << endl;
	cin >> a.n;
	a.coscount();
	_getch();
	return 0;
}

