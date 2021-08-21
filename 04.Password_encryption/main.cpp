#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

using std::cin;
using std::cout;
using std::string;
using std::vector;

const size_t PASSWORD_ENCRYPTION_VERSION{1};

void const display_message(const string &message);
void const display_message(const string &&message, const vector<size_t> &words);
void encrypt_message(const string &message, vector<size_t> &ascii_no, vector<size_t> &ascii_keys);
void decrypt_message(const vector<size_t> &message, vector<size_t> &ascii_no, const vector<size_t> &ascii_keys);

int main()
{
    cout << "= = = = = = = = = = =\n"
         << "\tPassword Encryption® version " << PASSWORD_ENCRYPTION_VERSION << "\n"
         << "= = = = = = = = = = =\n\n";

    char choose{};
    do
    {
        string org_message{};
        cout << "[+] Enter your Password: ";
        cin >> org_message;

        // Display original message
        display_message(org_message);

        // Encrypting message variable
        vector<size_t> crypto_msg(org_message.length());
        // Decrypting message variable
        vector<size_t> dcrypto_msg(org_message.length());
        // Encryption keys variable
        vector<size_t> msg_keys(org_message.length());

        // Encrypting the message
        encrypt_message(org_message, crypto_msg, msg_keys);
        display_message("Encrypted Password", crypto_msg);

        // Decrypting the message
        decrypt_message(crypto_msg, dcrypto_msg, msg_keys);
        display_message("Decrypted Password", dcrypto_msg);

        for (size_t i = 0; i < org_message.length(); ++i)
            if (org_message.at(i) != static_cast<char>(dcrypto_msg.at(i)))
                break;
        cout << "[#] Orginal And Decrypted Password are both same ✔\n";

        cout << "[+] Would you like to encrypt another password My Good sir:\n\tPress y for yes? ";
        cin >> choose;
    } while (tolower(choose) == 'y');

    cout << "\n= = = = = X = = = = =\n\tEnd Of Password Encryption\n= = = = = X = = = = =";

    return 0;
}

void const display_message(const string &message)
{
    cout << "[#] Original Password => ";
    for (const char &word : message)
        cout << word << " ";
    cout << '\n';
}

void const display_message(const string &&message, const vector<size_t> &ascii_ints)
{
    cout << "[#] " << message << " => ";
    for (const size_t &index : ascii_ints)
    {
        // cout << index << " ";
        cout << static_cast<char>(index) << " ";
    }
    cout << "\n";
}

void encrypt_message(const string &message, vector<size_t> &ascii_no, vector<size_t> &ascii_keys)
{
    size_t encrypt{};
    for (size_t i{}; i < ascii_no.size(); ++i)
    {
        // Aplly Extra encryption
        encrypt = static_cast<size_t>(message.at(i)) * 10;
        // Remembering the deviding key
        ascii_keys.at(i) = (encrypt / 94);
        // Getting ascii number between 33 to 126
        ascii_no.at(i) = (encrypt % 94) + 33;
    }
}

void decrypt_message(const vector<size_t> &message, vector<size_t> &ascii_no, const vector<size_t> &ascii_keys)
{
    size_t decrypt{};
    for (size_t i{}; i < message.size(); ++i)
    {
        // Setting up the ascii number
        decrypt = (message.at(i) - 33);
        // Getting back the middle form of encrypted number
        decrypt = (decrypt + (std::floor(ascii_keys.at(i)) * 94));
        // Aplly Extra decryption
        ascii_no.at(i) = decrypt / 10;
    }
}