#include "transaction.h"
#include "ui_transaction.h"

Transaction::Transaction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transaction)
{
    ui->setupUi(this);
    this->setFixedSize(400, 300);
}

Transaction::~Transaction()
{
    delete ui;
}

void Transaction::readData()
{
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
    QString statement = "SELECT * FROM transactions";
    query.prepare(statement);

    if (!query.exec())
        qDebug() << "Update failed:" << query.lastError() << query.lastQuery();
    else
        qDebug() << "Update successful " << query.lastQuery();

    while(query.next())
    {
        ui->listWidget->addItem(query.value(0).toString() + "*****************" +
                                query.value(1).toString() + "***********" +
                                query.value(2).toString());

        qDebug() << query.value(0).toString() + " " + query.value(1).toString() + " "
                    + query.value(2).toString();
    }

    db.close();
}
