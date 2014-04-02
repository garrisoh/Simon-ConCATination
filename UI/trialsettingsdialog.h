#ifndef TRIALSETTINGSDIALOG_H
#define TRIALSETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class TrialSettingsDialog;
}

class TrialSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TrialSettingsDialog(QWidget *parent = 0);
    ~TrialSettingsDialog();

private:
    Ui::TrialSettingsDialog *ui;
};

#endif // TRIALSETTINGSDIALOG_H
