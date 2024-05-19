#include <iostream>
#include <string>

using namespace std;

const int MAX_ENTRIES = 0; // Maximum number of entries in the database

// Function to encrypt/decrypt data using XOR with a key
string xorEncryptDecrypt(string data, char key) {
    string result = data;
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] = data[i] ^ key;
    }
    return result;
}

int main() {
    string data_base[MAX_ENTRIES]; // Fixed-size array for storing encrypted data
    int entry_count = 0; // Number of entries currently in the database
    string input;
    char key = '$'; // Simple XOR key for encryption/decryption

    while (true) {
        cout << "Enter command (input/database/exit): ";
        cin >> input;

        if (input == "input") {
            if (entry_count >= MAX_ENTRIES) {
                cout << "Database is full. Cannot add more data." << endl;
                continue;
            }
            cout << "Enter data to input: ";
            string data;
            cin.ignore(); // To ignore leftover newline character from previous input
            getline(cin, data);
            string encryptedData = xorEncryptDecrypt(data, key);
            data_base[entry_count] = encryptedData;
            entry_count++;
            cout << "Data has been encrypted and stored." << endl;
        } else if (input == "database") {
            while (true) {
                cout << "Encrypted data in the database: " << endl;
                for (int i = 0; i < entry_count; ++i) {
                    cout << data_base[i] << endl;
                }
                cout << "Enter decryption keyword to view data or type 'exit' to go back: ";
                string keyword;
                cin >> keyword;
                if (keyword == "exit") {
                    break;
                } else if (keyword == "pokemon$$") {
                    cout << "Decrypted data in the database: " << endl;
                    for (int i = 0; i < entry_count; ++i) {
                        string decryptedData = xorEncryptDecrypt(data_base[i], key);
                        cout << decryptedData << endl;
                    }
                    break; // Go back to the main menu after showing decrypted data
                } else {
                    cout << "Incorrect keyword! Try again." << endl;
                }
            }
        } else if (input == "exit") {
            break;
        } else {
            cout << "Invalid command! Please try again." << endl;
        }
    }

    return 0;
}

