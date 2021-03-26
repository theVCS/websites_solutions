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
#define INF 1000000000
#define endl "\n"
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

void solve()
{
    ll n, k, res = 0, first = -1, last = -1;
    string s, a;

    cin >> n >> k;
    cin >> s;

    a = s;

    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            first = i;
            break;
        }
    }

    for (ll i = n - 1; i >= 0; i--)
    {
        if (s[i] == '*')
        {
            last = i;
            break;
        }
    }

    if (first == -1)
    {
        cout << 0 << endl;
    }
    else if (first == last)
    {
        cout << 1 << endl;
    }
    else
    {
        res = 1;
        for (ll i = first; i < last;)
        {
            if (s[i] == '*')
            {
                i += k;
                res++;
            }
            else
            {
                ll j = i - 1;
                while (j > i - k)
                {
                    if (s[j] == '*')
                    {
                        res++;
                        i = j + k;
                        break;
                    }
                    j--;
                }
            }
        }
        cout << res << endl;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream fi("input.txt");
    // ofstream fo("output.txt");

    // fi >> input;
    // fo << output;

    int t = 1;

    cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}