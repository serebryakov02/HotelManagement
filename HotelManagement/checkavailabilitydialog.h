#ifndef CHECKAVAILABILITYDIALOG_H
#define CHECKAVAILABILITYDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QVector>
#include <QString>

namespace Ui {
class CheckAvailabilityDialog;
}

class CheckAvailabilityDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CheckAvailabilityDialog(QWidget *parent = nullptr);
    ~CheckAvailabilityDialog();
    void readData();

private:
    Ui::CheckAvailabilityDialog *ui;
};

#endif // CHECKAVAILABILITYDIALOG_H
