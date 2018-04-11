#include<stdio.h>

int main()
{
   
int  a[3][3],*p,i;
   
p=&a[0][0];
   
for(i=0;i<9;i++)
      
p[i]=i;
   
for(i=0;i<3;i++)
     for(int j=0;j<3;j++) 
printf("%d \n",a[i][j]);

return 0;
}
