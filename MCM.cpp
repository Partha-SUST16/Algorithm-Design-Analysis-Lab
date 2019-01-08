#include<bits/stdc++.h>
using namespace std;

int table[10][10];
vector<int>v;

int MCM(int i, int j)
{
    if(i==j) return 0;

    else
    {
        int min = INT_MAX;

        for(int k=i;k<j;k++)
        {
            if(table[i][k]==0)
                table[i][k] = MCM(i,k);
            if(table[k+1][j]==0)
                table[k+1][j] = MCM(k+1,j);
            int sum = table[i][k] + table[k+1][j] + v[i-1]*v[j]*v[k];
            if(sum<min)
                min = sum;
        }
        table[i][j]=min;
        return min;
    }
}
int main()
{
    int n;
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    cout<<MCM(1,n-1);
}
