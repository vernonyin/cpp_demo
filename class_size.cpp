#include <iostream>

class A{
    public:
        long a;
};
class B : public A {
    public:
        long b;
};
void seta(B* data, int idx) {
    data[idx].a = 2;
}
int main(int argc, char *argv[]) {
	double x =5.96894;
	std::cout<<"int(x)="<<(int)x<<std::endl;
	std::cout<<"sizeof(A)="<<sizeof(A)<<std::endl;	
	std::cout<<"sizeof(B)="<<sizeof(class B)<<std::endl;	
    B data[4];
    for(int i=0; i<4; ++i){
        data[i].a = 1;
        data[i].b = 1;
        seta(data, i);
    }
    for(int i=0; i<4; ++i){
         std::cout << data[i].a << data[i].b;
    }
	B bb;
	seta(&bb,0);
	std::cout<<"bb.a= "<<bb.a<<",bb.b"<<bb.b<<std::endl;
    return 0;
}
