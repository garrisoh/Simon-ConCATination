#ifndef QUADRANT_H
#define QUADRANT_H

#include <QWidget>

#include "globals.h"


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

public:
	//Quadrant(Color color, Sound sound);
	explicit Quadrant(QWidget *parent = 0);

	void hover();
	void unhover();
	void press();
	void unpress();

	void setColor(int color);

};

#endif // QUADRANT_H
