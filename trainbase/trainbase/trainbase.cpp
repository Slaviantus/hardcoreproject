// trainbase.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "string"

using namespace std;

class train
{
	int number = 0;
	int carnum = 0;
	string start;
	string finish;
	int *typecar;
	void fillarray();
	class carriage
	{
		string type;
	public:
		carriage();
		~carriage();
	};
public:
	train();
	void Show();
	~train();
};



void train::fillarray()
{
	cout << "Enter the type of carriages \n Enter 1 if the carriage is econom \n Enter 2 if the carriage is business \n Enter 3 if the carriage is rich" << endl;
	for (int i = 0; i < carnum; i++)
	{
		cout << "The " << i + 1 << " carriage is:" << endl;
		cin >> typecar[i];
	}
}



void train::Show()
{
	cout << "train №:" << number << " From:" << start << " to:" << finish << endl;
}



train::train()
{
	cout << "Enter number of train" << endl;
	cin >> number;
	cout << "Enter number of carriges" << endl;
	cin >> carnum;
	cout << "Enter start station" << endl;
	cin >> start;
	cout << "Enter destination" << endl;
	cin >> finish;
	typecar = new int[carnum];
	fillarray();
}



train::~train()
{
	delete[] typecar;
}



train::carriage::carriage()
{

}



train::carriage::~carriage()
{

}




int main()
{
	train a;
	a.Show();
	return 0;
}