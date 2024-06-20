#include <iostream>
#include <string>
#include <sstream> // For stringstream

using namespace std;

const int MAX_ENTRIES = 2; // Maximum number of entries in the database

// Function to encrypt/decrypt data using XOR with a key
string xorEncryptDecrypt(const string& data, char key) {
    string result = data;
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] = data[i] ^ key-'a'+26;
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
    char keys[MAX_ENTRIES]; // Array for storing encryption keys
    int entry_count = 0; // Number of entries currently in the database
    int choice;

    while (true) {
        clearScreen(); // Clear the screen before displaying the menu
        displayMenu();
        while(true){
        cin >> choice;
        	if(cin.fail()){
        		cin.clear();
        		cin.ignore(100, '\n');
        		cout<<"You enter an charachter please input an intiger";
			}else{
				break;
			}
		}
		
        cin.ignore(); // To ignore leftover newline character from previous input

        if (choice == 1) {
            clearScreen();
            if (entry_count >= MAX_ENTRIES) {
                cout << "Database is full. Cannot add more data.\n";
                cout << "Press Enter to continue...";
                cin.get(); 
            }else{
			cout << "\nEnter data to input: ";
            string data;
            getline(cin, data);
            cout << "Enter a single character key for encryption: ";
            char key;
            cin >> key;
            cin.ignore(); // To ignore leftover newline character
            string encryptedData = xorEncryptDecrypt(data, key);
            data_base[entry_count] = encryptedData;
            keys[entry_count] = key;
            entry_count++;
            cout << "Data has been encrypted and stored.\n";
            cout << "Press Enter to continue...";
            cin.get(); }
		} else if (choice == 2) {
            if (entry_count == 0) {
                clearScreen();
                cout << "Database is empty.\n";
                cout << "Press Enter to continue...";
                cin.get(); 
            }
            while (true) {
                clearScreen();
                cout << "\n----------------------------\n";
                cout << "   ENCRYPTED DATABASE       \n";
                cout << "----------------------------\n";
                for (int i = 0; i < entry_count; ++i) {
                    cout << i + 1 << ". " << data_base[i] << endl;
                }
                cout << "----------------------------\n";
                cout << "Enter entry number and decryption key to view data or type 'exit' to go back.\n";
                
                string input;
                cin >> input;
                if (input == "exit") {
                    break;
                }

                stringstream conv(input);
                int entry_number;
                if (!(conv >> entry_number) || entry_number < 1 || entry_number> entry_count) {
                    cout << "Invalid entry number! Press Enter to continue...";
                    cin.ignore();
                    cin.get();
                    continue;
                }
                conv >> entry_number;
                
                cout << "Decryption key: ";
                char key;
                cin >> key;
                cin.ignore(); // To ignore leftover newline character

                if (key == keys[entry_number - 1]) {
                    clearScreen();
                    cout << "\n----------------------------\n";
                    cout << "   DECRYPTED DATA ENTRY     \n";
                    cout << "----------------------------\n";
                    string decryptedData = xorEncryptDecrypt(data_base[entry_number - 1], key);
                    cout << entry_number << ". " << decryptedData << endl;
                    cout << "----------------------------\n";
                    cout << "Press Enter to continue...";
                    cin.get();
                } else {
                    clearScreen();
                    cout << "Incorrect key! Try again.\n";
                    cout << "Press Enter to continue...";
                    cin.get();
                }
            }
        } else if (choice == 3) {
            cout << "Exiting program. Goodbye!\n";
            break;
        } else {
            clearScreen();
            cout << "Invalid choice! Please try again.\n";
            cout << "Press Enter to continue...";
            cin.get(); 
        }
    }

    return 0;
}

