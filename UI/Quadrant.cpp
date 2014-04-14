#include "Quadrant.h"

#include "ui_Quadrant.h"


#include <iostream>



Quadrant::Quadrant(QWidget *parent) :
	QWidget(parent),
	_widget(new Ui::Quadrant)
{
	std::cout << "Quadrant constructor called" << std::endl;
	_widget->setupUi(this);
}


void Quadrant::hover() {
	std::cout << "Quadrant hover" << std::endl;

	/*switch(_color)
	{
	case Qt::red:
		setColor(Qt::darkRed);
		break;
	case Qt::blue:
		setColor(Qt::darkBlue);
		break;
	case Qt::green:
		setColor(Qt::darkGreen);
		break;
	case Qt::yellow:
		setColor(Qt::darkYellow);
		break;
	case Qt::darkRed:
		break;
	case Qt::darkBlue:
		break;
	case Qt::darkGreen:
		break;
	case Qt::darkYellow:
		break;
	default:
		std::cout << "Error: Could not identify current color " << _color << std::endl;
	}*/


}

void Quadrant::unhover() {
	std::cout << "Quadrant unhover" << std::endl;

	/*switch(_color)
	{
	case Qt::red:
		break;
	case Qt::blue:
		break;
	case Qt::green:
		break;
	case Qt::yellow:
		break;
	case Qt::darkRed:
		setColor(Qt::red);
		break;
	case Qt::darkBlue:
		setColor(Qt::blue);
		break;
	case Qt::darkGreen:
		setColor(Qt::green);
		break;
	case Qt::darkYellow:
		setColor(Qt::yellow);
		break;
	default:
		std::cout << "Error. Could not identify current color " << _color << std::endl;
	}*/
}

void Quadrant::press() {
	std::cout << "Quadrant press" << std::endl;
	_widget->label->setPixmap(_litImage);
}

void Quadrant::unpress() {
	std::cout << "Quadrant unpress" << std::endl;
	_widget->label->setPixmap(_unlitImage);
}

void Quadrant::setColor(int color)
{
	_color = color;
	std::string colorName;
	switch(color)
	{
	case Qt::red:
		colorName = "red";
		break;
	case Qt::blue:
		colorName = "blue";
		break;
	case Qt::green:
		colorName = "green";
		break;
	case Qt::yellow:
		colorName = "yellow";
		break;
	case Qt::darkRed:
		colorName = "darkRed";
		break;
	case Qt::darkBlue:
		colorName = "darkBlue";
		break;
	case Qt::darkGreen:
		colorName = "darkGreen";
		break;
	case Qt::darkYellow:
		colorName = "darkYellow";
		break;
	}

	std::string newStyleSheet = "QWidget {\nbackground-color: " + colorName + ";\n};";

	this->setStyleSheet(QString::fromUtf8(newStyleSheet.c_str()));
}
/*
void Quadrant::setImage(std::string filename)
{
	_widget->label->setPixmap(QPixmap::fromImage(QImage(filename.c_str())));
}*/

void Quadrant::setImages(std::string unlitFilename, std::string litFilename)
{
	_unlitImage = QPixmap::fromImage(QImage(unlitFilename.c_str()));
	_litImage = QPixmap::fromImage(QImage(litFilename.c_str()));
	_widget->label->setPixmap(_unlitImage);
}

