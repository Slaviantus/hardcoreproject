

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

class sinus
{
public:
	double x;
	static int n;
	void sincount()
	{
		for (int i = 0; i <= n; i++)
		{
			s += pow(-1, i) * pow(x, 2 * i + 1) / fact(2 * i);
		}
	}
	void print()
	{
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

int sinus::n;
int main()
{
	/*cosinus a;
	cout << "Enter x" << endl;
	cin >> a.x;
	cout << "Enter n" << endl;
	cin >> a.n;
	a.coscount();*/
	sinus b;
	cout << "Enter x" << endl;
	cin >> b.x;
	cout << "Enter x" << endl;
	cin >> b.x;
	b.sincount();
	b.print();
	_getch();
	return 0;
}

