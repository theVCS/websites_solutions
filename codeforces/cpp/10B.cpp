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
int arr[100][100];
int cost[100][100];

void solve()
{
    int q;
    cin >> n >> k;

    int c = (k + 1) / 2;

    REP(i, 1, k)
    {
        REP(j, 1, k)
        {
            arr[i][j] = arr[i][j - 1] + 1;
            cost[i][j] = abs(i - c) + abs(j - c) + cost[i][j - 1];
        }
    }

    while (n--)
    {
        int ele;
        cin >> ele;

        int x = -1, l = -1, r = -1;

        int mn = INF;

        REP(row, 1, k)
        {
            for (int _l = 1, _r = ele; _r <= k; _l++, _r++)
            {
                if (arr[row][_r] - arr[row][_l - 1] == ele)
                {
                    if (mn > cost[row][_r] - cost[row][_l - 1])
                    {
                        mn = cost[row][_r] - cost[row][_l - 1];
                        l = _l;
                        r = _r;
                        x = row;
                    }
                }
            }
        }

        if (mn == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << x << " " << l << " " << r << endl;
            REP(i, l, r)
            arr[x][i] -= i - l + 1;
            REP(i, r + 1, k)
            arr[x][i] -= ele;
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