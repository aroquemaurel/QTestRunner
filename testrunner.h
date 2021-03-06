/* 
 * Thanks to 
 * https://marcoarena.wordpress.com/2012/06/23/increase-your-qtest-productivity
 *
 * @aroquemaurel
 */

#ifndef TESTRUNNER_H
#define TESTRUNNER_H

// Qt includes
#include <QTest>
#include <QSharedPointer>
// std includes
#include <algorithm>
#include <list>
#include <iostream>

// Test Runner allows automatic execution of tests
class TestRunner
{
public:
    static TestRunner& Instance();

    template <typename T> char RegisterTest(char *name) {
        if ( std::find_if( begin(m_tests), end(m_tests), [&name](QSharedPointer<QObject>& elem)
        { return elem->objectName() == name; }) == end(m_tests) ) {
            QSharedPointer<QObject> test(new T());
            test->setObjectName(name);
            m_tests.push_back(test);
        }
        return char(1);
    }

    int RunAll(int argc, char *argv[]);

private:
   std::list<QSharedPointer<QObject>> m_tests;
};

// Use this macro after your test declaration
#define DECLARE_TEST(className)\
    static char test_##className = TestRunner::Instance().RegisterTest<className>(#className);

// Use this macro to execute all tests
#define RUN_ALL_TESTS(argc, argv)\
    TestRunner::Instance().RunAll(argc, argv);

#endif // TESTRUNNER_H
