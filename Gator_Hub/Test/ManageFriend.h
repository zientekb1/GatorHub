/*
Name: Manage Friends
Desciption: User interaction with users to add/remove 
			and viewing friends profile.

Date Coded: April 23th
Who contributed: Brendan Zientek
*/
#ifndef ifndef_ManageFriends
#define ifndef_ManageFriends

#include <iostream>
#include <string>
#include "Friend.h"

using namespace std;

class manageFriends
{
private:
	Friends friendProfile;
	int choice;
	string name;
	ifstream inputFile;
public:
	void displayCurrentUsers();
	void manageFriendsList();
};
inline void manageFriends::displayCurrentUsers()
{
	cout << "\n====== Current Users ======\n";
	cout << "Brendan Zientek\nEve Guenda\nAna Tovar\nArielle Fashakin\n";
	cout << "=============================\n";
	cout << "\nPlease Type The Full Name of The User: ";
	cin.ignore();
	getline(cin, name);
}
inline void manageFriends::manageFriendsList()
{
	cout << "====== Friends Menu ======\n";
	cout << "1. Send Friend Request\n2. Search Friend\n3. Show all Friends\n";
	cout << "==========================\n";
	cin >> choice;

	if (choice == 1)
	{
		displayCurrentUsers();
		if (name == "Brendan Zientek")
		{
			friendProfile.addFriend(name);
		}
		else if (name == "Eve Guenda")
		{
			friendProfile.addFriend(name);
		}
		else if (name == "Ana Tovar")
		{
			friendProfile.addFriend(name);
		}
		else if (name == "Arielle Fashakin")
		{
			friendProfile.addFriend(name);
		}
		else
		{
			cout << "User inputted does not have a profile\n";
		}
	}
	else if (choice == 2)
	{
		displayCurrentUsers();
		if (name == "Brendan Zientek")
		{
			inputFile.open("BrendanProfile.txt", ios::in | ios::beg);
			friendProfile.readFile(inputFile);
		}
		else if (name == "Eve Guenda")
		{
			inputFile.open("EveProfile.txt", ios::in | ios::beg);
			friendProfile.readFile(inputFile);
		}
		else if (name == "Ana Tovar")
		{
			inputFile.open("AnaProfile.txt", ios::in | ios::beg);
			friendProfile.readFile(inputFile);
		}
		else if (name == "Arielle Fashakin")
		{
			inputFile.open("ArielleProfile.txt", ios::in | ios::beg);
			friendProfile.readFile(inputFile);
		}
		else
		{
			cout << "Error in profile search menu\n";
		}
		
	}
	else if (choice == 3)
	{
		friendProfile.friendsList();	//need to add ana and arielle
	}
	else
	{
		cout << "error in choice selection\n";
	}
}
#endif // !ifndef_Friends
