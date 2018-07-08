// proekt Murin 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "cmath"

using namespace std;

class  Modul
{
public:
	void SetXYZ(int valueX, int valueY, int valueZ)
	{
		x = valueX;
		y = valueY;
		z = valueZ;
	}

	void modulres()
	{
		result = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}

	double Getresult()
	{
		return result;
	}
private:
	int x;
	int y;
	int z;
	double result = 0;
};

int main()
{
	Modul a;
	a.SetXYZ(2, 2, 2);
	a.modulres();
	cout << "Result: " << a.Getresult() << endl;
	_getch();
    return 0;
}

