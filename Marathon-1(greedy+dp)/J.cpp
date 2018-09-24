/*input
3

USA

USSR

LAILI

MAJNU

SHAHJAHAN

MOMTAJ
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
 #define vii vector<int>
 #define vll vector<ll>
 #define vss vector<string>
 #define vpii vector<pii>
 #define vpll vector<pll>
 #define all(v) v.begin(),v.end()
 #define debug(x)  cout<<#x"="<<(x)<<endl
 #define pb push_back
 #define nd '\n'


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
//ll setBit1(ll num, int idx) {return num or (1ll<<idx);}
//ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
//ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}

const int mod = 1000000007;
const int N = 300005;

ll dp1[50][50],dp2[50][50][70];
string s1,s2;
ll ans1,ans2;

ll funck(int i,int j)//lcs
{
	if(i>=s1.length() or j>=s2.length())return 0;

	if(dp1[i][j]!=-1)return dp1[i][j];

	dp1[i][j]=0;
	if(s1[i]==s2[j])
		dp1[i][j] = funck(i+1,j+1)+1;
	else
		dp1[i][j] = max(funck(i+1,j),funck(i,j+1));
	return dp1[i][j];
}

ll funck2(int i,int j,int c)
{
	if(i>=s1.length())
	{
		c+=s2.length()-j;
		if(c==ans1)return 1;
		return 0;
	}
	if(j>=s2.length())
	{
		c+=s1.length()-i;
		if(c==ans1)
			return 1;
		return 0;
	}
	if(dp2[i][j][c]!=-1)return dp2[i][j][c];
	dp2[i][j][c]=0;
	if(s1[i]==s2[j])
		dp2[i][j][c]=funck2(i+1,j+1,c+1);
	else
	{
		dp2[i][j][c]+=funck2(i+1,j,c+1);
		dp2[i][j][c]+=funck2(i,j+1,c+1);
	}
	return dp2[i][j][c];
}
int main()
{
	int t=1,tt;
	sc("%d",&tt);
	while(tt--)
	{
		mem(dp1,-1);
		mem(dp2,-1);
		cin>>s1>>s2;
		ans1=s1.length()+s2.length()-funck(0,0);
		//ans2=s2.length();
		ans2=funck2(0,0,0);
		pf("Case %d: %lld %lld\n",t++,ans1,ans2);

	}
	return 0;
}
