#include <QCoreApplication>
#include <QtNetwork>
#include <QtSql>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTcpSocket rar;
    QSqlDatabase data;

    return a.exec();
}
