#include "gamemodel.h"


void GameModel::append(const Game & game)
{
    beginInsertRows(QModelIndex(), m_data.count(), m_data.count());
    m_data.append(game);
    endInsertRows();
}

QVariant GameModel::headerData(int section, Qt::Orientation orientation, int role)
{
    if (orientation != Qt::Horizontal) return QVariant();
    if (role != Qt::DisplayRole) return QVariant();
    switch (section) {
    case 0: return "Participant ID";
    case 1: return "Sound Type";
    case 2: return "Color Type";
    case 3: return "Input Type";
    default: return QVariant();
    }
}
