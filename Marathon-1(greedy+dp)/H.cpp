/*input
4

1 10

100 1

1 1000

1 10000
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

int len;
int digit[20];
ll dp[17][17][2][2][2];

void toDigit(ll x)
{
	len = 0;
	if(x==0)
		digit[len++] = 0;
	while(x)
		digit[len++]=(x%10),x/=10;
	reverse(digit,digit+len);
}

ll  digitDP(int pos, bool noLimitOfPrvPos,bool isStart,int backPos, bool isBig)
{
    if(pos > backPos)
    {
        if(!noLimitOfPrvPos && isBig)return 0;
        return 1;
    }

    if(dp[pos][backPos][noLimitOfPrvPos][isStart][isBig] != -1)
        return dp[pos][backPos][noLimitOfPrvPos][isStart][isBig];

    int limit;
    if(noLimitOfPrvPos == true)limit = 9;
    else limit = digit[pos];

    ll ret = 0;
    for(int i=0;i<=limit;i++)
    {
        if(isStart == 0 && i == 0)
        {
            ret += digitDP(pos+1,noLimitOfPrvPos || i<digit[pos],0, backPos,isBig);
        }
        else if(pos == backPos)
        {
            ret += digitDP(pos+1,noLimitOfPrvPos || i<digit[pos],isStart | i > 0, backPos,isBig);
        }
        else
        {
            if(i == digit[backPos])
            {
                ret += digitDP(pos+1,noLimitOfPrvPos || i<digit[pos],isStart | i > 0,backPos-1,isBig);
                continue;
            }

            ret += digitDP(pos+1,noLimitOfPrvPos || i<digit[pos],isStart | i > 0,backPos-1,i > digit[backPos]);
        }
    }
    dp[pos][backPos][noLimitOfPrvPos][isStart][isBig] = ret;
    return ret;
}
ll getAns(ll x)
{
	if(x<0)return 0;
	if(x<10)return x+1;
	mem(dp,-1);
	toDigit(x);
	return digitDP(0,0,0,len-1,0);
}
int main()
{
    int t=1,tt;
	sc("%d",&tt);
	while(tt--)
	{
		ll a,b;
		sc("%lld%lld",&a,&b);
		if(a>b)
			swap(a,b);
		pf("Case %d: %lld\n",t++,(getAns(b)-getAns(a-1)));
	}
    return 0;
}
