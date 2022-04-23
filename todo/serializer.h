/* ----------------------------------------------------
 * Filename: serializer.h
 * Project: Todo
 * Licence: GPL
 * ----------------------------------------------------
 * Date of Last Edit:
 * APRIL 22nd, 2022
 * Last Edit: Taylor Ramsay (T_Ramsay0@fullerton.edu)
 * Editors:
 *  - Taylor Ramsay
 * ----------------------------------------------------
 * Description: Serializes the data from a QVector<TaskCategory> and converts it to a representation of a JSON Document
 */
#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QList>
#include "taskcategory.h"

class Serializer
{
public:
    Serializer();

    // Returns a QJsonDocument of serialzed data from QVector<TaskCategory>
    QJsonDocument write(const QVector<TaskCategory>& taskCategories);
};

#endif // SERIALIZER_H
