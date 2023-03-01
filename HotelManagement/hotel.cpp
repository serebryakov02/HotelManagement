#include "hotel.h"

Hotel* Hotel::instance = nullptr;

int Hotel::CheckOut(int roomno)
{
    qDebug() << "In CheckOut for room no" << roomno;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = "/home/serebryakov/QtProjects2023/February/HotelManagement/"
                     "hotel_management.db";
    db.setDatabaseName(dbPath);

    if (!QFile::exists(dbPath))
        qDebug() << ".db file does not exist";
    else
        qDebug() << ".db file exists";

    if (!db.open())
        qDebug() << "Connection failed:" << db.lastError().text();
    else
        qDebug() << "Connection successful";

    QSqlQuery query;
    QString statement = "UPDATE room SET available = :value WHERE number = "
            + QString::number(roomno);
    query.prepare(statement);
    query.bindValue(":value", "y");
    if (!query.exec())
        qDebug() << "Update failed:" << query.lastError() << query.lastQuery();
    else
        qDebug() << "Update successful " << query.lastQuery();

    db.close();

    return 0;
}

int Hotel::BookRoom(int roomno, const QString &name, const QString &contact,
                    const QString &govtid, const QString &address)
{
    qDebug() << "In BookRoom for room no" << roomno;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = "/home/serebryakov/QtProjects2023/February/HotelManagement/"
                     "hotel_management.db";
    db.setDatabaseName(dbPath);

    if (!QFile::exists(dbPath))
        qDebug() << ".db file does not exist";
    else
        qDebug() << ".db file exists";

    if (!db.open())
        qDebug() << "Connection failed:" << db.lastError().text();
    else
        qDebug() << "Connection successful";

    QSqlQuery query;

    // Prepare hotel room query.
    QString statement = "UPDATE room SET available = :value WHERE number = "
            + QString::number(roomno);
    query.prepare(statement);
    query.bindValue(":value", "n");
    if (!query.exec())
        qDebug() << "Update failed:" << query.lastError() << query.lastQuery();
    else
        qDebug() << "Update successful " << query.lastQuery();

    // Prepare customer query.
    query.clear();
    statement.clear();
    statement = "INSERT INTO customer(name, mobileno, address, govtid)"
                "VALUES (:name, :mobileno, :address, :govtid)";
    query.prepare(statement);
    query.bindValue(":name", name);
    query.bindValue(":mobileno", contact);
    query.bindValue(":address", address);
    query.bindValue(":govtid", govtid);
    QString customer_id;
    if(!query.exec())
        qDebug() << "Update failed:" << query.lastError() << query.lastQuery();
    else
    {
        qDebug() << "Update successful " << query.lastQuery();
        customer_id = query.lastInsertId().toString(); // ???
        qDebug() << "Last inserted ID is: " << customer_id;
    }

    // Prepare transaction query.
    query.clear();
    statement.clear();
    statement = "INSERT INTO transactions(room_id, customer_id)"
                "VALUES (:room_id, :customer_id)";
    query.prepare(statement);
    query.bindValue(":room_id", roomno);
    query.bindValue(":customer_id", customer_id);
    if(!query.exec())
        qDebug() << "Update failed:" << query.lastError() << query.lastQuery();
    else
    {
        qDebug() << "Update successful " << query.lastQuery();
        qDebug() << "Last inserted ID is " << query.lastInsertId().toString();
    }

    db.close();

    return 0;
}

QVector<int> Hotel::GetRoomList(const QString &flag = "y")
{
    QVector<int> rooms;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = "/home/serebryakov/QtProjects2023/February/HotelManagement/"
                     "hotel_management.db";
    db.setDatabaseName(dbPath);

    if (!QFile::exists(dbPath))
        qDebug() << ".db file does not exist";
    else
        qDebug() << ".db file exists";

    if (!db.open())
        qDebug() << "Connection failed:" << db.lastError().text();
    else
        qDebug() << "Connection successful";

    QSqlQuery query;
    QString statement = "SELECT number FROM room WHERE available = :value";
    query.prepare(statement);
    query.bindValue(":value", flag);

    if(!query.exec())
        qDebug() << "Update failed:" << query.lastError() << query.lastQuery();
    else
        qDebug() << "Fetch was successful";

    while (query.next())
    {
        QString record = query.value(0).toString();
        rooms.push_back(record.toInt());
        qDebug() << "Line is " << record;
    }

    db.close();

    return rooms;
}

Hotel *Hotel::GetInstance()
{
    return instance == nullptr ? instance = new Hotel() : instance;
}
