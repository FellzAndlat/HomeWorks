#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{

    dataBase = new QSqlDatabase();


}

DataBase::~DataBase()
{
    delete dataBase;
}

/*!
 * \brief Метод добавляет БД к экземпляру класса QSqlDataBase
 * \param driver драйвер БД
 * \param nameDB имя БД (Если отсутствует Qt задает имя по умолчанию)
 */
void DataBase::AddDataBase(QString driver, QString nameDB)
{

    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);

}

/*!
 * \brief Метод подключается к БД
 * \param для удобства передаем контейнер с данными необходимыми для подключения
 * \return возвращает тип ошибки
 */
void DataBase::ConnectToDataBase(QVector<QString> data)
{

    dataBase->setHostName(data[hostName]);
    dataBase->setDatabaseName(data[dbName]);
    dataBase->setUserName(data[login]);
    dataBase->setPassword(data[pass]);
    dataBase->setPort(data[port].toInt());


    ///Тут должен быть код ДЗ


    bool status;
    status = dataBase->open( );
    emit sig_SendStatusConnection(status);

}
/*!
 * \brief Метод производит отключение от БД
 * \param Имя БД
 */
void DataBase::DisconnectFromDataBase(QString nameDb)
{

    *dataBase = QSqlDatabase::database(nameDb);
    dataBase->close();

}
/*!
 * \brief Метод формирует запрос к БД.
 * \param request - SQL запрос
 * \return
 */
void DataBase::RequestToDB(QString request)
{
    QSqlQueryModel *queryModel = new QSqlQueryModel(this);

    if (request == "Все") {
        queryModel->setQuery("SELECT title, description FROM film", *dataBase);
    } else if (request == "Комедия") {
        queryModel->setQuery("SELECT title, description FROM film f "
                             "JOIN film_category fc ON f.film_id = fc.film_id "
                             "JOIN category c ON c.category_id = fc.category_id "
                             "WHERE c.name = 'Comedy'", *dataBase);
    } else if (request == "Ужасы") {
        queryModel->setQuery("SELECT title, description FROM film f "
                             "JOIN film_category fc ON f.film_id = fc.film_id "
                             "JOIN category c ON c.category_id = fc.category_id "
                             "WHERE c.name = 'Horror'", *dataBase);
    }

    if (queryModel->rowCount() == 0) {
        emit sig_SendDataFromDB(nullptr, request);
        return;
    }

    emit sig_SendDataFromDB(queryModel, request);

}

/*!
 * @brief Метод возвращает последнюю ошибку БД
 */
QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}
