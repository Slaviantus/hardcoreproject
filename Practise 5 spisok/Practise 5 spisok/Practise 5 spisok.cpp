// Practise 5 spisok.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Merkoff.h"
#include "iostream"
#include "conio.h"
#include "String"

using namespace std;

int main()
{
	Merkoff List;
	//List.Entermonth();
	List.menu();
	_getch();
    return 0;
}

