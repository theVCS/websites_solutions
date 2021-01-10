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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll t[5001];
bool flag;

ll dp(string s, int n)
{
    if (n <= 1)
    {
        return 0;
    }
    else if (t[n] != -1)
    {
        return t[n];
    }
    else if (s[n - 1] <= 54 && s[n - 2] <= 50)
    {
        if (s[n - 1] == '0' && s[n - 2] == '0' || s[n - 2] > 50)
        {
            flag = false;
            return 0;
        }
        else if (s[n - 1] == '0')
        {
            return t[n] = dp(s, n - 2);
        }
        else if (s[n - 2] == '0')
        {
            return t[n] = dp(s, n - 1);
        }
        else
        {
            return t[n] = 1 + dp(s, n - 1) + dp(s, n - 2);
        }
    }
    else if (s[n - 1] == '0' && s[n - 2] > 50)
    {
        flag = false;
        return 0;
    }
    else
    {
        return t[n] = dp(s, n - 1);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    ll ans;

    while (cin >> s)
    {
        if (s == "0")
        {
            return 0;
        }

        memset(t, -1, sizeof(t));

        flag = true;

        ans = dp(s, s.size());

        if (flag)
        {
            cout << 1 + dp(s, s.size()) << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}