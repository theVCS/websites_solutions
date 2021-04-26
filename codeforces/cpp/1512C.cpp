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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

void solve()
{
    ll a, b;
    string s;

    cin >> a >> b;
    cin >> s;

    ll n = s.size();

    ll zero = 0;
    ll one = 0;

    for (char c : s)
    {
        if (c == '1')
            one++;
        else if (c == '0')
            zero++;
    }

    if (zero > a || one > b)
    {
        cout << -1 << endl;
        return;
    }

    a -= zero;
    b -= one;

    ll f = 1;

    for (ll i = 0; i < n / 2; i++)
    {
        ll j = n - i - 1;

        if (s[i] == '?')
        {
            if (s[j] == '?')
                continue;
            if (s[j] == '1')
                b--;
            else
                a--;
            s[i] = s[j];
        }
        else
        {
            if (s[j] == '?')
            {
                if (s[i] == '1')
                    b--;
                else
                    a--;
                s[j] = s[i];
            }
            else if (s[i] != s[j])
            {
                f = 0;
                break;
            }
        }
        if (a < 0 || b < 0)
        {
            f = 0;
            break;
        }
    }
    if (f == 0)
    {
        cout << "-1" << endl;
        return;
    }
    for (ll i = 0; i < n / 2; i++)
    {
        ll j = n - i - 1;
        if (s[i] == '?')
        {
            if (a > 1)
            {
                s[i] = '0';
                s[j] = '0';
                a -= 2;
            }
            else if (b > 1)
            {
                s[i] = '1';
                s[j] = '1';
                b -= 2;
            }
            else
            {
                f = 0;
                break;
            }
        }
    }
    if (f == 0)
    {
        cout << -1 << endl;
        return;
    }

    ll middle = (n + 1) / 2 - 1;
    if (s[middle] == '?')
    {
        if (a > 0)
            s[middle] = '0';
        else
            s[middle] = '1';
    }
    cout << s << endl;
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