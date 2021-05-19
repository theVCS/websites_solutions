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
#define maxN 200001
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

int n;
int university[maxN];
ll progSki[maxN];
vector<ll> uni[maxN];
vector<pii> uniDat;
set<int> uniSet;

void solve()
{
    cin >> n;

    ll tot = 0;
    int maxSize = 0;

    uniSet.clear();
    uniDat.clear();

    REP(i, 1, n)
    {
        cin >> university[i];
        uni[university[i]].clear();
        uniSet.insert(university[i]);
    }

    REP(i, 1, n)
    {
        cin >> progSki[i];
        uni[university[i]].push_back(progSki[i]);
        tot += progSki[i];
    }

    for (int u : uniSet)
    {
        uniDat.push_back({(int)uni[u].size(), u});

        maxSize = max(maxSize, (int)uni[u].size());

        sort(all(uni[u]), greater<>());

        REP(i, 1, uni[u].size() - 1)
        uni[u][i] += uni[u][i - 1];
    }

    sort(all(uniDat));

    cout << tot << " ";

    REP(i, 2, n)
    {
        ll temp = 0;

        if (i > maxSize)
        {
            cout << 0 << " ";
            continue;
        }

        pii p = {i, 0};

        int index = lower_bound(all(uniDat), p) - uniDat.begin();

        REP(j, index, uniDat.size() - 1)
        {
            int sz = uniDat[j].first;
            temp += uni[uniDat[j].second][sz - 1 - (sz % i)];
        }

        cout << temp << " ";
    }

    cout << endl;
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