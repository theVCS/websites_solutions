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
#define maxN 300001
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
int segTree[4 * maxN];
string s;

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        if (s[si - 1] == '?')
        {
            segTree[si] = 2;
        }
        else
        {
            segTree[si] = 1;
        }
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);

        if (s[si - 1] == '?')
        {
            segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
        }
        else if (s[si - 1] == '1')
        {
            segTree[si] = segTree[2 * si];
        }
        else
        {
            segTree[si] = segTree[2 * si + 1];
        }
    }
}

int lev;

int level(int index)
{
    return log2(index);
}

void update(int si)
{
    while (si)
    {
        int l = level(si);

        if (lev == l)
        {
            if (s[si - 1] == '?')
            {
                segTree[si] = 2;
            }
            else
            {
                segTree[si] = 1;
            }
        }
        else
        {
            if (s[si - 1] == '?')
            {
                segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
            }
            else if (s[si - 1] == '1')
            {
                segTree[si] = segTree[2 * si];
            }
            else
            {
                segTree[si] = segTree[2 * si + 1];
            }
        }

        si /= 2;
    }
}

void solve()
{
    cin >> n;
    lev = n - 1;
    n--;
    n = 1 << n;

    cin >> s;
    reverse(all(s));

    build(1, 1, n);

    int q;
    int index;
    char c;
    cin >> q;

    REP(i, 1, q)
    {

        cin >> index >> c;
        index = s.size() - index;
        s[index] = c;
        update(index + 1);
        cout << segTree[1] << endl;

        // REP(i, 1, 7)
        // cout << segTree[i] << " ";
        // cout << endl;
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