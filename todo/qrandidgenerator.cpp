#include "qrandidgenerator.h"

/*
 *         QRandIDGenerator() {}
    QRandIDGenerator(const StringList& loadFirst);

    StringListIterator begin();
    StringListIterator end();
    constStringListIterator begin() const;
    constStringListIterator end() const;

    virtual QString get();

    void load(const QString& id);
    void load(const StringList& list);
    void remove(const QString& id);

    void clear();
    bool empty();
 */


QRandIDGenerator::QRandIDGenerator(const StringList& loadFirst)
    :
      list(loadFirst)
{}

StringListIterator QRandIDGenerator::begin()
{
    return list.begin();
}

StringListIterator QRandIDGenerator::end()
{
    return list.end();
}

constStringListIterator QRandIDGenerator::begin() const
{
    return list.begin();
}

constStringListIterator QRandIDGenerator::end() const
{
    return list.end();
}

QString QRandIDGenerator::get()
{
    QString tempId;
    do
    {
        tempId = QString::number(QRandomGenerator64::global()->generate()).rightJustified(20,QLatin1Char('0'));

    }while (!list.contains(tempId));

    this->list.append(tempId);
    return tempId;
}

void QRandIDGenerator::load(const QString& id)
{
    list.append(id);
    return;
}

void QRandIDGenerator::load(const StringList& list)
{
    for (const QString& qString : list)
    {
        this->list.append(qString);
    }

    return;
}

bool QRandIDGenerator::remove(const QString& id)
{
    return this->list.removeOne(id);
}

void QRandIDGenerator::clear()
{
    this->list.clear();
}

bool QRandIDGenerator::empty() const
{
    return this->list.empty();
}
