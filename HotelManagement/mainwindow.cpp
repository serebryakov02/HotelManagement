#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(800, 600);

    m_ptrCheckAvailabilityDialog = new CheckAvailabilityDialog(this);
    m_ptrBookRoomDialog = new BookRoomDialog(this);
    m_ptrCheckOutDialog = new CheckOutDialog(this);
    m_ptrTransaction = new Transaction(this);

    QPixmap pm("/home/serebryakov/QtProjects2023/February/HotelManagement/hotel.jpg");
    ui->label->setPixmap(pm);
    ui->label->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete m_ptrCheckAvailabilityDialog;
    delete m_ptrBookRoomDialog;
    delete m_ptrCheckOutDialog;
    delete m_ptrTransaction;
    delete ui;
}


void MainWindow::on_btnRoomBoking_clicked()
{
    qDebug() << "In MainWindow::on_btnRoomBoking_clicked()\n";
    m_ptrBookRoomDialog->readData();
    m_ptrBookRoomDialog->exec();
}


void MainWindow::on_btnCheckOut_clicked()
{
    qDebug() << "In MainWindow::on_btnCheckOut_clicked()";
    m_ptrCheckOutDialog->readData();
    m_ptrCheckOutDialog->exec();
}


void MainWindow::on_btnCheckAvailability_clicked()
{
    qDebug() << "In MainWindow::on_btnCheckAvailability_clicked()\n";
    m_ptrCheckAvailabilityDialog->readData();
    m_ptrCheckAvailabilityDialog->exec();
}


void MainWindow::on_btnTransactions_clicked()
{
    qDebug() << "In MainWindow::on_btnTransactions_clicked()";
    m_ptrTransaction->readData();
    m_ptrTransaction->exec();
}

