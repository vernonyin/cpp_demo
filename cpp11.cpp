#include <iostream>
using namespace std;

class Test
{
public:
    void TestWork(int index)
    {
        std::cout<< "TestWork 1" << std::endl;
    }
    void TestWork(int * index)
    {
        std::cout <<"TestWork 2"  <<std::endl;
    }
};
 
int main()
{
    Test test;
//build ambiguous
  //  test.TestWork(NULL);
    test.TestWork(nullptr);
 int numbers[] = { 1,2,3,4,5 };
    std::cout<< "numbers:"  <<std::endl;
    for (auto number : numbers)
    {
        std::cout <<number<< std::endl;
    }
}
