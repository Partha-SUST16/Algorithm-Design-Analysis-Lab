#include<bits/stdc++.h>
using namespace std;

int tab[10][10];
vector<int>v;

int MCM(int i,int j)
{
    if(i==j)
        return 0;

    else
    {
        int mi = INT_MAX;

        for(int k=i; k<j; k++)
        {
            if(tab[i][k]==0)
                tab[i][k] = MCM(i,k);
            if(tab[k+1][j]==0)
                tab[k+1][j] = MCM(k+1,j);
            int sum = tab[i][k] + tab[k+1][j] + v[i]*v[j]*v[k];
            if(sum<mi)
                mi = sum;
        }
        tab[i][j] = mi;
        return mi;
    }
}
int main()
{
    int n;
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    cout<<MCM(0,n-1);
}
