#include "checkavailabilitydialog.h"
#include "ui_checkavailabilitydialog.h"
#include "hotel.h"

CheckAvailabilityDialog::CheckAvailabilityDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckAvailabilityDialog)
{
    ui->setupUi(this);
    this->setFixedSize(335, 198);
    qDebug() << "In CheckAvailabilityDialog()\n";
}

CheckAvailabilityDialog::~CheckAvailabilityDialog()
{
    qDebug()<<"Deleting CheckAvailabilityDialog\n";
    delete ui;
}

void CheckAvailabilityDialog::readData()
{
    qDebug() << "In CheckAvailabilityDialog::readData()\n";

    QVector<int> rooms = Hotel::GetInstance()->GetRoomList("y");
    ui->lblAvailable->setStyleSheet("QLabel { background-color : grey; color : aqua; }");

    QVector<int> tempRooms { 100, 101, 102, 103, 104, 200, 201, 202, 203, 204 };

    // Set default color to all.
    for (auto it = tempRooms.begin(); it != tempRooms.end(); it++)
    {
        // Put logic to change the color of labels.
        QString lblName = "lbl" + QString::number(*it);
        QLabel* ptr = this->findChild<QLabel*>(lblName);

        if (ptr)
            ptr->setStyleSheet("QLabel { background-color : lightgrey; color : aqua; }");
    }

    for (auto it = rooms.begin(); it != rooms.end(); it++)
    {
        // Put logic to change the color of labels.
        QString lblName = "lbl" + QString::number(*it);
        QLabel* ptr = this->findChild<QLabel*>(lblName);

        if (ptr)
            ptr->setStyleSheet("QLabel { background-color : grey; color : aqua; }");
    }
}
