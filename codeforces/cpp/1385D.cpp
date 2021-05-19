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

int n;
string s;
int cnt[131072][26];

int fun(int l, int r, int c = 0)
{
    if (l == r)
    {
        return ((s[l] - 'a') != c);
    }

    int mid = (l + r) / 2;

    int leftCnt = cnt[mid][c] - (l == 0 ? 0 : cnt[l - 1][c]);
    int rightCnt = cnt[r][c] - cnt[mid][c];

    return min((mid - l + 1 - leftCnt) + fun(mid + 1, r, c + 1), (r - mid - rightCnt) + fun(l, mid, c + 1));
}

void solve()
{
    cin >> n;
    cin >> s;

    REP(i, 0, 25)
    cnt[0][i] = 0;

    cnt[0][s[0] - 'a'] = 1;

    REP(i, 1, n - 1)
    {
        REP(j, 0, 25)
        {
            cnt[i][j] = cnt[i - 1][j];
        }

        cnt[i][s[i] - 'a'] += 1;
    }

    cout << fun(0, n - 1) << endl;
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