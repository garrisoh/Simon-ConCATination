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
    /** Constructor */
    explicit ChangePassDialog(QWidget *parent = 0);
    /** Destructor */
    ~ChangePassDialog();
    /** Set dialog title */
    void setTitle(QString title);
    /** Set dialog subtitle */
    void setSubtitle(QString subtitle);

protected:
    /** Called when close button is pressed */
    void closeEvent(QCloseEvent *event);

private slots:
    /** Verify when ok button clicked */
    void on_pushButton_clicked();

private:
    Ui::ChangePassDialog *ui;
};

#endif // CHANGEPASSDIALOG_H
