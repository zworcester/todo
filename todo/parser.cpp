/* ----------------------------------------------------
 * Filename: Parser.h
 * Project: Todo
 * Licence: GPL
 * ----------------------------------------------------
 * Date of Last Edit:
 * APRIL 22nd, 2022
 * Last Edit: Desirae Prather (DesiraePrather@fullerton.edu)
 * Editors:
 *  Desirae Prather (DesiraePrather@fullerton.edu)
 */
#include "parser.h"

Parser::Parser(QString jsonString)
{
    this->jsonString = jsonString;
}

// Set the jsonString value or change jsonString value
void Parser::setJsonString(QString jsonString)
{
    this->jsonString=jsonString;
} 

// Returns dataVector
QVector<TaskCategory> Parser::getReadDataVector()
{
    return dataVector;
}

// Reads jsonString and creates Tasks and TaskCategories class object
// and append them to dataVector
void Parser::read()
{
    QByteArray jsonByteArray = jsonString.toUtf8();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonByteArray);
    QJsonObject jsonObject =jsonDocument.object();
    QJsonArray jsonCategoriesArray = jsonObject["categories"].toArray();

    if (!jsonCategoriesArray.isEmpty()) {// checks to see if it is not empty
        for (QJsonValueRef&& category : jsonCategoriesArray) {
            QJsonObject jsonCategoryObject = category.toObject();
            QString categoryId=jsonCategoryObject["id"].toString();
            QString categoryName=jsonCategoryObject["name"].toString();
            QJsonArray jsonTasksArray = jsonCategoryObject["tasks"].toArray();

            TaskCategory categoryObject(categoryId, categoryName);

            if (!jsonTasksArray.isEmpty()) {// checks to see if it is not empty
                for (QJsonValueRef&& task : jsonTasksArray) {
                    QJsonObject jsonTaskObject = task.toObject();
                    QString taskId=jsonTaskObject["id"].toString();
                    QString taskName=jsonTaskObject["name"].toString();
                    QString taskDecription=jsonTaskObject["description"].toString();
                    bool taskchecked=jsonTaskObject["checked"].toBool();
                    Task taskObject(taskId,taskName,taskDecription,taskchecked);
                    categoryObject.append(taskObject);
                }
            }
            dataVector.append(categoryObject);
        }
    }
}

