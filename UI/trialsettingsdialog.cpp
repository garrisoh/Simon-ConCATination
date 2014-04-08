//view controller

#include <iostream>
#include <QMessageBox>
#include "trialsettingsdialog.h"
#include "ui_trialsettingsdialog.h"

TrialSettingsDialog::TrialSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrialSettingsDialog)
{

    ui->setupUi(this);
    model = new TrialSettingsModel(ui->gameTableView);

}

TrialSettingsDialog::~TrialSettingsDialog()
{

    delete ui;

}


//getters
QString TrialSettingsDialog::getParticipantID()
{

    return ui->pidEdit->text();

}

QString TrialSettingsDialog::getName()
{

    return ui->nameEdit->text();

}

QString TrialSettingsDialog::getAge()
{

    return ui->ageEdit->text();

}

QString TrialSettingsDialog::getGender()
{

    return ui->genderComboBox->currentText();

}

QString TrialSettingsDialog::getColorString()
{

    return ui->colorComboBox->currentText();

}

QString TrialSettingsDialog::getSoundString()
{

    return ui->soundComboBox->currentText();

}

QString TrialSettingsDialog::getInterfaceString()
{

    return ui->inputComboBox->currentText();

}

QTableView* TrialSettingsDialog::getTableView()
{

    return ui->gameTableView;

}


//setters
void TrialSettingsDialog::setParticipantID(QString text)
{

    ui->pidEdit->setText(text);

}

void TrialSettingsDialog::setName(QString text)
{

    ui->nameEdit->setText(text);

}

void TrialSettingsDialog::setAge(QString text)
{

    ui->ageEdit->setText(text);

}

void TrialSettingsDialog::setGender(QString text)
{

    ui->genderComboBox->setCurrentText(text);

}

void TrialSettingsDialog::setColor(QString text)
{

    ui->colorComboBox->setCurrentText(text);

}

void TrialSettingsDialog::setSound(QString text)
{

    ui->soundComboBox->setCurrentText(text);

}

void TrialSettingsDialog::setInterface(QString text)
{

    ui->inputComboBox->setCurrentText(text);

}

//called when add button is clicked
void TrialSettingsDialog::on_addButton_2_clicked()
{

    //let the model do the work
    model->addGame(getSoundString(), getColorString(), getInterfaceString());

}

//called when remove button is clicked
void TrialSettingsDialog::on_removeButton_2_clicked()
{

    //let model do the work
    model->removeGame();

}

//called when item is clicked
void TrialSettingsDialog::on_gameTableView_clicked(const QModelIndex &index)
{
    int clickedRow = index.row();
    setColor(model->getItemAt(clickedRow, 0));
    setSound(model->getItemAt(clickedRow, 1));
    setInterface(model->getItemAt(clickedRow, 2));

}

//called when start button is clicked
void TrialSettingsDialog::on_startButton_2_clicked()
{

    //check if all fields are filled in
    QString compareTo = QString("");
    if(getParticipantID() == compareTo || getName() == compareTo || getAge() == compareTo)
    {

        QMessageBox* msgBox = new QMessageBox();
        msgBox->setText("Error! One or more fields are blank!");
        msgBox->exec();
        delete msgBox;
        return;

    } else
    {

        model->start(getParticipantID().toStdString(), getName().toStdString(),
                     getAge().toStdString(), getGender().toStdString());

    }

}
