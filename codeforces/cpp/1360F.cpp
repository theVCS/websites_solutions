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

int n, m;
string s[10];
bool flag = false;

bool check(string &str)
{
    REP(i, 0, n - 1)
    {
        int cnt = 0;

        REP(j, 0, m - 1)
        {
            if (s[i][j] != str[j])
                cnt++;
        }

        if (cnt > 1)
            return false;
    }

    return true;
}

void varyString(string &s)
{
    string str = s;

    REP(i, 0, m - 1)
    {
        REP(j, 0, 25)
        {
            if (s[i] == ('a' + j))
                continue;
            else
            {
                str[i] = ('a' + j);

                if (check(str))
                {
                    cout << str << endl;
                    flag = true;
                    return;
                }
            }
        }

        str[i] = s[i];
    }
}

void solve()
{
    flag = false;

    cin >> n >> m;

    REP(i, 0, n - 1)
    cin >> s[i];

    REP(i, 0, n - 1)
    {
        varyString(s[i]);

        if (flag)
            return;
    }

    cout << -1 << endl;
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