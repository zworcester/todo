/* ----------------------------------------------------
 * Filename: mainwindow.cpp
 * Project: Todo
 * Licence: GPL
 * ----------------------------------------------------
 * Date of Last Edit:
 * APRIL 22nd, 2022
 * Last Edit: Taylor Ramsay (T_Ramsay0@fullerton.edu)
 * Editors:
 *  - Zachary Worcester
 *  - Taylor Ramsay
 * ----------------------------------------------------
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString testring ="{\n \"categories\": [\n {\n \"id\" : \"C1\",\n  \"name\" : \"category 1\",\n  \"tasks\" : [\n {\n  \"id\" : \"T1.1\", \n \"name\" : \"task 1.1\", \n \"description\" : \"\", \n \"checked\" : false \n }, \n {\n \"id\" : \"T1.2\", \n \"name\" : \"task 1.2\", \n \"description\" : \"Test Task 1.2\", \n \"checked\" : false \n }, \n { \n \"id\" : \"T1.3\", \n \"name\" : \"task 1.3\", \n  \"description\" : \"\", \n \"checked\" : true \n   } \n ] \n },\n {\n \"id\" : \"C2\", \n \"name\" : \"category 2\", \n \"tasks\" : [ \n { \n \"id\" : \"T2.1\", \n \"name\" : \"task 2.1\", \n \"description\" : \"\", \n  \"checked\" : false \n },\n {\n \"id\" : \"T2.2\",\n \"name\" : \"task 2.2\",\n \"description\" : \"Test Task 2.2\",\n \"checked\" : false\n }\n ]\n },\n  {\n \"id\" : \"C3\",\n \"name\" : \"category 3\",\n \"tasks\" : [\n ]\n },\n {\n \"id\" : \"C4\",\n \"name\" : \"category 4\",\n \"tasks\" : [\n  {\n  \"id\" : \"T4.1\",\n \"name\" : \"task 4.1\",\n \"description\" : \"\",\n \"checked\" : false\n  },\n  {\n \"id\" : \"T4.2\",\n \"name\" : \"task 4.2\",\n \"description\" : \"Test Task 4.2\",\n  \"checked\" : false\n   },\n   {\n  \"id\" : \"T4.3\", \n \"name\" : \"task 4.3\", \n \"description\" : \"\", \n \"checked\" : true \n },\n  {\n  \"id\" : \"T4.4\",\n \"name\" : \"\",\n  \"description\" : \"\",\n \"checked\" : true\n},\n {\n\"id\" : \"T4.5\",\n\"name\" : \"task 4.5\",\n\"description\" : \"Test Task 4.5\",\n \"checked\" : true \n }\n ]\n }\n  ]\n}";

#define DEBUG 1
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , metaScene(new QGraphicsScene)
    , form(nullptr)
{
    ui->setupUi(this);
    QObject::connect(ui->editorButton, &QPushButton::clicked, this, &MainWindow::editorButtonClicked);
    QObject::connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::quitActionTriggered);
    QObject::connect(ui->actionNew, &QAction::triggered, this, &MainWindow::newActionTriggered);
    QObject::connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openActionTriggered);
    QObject::connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveActionTriggered);

    form = new TaskEditorForm();
    QObject::connect(form, &TaskEditorForm::tasksSaved, this, &MainWindow::tasksChanged);

}

MainWindow::~MainWindow()
{
    delete metaScene;
    delete ui;
    delete form;
}

// Listener for edit button press
void MainWindow::editorButtonClicked()
{
    form->populateForms(this->tasks);
    form->show();
}

// Loads Tasks from a Qvector
void MainWindow::loadTasks(QVector<TaskCategory> newTasks)
{
    this->tasks = newTasks;
    metaScene->clear();
    TaskGraphicsWidget* taskGraphics = new TaskGraphicsWidget;
    taskGraphics->setTasks(tasks);

    metaScene->addItem(taskGraphics);

    ui->graphicsView->setScene(metaScene);
    ui->graphicsView->show();

    return;
}

// Listener for Task edit button press
void MainWindow::tasksChanged(QVector<TaskCategory> tasks)
{
    loadTasks(tasks);

    return;
}

// Listener for file menu quit trigger
void MainWindow::quitActionTriggered()
{
    QApplication::quit();
}

// Listener for file menu new trigger
void MainWindow::newActionTriggered()
{
    if (!this->tasks.empty())
    {
        QMessageBox::StandardButton answer = QMessageBox::question(this, "Are You Sure?", "Would you like to create a new file?\nAny unsaved changes will be discarded.");

        if (answer == QMessageBox::Yes)
        {
            loadTasks(QVector<TaskCategory>());
        }
    }
}

// Listener for file menu open trigger
void MainWindow::openActionTriggered()
{
    QFileDialog fDO(this, "Open a Todo List", QDir::currentPath(), "JSON files (*.json)");
    fDO.setFileMode(QFileDialog::ExistingFile);
    fDO.setAcceptMode(QFileDialog::AcceptOpen);

    if (fDO.exec())
    {
        QFile f(fDO.selectedFiles().at(0));

        if (!f.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, "Error", "The file could not be opened.");
        }

        QString json;

        while (!f.atEnd())
        {
            json += f.readLine() + '\n';
        }

        Parser p(json);
        p.read();

        loadTasks(p.getReadDataVector());
    }

}

// Listener for file menu save trigger
void MainWindow::saveActionTriggered()
{
    QFileDialog fDO(this, "Save a Todo List", QDir::currentPath(), "JSON file (*.json)");
    fDO.setFileMode(QFileDialog::AnyFile);
    fDO.setAcceptMode(QFileDialog::AcceptSave);

    if (fDO.exec())
    {
        QFile f(fDO.selectedFiles().at(0));

        if (!f.open(QIODevice::WriteOnly))
        {
            QMessageBox::warning(this, "Error", "The file could not be made.");
        }

        Serializer s;
        QJsonDocument d = s.write(tasks);
        f.write(d.toJson());
    }

}
