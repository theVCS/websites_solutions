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

bool flag;
ll t[5001];

int getCode(char c1, char c2)
{
    return 10 * (c1 - '0') + (c2 - '0');
}

ll solve(string s, int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else if (t[n] != -1)
    {
        return t[n];
    }
    else if (s[n - 1] == '0' && s[n - 2] == '0')
    {
        flag = false;
        return 0;
    }
    else if (s[n - 1] == '0')
    {
        int code = getCode('0', s[n - 2]);

        if (code >= 3)
        {
            flag = false;
            return 0;
        }
        return t[n] = solve(s, n - 2);
    }
    else if (s[n - 2] == '0')
    {
        return t[n] = solve(s, n - 1);
    }

    int cnt = getCode(s[n - 2], s[n - 1]);

    if (cnt <= 26)
    {
        return t[n] = solve(s, n - 1) + solve(s, n - 2);
    }
    else
    {
        return t[n] = solve(s, n - 1);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;

    while (true)
    {
        cin >> s;
        flag = true;
        memset(t, -1, sizeof(t));

        if (s == "0")
        {
            return 0;
        }

        cout << solve(s, s.size()) * flag << endl;
    }

    return 0;
}