#include "simonui.h"
#include "ui_simonui.h"
#include <QString>


SimonUI::SimonUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimonUI)
{
	ui->setupUi(this);

	std::string path = "../Simon-ConCATination/UI/Images/FullImage/";

	_normalImage = QPixmap::fromImage(QImage( std::string(path + "SimonNoneLit.png").c_str()));
	_bottomLeftLit = QPixmap::fromImage(QImage( std::string(path + "SimonBottomLeftLit.png").c_str()));
	_bottomLeftHover = QPixmap::fromImage(QImage( std::string(path + "SimonBottomLeftHover.png").c_str()));
	_bottomRightLit = QPixmap::fromImage(QImage( std::string(path + "SimonBottomRightLit.png").c_str()));
	_bottomRightHover = QPixmap::fromImage(QImage( std::string(path + "SimonBottomRightHover.png").c_str()));
	_topLeftLit = QPixmap::fromImage(QImage( std::string(path + "SimonTopLeftLit.png").c_str()));
	_topLeftHover = QPixmap::fromImage(QImage( std::string(path + "SimonTopLeftHover.png").c_str()));
	_topRightLit = QPixmap::fromImage(QImage( std::string(path + "SimonTopRightLit.png").c_str()));
	_topRightHover = QPixmap::fromImage(QImage( std::string(path + "SimonTopRightHover.png").c_str()));


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
	// determine quadrant
    QString s;
	switch (q)
	{
	case QuadrantTopLeft:
		s = "Top Left ";
		break;
	case QuadrantTopRight:
		s = "Top Right ";
		break;
    case QuadrantBottomLeft:
        s = "Bottom Left ";
        break;
    case QuadrantBottomRight:
        s = "Bottom Right ";
        break;
    default:
        break;
    }

	switch (e)
	{
    case EventTypeHover:
        // set top label on hover
		if (q == QuadrantNone)
		{
			setImage(&_normalImage);
			break;
		}
		ui->label->setText(s + "Hovered");
		hoverQuadrant(q);
        break;
    case EventTypePressed:
        // set bottom label on press
		if (q == QuadrantNone)
			break;
		ui->label_2->setText(s + "Pressed");
		pressQuadrant(q);
        break;
	case EventTypeRelease:
        // set bottom label on release
		ui->label_2->setText(s + "Released");
		setImage(&_normalImage);
		break;
    case EventTypeClicked:
        // set bottom label on click
		ui->label_2->setText(s + "Clicked");
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
