#include "simonui.h"
#include "ui_simonui.h"
#include <QString>
#include "Quadrant.h"


SimonUI::SimonUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimonUI)
{
	ui->setupUi(this);

	_quadrants = new Quadrant*[4];
	_quadrants[0] = ui->quadrantTopLeft;
	_quadrants[1] = ui->quadrantTopRight;
	_quadrants[2] = ui->quadrantBottomLeft;
	_quadrants[3] = ui->quadrantBottomRight;

	_quadrants[0]->setColor(Qt::green);
	_quadrants[1]->setColor(Qt::red);
	_quadrants[2]->setColor(Qt::yellow);
	_quadrants[3]->setColor(Qt::blue);
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

void SimonUI::onEvent(QuadrantID q, EventType e)
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
		{
            ui->label->setText(s + "Hovered");
            _quadrants[q - QuadrantTopLeft]->hover();
		}
        break;
    case EventTypePressed:
        // set bottom label on press
        ui->label_2->setText(s + "Pressed");
        _quadrants[q - QuadrantTopLeft]->press();
        break;
    case EventTypeRelease:
        // set bottom label on release
        ui->label_2->setText(s + "Released");
        _quadrants[q - QuadrantTopLeft]->unpress();
        break;
    case EventTypeClicked:
        // set bottom label on click
        ui->label_2->setText(s + "Clicked");
        _quadrants[q - QuadrantTopLeft]->press();
        _quadrants[q - QuadrantTopLeft]->unpress();
        break;
    default:
        break;
    }
}


void SimonUI::pressQuadrant(QuadrantID q) {
	_quadrants[q]->press();
}

void SimonUI::unpressQuadrant(QuadrantID q) {
	_quadrants[q]->unpress();
}

void SimonUI::hoverQuadrant(QuadrantID q) {
	_quadrants[q]->hover();
}

void SimonUI::unhoverQuadrant(QuadrantID q) {
	_quadrants[q]->unhover();
}

void SimonUI::setVariables(ColorType color, SoundType sound)
{

}


