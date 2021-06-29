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

int n, k;

vector<int> arr[128];

int digFormed(int mask)
{
    if (mask == 119)
        return 0;
    else if (mask == 36)
        return 1;
    else if (mask == 93)
        return 2;
    else if (mask == 109)
        return 3;
    else if (mask == 46)
        return 4;
    else if (mask == 107)
        return 5;
    else if (mask == 123)
        return 6;
    else if (mask == 37)
        return 7;
    else if (mask == 127)
        return 8;
    else if (mask == 111)
        return 9;
    else
        return -1;
}

void graphBuilder(int mask = 0)
{
    if (mask == 127)
        return;

    REP(bit, 0, 6)
    {
        if (mask & (1 << bit))
            continue;

        int nmask = (mask | (1 << bit));
        arr[mask].push_back(nmask);
        graphBuilder(nmask);
    }
}

int maxDig[128][8];

void dfs(int mask, int start, int lev = 0)
{
    maxDig[start][lev] = max(maxDig[start][lev], digFormed(mask));

    for (int child : arr[mask])
    {
        dfs(child, start, lev + 1);
    }
}

void initialize()
{
    REP(i, 0, 127)
    {
        REP(j, 0, 6)
        maxDig[i][j] = -1;
        dfs(i, i);
    }
}

void solve()
{
    graphBuilder();
    initialize();

    string s;

    cin >> n >> k;

    REP(i, 1, n)
    {
        cin >> s;
    }

    REP(i, 0, 127)
    {
        REP(j, 0, 6)
        {
            cout << maxDig[i][j] << " ";
        }
        cout << endl;
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