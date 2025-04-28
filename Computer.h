#include <string>
using namespace std;

class Computer {
private:
	// Private Varables
	string username;
	string password;
	bool isEncrypt;

	//Private Functions
	string generateRandomPassword();

public:
	// Constuctors
	Computer();
	Computer(string user, string passwd);

	// Return Functions
	string GivePassword();
	string GiveUsername();
	string GiveEncrypt();

	// Enter Functions
	void NewPassword(string passwd);
	void SetEncryptionStatus(bool status);


};
