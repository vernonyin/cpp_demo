
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int MAX = 1001;
int MaxLen[MAX][MAX]; //最长公共子序列，动态规划求法

int main(){
	int a=1;
	int b=2;
	int t=++a+b*++a+b;
    string s="DabcDeFghiJKLmn";
    cout<<s<<endl;
    int length=s.size();
    for(int ii=0;ii<length;ii++){
        if(s[ii] <'a' || s[ii] > 'z'){
            int jj=ii;
            char min;
            for(jj=ii;jj<length;jj++){
                //找到a-z
				cout<<"----ii="<<jj<<",s[jj]="<<s[jj]<<endl;
                if(s[jj] >='a' && s[jj] <= 'z'){
					cout<<"====="<<jj<<endl;
                    min = s[jj];
                    break;
                }
            }
			cout<<"ii="<<ii<<",jj="<<jj<<",min="<<min<<endl;
            if(jj<length){
                int kk=0;
                for(kk=jj;kk>ii;kk--){
                    s[kk] = s[kk-1];
                }
                s[kk] = min;
            }
        }
		cout<<s<<endl;
    }
     cout<<s<<endl;
    return 0;
}
