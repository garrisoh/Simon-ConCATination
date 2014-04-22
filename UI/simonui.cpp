#include "simonui.h"
#include "ui_simonui.h"
#include "trialsettingsdialog.h"
#include "passdialog.h"
#include "changepassdialog.h"

SimonUI::SimonUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimonUI),
    yellow(":Sounds/yellow.wav"),
    blue(":Sounds/blue.wav"),
    green(":Sounds/green.wav"),
    red(":Sounds/red.wav")
{
    ui->setupUi(this);

    _litImages = NULL;
    _hoveredImages = NULL;

    // default values
    setVariables(ColorTypeOn, SoundTypeRegular);
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
        pressQuadrant(QuadrantNone);
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
    // stop all sounds first
    yellow.stop();
    blue.stop();
    green.stop();
    red.stop();

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

    // clean up old resources
    if (_litImages)
        delete[] _litImages;
    if (_hoveredImages)
        delete[] _hoveredImages;

    // load in new resources
    if (color == ColorTypeOn) {
        _normalImage = QPixmap::fromImage(QImage(":Images/Color/SimonNoneLit.png"));
        _bottomLeftLit = QPixmap::fromImage(QImage(":Images/Color/SimonBottomLeftLit.png"));
        _bottomLeftHover = QPixmap::fromImage(QImage(":Images/Color/SimonBottomLeftHover.png"));
        _bottomRightLit = QPixmap::fromImage(QImage(":Images/Color/SimonBottomRightLit.png"));
        _bottomRightHover = QPixmap::fromImage(QImage(":Images/Color/SimonBottomRightHover.png"));
        _topLeftLit = QPixmap::fromImage(QImage(":Images/Color/SimonTopLeftLit.png"));
        _topLeftHover = QPixmap::fromImage(QImage(":Images/Color/SimonTopLeftHover.png"));
        _topRightLit = QPixmap::fromImage(QImage(":Images/Color/SimonTopRightLit.png"));
        _topRightHover = QPixmap::fromImage(QImage(":Images/Color/SimonTopRightHover.png"));
    } else if (color == ColorTypeGrayscale) {
        _normalImage = QPixmap::fromImage(QImage(":Images/Gray/SimonNoneLit.png"));
        _bottomLeftLit = QPixmap::fromImage(QImage(":Images/Gray/SimonBottomLeftLit.png"));
        _bottomLeftHover = QPixmap::fromImage(QImage(":Images/Gray/SimonBottomLeftHover.png"));
        _bottomRightLit = QPixmap::fromImage(QImage(":Images/Gray/SimonBottomRightLit.png"));
        _bottomRightHover = QPixmap::fromImage(QImage(":Images/Gray/SimonBottomRightHover.png"));
        _topLeftLit = QPixmap::fromImage(QImage(":Images/Gray/SimonTopLeftLit.png"));
        _topLeftHover = QPixmap::fromImage(QImage(":Images/Gray/SimonTopLeftHover.png"));
        _topRightLit = QPixmap::fromImage(QImage(":Images/Gray/SimonTopRightLit.png"));
        _topRightHover = QPixmap::fromImage(QImage(":Images/Gray/SimonTopRightHover.png"));
    } else {
        _normalImage = QPixmap::fromImage(QImage(":Images/Mono/SimonNoneLit.png"));
        _bottomLeftLit = QPixmap::fromImage(QImage(":Images/Mono/SimonBottomLeftLit.png"));
        _bottomLeftHover = QPixmap::fromImage(QImage(":Images/Mono/SimonBottomLeftHover.png"));
        _bottomRightLit = QPixmap::fromImage(QImage(":Images/Mono/SimonBottomRightLit.png"));
        _bottomRightHover = QPixmap::fromImage(QImage(":Images/Mono/SimonBottomRightHover.png"));
        _topLeftLit = QPixmap::fromImage(QImage(":Images/Mono/SimonTopLeftLit.png"));
        _topLeftHover = QPixmap::fromImage(QImage(":Images/Mono/SimonTopLeftHover.png"));
        _topRightLit = QPixmap::fromImage(QImage(":Images/Mono/SimonTopRightLit.png"));
        _topRightHover = QPixmap::fromImage(QImage(":Images/Mono/SimonTopRightHover.png"));
    }

    // fill arrays
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

void SimonUI::setImage(QPixmap* image)
{
	ui->image->setPixmap(*image);
}

void SimonUI::enableMenu(bool enable)
{
    ui->actionNew_Trial->setEnabled(enable);
    ui->actionChange_Password->setEnabled(enable);
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

    // make static so it doesn't get deallocated until the next game
    static SimonController *controller = NULL;
    if (controller) {
        delete controller;
        controller = NULL;
    }

    controller = new SimonController();

    // show settings screen
    TrialSettingsDialog settings;
    settings.setController(controller);
    settings.exec();
}
