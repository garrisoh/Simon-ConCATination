#include <QtGui>
#include "InterfaceManagers/globals.h"
#include "game.h"

class GameModel : public QStandardItemModel {

public:
QStandardItemModel* createModel(QObject* parent);


};
