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
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

void solve()
{
    string s;
    cin >> s;

    ll n = s.size();

    if (count(s.begin(), s.end(), 'a') == n)
    {
        cout << "NO" << endl;
        return;
    }
    string a = 'a' + s, c = s + 'a';
    string b = a, d = c;

    reverse(d.begin(), d.end());
    reverse(b.begin(), b.end());
    if (a != b)
    {
        cout << "YES" << endl;
        cout << a << endl;
        return;
    }
    if (c != d)
    {
        cout << "YES" << endl;
        cout << c << endl;
        return;
    }
    cout << "YES" << endl;
    REP(i, 0, n)
    {
        string x = s.substr(0, i + 1) + 'a' + s.substr(i + 1, n - i);
        string y;

        reverse(y.begin(), y.end());
        if (y != x)
        {
            cout << x << endl;
            return;
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

    cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}