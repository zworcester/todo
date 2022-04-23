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


    QJsonDocument write(const QVector<TaskCategory>& taskCategories);
};

#endif // SERIALIZER_H



//alrighty friends I just made a push to main that implements two classes, Task and TaskCategory.

//basically I think the program will be in perfect working order if I write the UI, one of you writes a class that is the parser, and the other writes the class that is the serializer.

//The parser needs to read a JSON document and create a QVector<TaskCategory> out of it. TaskCategory already has all of the functions for adding tasks to it using
//TaskCategory::append(Task), and the UI will handle actually getting the JSON document, so all the parser needs to do is read a JSON document already loaded from the
//disk and convert it to a QVector<TaskCategory>. For example, you might write a function in the parser with the following signature: QVector<TaskCategory> read(QJsonDocument q);

//The serializer as you may know does the opposite. It takes a QVector<TaskCategory> and converts it to a representation of a JSON document. Again, UI will handle actually
//saving the file to the disk, so the serializer might have a function with the signature: QJsonDocument write(QVector<TaskCategory> taskCategories);
