#ifndef BOOKROOMDIALOG_H
#define BOOKROOMDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QVector>
#include <QString>
#include <QMessageBox>

namespace Ui {
class BookRoomDialog;
}

class BookRoomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BookRoomDialog(QWidget *parent = nullptr);
    ~BookRoomDialog();
    void readData();

private slots:
    void on_btnSubmit_clicked();
    void on_btnCancel_clicked();

private:
    Ui::BookRoomDialog *ui;
};

#endif // BOOKROOMDIALOG_H
