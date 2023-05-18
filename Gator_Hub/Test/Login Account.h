/*
Name: Login Account
Desciption : User is prompted to log-in or register for the GatorHub
Date Coded : April 30
Who contributed : Arielle Fashakin
*/
#ifndef ifndef_Login_Account
#define ifndef_Login_Account

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class LoginAccount
{
private:
    string username, password, user, pass;
public:
    int LoginMenu(); //main log menu 
    bool LogIn();   //validate login credentials
};

inline bool LoginAccount::LogIn()
{
    cout << "Enter Username: "; cin >> username;
    cout << "Enter Password: "; cin >> password;
    ifstream read(username + ".txt");
    getline(read, user);
    getline(read, pass);

    if (user == username && pass == password)
    {
        return true;    //if username entered is equivalent to the txt file namr
    }
    else
    {
        return false;   
    }
}
inline int LoginAccount::LoginMenu()
{
    int choice;
    cout << "Select an option!\n1: Register\n2: Login\n Your choice: ";
    cin >> choice;
    if (choice == 1)
    {
        string username, password;
        cout << "Type a username: "; cin >> username;
        cout << "Type a password: "; cin >> password;
        ofstream file;
        file.open(username + ".txt");
        file << username << endl << password;
        file.close();
        LoginAccount::LoginMenu();
    }
    else if(choice == 2)
    {
        bool status = LogIn();
        if (!status)
        {
            cout << "Incorrect Information, Try Again!" << endl;
            system("PAUSE");
            LoginAccount::LoginMenu();  //if login credentials
            return 0;
        }
        else
        {
            cout << "Welcome to GatorHub!" << endl;
            system("PAUSE");
            return 1;
        }
    }
}
#endif // !ifndef_Login_Account
