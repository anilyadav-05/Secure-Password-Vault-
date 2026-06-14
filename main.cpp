#include <iostream>
#include <string>

using namespace std;

string encryptPassword(string password, string key) {
    string result = "";
    int keyLength = key.length();

    for (int i = 0; i < password.length(); i++) {
        char p = password[i];
        char k = key[i % keyLength];

       
        //  Shift inputs down to 0-94 range
        int pVal = p - 32;
        int kVal = k - 32;

        int encryptedVal = (pVal + kVal) % 95;

        //  Shift back up to ASCII range (add 32)
        char encryptedChar = (char)(encryptedVal + 32);

        result += encryptedChar;
    }
    return result;
}

string decryptPassword(string encryptedText, string key) {
    string result = "";
    int keyLength = key.length();

    for (int i = 0; i < encryptedText.length(); i++) {
        char e = encryptedText[i];
        char k = key[i % keyLength];

        int eVal = e - 32;
        int kVal = k - 32;

        int val = (eVal - kVal);

        while (val < 0) {
            val += 95;
        }

        char originalChar = (char)(val + 32);

        result += originalChar;
    }
    return result;
}

int main() {
    string myKey;
    string myPassword;
    int choice;

    cout << "Enter a MasterKey (e.g., MANIT): ";
    getline(cin, myKey);

    if (myKey.empty()) {
        cout << "Key cannot be empty!" << endl;
        return 0;
    }

    cout << "\n1. Encrypt\n2. Decrypt\nChoose: ";
    cin >> choice;
    cin.ignore(); 

    if (choice == 1) {
        cout << "Enter Password to hide: ";
        getline(cin, myPassword);
        string secret = encryptPassword(myPassword, myKey);
        cout << "Protected Password: " << secret << endl;
    } 
    else if (choice == 2) {
        cout << "Enter Protected Password: ";
        getline(cin, myPassword);
        string original = decryptPassword(myPassword, myKey);
        cout << "Original Password: " << original << endl;
    }

    return 0;
}
