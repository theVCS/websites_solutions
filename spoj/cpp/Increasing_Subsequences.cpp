#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 5000000
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100011
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, k;
ll arr[maxN];
ll ft[maxN][51];

ll query(int index, int x) // query from 1 to index where level is x;
{
    int sum = 0;

    while (index)
    {
        sum = (sum + ft[index][x]) % mod;
        index -= (index & -1 * index);
    }

    return sum;
}

void update(int index, int x, ll val)
{
    while (index < maxN)
    {
        ft[index][x] = (ft[index][x] + val) % mod;
        index += (index & -1 * index);
    }
}

ll ans = 0;

void init()
{
    REP(i, 1, n + 1)
    {
        REP(lev, 1, k + 1)
        {
            ll sum = lev == 1 ? 1 : query(arr[i] - 1, lev - 1);
            update(arr[i], lev, sum);

            if (lev == k)
                ans = (ans + sum) % mod;
        }
    }
}

void solve()
{
    cin >> n >> k;

    REP(i, 1, n + 1)
    {
        cin >> arr[i];
        arr[i]++;
    }

    init();

    cout << ans;
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