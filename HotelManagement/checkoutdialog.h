#ifndef CHECKOUTDIALOG_H
#define CHECKOUTDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QVector>
#include <QMessageBox>

namespace Ui {
class CheckOutDialog;
}

class CheckOutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CheckOutDialog(QWidget *parent = nullptr);
    ~CheckOutDialog();
    void readData();

private slots:
    void on_btnCheckOut_clicked();
    void on_btnCancel_clicked();

private:
    Ui::CheckOutDialog *ui;
};

#endif // CHECKOUTDIALOG_H
