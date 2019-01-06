#include <bits/stdc++.h>
using namespace std;

int arr[100];

void printLIS(int dp[],int n)
{
    int temp = *max_element(dp,dp+n);
    vector<int>v;
    for(int i=n-1;i>=0;i--)
     if(dp[i]==temp)
    {
        v.push_back(i);
        temp--;
    }
    reverse(v.begin(),v.end());
    for(int i : v)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int LIS(int n)
{
    int dp[n];
    for(int i=0;i<=n;i++)dp[i]=1;

    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
            if(arr[j]<arr[i])
                dp[i] = max(dp[i],dp[j]+1);
        //cout<<dp[i]<<" ";
    }
    //sort(dp,dp+n+1);
    printLIS(dp,n);
    return *max_element(dp,dp+n);
}



int main()
{
   int n;
   cin >> n;
   for(int i=0;i<n;i++)cin>>arr[i];
    cout<<LIS(n)<<endl;
    return 0;
}
