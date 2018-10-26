
#include <iostream>
using namespace std;

class Point{
public:
	Point(float xval);
	virtual ~Point();

	float x() const;
	static int PointCount();

protected:
	virtual ostream& print(ostream &os) const;

	float _x;
	static int _point_count;
};

Point::Point(float xval){
 _x = xval;
};


Point::~Point(){

}

//consts 要加进来，不能省略
float Point::x() const{
	return _x;
}

ostream& Point::print(ostream &os) const{
	os<<_x<<endl;
	return os;
}


/*
//是因为没有实现
Undefined symbols for architecture x86_64:
  "Point::Point(float)", referenced from:
      _main in object_book.cpp.o
  "Point::~Point()", referenced from:
      _main in object_book.cpp.o
ld: symbol(s) not found for architecture x86_64

*/
int main(){
	Point p(4.0);
	//
	cout<<sizeof(class Point)<<endl;
	cout<<sizeof(p)<<endl;
}