//view controller

#include <iostream>
#include <QMessageBox>
#include <QFileDialog>
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
    model->removeGame(selectedRow);
    selectedRow = -1;

}

//called when item is clicked
void TrialSettingsDialog::on_gameTableView_clicked(const QModelIndex &index)
{

    selectedRow = index.row();

    setColor(model->getItemAt(selectedRow, 0));
    setSound(model->getItemAt(selectedRow, 1));
    setInterface(model->getItemAt(selectedRow, 2));

}

//called when start button is clicked
void TrialSettingsDialog::on_startButton_2_clicked()
{

    //check if all fields are filled in
    QString compareTo = QString("");
    if(getParticipantID() == compareTo || getAge() == compareTo)
    {

        //not all fields are filled in
        QMessageBox* msgBox = new QMessageBox();
        msgBox->setText("Error! One or more fields are blank!");
        msgBox->exec();
        delete msgBox;
        return;

    } else
    {

        model->start(getParticipantID().toStdString(),
                     getAge().toStdString(), getGender().toStdString());

    }

}

//when up button is pressed
void TrialSettingsDialog::on_upButton_clicked()
{

    //verify boundaries
    if (selectedRow <= 0) return;

    //swap the rows
    model->swapRows(selectedRow, selectedRow - 1);
    selectedRow--;
    getTableView()->selectRow(selectedRow);

}

//when down button is pressed
void TrialSettingsDialog::on_downButton_clicked()
{

    //verify boundaries
    if (selectedRow == -1) return;
    if (selectedRow >= model->getRowCount() - 1) return;

    //swap the rows
    model->swapRows(selectedRow, selectedRow + 1);
    selectedRow++;
    getTableView()->selectRow(selectedRow);

}


//called when checkbox is checked or unchecked
void TrialSettingsDialog::on_checkBox_stateChanged(int arg1)
{
    //not checked
    if (arg1 < 1)
    {

        //set models demoMode to false
        model->setDemoMode(false);

    }
    //checkbox is checked
    else
    {

        model->setDemoMode(true);

    }

}


//called when save
void TrialSettingsDialog::on_pushButton_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save CSV File As..."), "", tr("Comma Delimited Files (*.csv *.txt)"));
    model->setSaveLocation(fileName.toStdString());

}
