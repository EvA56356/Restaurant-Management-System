#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include<sstream>
#include"menu.h"
#include"raw.h"
#include"chef.h"
#include"customer.h"
#include"manager.h"
using namespace std;

int main()
{
	vector<int>table(10); // Total table in the resturant
	manager m;
	chef f;
	customer c;
	int identity;
	int manager;
	int chef;
	int customer;
	int flag1 = 0; // the condition of while loop tp exit the whole program
	int flag2 = 0; // the condition of while loop to back to the choice of manager
	while (flag1 == 0) {
		cout << "1. Manager   2. Chef   3. Customer  4. Exit the program" << endl;
		cout << "Select your identity: ";
		cin >> identity;
		system("cls");
		int flag1 = 0;
		int flag2 = 0;
		while (flag2 == 0)
		{
			switch (identity)// go to the role you select
			{
			case 1:
				cout << "1. Browse the raw material information." << endl;
				cout << "2. Add information to raw material list." << endl;
				cout << "3. Modify the raw material information." << endl;
				cout << "4. Delete information from raw material list." << endl;
				cout << "5. Browse the menu information." << endl;
				cout << "6. Add information to menu list." << endl;
				cout << "7. Modify the menu information." << endl;
				cout << "8. Delete information from menu list." << endl;
				cout << "9. Browse the customer information." << endl;
				cout << "10. Add a new reservation for a customer." << endl;
				cout << "11. Modify the customer information." << endl;
				cout << "12. Delete customer information." << endl;
				cout << "13. Print out the gross profit." << endl;
				cout << "14. Choose your identity again." << endl;
				cout << "15. Exit the program." << endl;
				cout << "What do you want to do?" << endl;
				cin >> manager;
				system("cls");
				switch (manager)
				{
				case 1:
					// Browse the raw material information
					m.raw_browse();
					system("pause");
					system("cls");
					break;
				case 2:
					// Add information to raw material list
					m.raw_add();
					system("pause");
					system("cls");
					break;
				case 3:
					// Modify the raw material information
					m.raw_modify();
					system("pause");
					system("cls");
					break;
				case 4:
					// Delete information from raw material list
					m.raw_delete();
					system("pause");
					system("cls");
					break;
				case 5:
					//  Browse the menu information
					m.menu_browse();
					system("pause");
					system("cls");
					break;
				case 6:
					// Add information to menu list
					m.menu_add();
					system("pause");
					system("cls");
					break;
				case 7:
					// Modify the menu information
					m.menu_modify();
					system("pause");
					system("cls");
					break;
				case 8:
					// Delete information from menu list
					m.menu_delete();
					system("pause");
					system("cls");
					break;
				case 9:
					// Browse the customer information
					m.cus_browse();
					system("pause");
					system("cls");
					break;
				case 10:
					// Add a new reservation for a customer 
					m.cus_add();
					system("pause");
					system("cls");
					break;
				case 11:
					// Modify the customer information
					m.cus_modify();
					system("pause");
					system("cls");
					break;
				case 12:
					// Delete customer information
					m.cus_delete();
					system("pause");
					system("cls");
					break;
				case 13:
					m.gross_profit(table);
					system("pause");
					system("cls");
					break;
				case 14:
					flag2 = 1;// back to the choice 
					system("cls");
					break;
				case 15:
					return 0;
				default:
					break;

				}
				break;
			case 2:
				cout << "1. Browse the menu information." << endl;
				cout << "2. Add information to menu list." << endl;
				cout << "3. Modify the menu information." << endl;
				cout << "4. Delete information from menu list." << endl;
				cout << "5. Browse the raw material information." << endl;
				cout << "6. Add information to raw material list." << endl;
				cout << "7. Modify the raw material information." << endl;
				cout << "8. Delete information from raw material list." << endl;
				cout << "9. Choose your identity again." << endl;
				cout << "10. Exit the program." << endl;
				cout << "What do you want to do?" << endl;
				cin >> chef;
				switch (chef)
				{
				case 1:
					// Browse the menu information
					f.menu_browse();
					system("pause");
					system("cls");
					break;
				case 2:
					//  Add information to menu list
					f.menu_add();
					system("pause");
					system("cls");
					break;
				case 3:
					// Modify the menu information
					f.menu_modify();
					system("pause");
					system("cls");
					break;
				case 4:
					// Delete information from menu list
					f.menu_delete();
					system("pause");
					system("cls");
					break;
				case 5:
					// Browse the raw material information
					f.raw_browse();
					system("pause");
					system("cls");
					break;
				case 6:
					//  Add information to raw material list
					f.raw_add();
					system("pause");
					system("cls");
					break;
				case 7:
					//  Modify the raw material information
					f.raw_modify();
					system("pause");
					system("cls");
					break;
				case 8:
					// Delete information from raw material list
					f.raw_delete();
					system("pause");
					system("cls");
					break;
				case 9:
					flag2 = 1;// back to the choice 
					system("cls");
					break;
				case 10:
					return 0;
				default:
					break;
				}
				break;
			case 3:
				cout << "1. Order dishes." << endl;
				cout << "2. Check out." << endl;
				cout << "3. Choose your identity again." << endl;
				cout << "4. Exit the program." << endl;
				cout << "What do you want to do?" << endl;
				cin >> customer;
				switch (customer)
				{
				case 1:
					// Order dishes
					c.order();
					int i;
					for (i= 0; i < 10;i++)
					{
						//repeat
						if (c.Getid() == table[i])
							break;
					}
					if (i == 10)
					{
						table.push_back(c.Getid());
					}
					system("pause");
					system("cls");
					break;
				case 2:
					// Check out
					c.checkout();
					system("pause");
					system("cls");
					break;
				case 3:
					flag2 = 1;// back to the choice 
					system("cls");
					break;
				case 4:
					return 0;
				default:
					break;
				}
				break;
			case 4:
				flag1 = 1;
				return 0;
			default:
				break;
			};
		}
	}
	return 0;
}

