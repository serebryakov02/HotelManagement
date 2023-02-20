#ifndef HOTEL_H
#define HOTEL_H

#include <QString>
#include <QVector>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QFile>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

class Hotel
{
private:
    Hotel() {}
    Hotel(const Hotel&) {}
    static Hotel* instance;
    // Update DB & Vector.
    void updateHotelData(int room);

public:
    int BookRoom(int roomno, const QString& name, const QString& contact,
                 const QString& govtid, const QString& address);
    int CheckOut(int roomno);
    QVector<int> RoomAvailability();
    QVector<int> GetRoomList(const QString&);
    static Hotel* GetInstance();
};

#endif // HOTEL_H
