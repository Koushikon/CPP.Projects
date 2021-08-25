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

const size_t PASSWORD_ENCRYPTION_VERSION{1};

class Password
{
private:
    // Original message stored
    string org_message{};
    // Encrypting message stored
    vector<size_t> crypto_msg;
    // Decrypting message stored
    vector<size_t> dcrypto_msg;
    // Encryption keys stored
    vector<size_t> msg_keys;

protected:
    // vector display function
    void const display_message(const string &&message, const vector<size_t> &words);

public:
    Password(string message);
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