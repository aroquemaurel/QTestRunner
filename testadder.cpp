/* 
 * Thanks to 
 * https://marcoarena.wordpress.com/2012/06/23/increase-your-qtest-productivity
 *
 * @aroquemaurel
 */

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
