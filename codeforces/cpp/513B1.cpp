#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 1000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define printd(x) cout << fixed << setprecision(10) << x
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        power >>= 1;
    }
    return res;
}

int n, m, val;
vector<vector<int>> res;

void fun(int mask = 0, vector<int> vec = {})
{
    if (vec.size() == n)
    {
        int v = 0;

        REP(i, 0, n - 1)
        {
            int ele = vec[i];

            REP(j, i, n - 1)
            {
                ele = min(ele, vec[j]);
                v += ele;
            }
        }

        if (v == val)
        {
            res.push_back(vec);
        }

        return;
    }

    REP(i, 1, n)
    {
        if ((mask & (1 << i)))
            continue;

        vec.push_back(i);
        fun((mask | (1 << i)), vec);

        vec.pop_back();
    }
}

void solve()
{
    cin >> n >> m;

    int v = n;

    REP(i, 1, n)
    {
        val += v * i;
        v--;
    }

    fun();

    for (int ele : res[m - 1])
    {
        cout << ele << " ";
    }

    // for (vector<int> v : res)
    // {
    //     for (int e : v)
    //     {
    //         cout << e << " ";
    //     }
    //     cout << endl;
    // }
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