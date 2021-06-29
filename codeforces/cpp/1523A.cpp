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
#define maxN 1001
#define endl "\n"
#define INF 10000000000000
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

string s;
ll n, m;
ll arr[maxN];

bool check(int index)
{
    if (index == 0)
    {
        if (s[index + 1] == '1')
            return true;
        else
            return false;
    }
    else if (index == n - 1)
    {
        if (s[index - 1] == '1')
            return true;
        else
            return false;
    }
    else
    {
        if ((s[index + 1] == '1' || s[index - 1] == '1') && (s[index + 1] != s[index - 1]))
            return true;
        else
            return false;
    }
}

void solve()
{
    cin >> n >> m;
    cin >> s;

    string str = s;
    int steps = 0;

    while (true)
    {
        steps++;

        if (steps > m)
            break;

        int i = 0;
        int changes = 0;

        while (i < n)
        {
            if (s[i] == '0')
            {
                if (check(i))
                    str[i] = '1', changes++;
            }
            i++;
        }

        s = str;

        if (changes == 0)
            break;
    }

    REP(i, 0, n - 1)
    cout << s[i];
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