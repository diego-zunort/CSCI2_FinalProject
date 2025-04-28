#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Funtion to Clear Terminal
void ClearTerminal() {
	// Clear screen (not sure how this works but okay?)
	cout << "\033[2J\033[1;1H";
}

// Funtion to wait to press
void PressToContinue() {
	cout << "\nPress Enter to continue...";
	cin.ignore();
	cin.get();
}

