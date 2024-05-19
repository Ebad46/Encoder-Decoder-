#include <iostream>
#include <string>
#include <iomanip> // For formatting

using namespace std;

const int MAX_ENTRIES = 100; // Maximum number of entries in the database

// Function to encrypt/decrypt data using XOR with a key
string xorEncryptDecrypt(string data, char key) {
    string result = data;
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] = data[i] ^ key;
    }
    return result;
}

// Function to display a menu
void displayMenu() {
    cout << "\n----------------------------\n";
    cout << "       DATA MANAGER         \n";
    cout << "----------------------------\n";
    cout << "1. Input Data\n";
    cout << "2. View Encrypted Database\n";
    cout << "3. Exit\n";
    cout << "----------------------------\n";
    cout << "Choose an option: ";
}

// Function to clear the screen
void clearScreen() {
    // Clear screen command for different systems
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    string data_base[MAX_ENTRIES]; // Fixed-size array for storing encrypted data
    int entry_count = 0; // Number of entries currently in the database
    char key = '$'; // Simple XOR key for encryption/decryption
    int choice;

    while (true) {
        clearScreen(); // Clear the screen before displaying the menu
        displayMenu();
        cin >> choice;
        cin.ignore(); // To ignore leftover newline character from previous input

        if (choice == 1) {
            clearScreen();
            if (entry_count >= MAX_ENTRIES) {
                cout << "Database is full. Cannot add more data." << endl;
                continue;
            }
            cout << "\nEnter data to input: ";
            string data;
            getline(cin, data);
            string encryptedData = xorEncryptDecrypt(data, key);
            data_base[entry_count] = encryptedData;
            entry_count++;
            cout << "Data has been encrypted and stored.\n";
            cout << "Press Enter to continue...";
            cin.get(); // Wait for user input to proceed
        } else if (choice == 2) {
            if (entry_count == 0) {
                clearScreen();
                cout << "Database is empty.\n";
                cout << "Press Enter to continue...";
                cin.get(); // Wait for user input to proceed
                continue;
            }
            while (true) {
                clearScreen();
                cout << "\n----------------------------\n";
                cout << "   ENCRYPTED DATABASE       \n";
                cout << "----------------------------\n";
                for (int i = 0; i < entry_count; ++i) {
                    cout << setw(2) << i + 1 << ". " << data_base[i] << endl;
                }
                cout << "----------------------------\n";
                cout << "Enter decryption keyword to view data or type 'exit' to go back: ";
                string keyword;
                cin >> keyword;
                cin.ignore(); // To ignore leftover newline character

                if (keyword == "exit") {
                    break;
                } else if (keyword == "pokemon$$") {
                    clearScreen();
                    cout << "\n----------------------------\n";
                    cout << "   DECRYPTED DATABASE       \n";
                    cout << "----------------------------\n";
                    for (int i = 0; i < entry_count; ++i) {
                        string decryptedData = xorEncryptDecrypt(data_base[i], key);
                        cout << setw(2) << i + 1 << ". " << decryptedData << endl;
                    }
                    cout << "----------------------------\n";
                    cout << "Press Enter to continue...";
                    cin.get(); // Wait for user input to proceed
                    break; // Go back to the main menu after showing decrypted data
                } else {
                    clearScreen();
                    cout << "Incorrect keyword! Try again.\n";
                    cout << "Press Enter to continue...";
                    cin.get(); // Wait for user input to proceed
                }
            }
        } else if (choice == 3) {
            clearScreen();
            cout << "Exiting program. Goodbye!\n";
            break;
        } else {
            clearScreen();
            cout << "Invalid choice! Please try again.\n";
            cout << "Press Enter to continue...";
            cin.get(); // Wait for user input to proceed
        }
    }

    return 0;
}

