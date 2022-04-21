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

    StringListIterator begin();
    StringListIterator end();
    constStringListIterator begin() const;
    constStringListIterator end() const;

    QString get();

    void load(const QString& id);
    void load(const StringList& list);
    bool remove(const QString& id);

    void clear();
    bool empty() const;

private:
    StringList list;
};

#endif // QRANDIDGENERATOR_H
