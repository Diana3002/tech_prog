#include <QtTest>

// add necessary includes here
#include <../Client/task1.cpp>
#include <QWidget>

class test_parinova : public QObject
{
    Q_OBJECT

public:
    test_parinova();
    ~test_parinova();

private slots:
    void test_case1();

};

test_parinova::test_parinova()
{
    QVector<QVector<int>> G = {{1,1,0,0},{1,0,1,1},{0,0,0,1},{0,1,1,0}};
    QVERIFY(solve(G) = "|0 1 1 1|1 0 1 0|1 1 0 1|1 0 1 0|");
}

test_parinova::~test_parinova()
{

}

void test_parinova::test_case1()
{

}

QTEST_APPLESS_MAIN(test_parinova)

#include "tst_test_parinova.moc"
