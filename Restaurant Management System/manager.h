#ifndef MANAGER_H
#define MANAGER_H
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>
#include<sstream>
#include<cstdio>
#include"menu.h"
#include"raw.h"
using namespace std;

class manager
{
public:
	//menu
	void menu_add();
	void menu_browse();
	void menu_delete();
	void menu_modify();
	//raw material
	void raw_add();
	void raw_browse();
	void raw_delete();
	void raw_modify();
	//customer
	void cus_add();
	void cus_browse();
	void cus_delete();
	void cus_modify();
	//gross profit
	void gross_profit(vector<int> v);
};

void manager::menu_add()
{
	menu m;
	m.menu_add();
}

void manager::menu_browse()
{
	menu m;
	m.menu_browse();
}

void manager::menu_delete()
{
	string name;
	cout << " Please type the course name: ";
	cin >> name;
	menu m;
	m.menu_delete(name);
}

void manager::menu_modify()
{
	string name;
	cout << " Please type the course name: ";
	cin >> name;
	menu m;
	m.menu_modify(name);
}

void manager::raw_add()
{
	raw r;
	r.raw_add();
}

void manager::raw_browse()
{
	raw r;
	r.raw_browse();
}

void manager::raw_delete()
{
	string name;
	cout << " Please type the name of the raw material: ";
	cin >> name;
	raw r;
	r.raw_delete(name);
}

void manager::raw_modify()
{
	string name;
	cout << " Please type the name of the raw material: ";
	cin >> name;
	raw r;
	r.raw_modify(name);
}

void manager::cus_add()
{
	fstream fout("temp.txt", ios::app);
	fout.close();
}

void manager::cus_browse()
{
	int num;
	cout << "Which table information do you want to check? " << endl;
	cout << "Please the table number :";
	cin >> num;
	
	//raed data from specific file and store it into the vecor
	char str[20];
	sprintf_s(str, "%d.txt", num);
	ifstream fin(str);
	if (!fin)
	{
		cerr << "Failure of opening the file! " << endl;
	}
	vector<string> table;
	table.clear();
	string line;
	string temp;
	while (getline(fin, line))
	{
		stringstream input(line);
		while (input >> temp)
		{
			table.push_back(temp);
		}
	}
	fin.close();

	// print out the customer info (dish name and pricec)
	cout << endl << setw(12) << "Name" << setw(12) << "Price" << endl;
	for (int i = 0; i < table.size(); i += 2) {
		for (int j = 0; j < 2; j++)
			cout << setw(12) << table[i + j] << " ";

		cout << endl;
	}
}

void manager::cus_delete()
{
	int num;
	cout << "Which table information do you want to delete? " << endl;
	cout << "Please the table number :";
	cin >> num;
	
	//delete the file
	char str[20];
	sprintf_s(str, "%d.txt", num);
	remove(str);
}

void manager::cus_modify()
{
	int num;
	cout << "Which table information do you want to check? " << endl;
	cout << "Please the table number :";
	cin >> num;

	//raed data from specific file and store it into the vecor
	char str[20];
	sprintf_s(str, "%d.txt", num);
	ifstream fin(str);
	if (!fin)
	{
		cerr << "Failure of opening the file! " << endl;
	}
	vector<string> table;
	table.clear();
	string line;
	string temp;
	while (getline(fin, line))
	{
		stringstream input(line);
		while (input >> temp)
		{
			table.push_back(temp);
		}
	}
	fin.close();
	
	string name;
	int pos=0;//line number
	cout << "Type the course name that you want to delete. " << endl;
	cin >> name;
	//search the course
	for (int i = 0; i < table.size(); i+=2)
	{
		if (name == table[i])
		{
			pos = (i + 2) / 2;// return the line number
			break;
		}
	}
	// Not found
	if (pos == 0)
	{
		cout << "The course cannot be found. " << endl;
		return;
	}

	//delete the course
	//delete the course name
	for (int i = pos*2-1; i < table.size(); i++)
	{
		table[i - 1] = table[i];
	}
	table.pop_back();
	//delete the price
	for (int i = pos * 2-1 ; i < table.size(); i++)
	{
		table[i - 1] = table[i];
	}
	table.pop_back();

	ofstream fout(str);
	for (int i = 0; i < table.size(); i += 2)
	{
		fout << table[i] << "\t" << table[i + 1] << endl;
	}
	fout.close();
}

void manager::gross_profit(vector<int> v) 
{
	int allProfit = 0;

	//read cost into a vector
	vector<string> cost;
	ifstream fin1("raw.txt");
	if (!fin1)
	{
		cout << "Failure of opening the file! " << endl;
	}
	string line1;
	string temp1;
	while (getline(fin1, line1))
	{
		stringstream input1(line1);
		while (input1 >> temp1)
		{
			cost.push_back(temp1);
		}
	}
	fin1.close();

	//get the profit for all dish
	vector<string> price;
	for (int i = 0; i < v.size(); i++) {
		//the vector has been initialized to 0 in "main" function
		if (v[i] != 0) {
			//read price into a vector
			price.clear();
			//choose the .txt file
			char str[20];
			sprintf_s(str, "%d.txt", v[i]);
			ifstream fin;
			fin.open(str);

			//get data
			if (!fin)
			{
				cout << "Failure of opening the file! " << endl;
			}
			string line;
			string temp;
			while (getline(fin, line))
			{
				stringstream input(line);
				while (input >> temp)
				{
					price.push_back(temp);
				}
			}
			fin.close();

			//calculate the profit
			int profit = 0; //initialized
			for (int i = 0; i < cost.size(); i += 2) 
			{
				for (int j = 0; j < price.size(); j += 2)
				{
					// raw material matches with the dish
					if (price[j] == cost[i])
					{
						profit += stoi(price[j + 1]) - stoi(cost[i + 1]);
					}
				}
			}

			//add all dishes together
			allProfit += profit;
		}
	}
	cout << "The profit is: " << allProfit << endl; //print out the result
}

#endif