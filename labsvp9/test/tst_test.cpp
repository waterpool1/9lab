#include <QtTest>
#include "../objects/objects.h"
// add necessary includes here

class Test : public QObject
{
    Q_OBJECT

public:
    Test();
    ~Test();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
};

Test::Test()
{

}

Test::~Test()
{

}

void Test::test_case1()
{
    Sedan sedan;
    QVERIFY(!sedan.drive(100));
    QCOMPARE(sedan.getFuelLevel(), 0);
    sedan.refuel();
    QCOMPARE(sedan.getFuelLevel(), 40000);
    QVERIFY(sedan.drive(100));
    QCOMPARE(sedan.getMilage(), 100);
    QCOMPARE(sedan.getFuelLevel(), 32000);
    QVERIFY(!sedan.drive(500));
    QCOMPARE(sedan.getMilage(), 100);
    QCOMPARE(sedan.getFuelLevel(),32000);
    sedan.refuel();
    QCOMPARE(sedan.getFuelLevel(),40000);
    QVERIFY(sedan.drive(500));
    QCOMPARE(sedan.getFuelLevel(), 0);
}
void Test::test_case2(){
    Bicycle bicycle;
    QVERIFY(bicycle.drive(0));
    QCOMPARE(bicycle.getBiMilage(), 0);
    QVERIFY(bicycle.drive(100));
    QCOMPARE(bicycle.getBiMilage(), 100);
    QVERIFY(bicycle.drive(10000));
    QCOMPARE(bicycle.getBiMilage(), 10100);
}
void Test::test_case3(){
    Route route;
    RoutePoint routepoint;
    Bus bus;
    QVERIFY(!route.run(&bus));
    routepoint.xKm = 0;
    routepoint.yKm = 0;
    routepoint.name = "tochka1";
    route.addPoint(routepoint);
    QVERIFY(!route.run(&bus));
    routepoint.xKm = 30;
    routepoint.yKm = 40;
    routepoint.name = "tochka1";
    route.addPoint(routepoint);
     QCOMPARE(bus.getFuelLevel(), 0);
    QVERIFY(route.run(&bus));
    QCOMPARE(route.getTravel(), 50);
    QCOMPARE(bus.getMilage(), 50);
    QCOMPARE(bus.getFuelLevel(), 110000);
}

QTEST_APPLESS_MAIN(Test)

#include "tst_test.moc"
