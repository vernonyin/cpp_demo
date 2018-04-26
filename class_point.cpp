#include <iostream>
using namespace std;

class ClassA
{
public:
    virtual ~ ClassA(){};
    virtual void FunctionA(){};
};
class ClassB:public ClassA
{
public:
   virtual void FunctionB(){};
};
class ClassC :public ClassB
{
    public:
};

int main(){ 
ClassC aObject;
ClassA* pA=&aObject;
ClassB* pB=&aObject;
ClassC* pC=&aObject;
printf("pA=%llu\n",pA);
printf("pB=%llu\n",pB);
printf("pC=%llu\n",pC);
}
