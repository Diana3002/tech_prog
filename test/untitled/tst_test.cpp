#include <QtTest>
#include "../../Server/mytcpserver.h"
// add necessary includes here

class test : public QObject
{
    Q_OBJECT

public:
    test();
    ~test();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();
    void test_case5();
    void test_case6();
    void test_case7();
    void test_case8();
    void test_case9();
    void test_case10();



};

test::test()
{
}

test::~test()
{

}

void test::test_case1()
{
    std::vector<int> input = {1, 3, 5, 3, 1};
    std::vector<int> output = {3, 1, 1, 3, 5};
    int step = 2;
    heap_sort(input, input.size(), step);
    QVERIFY(input == output);
}

void test::test_case2(){
    std::vector<int> input = {5, 6, 4, 2, 1, 3};
    std::vector<int> output = {2, 1, 3, 4, 5, 6};
    int step = 4;
    heap_sort(input, input.size(), step);
    QVERIFY(input == output);
}

void test::test_case3(){
    std::vector<int> input = {5, 12, 434, 32, 53};
    std::vector<int> output = {53, 32, 5, 12, 434};
    int step = 1;
    heap_sort(input, input.size(), step);
    QVERIFY(input == output);
}
void test::test_case4(){
    std::vector<int> input = {1, 89, 43, 3, 3, 5, 2, 12, 93};
    std::vector<int> output = {89, 12, 43, 3, 3, 5, 2, 1, 93};
    int step = 1;
    heap_sort(input, input.size(), step);
    QVERIFY(input == output);
}

void test::test_case5(){
    std::vector<int> input = {56, 89, 13, 43, 54, 32, 54, 32};
    std::vector<int> output = {32, 13, 32, 43, 54, 54, 56, 89};
    int step = 6;
    heap_sort(input, input.size(), step);
    QVERIFY(input == output);
}

void test::test_case6(){
    std::vector<int> input = {43, 23, 12, 11, 10, 87, 65, 32};
    std::vector<int> output = {65, 32, 43, 23, 10, 12, 11, 87};
    int step = 1;
    heap_sort(input, input.size(), step);
    QVERIFY(input == output);
}

void test::test_case7(){
    std::vector<int> input = {11, 10, 11, 213, 21, 67, 25, 50, 75, 100};
    std::vector<int> output = {100, 75, 67, 50, 21, 11, 25, 11, 10, 213};
    int step = 1;
    heap_sort(input, input.size(), step);
    QVERIFY(input == output);
}

void test::test_case8(){
    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> output = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int step = 9;
    heap_sort(input, input.size(), step);
    QVERIFY(input == output);
}

void test::test_case9(){
    std::vector<int> input = {89, 87, 35, 32};
    std::vector<int> output = {35, 32, 87, 89};
    int step = 2;
    heap_sort(input, input.size(), step);
    QVERIFY(input == output);
}

void test::test_case10(){
    std::vector<int> input = {25, 125, 625};
    std::vector<int> output = {25, 125, 625};
    int step = 4;
    heap_sort(input, input.size(), step);
    QVERIFY(input == output);
}




QTEST_APPLESS_MAIN(test)

#include "tst_test.moc"
