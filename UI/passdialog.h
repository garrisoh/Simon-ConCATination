#ifndef PASSDIALOG_H
#define PASSDIALOG_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class PassDialog;
}

/** A dialog box for entering a password */
class PassDialog : public QDialog
{
    Q_OBJECT

public:
    /** Constructor */
    explicit PassDialog(QWidget *parent = 0);
    /** Destructor */
    ~PassDialog();
    /** Set dialog title */
    void setTitle(QString title);
    /** Set dialog subtitle */
    void setSubtitle(QString subtitle);

protected:
    /** Called when close button is pressed */
    void closeEvent(QCloseEvent *event);

private slots:
    /** Called when pushbutton clicked */
    void on_pushButton_clicked();

private:
    Ui::PassDialog *ui;

    /** Verify admin password */
    bool verifyPassword();
};

#endif // PASSDIALOG_H
