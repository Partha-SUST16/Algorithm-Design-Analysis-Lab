/*input
 9
1 2 1 3 2 2 2 2 3
*/
 #include <iostream>
 #include <vector>
 #include <cmath>
 #include <set>
 #include <queue>
 #include <map>
 #include <cstdio>
 #include <cstring>
 #include <string>
 #include <stack>
 #include <algorithm>
 #include <limits.h>
 #include <bits/stdc++.h>
 #define fw(x) freopen("x.txt","w",stdout)
 #define For(i,a,b,c) for(int i = a;i < b;i+=c)
 #define REP(i,n) for(int i = 0;i < n;++i)
 #define mem(a,s) memset(a,s,sizeof a)
 #define fast ios_base::sync_with_stdio(0)
 #define pf printf
 #define sc scanf
 #define ll long long
 #define debug(x)  cout<<#x"="<<(x)<<endl
 using namespace std;


    // moves

//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*night move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*night move*/


 //big_mod

//ll bigmod(ll a,ll b,ll m)
//{if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a)% m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

ll dp[100050];
ll a[100050];
ll funck(int n)
{
    if(n<=0)return 0;
    //if(n==1)return 1;
    if(dp[n]!=-1)return dp[n];
    dp[n]=0;
    return dp[n]=max(funck(n-1),funck(n-2)+a[n]*n);
}
int main()
{
    mem(dp,-1);
    int n;
    cin >> n;
    int temp = 0;
    for(int i=0,x;i<n;i++)
    {
        cin >> x;
        a[x]++;
        temp = max(temp,x);
    }
    cout<<funck(temp)<<endl;
    return 0;
}
