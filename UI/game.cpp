#include "game.h"

Game::Game(QString pid, QString sound, QString color, QString input)
{
    gpid = pid;
    gsound = sound;
    gcolor = color;
    ginput = input;
}

QString Game::getPID() { return gpid; }
QString Game::getSound() { return gsound; }
QString Game::getColor() { return gcolor; }
QString Game::getInput() { return ginput; }
