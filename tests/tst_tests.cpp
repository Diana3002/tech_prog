#include <QtTest>
#include "../ProgProject-main/functioforserver.h"

class tests : public QObject
{
    Q_OBJECT

public:
    tests();
    ~tests();

private slots:
    void test_case1();
    void test_case2();
};

tests::tests()
{

}

tests::~tests()
{

}

void tests::test_case1()
{
    QVector<QPair<QString, QString>> input = {{"3","4"}, {"4", "5"}, {"5", "6"}, {"4", "6"}, {"2", "4"}};
    QString output = "4564";
    QVERIFY(solver_task3(input, output)==true);
}

void tests::test_case2()
{
    QVector<QPair<QString, QString>> input = {{"3","4"}, {"4", "5"}, {"5", "6"}, {"4", "6"}, {"2", "4"}, {"2", "5"}};
    QString output = "2452";
    QVERIFY(solver_task3(input, output)==true);
}

QTEST_APPLESS_MAIN(tests)

#include "tst_tests.moc"
