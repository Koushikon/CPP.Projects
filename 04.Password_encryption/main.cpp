#include "password.h"

const void perform_operations(Password &msg);
char once_again();

int main()
{
    cout << "= = = = = = = = = = =\n\tPassword Encryption® version "
         << PASSWORD_ENCRYPTION_VERSION
         << "\n= = = = = = = = = = =\n\n";

    do
    {
        string org_message{};
        cout << "[+] Enter your Password? ";
        cin >> org_message;

        short level{};
        do
        {
            cout << "[+] Enter encryption Level between 1 to 5? ";
            cin >> level;
        } while (level < 1 || level > 5);

        // Next we're passing the level of encryption
        Password ps1{org_message};
        perform_operations(ps1);

    } while (once_again() == 'y');

    cout << "\n= = = = = X = = = = =\n\tEnd Of Password Encryption\n= = = = = X = = = = =";

    return 0;
}

const void perform_operations(Password &msg)
{
    msg.display_message();
    msg.encrypting_it();
    msg.decrypting_it();
    cout << "[#] Orginal And Decrypted Password are both same It's "
         << std::boolalpha << msg.compare_original_decrypt_message() << "\n";
}

char once_again()
{
    char choice{};
    cout << "[+] Would you like to encrypt another password My Good sir:\n\tPress y for yes? ";
    cin >> choice;
    return tolower(choice);
}