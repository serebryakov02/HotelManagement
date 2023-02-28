#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_ptrCheckAvailabilityDialog = new CheckAvailabilityDialog(this);
}

MainWindow::~MainWindow()
{
    delete m_ptrCheckAvailabilityDialog;
    delete ui;
}


void MainWindow::on_btnRoomBoking_clicked()
{

}


void MainWindow::on_btnCheckOut_clicked()
{

}


void MainWindow::on_btnCheckAvailability_clicked()
{
    qDebug() << "In MainWindow::on_btnCheckAvailability_clicked()\n";
    m_ptrCheckAvailabilityDialog->readData();
    m_ptrCheckAvailabilityDialog->exec();
}


void MainWindow::on_btnTransactions_clicked()
{

}

