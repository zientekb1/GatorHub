/*
Name: Manage Profile
Desciption: User can setup, update, and display there profile.
			all user information is stored in UserProfile.txt
Date Coded: April 20
Who contributed: Brendan
*/
#ifndef indef_ManageProfile
#define indef_ManageProfile

#include <iostream>
#include "profile.h"

using namespace std;
class ManageProfile
{
public:
	void manageProfile();	//Display, update, and setup user's profile
	Profile mp;
};
inline void ManageProfile::manageProfile()
{	
	int choice;
	cout << "====== Profile Settings ======\n";
	cout << "1. Profile Setup\n2. Display Profile\n";
	cout << "==============================\n";
	cin >> choice;

	/*Calls all of the update function stored in Profile.h 
	to setup user profile and stores them in UserProfileData.txt*/
	if (choice == 1)
	{
		mp.setupProfile();
	}
	else if (choice == 2)	//Displays all the information in UserProfileData.txt
	{
		mp.printAll();
	}
	else
	{
		cout << "Error choice Manage Profile\n";
	}
}
#endif
