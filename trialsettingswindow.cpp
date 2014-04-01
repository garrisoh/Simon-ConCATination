#include "trialsettingswindow.h"
#include "ui_trialsettingswindow.h"


#ifndef TRIALSETTINGSSCREEN_H
#define TRIALSETTINGSSCREEN_H



TrialSettingsWindow::TrialSettingsWindow()
{
    setupUi(this);
}

TrialSettingsWindow::~TrialSettingsWindow()
{
}

//sets up and displays the components
void TrialSettingsWindow::setupUi(QMainWindow *MainWindow)
   {
       if (MainWindow->objectName().isEmpty())
           MainWindow->setObjectName(QStringLiteral("MainWindow"));
       MainWindow->resize(552, 600);
       centralwidget = new QWidget(MainWindow);
       centralwidget->setObjectName(QStringLiteral("centralwidget"));
       formLayoutWidget = new QWidget(centralwidget);
       formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
       formLayoutWidget->setGeometry(QRect(10, 50, 531, 491));
       formLayout = new QFormLayout(formLayoutWidget);
       formLayout->setObjectName(QStringLiteral("formLayout"));
       formLayout->setSizeConstraint(QLayout::SetNoConstraint);
       formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
       formLayout->setContentsMargins(0, 0, 0, 0);
       gameNumberLabel = new QLabel(formLayoutWidget);
       gameNumberLabel->setObjectName(QStringLiteral("gameNumberLabel"));

       formLayout->setWidget(0, QFormLayout::LabelRole, gameNumberLabel);

       gameNumberLabelDisplay = new QLabel(formLayoutWidget);
       gameNumberLabelDisplay->setObjectName(QStringLiteral("gameNumberLabelDisplay"));

       formLayout->setWidget(0, QFormLayout::FieldRole, gameNumberLabelDisplay);

       nameLabel = new QLabel(formLayoutWidget);
       nameLabel->setObjectName(QStringLiteral("nameLabel"));

       formLayout->setWidget(1, QFormLayout::LabelRole, nameLabel);

       nameEdit = new QLineEdit(formLayoutWidget);
       nameEdit->setObjectName(QStringLiteral("nameEdit"));

       formLayout->setWidget(1, QFormLayout::FieldRole, nameEdit);

       ageLabel = new QLabel(formLayoutWidget);
       ageLabel->setObjectName(QStringLiteral("ageLabel"));

       formLayout->setWidget(2, QFormLayout::LabelRole, ageLabel);

       ageEdit = new QLineEdit(formLayoutWidget);
       ageEdit->setObjectName(QStringLiteral("ageEdit"));

       formLayout->setWidget(2, QFormLayout::FieldRole, ageEdit);

       genderLabel = new QLabel(formLayoutWidget);
       genderLabel->setObjectName(QStringLiteral("genderLabel"));

       formLayout->setWidget(3, QFormLayout::LabelRole, genderLabel);

       genderComboBox = new QComboBox(formLayoutWidget);
       genderComboBox->setObjectName(QStringLiteral("genderComboBox"));

       formLayout->setWidget(3, QFormLayout::FieldRole, genderComboBox);

       soundLabel = new QLabel(formLayoutWidget);
       soundLabel->setObjectName(QStringLiteral("soundLabel"));

       formLayout->setWidget(4, QFormLayout::LabelRole, soundLabel);

       soundComboBox = new QComboBox(formLayoutWidget);
       soundComboBox->setObjectName(QStringLiteral("soundComboBox"));

       formLayout->setWidget(4, QFormLayout::FieldRole, soundComboBox);

       colorLabel = new QLabel(formLayoutWidget);
       colorLabel->setObjectName(QStringLiteral("colorLabel"));

       formLayout->setWidget(5, QFormLayout::LabelRole, colorLabel);

       colorComboBox = new QComboBox(formLayoutWidget);
       colorComboBox->setObjectName(QStringLiteral("colorComboBox"));

       formLayout->setWidget(5, QFormLayout::FieldRole, colorComboBox);

       inputLabel = new QLabel(formLayoutWidget);
       inputLabel->setObjectName(QStringLiteral("inputLabel"));

       formLayout->setWidget(6, QFormLayout::LabelRole, inputLabel);

       inputComboBox = new QComboBox(formLayoutWidget);
       inputComboBox->setObjectName(QStringLiteral("inputComboBox"));

       formLayout->setWidget(6, QFormLayout::FieldRole, inputComboBox);

       gameTableView = new QTableView(formLayoutWidget);
       gameTableView->setObjectName(QStringLiteral("gameTableView"));
       gameTableView->setFrameShape(QFrame::StyledPanel);
       gameTableView->setFrameShadow(QFrame::Sunken);
       gameTableView->setMidLineWidth(9);

       //connect(btn, SIGNAL(clicked()), SLOT(setFilter()));
       //m_model.append(Vehicle("Volvo", "240", "SQL8941"));
       //m_model.append(Vehicle("Volvo", "850"));
       //m_model.append(Vehicle("Volvo", "940", "QRZ1321"));
       //m_model.append(Vehicle("Volvo", "960", "QRZ1628"));
       //m_proxy.setSourceModel(&m_model);
       //m_proxy.setFilterKeyColumn(2);
       //view->setModel(&m_proxy);

       formLayout->setWidget(7, QFormLayout::FieldRole, gameTableView);

       horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

       formLayout->setItem(8, QFormLayout::LabelRole, horizontalSpacer);

       horizontalLayout_3 = new QHBoxLayout();
       horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
       horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

       horizontalLayout_3->addItem(horizontalSpacer_2);

       startButton = new QPushButton(formLayoutWidget);
       startButton->setObjectName(QStringLiteral("startButton"));

       horizontalLayout_3->addWidget(startButton);


       formLayout->setLayout(8, QFormLayout::FieldRole, horizontalLayout_3);

       addDeleteBox = new QDialogButtonBox(formLayoutWidget);
       addDeleteBox->setObjectName(QStringLiteral("addDeleteBox"));
       addDeleteBox->setOrientation(Qt::Vertical);
       addDeleteBox->setStandardButtons(QDialogButtonBox::Discard|QDialogButtonBox::Save);
       addDeleteBox->setCenterButtons(false);

       formLayout->setWidget(7, QFormLayout::LabelRole, addDeleteBox);

       label = new QLabel(centralwidget);
       label->setObjectName(QStringLiteral("label"));
       label->setGeometry(QRect(10, 0, 531, 41));
       label->setWordWrap(true);
       MainWindow->setCentralWidget(centralwidget);
       menubar = new QMenuBar(MainWindow);
       menubar->setObjectName(QStringLiteral("menubar"));
       menubar->setGeometry(QRect(0, 0, 552, 19));
       MainWindow->setMenuBar(menubar);
       statusbar = new QStatusBar(MainWindow);
       statusbar->setObjectName(QStringLiteral("statusbar"));
       MainWindow->setStatusBar(statusbar);

       retranslateUi(MainWindow);

       QMetaObject::connectSlotsByName(MainWindow);
   } // setupUi

    //updates ui
   void TrialSettingsWindow::retranslateUi(QMainWindow *MainWindow)
   {
       MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
       gameNumberLabel->setText(QApplication::translate("MainWindow", "Participant ID", 0));
       gameNumberLabelDisplay->setText(QApplication::translate("MainWindow", "001", 0));
       nameLabel->setText(QApplication::translate("MainWindow", "Name", 0));
       ageLabel->setText(QApplication::translate("MainWindow", "Age", 0));
       genderLabel->setText(QApplication::translate("MainWindow", "Gender", 0));
       genderComboBox->clear();
       genderComboBox->insertItems(0, QStringList()
        << QApplication::translate("MainWindow", "Female", 0)
        << QApplication::translate("MainWindow", "Male", 0)
       );
       soundLabel->setText(QApplication::translate("MainWindow", "Sound Type", 0));
       soundComboBox->clear();
       soundComboBox->insertItems(0, QStringList()
        << QApplication::translate("MainWindow", "3D (Surround)", 0)
        << QApplication::translate("MainWindow", "Mono", 0)
        << QApplication::translate("MainWindow", "No Sound", 0)
       );
       colorLabel->setText(QApplication::translate("MainWindow", "Color Type", 0));
       colorComboBox->clear();
       colorComboBox->insertItems(0, QStringList()
        << QApplication::translate("MainWindow", "Color", 0)
        << QApplication::translate("MainWindow", "Grayscale", 0)
        << QApplication::translate("MainWindow", "No Color", 0)
       );
       inputLabel->setText(QApplication::translate("MainWindow", "Input Type", 0));
       inputComboBox->clear();
       inputComboBox->insertItems(0, QStringList()
        << QApplication::translate("MainWindow", "Leap Controller", 0)
        << QApplication::translate("MainWindow", "Keyboard", 0)
        << QApplication::translate("MainWindow", "Mouse", 0)
       );
       startButton->setText(QApplication::translate("MainWindow", "Start", 0));
#ifndef QT_NO_TOOLTIP
       addDeleteBox->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
       label->setText(QApplication::translate("MainWindow", "Enter information for one game, then click 'add' to add game to trial. When done adding games, click 'Start'", 0));
   } // retranslateUi


#endif // TRIALSETTINGSSCREEN_H
