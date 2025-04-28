#include "Computer.h"
#include "Encryption.h"
#include "main.h"

using namespace std;

int main() {

	// Initialize random seed
	srand(time(0));

	// Varables for program
	int size = 3;
	string input_username, input_password, input;
	bool running = true;
	Computer* Server = new Computer[size];

	// Create 3 initial computers with random passwords
	Server[0] = Computer("User1", "random");
	Server[1] = Computer("User2", "random");
	Server[2] = Computer("User3", "random");

	// Temp varable for user-created computer
	Computer* u1 = nullptr;

	while (running) {
		cout << "---------------------------" << endl;
		cout << " Admin Encryption Program  " << endl;
		cout << "---------------------------" << endl;
		cout << "Press 0 to Exit..." << endl;
		cout << "Press 1 to Create Computer..." << endl;
		cout << "Press 2 to Display ALL Computers..." << endl;
		cout << "Press 9 to Encrypt / Decrypt ALL Computers..." << endl;


		cin >> input;

		if (input == "0") {
			running = false;
		} else if (input == "1") {
			delete u1;

			ClearTerminal();

			cout << "Username: ";
			cin >> input_username;
			cout << "Password: ";
			cin >> input_password;

			// Set temp varable for user-created computer
			u1 = new Computer(input_username, input_password);

			// Create larger array
			Computer* temp = new Computer[size + 1];

			// Copy existing computers
			for (int i = 0; i < size; ++i) {
				temp[i] = Server[i];
			}

			// Add new computer
			temp[size] = *u1;

			// Replace old array
			delete[] Server;
			Server = temp;
			size++;

			cout << "\nNew Computer Created\n";
			PressToContinue();

		} else if (input == "2") {

			ClearTerminal();

			// Loops through array to print User and Passwords
			for (int i = 0; i < size; ++i) {
				cout << "Computer " << i + 1 << ": "
				     << Server[i].GiveUsername()
				     << " | Password: " << Server[i].GivePassword()
				     << " | Encrypted: " << Server[i].GiveEncrypt() <<endl;
			}

			PressToContinue();

		}
































		////////////////////////////////////////////////////////////////////////////////////////
		// This if statment is what is used to allow "Encryption" to a computer, remember,
		// our computers are just a class with a private username and password stored on a dynamic
		// array called server. We need to Encrypt and Decrypt computer Passwords and store keys
		// if needed, we are making another class in "Encrypt.h" to make make adding methods
		// of encryption easy!
		////////////////////////////////////////////////////////////////////////////////////////
		else if(input == "9") { // Ask user to Encrypt/Decrypt and implements

			ClearTerminal();
			cout << "1. Encrypt\n"
			     << "2. Decrypt" << endl;
			cin >> input;

			if (input == "1") {

				ClearTerminal();
				cout << "Select Encryption Method"
				     << "\n 1. Stack Reverse" << endl;
				cin >> input;
				if (input == "1") {
					ClearTerminal();
					// Encrypt all computer passwords using Stack Reverse
					cout << "Encrypting ALL computer passwords using Stack Reverse...\n";

					for (int i = 0; i < size; ++i) {
						// Get current password of each computer
						string currentPassword = Server[i].GivePassword();

						// Encrypt the password using Stack Reverse
						string encryptedPassword = encryptStack(currentPassword);

						// Set the encrypted password back to the computer
						Server[i].NewPassword(encryptedPassword);

						// Set computers as Encrypted
						Server[i].SetEncryptionStatus(true);

						cout << "Computer " << i + 1 << " Password Encrypted: " << encryptedPassword << endl;
					}

					PressToContinue();
				}
				else {
					cout << "Invalid Option, returning to main menu..." << endl;
				}
			} else if (input == "2") {
				if (input == "2") {
					ClearTerminal();
					cout << "Select Decryption Method"
					     << "\n 1. Stack Reverse" << endl;
					cin >> input;
					if (input == "1") {
						ClearTerminal();
						// Encrypt all computer passwords using Stack Reverse
						cout << "Decrypting ALL computer passwords using Stack Reverse...\n";

						for (int i = 0; i < size; ++i) {
							// Get current password of each computer
							string currentPassword = Server[i].GivePassword();

							// Encrypt the password using Stack Reverse
							string encryptedPassword = decryptStack(currentPassword);

							// Set the encrypted password back to the computer
							Server[i].NewPassword(encryptedPassword);

							// Set computers as Decrypted
							Server[i].SetEncryptionStatus(false);

							cout << "Computer " << i + 1 << " Password Encrypted: " << encryptedPassword << endl;
						}

						PressToContinue();
					}
				} else {
					cout << "Invalid Option.\n..." << endl;
					PressToContinue();
				}
			}
		}











































		else {
			// Invalid input
			cout << "Invalid Option.\n";
			PressToContinue();
		}
		// Clear screen
		ClearTerminal();
	}

	// Delete both "Server" array and temp value for user-created computer to prevent memory leak
	delete[] Server;
	delete u1;

	return 0;
}
