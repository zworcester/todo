#include "serializer.h"

Serializer::Serializer()
{

}

QJsonDocument write(const QVector<TaskCategory>& taskCategories) {
    QJsonDocument theDocument;
    QJsonArray theData;
    QJsonObject mainObject;


    for (const auto& categories : taskCategories) {
        QJsonObject theCategory;
        QJsonArray qTasks;
        theCategory.insert("id", categories.getID());
        theCategory.insert("name", categories.getName());

        for (const auto& tasks : categories) {
            QJsonObject taskData;
            taskData.insert("id", tasks.getID());
            taskData.insert("name", tasks.getName());
            taskData.insert("description", tasks.getDescription());
            taskData.insert("checked", tasks.isChecked());
            qTasks.push_back(taskData);
        }

        theCategory.insert("tasks", qTasks);

        theData.push_back(theCategory);
        mainObject.insert("categories", theData);
        theDocument.setObject(mainObject);
    }
    return theDocument;
}
