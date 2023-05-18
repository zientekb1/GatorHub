/*
Name: Post Class
Desciption: Stores users post in Post File.txt where the user can
			like, report, or delete all post

Date Coded: April 15 -
Who contributed: Brendan
*/

#ifndef ifndef_PostClass
#define ifndef_PostClass


#include <iostream>
#include <string>
#include <fstream>
#include <string>
using namespace std;
class PostClass
{
private:
	string postTitle;		//holds title of post
	string typedContent;	//holds the blog part of the post
	int likes = 0;				//holds the amount of likes on the post
	fstream postFile;		//opens the file "Post File.txt" to store post

public:
	string getTypedContent();
	void setTypedContent(string);

	int getLikes();

	string getPostTitle();
	void setPostTitle(string);

	void updateContent();	//updates the typedContent variable
	void likePost();		//likes post
	void makePost();		//writes post to Post File.txt
	void deletePost();		//deletes all the post in Post File.txt
	void printPost();		//display info in Post File.txt which stores post data
};
inline string PostClass::getTypedContent()
{
	return typedContent;
}
inline void PostClass::setTypedContent(string a)
{
	typedContent = a;
}
inline int PostClass::getLikes()
{
	return likes;
}
inline string PostClass::getPostTitle()
{
	return postTitle;
}
inline void PostClass::setPostTitle(string b)
{
	postTitle = b;
}
inline void PostClass::updateContent()
{
	string changeContent;
	cin.ignore();
	cout << getTypedContent() << "\n";
	getline(cin, changeContent);
	setTypedContent(changeContent);
}
inline void PostClass::likePost()
{
	string readFile;
	likes += 1;
	printPost();	//display all post to the user
	cout << "What is the title of the post you would like to leave a like on?\n";
	cin.ignore();
	getline(cin, postTitle);
	cout << "post titled: " << postTitle << " has " << getLikes() << " likes " << "\n";
}
inline void PostClass::makePost()	//write post to Post File.txt
{
	postFile.open("Post File.txt", ios::out | ios::app | ios::beg);
	postFile << "Title: " << getPostTitle() << "\n" "Post: " << getTypedContent() << "\n\n";
	postFile.close();
}
inline void PostClass::deletePost()	//Deletes all of the post in Post File.txt
{
	postFile.open("Post File.txt", ios::out | ios::trunc);	//trunc all post get removed
	postFile.close();
}
inline void PostClass::printPost()	//Displays all of the post in Post File.txt
{
	string readFile;
	cout << "\n====== Post Forum ======\n";
	postFile.open("Post File.txt", ios::in | ios::app | ios::beg);
	while (getline(postFile, readFile))
	{
		cout << readFile << endl;
	}
	cout << "==========================\n\n";
	postFile.close();
}
#endif // !ifndef_PostCalss
