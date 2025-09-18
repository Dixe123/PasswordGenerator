#include <iostream>
#include <random>
#include <windows.h>

using namespace std;

const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%&*_";
int passwordLength{ 0 };

string generatePassword();

int main() {
	while (true) {
		system("cls");
		cout << "================================" << endl;
		cout << "------ Password Generator ------" << endl << endl;

		cout << "Enter a password lengh [int]" << endl;
		cout << ">> ";
		if (!(cin >> passwordLength)) { 
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "\033[31m" << "wrong input type" << "\033[0m" << endl;
			cin.get();
			continue;
		}
		cout << endl;

		cout << "Password: " << "\033[32m" << generatePassword() << "\033[0m";

		cin.ignore();
		cin.get();
	}
	return 0;
}

string generatePassword() {
	string password;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, sizeof(chars) - 2);	//range of the generator

	for (int i{ 0 }; i < passwordLength; i++) {
		password += chars[dist(gen)];
	}
	return password;
}