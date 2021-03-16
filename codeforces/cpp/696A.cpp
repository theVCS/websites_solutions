#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
 
map<pair<ll, ll>, ll> mp;
 
int level(ll num)
{
    return log2l(num);
}
 
void solve()
{
    int q, code;
    ll a, b, c;
 
    cin >> q;
 
    while (q--)
    {
        cin >> code;
 
        if (code == 1)
        {
            cin >> a >> b >> c;
 
            int level1 = level(a);
            int level2 = level(b);
 
            if (level1 > level2)
            {
                swap(level1, level2);
                swap(a, b);
            }
 
            // level2(b) is always at a lower level than level1
            while (level(b) > level1)
            {
                mp[{b, b / 2}] += c;
                b /= 2;
            }
 
            // now a and b are at same level
            while (a != b)
            {
                mp[{a, a / 2}] += c;
                mp[{b, b / 2}] += c;
                a /= 2;
                b /= 2;
            }
        }
        else
        {
            cin >> a >> b;
 
            ll res = 0;
 
            int level1 = level(a);
            int level2 = level(b);
 
            if (level1 > level2)
            {
                swap(level1, level2);
                swap(a, b);
            }
 
            // level2(b) is always at a lower level than level1
 
            while (level(b) > level1)
            {
                res += mp[{b, b / 2}];
                b /= 2;
            }
 
            // now a and b are at same level
            while (a != b)
            {
                res += mp[{a, a / 2}];
                res += mp[{b, b / 2}];
                a /= 2;
                b /= 2;
            }
 
            cout << res << endl;
        }
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
 
    //cin >> t;
 
    while (t--)
    {
        solve();
    }
 
    //filptr.close();
    //outpter.close();
 
    return 0;
}