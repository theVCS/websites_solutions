#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
 
#define maxN 1000001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
#define printpoint(p) cout << p.x << " " << p.y << " " << p.z
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
 
ll mulmod(ll a, ll b, ll c)
{
    ll x = 0, y = a % c;
    while (b > 0)
    {
        if (b % 2 == 1)
            x = (x + y) % c;
        y = (y * 2LL) % c;
        b /= 2;
    }
    return x % c;
}
 
 
ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;
 
    while (power)
    {
        if (power & 1)
            res = mulmod(res,a,m);
        a = mulmod(a,a,m);
        power >>= 1;
    }
    return res;
}
 
//for testing a 32 bit integer it is only necessary to check the first 4 prime bases: 2, 3, 5 and 7. And for testing 64 bit integer it is enough to check the first 12 prime bases: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, and 37.
 
bool isComposite(ll a, ll d, ll s, ll n)
{
    ll res = binExp(a, d, n);
 
    if (res == 1 || res == n - 1)
        return false;
 
    for (ll i = 1; i < s; i++)
    {
        res = mulmod(res,res,n);
        if (res == n - 1)return false;
    }
    
    return true;
}
 
bool millerRabin(ll n)
{
    if (n <= 4)
    {
        return (n == 2 || n == 3);
    }
 
    if(n % 2 == 0)
    {
        return false;
    }
 
    ll d = n - 1, s = 0;
 
    while (d % 2 == 0)
        d /= 2,s++;

    for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a)
            return true;
 
        if (isComposite(a, d, s, n))
            return false;
    }
 
    return true;
}
 
void solve()
{
    ll n;
    cin >> n;
 
    if(millerRabin(n))
    {
        cout<<n<<" is a prime"<<endl;
    }
    else
    {
        cout<<n<<" is not a prime"<<endl;
    }
}
 
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");
 
    // filptr >> input;
    // outpter << output;
 
    int t = 1;
 
    cin >> t;
 
    while (t--)
    {
        solve();
    }
 
    //filptr.close();
    //outpter.close();
 
    return 0;
} 
