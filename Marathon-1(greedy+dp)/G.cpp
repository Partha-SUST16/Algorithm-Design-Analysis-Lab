/*input
3
AAAA
ABCDEFGH
QWERTYTREWQWERT
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
 #define fast ios_base::sync_with_stdio(0);cin.tie(NULL)
 #define pf printf
 #define sc scanf
 #define ll long long
 #define pii pair<int,int>
 #define pll pair<ll,ll>
 #define all(v) v.begin(),v.end()
 #define debug(x)  cout<<#x"="<<(x)<<endl
 #define pb push_back


 using namespace std;


    // moves

//int dx[]= {0,0,1,-1};/*4 side move*/
//int dy[]= {-1,1,0,0};/*4 side move*/
//int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
//int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
//int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
//int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/


 //big_mod

//ll bigmod(ll a,ll b,ll m)
//{if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a)% m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1ll;}
//ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
//ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
//ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}

const int inf = 1<<19;
int dp[1111];
int pali[1111][1111];

bool is_p(const string &s,int b,int e)//if from b to e is pallindrom
{
	if(b>=e)return true;
	if(pali[b][e]!=-1)
		return pali[b][e];
	return pali[b][e] = (s[b]==s[e]) && is_p(s,b+1,e-1);
}
// minimum number of palindrome partitions starting at b
int pp(const string &s,int b)
{
	if(b==s.length()) return 0;
	if(dp[b]!=-1)
		return dp[b];
	int best = inf;

	for(int i=b;i<s.length();i++)
		if(is_p(s,b,i))
			best = min(best,1+pp(s,i+1));
	return dp[b] = best;
}
int main()
{
	int t=1,tt; sc("%d",&tt);
	while(tt--)
	{
		string s; cin >> s;
		pf("Case %d: ",t++);
		mem(dp,-1);
		mem(pali,-1);
		pf("%d\n",pp(s,0));
	}
	return 0;
}
