/*
Name: Post Interaction Class
Desciption: User can like, report, create, delete, or display post by
			searching its title. Post data is stored in the Post File.txt
			Reported users are stored in Reported User List.txt
Date Coded: April 15
Who contributed: Brendan
*/

#ifndef ifndef_PostInteract
#define ifndef_PostInteract


#include <iostream>
#include <string>
#include <fstream>
#include "ReportedUsersEntity.h"	//Reported Users Entity 
#include "Post Class.h"				//Post Class Entity
#include "Profile.h"				//Profile Class Entity
#include "Post File.txt"			//Post Class Entity

using namespace std;
class PostInteraction
{
private:
	ReportedUsers reportedUser;
	PostClass PC;
	Profile PF;
	ifstream UserProfiletxt;
	string readFile;
public:
	void postInteraction();	//main menu
};
inline void PostInteraction::postInteraction()
{
	int choice;
	cout << "====== GatorHub Post Menu ======\n";
	cout << "1. Report User\n2. View Reported Users List\n"
		<< "3. Like Post\n4. Create a Post\n5. Delete Post\n"
		<< "6. Display Post\n";
	cout << "================================\n";
	cin >> choice;

	if (choice == 1)
	{
		reportedUser.writeReportedUser();	//Write reported user in file for admins
	}
	else if (choice == 2)					//Display reported users if the profile is an admins
	{
		UserProfiletxt.open("UserProfileData.txt");
		UserProfiletxt >> readFile;
		if (readFile == "Admin")
		{
			cout << "\n====== Reported Users ======\n";
			reportedUser.printFile();
			cout << "============================\n\n";
		}
		else
		{
			cout << "Only admins have permission to view reported users\n";

		}
		UserProfiletxt.close();
	}
	else if (choice == 3)		//Like post
	{
		PC.likePost();
	}
	else if (choice == 4)		//Create a post in Post File.txt
	{
		string content;
		cout << "What would you like to title the post? \n";
		cin.ignore();
		getline(cin, content);
		PC.setPostTitle(content);
		cout << "\nEnter what will be posted: \n";
		getline(cin, content);
		PC.setTypedContent(content);
		PC.makePost();
	}
	else if (choice == 5)		//Delete all of the post in Post File.txt
	{
		PC.deletePost();
	}
	else if (choice == 6)		//Display all of the post in Post File.txt
	{
		PC.printPost();
	}
	else
	{
		cout << "Error in post interaction menu\n";
	}
}
#endif // !ifndef_PostInteract
