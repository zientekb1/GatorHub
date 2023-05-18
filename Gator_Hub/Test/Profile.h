/*
Name: Profile Class
Desciption: Stpres users profile type, first name, last name, skills,
			username, password, birthday, person statement, clubs,
			classification, major, and prospective industry. Users
			can display profile information and update them as well.
			All profile information in stored in UserProfileData.txt
Date Coded: April 15
Who contributed: Brendan
*/
#ifndef ifndef_Profile
#define ifndef_Profile


#include <iostream>
#include <string>
using namespace std;
class Profile
{
private:
	string profileType = "";
	string fName = "";
	string lName = "";
	string skills = "";
	string birthday = "";
	string personalStatement = "";
	string clubs = "";
	string classification = "";
	string major = "";
	string prospectiveIndustry = "";
	fstream User_Profile_Data;
public:
	string getProfileType();
	void setProfileType(int);
	string getFname();
	void setFname(string);
	string getLname();
	void setLname(string);
	string getBirthday();
	void setBirthday(string);
	string getPersonalStatement();
	void setPersonalStatement(string);
	string getClubs();
	void setClubs(string);
	string getSkills();
	void setSkills(string);
	string getClassification();
	void setClassification(string);
	string getMajor();
	void setMajor(string);
	string getProspectiveIndustry();
	void setProspectiveIndustry(string);

	void updateFname();
	void updateLname();
	void updatePersonalStatement();
	void updateClubs();
	void updateSkills();
	void updateClassification();
	void updateMajor();
	void updateProspectiveIndustry();

	void setupProfile();	//Calls all of the update functions to setup a profile
	void printAll();		//Display all of the users profile data stored in "UserProfileData.txt"
	void updateProfileType();
	void updateBirthday();
};
inline string Profile::getProfileType()
{
	return profileType;
}
inline void Profile::setProfileType(int a)
{
	if (a == 1)
	{
		profileType = "Admin";
	}
	else if (a == 2)
	{
		profileType = "User";
	}
	else
	{
		cout << "error type setProfileType\n";
	}
}

inline string Profile::getFname()
{
	return fName;
}
inline void Profile::setFname(string b)
{
	fName = b;
}

inline string Profile::getLname()
{
	return lName;
}
inline void Profile::setLname(string c)
{
	lName = c;
}

inline string Profile::getSkills()
{
	return skills;
}
inline void Profile::setSkills(string d)
{
	skills = d;
}

inline string Profile::getBirthday()
{
	return birthday;
}
inline void Profile::setBirthday(string g)
{
	birthday = g;
}

inline string Profile::getPersonalStatement()
{
	return personalStatement;
}
inline void Profile::setPersonalStatement(string h)
{
	personalStatement = h;
}

inline string Profile::getClubs()
{
	return clubs;
}
inline void Profile::setClubs(string i)
{
	clubs = i;
}

inline string Profile::getClassification()
{
	return classification;
}
inline void Profile::setClassification(string j)
{
	classification = j;
}

inline string Profile::getMajor()
{
	return major;
}
inline void Profile::setMajor(string k)
{
	major = k;
}

inline string Profile::getProspectiveIndustry()
{
	return prospectiveIndustry;
}
inline void Profile::setProspectiveIndustry(string l)
{
	prospectiveIndustry = l;
}
inline void Profile::updateProfileType()
{
	int changeProfileType;
	cin.ignore();
	cout << "Profile Type:\n1. Admin\n2. User\n";
	cin >> changeProfileType;
	setProfileType(changeProfileType);
}
inline void Profile::updateFname()
{
	string changeFname;
	cin.ignore();
	cout << "Enter first name: \n";
	getline(cin, changeFname);
	setFname(changeFname);
}
inline void Profile::updateLname()
{
	string changeLname;
	cin.ignore();
	cout << "Enter last name: \n";
	getline(cin, changeLname);
	setLname(changeLname);
}
inline void Profile::updatePersonalStatement()
{
	string changePS;
	cin.ignore();
	cout << "Enter personal statement: \n";
	getline(cin, changePS);
	setPersonalStatement(changePS);
}
inline void Profile::updateClubs()
{
	string changeClubs;
	cin.ignore();
	cout << "Enter clubs: \n";
	getline(cin, changeClubs);
	setClubs(changeClubs);
}
inline void Profile::updateSkills()
{
	string changeSkills;
	cin.ignore();
	cout << "Enter skills: \n";
	getline(cin, changeSkills);
	setSkills(changeSkills);
}
inline void Profile::updateClassification()
{
	string changeClassification;
	cin.ignore();
	cout << "Enter classifications: \n";
	getline(cin, changeClassification);
	setClassification(changeClassification);
}
inline void Profile::updateMajor()
{
	string changeMajor;
	cin.ignore();
	cout << "Enter major: \n";
	getline(cin, changeMajor);
	setMajor(changeMajor);
}
inline void Profile::updateProspectiveIndustry()
{
	string changePI;
	cin.ignore();
	cout << "Enter prospective industry: \n";
	getline(cin, changePI);
	setProspectiveIndustry(changePI);
}
inline void Profile::updateBirthday()
{
	string changeBirthday;
	cin.ignore();
	cout << "Enter Birthday: \n";
	getline(cin, changeBirthday);
	setBirthday(changeBirthday);
}
inline void Profile::printAll()
{
	User_Profile_Data.open("UserProfileData.txt", ios::in | ios::app | ios::beg);
	string readFile;
	cout << "\n====== Profile ======\n";
	while (getline(User_Profile_Data, readFile))
	{
		cout << readFile << endl;
	}
	cout << "=======================\n\n";
	User_Profile_Data.close();
}
inline void Profile::setupProfile()	//inputs all of user profile data and stores it into the UserProfileData.txt
{
	updateProfileType();
	updateFname();
	updateLname();
	updateBirthday();
	updatePersonalStatement();
	updateClubs();
	updateSkills();
	updateClassification();
	updateMajor();
	updateProspectiveIndustry();

	User_Profile_Data.open("UserProfileData.txt", ios::out);
	User_Profile_Data << getProfileType() << "\n";
	User_Profile_Data << "Name: " << getFname() << " " << getLname() << "\n";
	User_Profile_Data << "Birthday: " << getBirthday() << "\n";
	User_Profile_Data << "About: " << getPersonalStatement() << "\n";
	User_Profile_Data << "Clubs: " << getClubs() << "\n";
	User_Profile_Data << "Skills: " << getSkills() << "\n";
	User_Profile_Data << "Classification: " << getClassification() << "\n";
	User_Profile_Data << "Major: " << getMajor() << "\n";
	User_Profile_Data << "Prospective industry " << getProspectiveIndustry() << "\n";
	User_Profile_Data.close();
}
#endif