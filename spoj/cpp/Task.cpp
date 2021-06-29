//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2")
#include<bits/stdc++.h>
constexpr auto INF = 9223372036854775807;
typedef long long int ll;
typedef unsigned long long int ull;
 
#define endl '\n'
#define MaxN 100005
#define MOD (ll)1000000007 // prime modulo value
#define MOD2 998244353 // 2nd prime modulo value
#define all(x) x.begin(),x.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
using namespace std;
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);
 
int myrand(int mod) 
{
    return mt()%mod;
}
 
//----------------------------------------------- //
 
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}
 
//----------------------------------------------- //
 
ll power(ll x, ll y, ll mod)
{
    ll ans = 1;
 
    x = x % mod;
 
    while (y > 0)
    {
        if (y & 1)
            ans = ((ans % mod) * (x % mod)) % mod;
 
        y = y >> 1;
        x = ((x % mod) * (x % mod)) % mod;
    }
    return ans;
}
 
//----------------------------------------------- //
 
//ll f[1000005];
/*
ll ncr(ll n, ll r,ll mod)
{
    if (n < r)
    {
        return 0;
    }
    ll num = f[n];
    ll temp = (f[r] * (f[n - r])) % mod;
    ll ans = num * power(temp, mod - 2, mod);
    return (ans % mod);
}
*/
//
bool isprime(ll n)
{
    if (n == 2)
        return true;
    if (n % 2 == 0 || n == 1)
    {
        return false;
    }
    for (ll j = 3; j <= sqrt(n); j += 2)
    {
        if (n % j == 0)
        {
            return false;
        }
    }
    return true;
}
//----------------------------------------------- //
ll parent[100005],ssize[100005];
void make_set(ll u)
{
    parent[u]=u;
    ssize[u]=1;
}
ll find_set(ll u)
{
    if(parent[u]==u)return u;
    return parent[u]=find_set(parent[u]);
}
void set_union(ll u,ll v)
{
    u=find_set(u);
    v=find_set(v);
    if(u==v)return ;
    if(ssize[u]>ssize[v])
        swap(u,v);
    ssize[v]+=ssize[u];
    parent[u]=v;
 
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("inputD.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    // __int128
    /*
    f[0] = 1;
 
    for(ll i=1;i<1e6 + 1;i+=1)
    {
        f[i] = (f[i - 1] * i) % MOD;
    }
    */
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> cost(k,0);
    for(ll i=0;i<k;i+=1)cin>>cost[i];
    vector<pair<ll,pair<ll,ll>>> edges; 
    for(ll i=0;i<m;i+=1)
    {
        ll u,v,l;
        cin>>u>>v>>l;
        u-=1;v-=1;
        ll sum=0;
        for(ll j=0;j<l;j+=1)
        {
            ll temp;
            cin>>temp;
            ll add=1LL<<(temp-1);
            sum+=add;
        }
        edges.push_back({sum,{u,v}});
    }
    for(ll i=0;i<n;i+=1)make_set(i);
    sort(all(edges));
    vector<bool> used(k,false);
    ll ans=0;
    for(auto i:edges)
    {
        ll w=i.first,u=i.second.first;
        ll v=i.second.second;
        if(find_set(u)==find_set(v))continue;
        set_union(u,v);
        for(ll j=0;j<k;j+=1)
        {
            if((!used[j]) && ((1LL<<j)&w))
            {
                ans+=cost[j];
                used[j]=true;
            }
        }
    }
    if(ssize[find_set(0)]!=n)cout<<1<<endl;
    else cout<<ans<<endl;
}