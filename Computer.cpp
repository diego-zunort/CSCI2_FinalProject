#include "Computer.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Computer::Computer() {
	username = "Unknown";
	password = "Password";
}

Computer::Computer(string user, string passwd) {
	username = user;
	if (passwd == "random") {
		password = generateRandomPassword();
	} else {
		password = passwd;
	}
}

string Computer::generateRandomPassword() {
	string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	string generatedPassword;
	int length = 8;

	for (int i = 0; i < length; ++i) {
		generatedPassword += chars[rand() % chars.length()];
	}

	return generatedPassword;
}

// Set new password
void Computer::NewPassword(string passwd) {
	password = passwd;  // Update the password
}

// Set new encryption bool
void Computer::SetEncryptionStatus(bool status) {
	isEncrypt = status;
}


// Return password
string Computer::GivePassword() {
	return password;
}

// Add missing method to return username
string Computer::GiveUsername() {
	return username;
}

string Computer::GiveEncrypt() {
	if (isEncrypt == true) {
		return "TRUE";
	} else {
		return "FALSE";
	}
}

