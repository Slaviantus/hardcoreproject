// trainbase.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "string"
#include "conio.h"

using namespace std;

class train
{
	int number = 0;
	int carnum = 0;
	string start;
	string finish;
	class carriage
	{
		int number;
		string type;
		bool *seats;
	public:
		void Setdata(int num, char t);
		bool *Getseats(bool )
		~carriage();
	};
	void showcar(carriage *cars, int carnum);
public:
	train();
	void Show();
	~train();
};



void train::Show()
{
	cout << "train №:" << number << " From:" << start << " to:" << finish << endl;
	
}

void train::showcar(carriage *cars, int carnum)
{
	for (int i = 0; i < carnum; i++)
	{
		cars[i].
	}
}



train::train()
{
	
	cout << "Enter number of train" << endl;
	cin >> number;
	cout << "Enter the total number of carriages" << endl;
	cin >> carnum;
	cout << "Enter start station" << endl;
	cin >> start;
	cout << "Enter destination" << endl;
	cin >> finish;
	carriage *wagen = new carriage[carnum];
	for (int i = 0; i < carnum; i++)
	{
		char t;
		cout << "Enter the type of carriage number " << i + 1 <<": c - econom, b - busines, a - royal" << endl;
		cin >> t;
		
		wagen[i].Setdata(i + 1, t);
	}
	showcar(wagen, carnum);
}



train::~train()
{

}


 void train::carriage::Setdata(int num, char t)
{
	 to_string(t);
	 number = num;
	 type = t;
	 if (type == "c")
	 {
		 bool seats = new bool[100];
		 type = "Econom";
	 }
	 if (type == "b")
	 {
		 bool seats = new bool[56];
		 type = "Business";
	 }
	 if (type == "a")
	 {
		 bool seats = new bool[36];
		 type = "Royal";
	 }
}



train::carriage::~carriage()
{

}




int main()
{
	train a;
	a.Show();
	_getch();
	return 0;
}