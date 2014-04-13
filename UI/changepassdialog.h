#ifndef CHANGEPASSDIALOG_H
#define CHANGEPASSDIALOG_H

#include <QDialog>

namespace Ui {
class ChangePassDialog;
}

/** A dialog for changing or entering a new password */
class ChangePassDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePassDialog(QWidget *parent = 0);
    ~ChangePassDialog();
    /** Set dialog title */
    void setTitle(QString title);
    /** Set dialog subtitle */
    void setSubtitle(QString subtitle);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ChangePassDialog *ui;
};

#endif // CHANGEPASSDIALOG_H
