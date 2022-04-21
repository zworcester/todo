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


    Parser p(testring);
    p.read();


    loadTasks(p.getReadDataVector());
    form = new TaskEditorForm();
    QObject::connect(form, &TaskEditorForm::tasksSaved, this, &MainWindow::tasksChanged);

}

MainWindow::~MainWindow()
{
    delete metaScene;
    delete ui;
    delete form;
}

void MainWindow::editorButtonClicked()
{
    form->populateForms(this->tasks);
    form->show();
}

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


void MainWindow::tasksChanged(QVector<TaskCategory> tasks)
{
    loadTasks(tasks);

    return;
}
