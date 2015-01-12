#include "testrunner.h"
template <class T>
class TestAdder
{
public:
 TestAdder(const QString& name)
 {
   auto newTest = new T();
   newTest->setObjectName(name);
   TestRunner::Instance().RegisterTest(newTest);
 }
};
