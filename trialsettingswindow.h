#ifndef TRIALSETTINGSWINDOW_H
#define TRIALSETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include <QAbstractTableModel>
#include <QSortFilterProxyModel>
#include "gamemodel.h"

class TrialSettingsWindow : public QMainWindow
{
    Q_OBJECT

public:

    //QWidget items
    QWidget *centralwidget;
    QWidget *formLayoutWidget;

    //form layout to make GUI look nice
    QFormLayout *formLayout;

    //lotsa labels
    QLabel *gameNumberLabel;
    QLabel *gameNumberLabelDisplay;
    QLabel *nameLabel;
    QLabel *ageLabel;
    QLabel *genderLabel;
    QLabel *colorLabel;
    QLabel *inputLabel;
    QLabel *soundLabel;
    QLabel *label;

    //one line text edits
    QLineEdit *nameEdit;
    QLineEdit *ageEdit;

    //combo boxes
    QComboBox *genderComboBox;
    QComboBox *soundComboBox;
    QComboBox *colorComboBox;
    QComboBox *inputComboBox;

    //table view to hold games
    QTableView *gameTableView;

    //spacers to make gui look nice
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;

    //buttons
    QPushButton *startButton;
    QDialogButtonBox *addDeleteBox;

    //menu bars
    QMenuBar *menubar;
    QStatusBar *statusbar;

    //Constructor and destructor
    TrialSettingsWindow();
    ~TrialSettingsWindow();

    //Methods
    void retranslateUi(QMainWindow *MainWindow);
    void setupUi(QMainWindow *MainWindow);

private:
    TrialSettingsWindow *ui;
};

#endif // TRIALSETTINGSWINDOW_H
