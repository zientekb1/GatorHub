/*
Name: Friend.h
Desciption: Stores and Outputs friends list and information

Date Coded: April 20th
Who contributed: Arielle Fashakin, Brendan Zientek
*/

#include <iostream>
#include <fstream>
#include "Profile.h"
using namespace std;

class Friends
{
private:
	Profile profileCreation;
	string fileContent;
	fstream addedFriendsFile;
	bool brendanFriend = false;
	bool eveFriend = false;
	bool anaFriend = false;
	bool arielleFriend = false;
public:
	void friendsList();		  //shows users profile if they are in the added friends file
	void readFile(ifstream&); //reads text profiles
	void addFriend(string);	  //adds friends to addedUsers if you sent user a friend request
	void addedFriends();
};
inline void Friends::readFile(ifstream &inputFile)
{
	cout << "\n";
	while (getline(inputFile, fileContent))
	{
		cout << fileContent << endl;
	}
	inputFile.close();
	cout << "\n";
}
inline void Friends::addedFriends()
{
	addedFriendsFile.open("addedUsers.txt", ios::in | ios::beg);
	while (getline(addedFriendsFile, fileContent))
	{
		if (fileContent == "Brendan Zientek")
		{
			brendanFriend = true;
		}
		else if (fileContent == "Eve Guenda")
		{
			eveFriend = true;
		}
		else if (fileContent == "Ana Tovar")
		{
			anaFriend = true;
		}
		else if (fileContent == "Arielle Fashakin")
		{
			arielleFriend = true;
		}
	}
}
inline void Friends::friendsList()
{
	ifstream inputFile;
	addedFriends();
	cout << "\n====== Friends List ======\n";
	if (brendanFriend)
	{
		inputFile.open("BrendanProfile.txt", ios::in | ios::beg);
		readFile(inputFile);
	}
	if (eveFriend)
	{
		inputFile.open("EveProfile.txt", ios::in | ios::beg);
		readFile(inputFile);
	}
	if (anaFriend)
	{
		inputFile.open("AnaProfile.txt", ios::in | ios::beg);
		readFile(inputFile);
	}
	if (arielleFriend)
	{
		inputFile.open("ArielleProfile.txt", ios::in | ios::beg);
		readFile(inputFile);
	}
	cout << "==========================\n\n";
}
inline void Friends::addFriend(string name)
{
	addedFriendsFile.open("AddedUsers.txt", ios::out | ios::app);

	addedFriendsFile << name << "\n";	//adds friend to added friends file
	cout << name << " is now your friend\n";

	addedFriendsFile.close();
}
