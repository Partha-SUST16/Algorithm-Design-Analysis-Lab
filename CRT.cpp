#include<bits/stdc++.h>
using namespace std;

int extgcd(int a,int b,int *x,int *y)
{
    if(a==0){
        *x = 0,*y = 1;
        return b;
    }
    int x1,y1;
    int gcd = extgcd(b%a,a,&x1,&y1);
    *x = y1-(b/a)*x1;
    *y = x1;
    return gcd;
}
int modinv(int a,int m){
    int x,y;
    int g = extgcd(a,m,&x,&y);
    if(x<0)
        return (x+m);
}

int CRT(int num[],int rem[],int k)
{
    int prod = 1;
    for(int i=0;i<k;i++)
        prod *= num[i];
    int res = 0;

    for(int i=0;i<k;i++)
    {
        int pp = prod/num[i];
        res += (rem[i]*modinv(pp,num[i])*pp)%prod;
        res%=prod;
    }
    return res%prod;
}
int main()
{
     int num[] = {3, 4, 5};
    int rem[] = {2, 3, 1};
    int k = sizeof(num)/sizeof(num[0]);
    cout << "x is " << CRT(num, rem, k);
}
