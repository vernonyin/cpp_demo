#include "iostream"

using namespace std;

template<int n>
 struct   Fn{
    static const int val = Fn<n-1>::val + Fn<n-2>::val;
};

template<>
struct Fn<1>{
    static const int val = 1;
};

template<>
struct Fn<0>{
    static const int val = 1;
};

unsigned int fit_block_size(unsigned int size)
{
  unsigned int i = 10;
  size = (size>>10);
  for(; size; i++, size = (size>>1));
  return 1 << (i<10 ? 10 : i);
}

int main(){
  cout<<"F3="<<Fn<3>::val<<endl;

  cout<<"100="<<fit_block_size(100)<<endl;
  cout<<"1100="<<fit_block_size(1100)<<endl;
  cout<<"1200="<<fit_block_size(1200)<<endl;
  cout<<"13000="<<fit_block_size(13000)<<endl;

}