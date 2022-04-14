#ifndef PARSER_H
#define PARSER_H

/* Parser is a class used to build a QVector<TaskCategory> from a json string.
 * This class is needed in order to provide the json information of saved to-do
 * lists that will be used in the window display. It contains the variables
 * jsonString and dataVector which is used to store all the read() TaskCategories.
 * It contains the functions setJsonString(QString jsonString),
 * getReadDataVector(), and read().
 */

#include <QVector>
#include <QString>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "taskcategory.h"

class Parser
{
public:
    Parser(QString jsonString="");

    // Returns dataVector
    QVector<TaskCategory> getReadDataVector();
    // Set the jsonString value or change jsonString value
    void setJsonString(QString jsonString);
    // Reads jsonString and creates Tasks and TaskCategories class object
    // and append them to dataVector
    void read();
private:
    QVector<TaskCategory> dataVector;
    QString jsonString;
};

#endif // PARSER_H
