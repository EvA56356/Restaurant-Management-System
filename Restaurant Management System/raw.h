#ifndef RAW_H
#define RAW_H
#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<sstream>
#include<stdlib.h>
using namespace std;

class chef;
class manager;
class raw
{
	friend class chef;
	friend class manager;
private:
	string name;   //name of raw material
	int price;     //price of raw material
	fstream file;  //file for storing data
public:
	void raw_add();
	vector<string> raw_read();
	void raw_browse();
	int raw_search(string name);
	void raw_delete(string name);
	void raw_modify(string name);
	int Getprice(string name);
};

void raw::raw_add()
{
	vector<string> raw = raw_read();
	int flag = 0; // detect whether the raw name is repeated  0--not repeat 1--repeat
	//open the file to add raw materials
	file.open("raw.txt", ios::app | ios::out);
	while (flag == 0)
	{
		cout << "Please input the name of raw material" << endl;
		cin >> name;
		cout << "Please input the price of raw material" << endl;
		cin >> price;
		int i;
		for (i = 0; i < raw.size(); i++)
		{
			if (name == raw[i])
			{
				flag = 0;
				break;
			}
		}
		//Not found
		if (i == raw.size() || i == 0)
		{
			flag = 1;
		}
		//Same name
		if (flag == 0)
		{
			cout << "The material has already been added. " << endl;
		}
	}
	//write into the file
	file << name << "\t" << price << endl;
	file.close();
}

vector<string> raw::raw_read()
{
	vector<string> raw;
	string line;  //string for each line 
	string temp;  //seperate string 
	file.open("raw.txt",ios::in);
	if (!file)
	{
		cerr << "Failure of opening the file! " << endl;
	}
	while (getline(file, line))
	{
		// read from each line
		stringstream input(line);
		// convert to string type and store in the temp vector
		while (input >> temp)
		{
			raw.push_back(temp);
		}
	}
	file.close();
	return raw;
}

void raw::raw_browse()
{
	vector<string> raw = raw_read();
	cout << endl << setw(12) << "Name" << setw(12) << "price" << endl;
	for (int i = 0; i < raw.size(); i += 2) {
		for (int j = 0; j < 2; j++)
			cout << setw(12) << raw[i + j] << " ";

		cout << endl;
	}
}

int raw::raw_search(string name)
{
	vector<string> raw = raw_read();
	for (int i = 0; i < raw.size(); i++)
	{
		if (name == raw[i])
		{
			return (i + 2) / 2; // return the line number
		}
	}
	cout << "The raw material cannot be found!" << endl;
	return 0;
}

void raw::raw_delete(string name)
{
	vector<string> raw = raw_read();
	if (raw_search(name) == 0)
	{
		cout << "The raw material cannot be found." << endl;
		return;
	}
	//locate the price position
	int pos = raw_search(name) * 2 - 1;
    //delete name
	for (int i = pos; i < raw.size(); i++)
	{
		raw[i - 1] = raw[i];
	}
	raw.pop_back();
	//delete price
	for (int i = pos; i < raw.size(); i++)
	{
		raw[i - 1] = raw[i];
	}
	raw.pop_back();
	
	//open file to write vector into the file
	file.open("raw.txt",ios::out);
	if (!file)
	{
		cerr << "Failure of opening the file! " << endl;
	}
	for (int i = 0; i < raw.size(); i += 2)
	{
		file << raw[i] << "\t" << raw[i + 1] << endl;
	}
	file.close();
}

void raw::raw_modify(string name)
{
	vector<string> raw = raw_read();
	// check if the name exists
	if (raw_search(name) == 0)
	{
		cout << "The raw material cannot be found." << endl;
		return;
	}

	string id;
	string price;
	cout << "Modify the name." << endl;
	cin >> id;
	cout << "Modify the price. " << endl;
	cin >> price;

	//locate the line number
	int pos = raw_search(name);
	raw[2*pos-2] = id;
	raw[2*pos-1] = price;

	//open file to write vector into the file
    file.open("raw.txt",ios::out);
	if (!file)
	{
		cerr << "Failure of opening the file! " << endl;
	}
	for (int i = 0; i < raw.size(); i += 2)
	{
		file << raw[i] << "\t" << raw[i + 1] << endl;
	}
	file.close();
}

int raw::Getprice(string name)
{
	int price;
	vector<string> raw = raw_read();
	stringstream input(raw[2 * raw_search(name) - 1]);
	//convert string type into int type
	input >> price;
	return price;
}

#endif 