#include "serializer.h"

Serializer::Serializer()
{

}

QJsonDocument write(const QVector<TaskCategory>& taskCategories) {
    QJsonDocument theDocument;
    QJsonArray theCategories;
    QJsonObject theTasks;


    for (const auto& categories : taskCategories) {

        for (const auto& tasks : categories) {

        }

    }

    return theDocument;
}
