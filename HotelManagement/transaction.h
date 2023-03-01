#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDialog>
#include <QSqlDatabase>
#include <QString>
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class Transaction;
}

class Transaction : public QDialog
{
    Q_OBJECT

public:
    explicit Transaction(QWidget *parent = nullptr);
    ~Transaction();
    void readData();

private:
    Ui::Transaction *ui;
};

#endif // TRANSACTION_H
