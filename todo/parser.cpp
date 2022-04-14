#include "parser.h"

Parser::Parser(QString jsonString)
{
    this->jsonString = jsonString;
}
void Parser::setJsonString(QString jsonString){
    this->jsonString=jsonString;
}
QVector<TaskCategory> Parser::getReadDataVector(){
    return dataVector;
}
void Parser::read(){

    QByteArray jsonByteArray = jsonString.toUtf8();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonByteArray);
    QJsonObject jsonObject =jsonDocument.object();
    QJsonArray jsonCategoriesArray = jsonObject["categories"].toArray();

    qDebug()<<jsonObject;// used for debugging purposes --showing object-- delete later

    if (!jsonCategoriesArray.isEmpty()){// checks to see if it is not empty
        for (auto category : jsonCategoriesArray){
            QJsonObject jsonCategoryObject = category.toObject();
            QString categoryId=jsonCategoryObject["id"].toString();
            QString categoryName=jsonCategoryObject["name"].toString();
            QJsonArray jsonTasksArray = jsonCategoryObject["tasks"].toArray();

            TaskCategory categoryObject(categoryId, categoryName);

            if (!jsonTasksArray.isEmpty()){// checks to see if it is not empty
                for (auto task : jsonTasksArray){
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
    qDebug()<<"Length of vector";// used for debugging purposes -- delete later
    qDebug()<<dataVector.length();// used for debugging purposes --showing vector length-- delete later

}

