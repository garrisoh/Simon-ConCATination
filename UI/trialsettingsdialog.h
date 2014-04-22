#ifndef TRIALSETTINGSDIALOG_H
#define TRIALSETTINGSDIALOG_H

#include <QDialog>
#include <QTableView>
#include <QCloseEvent>
#include "../globals.h"
#include "trialsettingsmodel.h"
#include "../StateMachines/simoncontroller.h"

namespace Ui {
class TrialSettingsDialog;
}

class TrialSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TrialSettingsDialog(QWidget *parent = 0);
    ~TrialSettingsDialog();

    //model
    TrialSettingsModel* model;

    //int cuz i need it
    int selectedRow; //makes up and down buttons work

    //getters
    QString getParticipantID();
    QString getAge();
    QString getGender();
    QString getColorString();
    QString getSoundString();
    QString getInterfaceString();
    QTableView* getTableView();

    //setters
    void setParticipantID(QString text);
    void setAge(QString text);
    void setGender(QString text);
    void setColor(QString text);
    void setSound(QString text);
    void setInterface(QString text);
    void setController(SimonController *controller);

    void closeEvent(QCloseEvent *event);

private slots:
    void on_addButton_2_clicked();

    void on_removeButton_2_clicked();

    void on_gameTableView_clicked(const QModelIndex &index);

    void on_startButton_2_clicked();

    void on_upButton_clicked();

    void on_downButton_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::TrialSettingsDialog *ui;
    SimonController *controller;
};

#endif // TRIALSETTINGSDIALOG_H
