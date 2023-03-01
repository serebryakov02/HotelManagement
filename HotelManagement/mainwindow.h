#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "checkavailabilitydialog.h"
#include "bookroomdialog.h"
#include "checkoutdialog.h"
#include "transaction.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnRoomBoking_clicked();
    void on_btnCheckOut_clicked();
    void on_btnCheckAvailability_clicked();
    void on_btnTransactions_clicked();

private:
    Ui::MainWindow *ui;

    CheckAvailabilityDialog* m_ptrCheckAvailabilityDialog;
    BookRoomDialog* m_ptrBookRoomDialog;
    CheckOutDialog* m_ptrCheckOutDialog;
    Transaction* m_ptrTransaction;
};

#endif // MAINWINDOW_H
