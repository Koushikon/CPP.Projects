#include <QCoreApplication>
#include<QDebug>
#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::getline;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo() << "Hello, Where are you from?";

    /*Taking an input
     * Print the input
     */

    // or

    /*
    Taking an input
    Print the input
    */


    string name{}; // Declare an variable
    getline(cin, name); // Taking an String Input
    cout << name << endl;

    qDebug() << "Types:" << QString("String") << QChar('x');

    return a.exec();
}
