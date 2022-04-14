#include "mainwindow.h"
#include "parser.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "todo_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    //used these strings to test out parser; delete later
//    QString str="{\"name\" : \"John\" }";
//    QString jstr0="{ \"categories\" : [ ]}";
//    QString jstr1="{ \"categories\" : [ {\"id\" : \"C1\", \"name\" : \"Category 1\",\"tasks\" : [{\"id\" : \"T1.1\", \"name\" : \"Task 1.1\", \"description\" : \"...\", \"checked\" : false}]}]}";
//    QString jstr3="{\n \"categories\": [\n {\n \"id\" : \"C1\",\n  \"name\" : \"category 1\",\n  \"tasks\" : [\n {\n  \"id\" : \"T1.1\", \n \"name\" : \"task 1.1\", \n \"description\" : \"\", \n \"checked\" : false \n }, \n {\n \"id\" : \"T1.2\", \n \"name\" : \"task 1.2\", \n \"description\" : \"Test Task 1.2\", \n \"checked\" : false \n }, \n { \n \"id\" : \"T1.3\", \n \"name\" : \"task 1.3\", \n  \"description\" : \"\", \n \"checked\" : true \n   } \n ] \n },\n {\n \"id\" : \"C2\", \n \"name\" : \"category 2\", \n \"tasks\" : [ \n { \n \"id\" : \"T2.1\", \n \"name\" : \"task 2.1\", \n \"description\" : \"\", \n  \"checked\" : false \n },\n {\n \"id\" : \"T2.2\",\n \"name\" : \"task 2.2\",\n \"description\" : \"Test Task 2.2\",\n \"checked\" : false\n }\n ]\n },\n  {\n \"id\" : \"C3\",\n \"name\" : \"category 3\",\n \"tasks\" : [\n ]\n },\n {\n \"id\" : \"C4\",\n \"name\" : \"category 4\",\n \"tasks\" : [\n  {\n  \"id\" : \"T4.1\",\n \"name\" : \"task 4.1\",\n \"description\" : \"\",\n \"checked\" : false\n  },\n  {\n \"id\" : \"T4.2\",\n \"name\" : \"task 4.2\",\n \"description\" : \"Test Task 4.2\",\n  \"checked\" : false\n   },\n   {\n  \"id\" : \"T4.3\", \n \"name\" : \"task 4.3\", \n \"description\" : \"\", \n \"checked\" : true \n },\n  {\n  \"id\" : \"T4.4\",\n \"name\" : \"\",\n  \"description\" : \"\",\n \"checked\" : true\n},\n {\n\"id\" : \"T4.5\",\n\"name\" : \"task 4.5\",\n\"description\" : \"Test Task 4.5\",\n \"checked\" : true \n }\n ]\n }\n  ]\n}";
//    Parser p(jstr3);
//    p.read();

    MainWindow w;
    w.show();
    return a.exec();
}
