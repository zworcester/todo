#ifndef BASICTEST_H
#define BASICTEST_H
#include <QObject>
#include <QTest>


class BasicTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase()
    {
        qDebug("Initiation of test.");
    }

    bool testCondition()
    {
        return true;
    }

    void testOne()
    {
        QVERIFY(testCondition());
    }

    void cleanupTestCase()
    {
        qDebug("Test complete.");
    }
};

#endif // BASICTEST_H
