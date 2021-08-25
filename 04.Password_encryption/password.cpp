#include "password.h"

Password::Password(string message) : org_message{message} {}

Password::~Password()
{
    cout << "[#] Object Memory Released\n";
}

void const Password::display_message()
{
    cout << "[#] Original Password => ";
    for (const char &word : org_message)
        cout << word << " ";
    cout << '\n';
}

void const Password::display_message(const string &&message_disp, const vector<size_t> &working_message)
{
    cout << "[#] " << message_disp << " => ";
    for (const size_t &index : working_message)
    {
        // cout << index << " ";
        cout << static_cast<char>(index) << " ";
    }
    cout << "\n";
}

void Password::encrypting_it()
{
    size_t encrypt{};
    for (size_t i{}; i < org_message.length(); ++i)
    {
        // Aplly Extra encryption
        encrypt = static_cast<size_t>(org_message.at(i)) * 16;
        // Remembering the deviding key
        msg_keys.push_back(encrypt / 94);
        // Getting ascii number between 33 to 126
        crypto_msg.push_back((encrypt % 94) + 33);
    }
    display_message("Encrypted Password", crypto_msg);
}

void Password::decrypting_it()
{
    size_t decrypt{};
    for (size_t i{}; i < crypto_msg.size(); ++i)
    {
        // Setting up the ascii number
        decrypt = (crypto_msg.at(i) - 33);
        // Getting back the middle form of encrypted number
        decrypt = (decrypt + (std::floor(msg_keys.at(i)) * 94));
        // Aplly Extra decryption
        dcrypto_msg.push_back(decrypt / 16);
    }
    display_message("Decrypted Password", dcrypto_msg);
}

bool Password::compare_original_decrypt_message()
{
    for (size_t i = 0; i < org_message.length(); ++i)
        if (org_message.at(i) != static_cast<char>(dcrypto_msg.at(i)))
            return false;
    return true;
}