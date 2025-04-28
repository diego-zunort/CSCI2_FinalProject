#include <string>
#include <stack>
using namespace std;

// Function to perform Stack Reverse Encryption (recursive method)
string encryptStack(string passwd, int index = 0) {
	// Base case: when the index is beyond the last character, return an empty string
	if (index == passwd.length()) {
		return "";
	}

	// Recursive case: push current character to the stack (i.e., call recursion)
	char ch = passwd[index];

	// Recurse to the next character, and then add current character
	return encryptStack(passwd, index + 1) + ch;
}


// Function to perform Stack Reverse Decryption (reverse it back)
string decryptStack(const string& encryptedPassword) {
	// Reverse the encrypted password back (same as encryption method)
	return encryptStack(encryptedPassword, 0); // Since it is a reversible operation
}
