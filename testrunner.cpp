#include "testrunner.h"

TestRunner &TestRunner::Instance() {
    static TestRunner instance;
    return instance;
}

int TestRunner::RunAll(int argc, char *argv[]) {
    int errorCode = 0;
    std::for_each( begin(m_tests), end(m_tests), [&] (QSharedPointer<QObject>& test) {
        errorCode |= QTest::qExec(test.data(), argc, argv);
        std::cout << std::endl;
    } );

    return errorCode;
}


template <typename T> char TestRunner::RegisterTest(char *name) {
    if ( std::find_if( begin(m_tests), end(m_tests), [&name](QSharedPointer<QObject>& elem)
    { return elem->objectName() == name; }) == end(m_tests) ) {
        QSharedPointer<QObject> test(new T());
        test->setObjectName(name);
        m_tests.push_back(test);
    }
    return char(1);
}
