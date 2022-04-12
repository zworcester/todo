#include "serializer.h"

Serializer::Serializer()
{

}

QJsonDocument write(const QVector<TaskCategory>& taskCategories) {
    QJsonDocument theDocument;


    for (const auto& categories : taskCategories) {
        QJsonArray theCategories;

        for (const auto& tasks : categories) {
            QJsonObject theTasks;
        }

    }

    return theDocument;
}
