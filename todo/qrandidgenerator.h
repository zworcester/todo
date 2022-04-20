#ifndef QRANDIDGENERATOR_H
#define QRANDIDGENERATOR_H

#include <QList>
#include <QRandomGenerator64>

#include "baseidgenerator.h"

typedef QList<QString> StringList;
typedef StringList::Iterator StringListIterator;
typedef StringList::ConstIterator constStringListIterator;

class QRandIDGenerator : public BaseIDGenerator
{
public:
    QRandIDGenerator() {}
    QRandIDGenerator(const StringList& loadFirst);

    StringListIterator begin();
    StringListIterator end();
    constStringListIterator begin() const;
    constStringListIterator end() const;

    virtual QString get();

    void load(const QString& id);
    void load(const StringList& list);
    bool remove(const QString& id);

    void clear();
    bool empty() const;

private:
    StringList list;
};

#endif // QRANDIDGENERATOR_H
