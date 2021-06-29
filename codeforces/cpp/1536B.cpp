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
string st;
vector<int> vec[27];

string fun(string s, vector<int> vec)
{
    string res;

    REP(i, 0, 25)
    {
        vector<int> v;
        char c = char(i + 'a');

        for (int index : vec)
        {
            if (index == n - 1)
                continue;
            if (st[index + 1] == c)
                v.push_back(index + 1);
        }

        if (v.size() == 0)
            return (s + c);

        string r = fun(s + c, v);

        if (res.size() == 0)
            res = r;
        else if (res.size() > r.size())
            res = r;
        else if (res.size() == r.size() && res > r)
            res = r;
    }

    return res;
}

void solve()
{
    cin >> n;
    cin >> st;

    REP(i, 1, 26)
    vec[i].clear();

    REP(i, 0, st.size() - 1)
    {
        int ele = st[i] - 'a' + 1;
        vec[ele].push_back(i);
    }

    string res;

    REP(i, 0, 25)
    {
        string s;
        s.push_back(char('a' + i));

        if (vec[i + 1].size() == 0)
        {
            cout << s << endl;
            return;
        }

        string r = fun(s, vec[i + 1]);

        if (res.size() == 0 || r.size() < res.size())
            res = r;
        else if (res.size() == r.size() && res > r)
            res = r;
    }

    cout << res << endl;
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