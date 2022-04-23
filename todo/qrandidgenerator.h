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

#ifndef QRANDIDGENERATOR_H
#define QRANDIDGENERATOR_H

#include <QList>
#include <QRandomGenerator64>

typedef QList<QString> StringList;
typedef StringList::Iterator StringListIterator;
typedef StringList::ConstIterator constStringListIterator;

class QRandIDGenerator
{
public:
    QRandIDGenerator() : list() { }
    QRandIDGenerator(const StringList& loadFirst);

    // Wrapper for the iterator beginning of the QList<QString> list
    StringListIterator begin();
    // Wrapper for the iterator end of the QList<QString> list
    StringListIterator end();
    // Wrapper for the const iterator beginning of the QList<QString> list
    constStringListIterator begin() const;
    // Wrapper for the const iterator end of the QList<QString> list
    constStringListIterator end() const;

    // Get the QString Representation of a random 64 bit int.
    QString get();

    // Load IDs for collision checking.
    void load(const QString& id);
    void load(const StringList& list);

    // Remove the requested ID from collision checker.
    bool remove(const QString& id);

    // Clear collision checker.
    void clear();

    // Returns true if collision checker is empty.
    bool empty() const;

private:
    StringList list;
};

#endif // QRANDIDGENERATOR_H
