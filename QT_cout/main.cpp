#include <QCoreApplication>
#include<iostream>
#include<QDebug>

using std::cout;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Nice to meet you \n";

    qInfo() << "QT way Nice to meet you\n";

    qDebug() << "This is from qDebug()\n";

    qCritical() << "This is from qCritical()\n";

    qWarning() << "This is from qWarning\n";

    // Immediately end the program execution
    qFatal("And, Ended...");

    qInfo() << "Again, QT way Nice to meet you \n";

    return a.exec();
}
