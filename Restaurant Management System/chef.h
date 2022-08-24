#ifndef CHEF_H
#define CHEF_H
#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<sstream>
#include"menu.h"
#include"raw.h"
#include"manager.h"
using namespace std;

class chef 
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
};

void chef::menu_add()
{
	menu m;
	m.menu_add();
}

void chef::menu_browse()
{
	menu m;
	m.menu_browse();
}

void chef::menu_delete()
{
	string name;
	cout << " Please type the course name: ";
	cin >> name;
	menu m;
	m.menu_delete(name);
}

void chef::menu_modify()
{
	string name;
	cout << " Please type the course name: ";
	cin >> name;
	menu m;
	m.menu_modify(name);
}

void chef::raw_add()
{
	raw r;
	r.raw_add();
}

void chef::raw_browse()
{
	raw r;
	r.raw_browse();
}

void chef::raw_delete()
{
	string name;
	cout << "Please type the  name of raw material: ";
	cin >> name;
	raw r;
	r.raw_delete(name);
}

void chef::raw_modify()
{
	string name;
	cout << " Please type the  name of raw material: ";
	cin >> name;
	raw r;
	r.raw_modify(name);
}

#endif