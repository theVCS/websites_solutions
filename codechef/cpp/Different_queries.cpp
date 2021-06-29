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
#define maxN 100001
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

int n, q;
ll arr[501];
ll addNegative[512];
ll addPositive[512];
struct change
{
    int l, r, x;
};
vector<change> changer;

bool cmp(change a, change b)
{
    return a.x < b.x;
}

void solve()
{
    int type, l, r, x;
    cin >> n >> q;

    REP(i, 1, n)
    {
        cin >> arr[i];
    }
    change c;
    REP(i, 1, q)
    {
        cin >> type >> l >> r >> x;

        if (type == 1)
        {
            if (x < 0)
            {
                addNegative[l] += x, addNegative[r + 1] -= x;
            }
            else
            {
                addPositive[l] += x, addPositive[r + 1] -= x;
            }
        }
        else
        {
            c.l = l, c.r = r, c.x = x;
            changer.push_back(c);
        }
    }

    sort(all(changer), cmp);

    ll cn = 0;

    REP(i, 1, n)
    {
        cn += addNegative[i];
        arr[i] += cn;
    }

    for (change c : changer)
    {
        int l = c.l, r = c.r, x = c.x;

        REP(i, l, r)
        arr[i] = x;
    }

    cn = 0;
    REP(i, 1, n)
    {
        cn += addPositive[i];
        arr[i] += cn;
        cout << arr[i] << " ";
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