#include "gamemodel.h"

QStandardItemModel* GameModel::createModel(QObject* parent)
{
    const int numRows = 10;
    const int numColumns = 10;

    QStandardItemModel* model = new QStandardItemModel(numRows, numColumns);
    for (int row = 0; row < numRows; ++row)
    {
        for (int column = 0; column < numColumns; ++column)
        {
            QString text = QString('A' + row) + QString::number(column + 1);
            QStandardItem* item = new QStandardItem(text);
            model->setItem(row, column, item);
        }
     }

    return model;
}
