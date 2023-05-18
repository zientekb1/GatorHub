/*
Name: Reported Users Class
Desciption: Stores reported post in a file titled Reported User List.txt and displays them
Date Coded: April 15
Who contributed: Brendan 
*/

#ifndef ifndef_ReportedUsersEntity
#define ifndef_ReportedUsersEntity

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class ReportedUsers
{
private:
	string reportedUsers;		//holds reported user name
	fstream reportedUsersFile;	//hold names of reported users
public:
	void setReportedUser(string);
	string getReportedUser() const;
	void printFile();			//Display reported users names
	void writeReportedUser();	//Write reported users into file
};
inline void ReportedUsers::setReportedUser(string a)
{
	reportedUsers = a;
}
inline string ReportedUsers::getReportedUser() const
{
	return reportedUsers;
}
inline void ReportedUsers::printFile()	//Display The Reported Users
{
	string readFile;
	reportedUsersFile.open("Reported User List.txt", ios::in | ios::app);
	while (getline(reportedUsersFile, readFile))
	{
		cout << readFile << endl;
	}
	reportedUsersFile.close();
}
inline void ReportedUsers::writeReportedUser()	//Write Reported Users
{
	reportedUsersFile.open("Reported User List.txt", ios::out | ios::app | ios::beg);
	string name;
	cout << "Enter the name of the user: ";
	cin.ignore();
	getline(cin, name);
	setReportedUser(name);
	reportedUsersFile << getReportedUser() << endl;
	reportedUsersFile.close();
	cout << "\n";
}
#endif // !ifndef_ReportedUsersEntity