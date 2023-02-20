#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
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

}


void MainWindow::on_btnTransactions_clicked()
{

}

