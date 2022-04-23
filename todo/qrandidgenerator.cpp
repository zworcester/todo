/* ----------------------------------------------------
 * Filename: taskeditorform.h
 * Project: Todo
 * Licence: GPL
 * ----------------------------------------------------
 * Date of Last Edit:
 * APRIL 22nd, 2022
 * Last Edit: Zachary Worcester (zworcester0@fullerton.edu
 * ----------------------------------------------------
 * Description:
 * This file implements a random ID generator.
 */

#include "qrandidgenerator.h"

QRandIDGenerator::QRandIDGenerator(const StringList& loadFirst)
    :
      list(loadFirst)
{}

// Wrapper for the iterator beginning of the QList<QString> list
StringListIterator QRandIDGenerator::begin()
{
    return list.begin();
}

// Wrapper for the iterator end of the QList<QString> list
StringListIterator QRandIDGenerator::end()
{
    return list.end();
}

// Wrapper for the const iterator beginning of the QList<QString> list
constStringListIterator QRandIDGenerator::begin() const
{
    return list.begin();
}

// Wrapper for the const iterator end of the QList<QString> list
constStringListIterator QRandIDGenerator::end() const
{
    return list.end();
}

// Get the QString Representation of a random 64 bit int.
QString QRandIDGenerator::get()
{
    QString tempId = QString::number(QRandomGenerator64::global()->generate()).rightJustified(20,QLatin1Char('0'));

    return tempId;
}

// Load IDs for collision checking.
void QRandIDGenerator::load(const QString& id)
{
    list.append(id);
    return;
}

// Load IDs for collision checking.
void QRandIDGenerator::load(const StringList& list)
{
    for (const QString& qString : list) {
        this->list.append(qString);
    }

    return;
}

// Remove the requested ID from collision checker.
bool QRandIDGenerator::remove(const QString& id)
{
    return this->list.removeOne(id);
}

// Clear collision checker.
void QRandIDGenerator::clear()
{
    this->list.clear();
}

// Returns true if collision checker is empty.
bool QRandIDGenerator::empty() const
{
    return this->list.empty();
}
