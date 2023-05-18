/*
Name: User Interface Class
Desciption: Displays menus which guides the user through the program
Date Coded: April 15
Who contributed: Brendan
*/

#include <stdlib.h>			//header file to clear screen
#include "PostInteract.h"	//Displays Post Interaction Class
#include "Manage Profile.h"	//Display Profile Settings menu
#include "ManageFriend.h"	//Displays Manage Friends Class menu
#include "Login Account.h"	//Guest become users

class UserInterface
{
private:
	int choice;	//hold users menu selection
public:
	void clearScreen();
	void displayLoginScreen();
	void displayHomeScreen();	//Displays what the users sees first
};
void UserInterface::displayHomeScreen() //first thing users sees
{
	cout << "====== Home Screen ======\n";
	cout << "1. Profile Settings\n";
	cout << "2. Friends Menu\n";
	cout << "3. Post Interaction Menu\n";
	cout << "=========================\n";
	cin >> choice;

	if (choice == 1)
	{
		clearScreen();		//Clears console screen
		ManageProfile mp;
		mp.manageProfile();	//takes user to Manage Profile.h
		displayHomeScreen();
	}
	else if (choice == 2)
	{
		clearScreen();
		manageFriends mf;
		mf.manageFriendsList();
		displayHomeScreen();
	}
	else if (choice == 3)
	{
		clearScreen();
		PostInteraction postcontrol;
		postcontrol.postInteraction(); //takes user to postInteract.h
		displayHomeScreen();
	}
	else
	{
		cout << "error in display home screen option\n";
		displayHomeScreen();
	}
}
void UserInterface::clearScreen()
{
	system("cls"); //this will clear the console
}
void UserInterface::displayLoginScreen()
{
	LoginAccount la;
	la.LoginMenu();
}
int main()
{
	UserInterface UI;
	UI.displayLoginScreen(); //Present guest with login or register screen to become a user
	UI.displayHomeScreen();	//when program starts show home screen
}