#include <iostream>
#include "trialsettingsdialog.h"
#include "ui_trialsettingsdialog.h"

TrialSettingsDialog::TrialSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrialSettingsDialog)
{
    ui->setupUi(this);
}

TrialSettingsDialog::~TrialSettingsDialog()
{
    delete ui;
}
