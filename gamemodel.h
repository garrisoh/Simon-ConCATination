#include <QApplication>
#include <QAbstractTableModel>
#include <QSortFilterProxyModel>
#include <QInputDialog>
#include <QTableView>
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>
#include "InterfaceManagers/globals.h"
#include "game.h"

class GameModel : public QAbstractTableModel {
    QList<Game> m_data;
public:
    GameModel(QObject * parent = 0) : QAbstractTableModel(parent) {}
    int columnCount(const QModelIndex &) const { return 3; }
    QVariant headerData(int section, Qt::Orientation orientation, int role);
    void append(const Game & game);
};
