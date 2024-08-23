#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void reg()
{
	string pass, confpass, login;

	cout << "Enter your login: " << endl;
	cin >> login;

	cout << "Enter your pass: ";
	cin >> pass;

	cout << "Enter your confpass: ";
	cin >> confpass;

	if (pass == confpass) {
		ofstream userout;
		userout.open(login + ".txt");
		if (userout.is_open())
			{
				userout << pass << endl;
			}
		userout.close();
		cout << "User create";
	}
	else {
		cout << "-";
		reg();
	}
}

void SignUp()
{
	string userSlog, userPass;
	cout << "Enter your login: ";
	cin >> userSlog;

	cout << "\nenter your Password: ";
	cin >> userPass;

	string password;

	ifstream in(userSlog + ".txt"); 
	if (in.is_open())
	{
		while (getline(in, password))
		{
			if (userPass == password) {
				cout << "Successful login";
			}
			else {
				cout << "Invalid password";
			}
		}
	}
	in.close();

	
}

int main()
{
	int user_enter;

	cout << "1. Reg\n2. Login\nEnter: ";
	cin >> user_enter;

	if (user_enter == 1) {
		reg();
	}
	else if (user_enter == 2) {
		SignUp();
	}
}