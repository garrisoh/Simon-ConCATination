#include "simonui.h"
#include "ui_simonui.h"
#include <QString>


SimonUI::SimonUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimonUI)
{
    ui->setupUi(this);

    _normalImage = QPixmap::fromImage(QImage(":Images/SimonNoneLit.png"));
    _bottomLeftLit = QPixmap::fromImage(QImage(":Images/SimonBottomLeftLit.png"));
    _bottomLeftHover = QPixmap::fromImage(QImage(":Images/SimonBottomLeftHover.png"));
    _bottomRightLit = QPixmap::fromImage(QImage(":Images/SimonBottomRightLit.png"));
    _bottomRightHover = QPixmap::fromImage(QImage(":Images/SimonBottomRightHover.png"));
    _topLeftLit = QPixmap::fromImage(QImage(":Images/SimonTopLeftLit.png"));
    _topLeftHover = QPixmap::fromImage(QImage(":Images/SimonTopLeftHover.png"));
    _topRightLit = QPixmap::fromImage(QImage(":Images/SimonTopRightLit.png"));
    _topRightHover = QPixmap::fromImage(QImage(":Images/SimonTopRightHover.png"));


	_litImages = new QPixmap*[4];
	_litImages[0] = &_topLeftLit;
	_litImages[1] = &_topRightLit;
	_litImages[2] = &_bottomLeftLit;
	_litImages[3] = &_bottomRightLit;

	_hoveredImages = new QPixmap*[4];
	_hoveredImages[0] = &_topLeftHover;
	_hoveredImages[1] = &_topRightHover;
	_hoveredImages[2] = &_bottomLeftHover;
	_hoveredImages[3] = &_bottomRightHover;

	setImage(&_normalImage);

	update();
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
    switch (e)
	{
    case EventTypeHover:
		if (q == QuadrantNone)
		{
			setImage(&_normalImage);
			break;
        }
		hoverQuadrant(q);
        break;
    case EventTypePressed:
		if (q == QuadrantNone)
            break;
		pressQuadrant(q);
        break;
    case EventTypeRelease:
		setImage(&_normalImage);
		break;
    case EventTypeClicked:
        pressQuadrant(q);
        break;
    default:
        break;
	}
}


void SimonUI::pressQuadrant(QuadrantID q) {
	setImage(_litImages[q - QuadrantTopLeft]);
}

void SimonUI::unpressQuadrant(QuadrantID q) {
}

void SimonUI::hoverQuadrant(QuadrantID q) {
	setImage(_hoveredImages[q - QuadrantTopLeft]);
}

void SimonUI::unhoverQuadrant(QuadrantID q) {
}

void SimonUI::setVariables(ColorType color, SoundType sound)
{

}

void SimonUI::releaseQuadrants() {
	for (int i = 0; i < 4; i++) {
	}
}

void SimonUI::setImage(QPixmap* image)
{
	ui->image->setPixmap(*image);
}
