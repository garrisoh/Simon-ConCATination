#ifndef QUADRANT_H
#define QUADRANT_H

#include <QWidget>

#include "../globals.h"


namespace Ui {
	class Quadrant;	// UI component, defined in Quadrant.ui
}

class Quadrant : public QWidget
{
private:
	//Image* _texture;
	//Sound* onClick;
	Ui::Quadrant* _widget;	// UI component, defined in Quadrant.ui
	int _color;
	QPixmap _litImage;
	QPixmap _unlitImage;

public:
	//Quadrant(Color color, Sound sound);
	explicit Quadrant(QWidget *parent = 0);

	void hover();
	void unhover();
	void press();
	void unpress();

	void setColor(int color);
	//void setImage(std::string filename);

	void setImages(std::string unpressedFilename, std::string pressedFilename);

};

#endif // QUADRANT_H
