#include "checkoutdialog.h"
#include "ui_checkoutdialog.h"
#include "hotel.h"

CheckOutDialog::CheckOutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckOutDialog)
{
    ui->setupUi(this);
    this->setFixedSize(414, 244);
    qDebug() << "ctor CheckOutDialog\n";
}

CheckOutDialog::~CheckOutDialog()
{
    delete ui;
}

void CheckOutDialog::readData()
{
    QVector<int> rooms = Hotel::GetInstance()->GetRoomList("n");
    ui->comboBox->clear();
    bool flag = false;

    for (auto it = rooms.begin(); it != rooms.end(); it++) {
        ui->comboBox->addItem(QString::number(*it));
        flag = true;
    }

    if (flag)
        ui->btnCheckOut->setEnabled(true);
}

void CheckOutDialog::on_btnCheckOut_clicked()
{
    // Call hotel's checkout.
    int roomno = ui->comboBox->currentText().toInt();

    if (roomno < 1)
    {
        QMessageBox::critical(this, "Warning!", "No room to checkout!");
        return;
    }

    int ret = Hotel::GetInstance()->CheckOut(roomno);

    if (ret == 0)
    {
        QMessageBox::information(this, "Success!", "Room has been check out!"
                                                   "Say thank you to customer!");
        hide();
    }
}


void CheckOutDialog::on_btnCancel_clicked()
{
    reject();
}

