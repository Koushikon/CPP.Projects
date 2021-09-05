#ifndef _PASSWORD_H_
#define _PASSWORD_H_

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::string;
using std::vector;

const size_t PASSWORD_ENCRYPTION_VERSION{2};

class Password
{
private:
    // Original message stored
    string org_message{};
    // Encryption level
    short level{};

    // Encrypting & Decrypting message stored
    vector<size_t> crypto_msg;
    vector<size_t> dcrypto_msg;

    // Decryption keys stored
    vector<size_t> msg_keys_1;
    vector<double> msg_keys_2;

    // Level of encryption
    void level_of_encryption_1(const string &message, vector<size_t> &cryptic, vector<size_t> &keys);
    void level_of_encryption_2(const string &message, vector<size_t> &cryptic, vector<double> &keys);
    void level_of_encryption_3();

    // Level of decryption
    void level_of_decryption_1(const vector<size_t> &cryptic, vector<size_t> &d_cryptic, const vector<size_t> &keys);
    void level_of_decryption_2(const string &message, vector<size_t> &cryptic, const vector<double> &keys);
    void level_of_decryption_3();

protected:
    // vector display function
    void const display_message(const string &&message, const vector<size_t> &words);

public:
    Password(string __message, short __level);
    ~Password();

    /*
     * Class Functions
     */

    // String display function
    void const display_message();
    void encrypting_it();
    void decrypting_it();
    bool compare_original_decrypt_message();
};

#endif // End of _PASSWORD_H_