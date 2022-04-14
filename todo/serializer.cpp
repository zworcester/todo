#include "serializer.h"

Serializer::Serializer()
{

}

QJsonDocument write(const QVector<TaskCategory>& taskCategories) {
    QJsonDocument jsonDocument;
    QJsonArray jsonData;
    QJsonObject mainObject;


    for (const auto& categories : taskCategories) {
        QJsonObject jsonCategory;
        QJsonArray qTasks;
        jsonCategory.insert("id", categories.getID());
        jsonCategory.insert("name", categories.getName());

        for (const auto& tasks : categories) {
            QJsonObject taskData;
            taskData.insert("id", tasks.getID());
            taskData.insert("name", tasks.getName());
            taskData.insert("description", tasks.getDescription());
            taskData.insert("checked", tasks.isChecked());
            qTasks.push_back(taskData);
        }

        jsonCategory.insert("tasks", qTasks);

        jsonData.push_back(jsonCategory);
        mainObject.insert("categories", jsonData);
        jsonDocument.setObject(mainObject);
    }
    return jsonDocument;
}
