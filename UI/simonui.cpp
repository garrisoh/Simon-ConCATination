#include "simonui.h"
#include "ui_simonui.h"
#include "trialsettingsdialog.h"
#include "passdialog.h"
#include "changepassdialog.h"
#include <QString>
#include <QTime>
#include <QApplication>
#include <QThread>

SimonUI::SimonUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimonUI),
    yellow(":Sounds/yellow.wav"),
    blue(":Sounds/blue.wav"),
    green(":Sounds/green.wav"),
    red(":Sounds/red.wav")
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
}

SimonUI::~SimonUI()
{
    delete ui;
    delete[] _litImages;
    delete[] _hoveredImages;
}

SimonUI* SimonUI::getMainWindow()
{
    // return the singleton
    static SimonUI *w = new SimonUI();
    return w;
}

void SimonUI::onEvent(QuadrantID q, EventType e)
{
    switch (e)
	{
    case EventTypeHover:
		hoverQuadrant(q);
        break;
    case EventTypePressed:
		pressQuadrant(q);
        break;
    case EventTypeRelease:
        setImage(&_normalImage);
        break;
    default:
        break;
	}
}


void SimonUI::pressQuadrant(QuadrantID q) {
    // for playback
    if (q == QuadrantNone) {
        setImage(&_normalImage);
        return;
    }

    setImage(_litImages[q - QuadrantTopLeft]);

    if (sound != SoundTypeOff) {
        playSound(q);
    }
}

void SimonUI::playSound(QuadrantID q)
{
    // play sounds
    switch (q) {
    case QuadrantBottomLeft:
        yellow.play();
        break;
    case QuadrantBottomRight:
        blue.play();
        break;
    case QuadrantTopLeft:
        green.play();
        break;
    case QuadrantTopRight:
        red.play();
        break;
    case QuadrantNone:
    default:
        break;
    }
}

void SimonUI::hoverQuadrant(QuadrantID q) {
    if (q == QuadrantNone) {
        setImage(&_normalImage);
        return;
    }
	setImage(_hoveredImages[q - QuadrantTopLeft]);
}

void SimonUI::setVariables(ColorType color, SoundType sound)
{
    this->sound = sound;
}

void SimonUI::setImage(QPixmap* image)
{
	ui->image->setPixmap(*image);
}

void SimonUI::on_actionChange_Password_triggered()
{
    // prompt for old password
    PassDialog pass;
    pass.setTitle("Change Password");
    pass.setSubtitle("Enter the existing password.");
    pass.exec();

    // prompt for new password
    ChangePassDialog cpass;
    cpass.exec();
}

void SimonUI::on_actionNew_Trial_triggered()
{
    PassDialog pass;
    pass.setTitle("New Trial");
    pass.exec();

    TrialSettingsDialog settings;
    settings.exec();
}
