#ifndef TRIALSETTINGSDIALOG_H
#define TRIALSETTINGSDIALOG_H

#include <QDialog>
#include <QTableView>
#include "../globals.h"
#include "trialsettingsmodel.h"

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

    //getters
    QString getParticipantID();
    QString getName();
    QString getAge();
    QString getGender();
    QString getColorString();
    QString getSoundString();
    QString getInterfaceString();
    QTableView* getTableView();

    //setters
    void setParticipantID(QString text);
    void setName(QString text);
    void setAge(QString text);
    void setGender(QString text);
    void setColor(QString text);
    void setSound(QString text);
    void setInterface(QString text);

private slots:
    void on_addButton_2_clicked();

    void on_removeButton_2_clicked();

    void on_gameTableView_clicked(const QModelIndex &index);

    void on_startButton_2_clicked();

private:
    Ui::TrialSettingsDialog *ui;
};

#endif // TRIALSETTINGSDIALOG_H
