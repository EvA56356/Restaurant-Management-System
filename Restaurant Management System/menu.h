#ifndef MENU_H
#define MENU_H

#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<sstream>
#include<stdlib.h>
using namespace std;

class chef;
class manager;
class menu
{
	friend class chef;
	friend class maneger;
private:
	int num;       //Index
	string name;   //Course name
	int price;     //Course price
	fstream file;  //File for storing the data
public:
	void menu_add();
	vector<string> menu_read();
	void menu_browse();
	int menu_search(string name);
	void menu_delete(string name);
	void menu_modify(string name);
	int Getprice(string name);
};

void menu::menu_add()
{
	vector<string> menu = menu_read();
	
	int flag = 0; //  Find the same name = 0

	file.open("menu.txt", ios::out|ios::app);
	while (flag == 0)
	{
		cout << "Please input the index number of dish" << endl;
		cin >> num;
		cout << "Please input the name of dish" << endl;
		cin >> name;
		cout << "Please input the price of dish" << endl;
		cin >> price;
		int i = 0;
		for (i = 0; i < menu.size(); i++)
		{
			if (name == menu[i])
			{
				flag = 0;
				break;
			}
		}
		//Not found or the file is empty
		if (i == menu.size() || i == 0)
		{
			flag = 1;
		}
		//Same name
		if (flag == 0)
		{
			cout << "The course has already been added. " << endl;
		}
	}

	file << num << "\t" << name << "\t" << price << endl;
	file.close();
}

vector<string> menu::menu_read()
{
	vector<string> menu;

	string line;  //string for each line 
	string temp;  //seperate string 

	//read the data from the file and store into vector menu
	file.open("menu.txt",ios::in);
	if (!file)
	{
		cerr << "Failure of opening the file! " << endl;
	}
	while (getline(file, line))
	{
		stringstream input(line);
		while (input >> temp)
		{
			menu.push_back(temp);
		}
	}
	file.close();
	return menu;
}

void menu::menu_browse()
{
	vector<string> menu=menu_read();
	cout << endl << setw(12) << "Number" << setw(12) << "name" << setw(12) << "price" << endl;
	for (int i = 0; i < menu.size(); i += 3) {
		for (int j = 0; j < 3; j++)
			cout << setw(12) << menu[i + j] << " ";
		cout << endl;
	}
}

int menu::menu_search(string name)
{
	vector<string> menu = menu_read();
	for (int i = 0; i < menu.size(); i++)
	{
		if (name == menu[i])
		{
			return (i + 2) / 3; //return the line number
		}
	}
	cout << "The dish cannot be found!" << endl;
	return 0;
}

void menu::menu_delete(string name)
{
	vector<string> menu = menu_read();
	// position of price
	int pos = menu_search(name) * 3 - 2;
	//delete number
	for (int i = pos; i < menu.size(); i++)
	{
		menu[i - 1] = menu[i];
	}
	menu.pop_back();
	//delete name
	for (int i = pos; i < menu.size(); i++)
	{
		menu[i - 1] = menu[i];
	}
	menu.pop_back();
	//delete price
	for (int i = pos; i < menu.size(); i++)
	{
		menu[i - 1] = menu[i];
	}
	menu.pop_back();

	//write the vector into the file
	file.open("menu.txt",ios::out);
	if (!file)
	{
		cerr << "Failure of opening the file! " << endl;
	}
	for (int i = 0; i < menu.size(); i += 3)
	{
		file << menu[i] << "\t" << menu[i+1] << "\t" << menu[i + 2] << endl;
	}
	file.close();
}

void menu::menu_modify(string name)
{
	vector <string> menu = menu_read();
	
	if (menu_search(name) == 0)
	{
		cout << "The course cannot be found." << endl;
		return;
	}
	string id;     // temp id
	string price;  // temp price
	cout << "Modify the name." << endl;
	cin >> id;
	cout << "Modify the price. " << endl;
	cin >> price;
	// locate the position of line number
	int pos = menu_search(name);
	menu[3*pos-2]=id;
	menu[ 3*pos-1]=price;

	file.open("menu.txt",ios::out);
	if (!file)
	{
		cerr << "Failure of opening the file! " << endl;
	}
	for (int i = 0; i < menu.size(); i += 3)
	{
		file  << menu[i] << "\t" << menu[i + 1] << "\t" << menu[i + 2] << endl;
	}
	file.close();
}

int menu::Getprice(string name)
{
	vector<string> menu = menu_read();
	int price;
	stringstream input(menu[3 * menu_search(name) - 1]);
	//convert string type into int type
	input >> price;
	return price;
}

#endif