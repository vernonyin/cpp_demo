#include <iostream>
using namespace std;
class A
{
    char a[2];
    public:
        virtual void aa(){};
};
class B:public virtual A
{
    char b[2];
    char a[2];
    public:
        virtual void bb(){};
        virtual void aa(){};
};
class C:public virtual B
{
    char a[2];
    char b[2];
    char c[2];
    public:
        virtual void cc(){};
        virtual void aa(){};
        virtual void bb(){};
};
int main()
{
    cout<<sizeof(A)<<endl<<sizeof(B)<<endl<<sizeof(C);
  int arr[]={1,2,3,4,5,6,7};
    int *p=arr;
    *(p++)+=89;
    printf("%d,%d\n",*p,*(++p));
    return 0;
}

