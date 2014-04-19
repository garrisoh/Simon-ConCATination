#include "changepassdialog.h"
#include "ui_changepassdialog.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QSettings>

ChangePassDialog::ChangePassDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePassDialog)
{
    ui->setupUi(this);
}

ChangePassDialog::~ChangePassDialog()
{
    delete ui;
}

void ChangePassDialog::on_pushButton_clicked()
{
    if (ui->lineEdit->text() != ui->lineEdit_2->text()) {
        ui->label_3->setText("Passwords do not match.");
    } else if (ui->lineEdit->text().length() == 0){
        ui->label_3->setText("Enter a password to continue.");
    } else {
        // save new password and close
        QSettings s;
        s.setValue("simon/password", ui->lineEdit->text());
        accept();
    }
}

void ChangePassDialog::setTitle(QString title)
{
    ui->label->setText(title);
}

void ChangePassDialog::setSubtitle(QString subtitle)
{
    ui->label_2->setText(subtitle);
}

void ChangePassDialog::closeEvent(QCloseEvent *event)
{
    // allow the user to close if we are not creating a new password
    QSettings s;
    if (s.contains("simon/password")) {
        QDialog::closeEvent(event);
        return;
    }

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
