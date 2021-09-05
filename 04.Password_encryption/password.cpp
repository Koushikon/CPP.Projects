#include "password.h"

Password::Password(string __message, short __level) : org_message{__message}, level{__level} {}

Password::~Password()
{
    // cout << "[#] ⊙ \t Object Memory Released --->> \n\n";
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
    switch (level)
    {
    case 2:
    {
        level_of_encryption_1(org_message, crypto_msg, msg_keys_1);
        level_of_encryption_2(org_message, crypto_msg, msg_keys_2);
    }
    break;
    case 1:
    default:
        level_of_encryption_1(org_message, crypto_msg, msg_keys_1);
        break;
    }
    display_message("Encrypted Password", crypto_msg);
}

void Password::level_of_encryption_1(const string &message, vector<size_t> &cryptic, vector<size_t> &keys)
{
    size_t encrypt{};
    for (size_t i{}; i < message.length(); ++i)
    {
        // Aplly Extra encryption
        encrypt = static_cast<size_t>(message.at(i)) * 16;
        // Remembering the deviding key
        keys.push_back(encrypt / 94);
        // Getting ascii number between 33 to 126
        cryptic.push_back((encrypt % 94) + 33);
    }
}

void Password::level_of_encryption_2(const string &message, vector<size_t> &cryptic, vector<double> &keys)
{
    for (size_t i{}; i < cryptic.size(); ++i)
    {
        keys.push_back((static_cast<double>(cryptic.at(i)) + static_cast<double>(message.at(i))) / 2);
        cryptic.at(i) = std::floor(keys.at(i));
    }
}

void Password::level_of_encryption_3()
{
}

void Password::decrypting_it()
{
    switch (level)
    {
    case 2:
    {
        level_of_decryption_2(org_message, crypto_msg, msg_keys_2);
        level_of_decryption_1(crypto_msg, dcrypto_msg, msg_keys_1);
    }
    break;
    case 1:
    default:
        level_of_decryption_1(crypto_msg, dcrypto_msg, msg_keys_1);
        break;
    }
    display_message("Decrypted Password", dcrypto_msg);
}

void Password::level_of_decryption_3()
{
}

void Password::level_of_decryption_2(const string &message, vector<size_t> &cryptic, const vector<double> &keys)
{
    for (size_t i{}; i < keys.size(); ++i)
        cryptic.at(i) = (keys.at(i) * 2) - message.at(i);
}

void Password::level_of_decryption_1(const vector<size_t> &cryptic, vector<size_t> &d_cryptic, const vector<size_t> &keys)
{
    size_t decrypt{};
    for (size_t i{}; i < keys.size(); ++i)
    {
        // Setting up the ascii number
        decrypt = (cryptic.at(i) - 33);
        // Getting back the middle form of encrypted number
        decrypt = decrypt + (std::floor(keys.at(i)) * 94);

        // Aplly Extra decryption
        d_cryptic.push_back(decrypt / 16);
    }
}

bool Password::compare_original_decrypt_message()
{
    for (size_t i = 0; i < org_message.length(); ++i)
        if (org_message.at(i) != static_cast<char>(dcrypto_msg.at(i)))
            return false;
    return true;
}