#ifndef GAME_H
#define GAME_H

#include <QString>

class Game {

public:
    QString gpid, gsound, gcolor, ginput;
    Game(QString pid, QString sound, QString color, QString input);
    QString getPID();
    QString getSound();
    QString getColor();
    QString getInput();
};

#endif // GAME_H
