/*input
2
4
7
6 4
2 5 10
9 8 12 2
2 12 7
8 2
10
2
1
2 3
1
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

vector<ll> *v;
ll n,m[200][500];

ll pp(ll i,ll p)
{

	if(i==2*n-1 || p==-1||p== v[i].size())
		return 0;
	if(m[i][p])
		return m[i][p];
	ll ans = 0;

	if(i<n-1)
		ans = max(pp(i+1,p),pp(i+1,p+1));
	else
		ans = max(pp(i+1,p),pp(i+1,p-1));
	m[i][p] = v[i][p]+ans;
	return m[i][p];
}
int main()
{
	int t=1,tt;
	sc("%d",&tt);
	while(tt--)
	{
		sc("%lld",&n);
		mem(m,0);
		int l = 0;
		v = new vector<ll>[2*n-1];

		for(int i=0;i<2*n-1;i++){
			for(int j=0;j<=l;j++)
			{
				ll val; sc("%lld",&val);
				v[i].pb(val);

			}
			if(i<n-1)l++;
			else
				l--;
		}
		pf("Case %d: %lld\n",t++,pp(0,0));
	}
	return 0;
}
