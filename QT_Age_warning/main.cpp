#include <QCoreApplication>
#include<iostream>

using std::cin;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int age{};
    cin>>age;

    if(age >= 1 && age <= 120){
        int dog_age{age*7};
        qInfo() << "Your age in dog years is " << dog_age << "\n";
    } else
        qWarning() << "Human age can't be possible this much\n";

    return a.exec();
}
