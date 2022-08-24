#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<sstream>
#include<stdlib.h>
#include"menu.h"
using namespace std;

class menu;
class customer
{
private:
	int id;        // table number
	fstream file;  // dish file to store the dishes the customer has ordered
	char str[20];  // file name
public:
	void order();
	void checkout();
	int Getid();
};

void customer::order() 
{
	menu m;
	int flag1 = 0;
	int flag2 = 0;
	string tempName; // name of the dish that customer want to order
	int tempPrice;
	bool judge = true; // The dish is not repeated ---- true
	vector<string> dish;// all the information from dish.txt

	//create a new dish file to store the customer information
	cout << "Please input the table number (from 1 to 10)" << endl;
	cin >> id;
	sprintf_s(str, "%d.txt", id);
	file.open(str, ios::out | ios::app);
	file.close();


	while (flag1 == 0) {
		flag2 = 0;
		// call the function to show the menu
		m.menu_browse();

		while (flag2 == 0) {
			cout << "Which dish do you want to order?" << endl;
			cout << "Input the name of the dish:";
			cin >> tempName;

			//read from the dish.txt
			dish.clear();
			string line;
			string temp;
			file.open(str, ios::in);
			while (getline(file, line)) {
				stringstream input(line);
				while (input >> temp) {
					dish.push_back(temp);
				}
			}
			file.close();
			
			// judge the input name is in dish.txt
			for (int i = 0; i < dish.size(); i++) {
				if (tempName == dish[i]) {
					judge = false;
				}
			}
			//same dish
			if (judge == false) {
				cout << "You have ordered the same dish. Please order another dish." << endl;
				judge = true;
			}
			//order
			else {
				// get price
				tempPrice = m.Getprice(tempName);
				// add the name and the price into the dish.txt
				file.open(str, ios::out|ios::app);
				file << tempName << "\t" << tempPrice << endl;
				file.close();
				cout << "This dish is ordered." << endl;
			}
			int choice;
			cout << "Do you want to continue your ording?" << endl;
			cout << "1. YES   2. NO" << endl;
			cin >> choice;
			switch (choice) {
			case 1:
				flag2 = 1;
				system("cls");
				break;
			case 2:
				return;

			}
		}
	}
}

void customer::checkout()
{
	vector<string>dish;

	//read into vector
	file.open(str, ios::in);
	string line;
	string temp;
	while (getline(file, line))
	{
		stringstream input(line);
		while (input >> temp)
		{
			dish.push_back(temp);
		}
	}
	file.close();

	//calculate
	int finalCost = 0;
	int price = 0; //store the temporary price
	for (int i = 1; i < dish.size(); i += 2) {
		price = stoi(dish[i]);
		finalCost += price;
	}
	//print the final cost
	cout << "The final cost is : " << finalCost << endl;
}

int customer::Getid()
{
	return id;
}

#endif