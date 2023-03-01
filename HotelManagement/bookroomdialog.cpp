#include "bookroomdialog.h"
#include "ui_bookroomdialog.h"
#include "hotel.h"

BookRoomDialog::BookRoomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookRoomDialog)
{
    ui->setupUi(this);
    this->setFixedSize(374, 361);
}

BookRoomDialog::~BookRoomDialog()
{
    delete ui;
}

void BookRoomDialog::readData()
{
    qDebug() << "BookRoomDialog::readData()\n";

    QVector<int> rooms = Hotel::GetInstance()->GetRoomList("y");
    ui->cmbBoxRooms->clear();

    for (auto it = rooms.begin(); it != rooms.end(); it++)
        ui->cmbBoxRooms->addItem(QString::number(*it));
}

void BookRoomDialog::on_btnSubmit_clicked()
{
    // Call hotel's book room.
    int roomno = ui->cmbBoxRooms->currentText().toInt();
    QString name = ui->txtName->text();
    QString contactno = ui->txtContactNo->text();
    QString govtid = ui->txtIdProof->text();
    QString address = ui->plainTextEditAddress->toPlainText();

    if (roomno < 1)
    {
        QMessageBox::critical(this, "Warning!", "We are sold out! No room is available!");
        return ;
    }

    int ret = Hotel::GetInstance()->BookRoom(roomno, name, contactno, govtid, address);

    if (ret == 0)
    {
        QMessageBox::information(this, "Success!", "Room has been booked! Please ask for "
                                                   "Govt. Id from customer.");
        this->hide();
    }
}


void BookRoomDialog::on_btnCancel_clicked()
{
    reject();
}

