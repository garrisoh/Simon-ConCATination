#include "changepassdialog.h"
#include "ui_changepassdialog.h"

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
        // TODO: Write to config file
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
