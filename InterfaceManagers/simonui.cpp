#include "simonui.h"
#include "ui_simonui.h"
#include <QString>

SimonUI::SimonUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimonUI)
{
    ui->setupUi(this);
}

SimonUI::~SimonUI()
{
    delete ui;
}

SimonUI& SimonUI::getMainWindow()
{
    // return the singleton
    static SimonUI w;
    return w;
}

void SimonUI::onEvent(Quadrant q, EventType e)
{
    // determine quadrant
    QString s;
    switch (q) {
    case QuadrantBottomLeft:
        s = "Bottom Left ";
        break;
    case QuadrantBottomRight:
        s = "Bottom Right ";
        break;
    case QuadrantTopLeft:
        s = "Top Left ";
        break;
    case QuadrantTopRight:
        s = "Top Right ";
        break;
    default:
        break;
    }

    switch (e) {
    case EventTypeHover:
        // set top label on hover
        if (q != QuadrantNone)
            ui->label->setText(s + "Hovered");
        break;
    case EventTypePressed:
        // set bottom label on press
        ui->label_2->setText(s + "Pressed");
        break;
    case EventTypeRelease:
        // set bottom label on release
        ui->label_2->setText(s + "Released");
        break;
    case EventTypeClicked:
        // set bottom label on click
        ui->label_2->setText(s + "Clicked");
        break;
    default:
        break;
    }
}
