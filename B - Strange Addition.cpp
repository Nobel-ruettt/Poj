#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
using namespace std;
/***template***/
#define ll                   long long
#define LL                   long long
#define dd                   double
#define scl(n)               scanf("%lld",&n)
#define sl(n)                scanf("%lld",&n)
#define scd(n)               scanf("%lf",&n)
#define pi                   pair<ll,ll>
#define pll                  pair<ll,ll>
#define pb                   push_back
#define mp                   make_pair
#define uu                   first
#define vv                   second
#define fr                   first
#define sc                   second
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define FOOR(i,a,b)          for(ll i=a;i<=b;i++)
#define LOP(i,a,b)           for(ll i=a;i<b;i++)
#define sorted(s)            sort(s.begin(),s.end())
#define sortedd(s)           sort(s.begin(),s.end(),cmp)
#define reversed(s)          reverse(s.begin(),s.end())
#define contains(a,b)        (find((a).begin(), (a).end(), (b)) != (a).end())
#define MAXN                 100005
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  9000000000000000
#define INF                  (1LL<<62)
#define mstt(a,b)            memset((a),(b),sizeof (a))
#define sz(x)                (ll)x.size()
ll Set(ll n,ll pos)
{
    return n=n|(1LL<<pos);
}
ll reset(ll n,ll pos)
{
    return n=n&~(1LL<<pos);
}
bool check(ll n,ll pos)
{
    return (bool)(n&(1LL<<pos));
}
ll mul(ll a,ll b)
{
    ll c;
    c = (a%mod * b%mod)%mod;
    return c;
}
ll add(ll a,ll b)
{
    ll c;
    c = (a%mod + b%mod)%mod;
    return c;
}
ll sub(ll a,ll b)
{
    ll c;
    c = ((a%mod - b%mod)%mod + mod)%mod;
    return c;
}
ll power(ll x,ll y,ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
ll s2, s1, t2, t1;
ll egcd(ll a, ll b)
{
    ll temp;
    if (a%b == 0)
    {
        return s1;
    }
    temp = s2 - (a/b)*s1;
    s2 = s1;
    s1 = temp;
    temp = t2 - (a/b)*t1;
    t2 = t1;
    t1 = temp;
    return egcd(b, a%b);
}
/***template***/
ll n;
ll arr[110];
ll bit[110];
ll dp[110][1<<4];
ll dir[110][1<<4];
ll solve(ll pos,ll mask)
{
    if(pos>n)
    {
        return 0;
    }
    if(dp[pos][mask]!=-1)
    {
        return dp[pos][mask];
    }
    ll ans=0;
    bool f=0;
    LOOP(i,3)
    {
        if(check(mask,i)==1)
        {
            if(check(bit[pos],i)==1)
            {
                f=1;
                break;
            }
        }
    }
    if(f==0)
    {
        if(ans<=(1+solve(pos+1,mask|bit[pos])))
        {
            ans=1+solve(pos+1,mask|bit[pos]);
            dir[pos][mask]=1;
        }
    }
    if(solve(pos+1,mask)>=ans)
    {
        ans=solve(pos+1,mask);
        dir[pos][mask]=2;
    }
    return dp[pos][mask]=ans;
}
void dfs(ll pos,ll mask)
{
    if(dir[pos][mask]==1)
    {
        cout<<arr[pos]<<" ";
        dfs(pos+1,mask|bit[pos]);
    }
    else if(dir[pos][mask]==2)
    {
        dfs(pos+1,mask);
    }
}
int main()
{
    scl(n);
    FOR(i,n)
    {
        scl(arr[i]);
        ll num=arr[i];
        for(ll j=0;j<3;j++)
        {
            if(num%10>0)
            {
                bit[i]=Set(bit[i],j);
            }
            num/=10;
        }
    }
    memset(dp,-1,sizeof dp);
    ll ans=solve(1,0);
    cout<<ans<<endl;
    dfs(1,0);
    return 0;
}
