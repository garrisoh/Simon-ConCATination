#include "passdialog.h"
#include "ui_Passdialog.h"

#include <QMessageBox>

PassDialog::PassDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PassDialog)
{
    ui->setupUi(this);
}

PassDialog::~PassDialog()
{
    delete ui;
}

void PassDialog::setTitle(QString title)
{
    ui->label->setText(title);
}

void PassDialog::setSubtitle(QString subtitle)
{
    ui->label_2->setText(subtitle);
}

void PassDialog::on_pushButton_clicked()
{
    if (verifyPassword()) {
        accept();
    } else {
        ui->label_3->setText("Password Incorrect.");
    }
}

bool PassDialog::verifyPassword()
{
    // TODO: Read from config file
    return ui->lineEdit->text() == "hi";
}

void PassDialog::closeEvent(QCloseEvent *event)
{
    // display warning message
    QMessageBox msgBox;
    msgBox.setText("Closing this window will close the application\nAre you sure you want to continue?");
    msgBox.setStandardButtons(QMessageBox::Close | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Close);
    int result = msgBox.exec();
    switch (result) {
        case QMessageBox::Close:
            // close application
            exit(0);
            break;
        case QMessageBox::Cancel:
            // cancel
            event->ignore();
            break;
        default:
            QDialog::closeEvent(event);
            break;
    }
}
