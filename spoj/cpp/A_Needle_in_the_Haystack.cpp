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

ll dp[1000001], powStor[1000001];

ll getHash(string s)
{
    ll _p = 1, pow = 31, value = 0;

    for (int i = 0; i < s.size(); i++)
    {
        value = (value + (s[i] - 'a' + 1) * _p) % mod;
        _p = (_p * pow) % mod;
    }
    return value;
}

void init(string s)
{
    ll _p = 31, p = 31;
    dp[0] = s[0] - 'a' + 1;
    powStor[0] = 1;

    for (int i = 1; i < s.size(); i++)
    {
        dp[i] = (dp[i - 1] + (s[i] - 'a' + 1) * _p) % mod;
        powStor[i] = _p;
        _p = (_p * p) % mod;
    }
}

ll subHash(int l, int r)
{
    ll res = dp[r];

    if (l > 0)
    {
        res = (res - dp[l - 1] + mod) % mod;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string haystack, needle;
    ll hhash, nhash;

    while (cin >> n)
    {
        cin >> needle;
        cin >> haystack;

        init(haystack);

        nhash = getHash(needle);

        for (int l = 0, r = needle.size() - 1; r < haystack.size(); r++, l++)
        {
            hhash = subHash(l, r);
            if ((nhash * powStor[l]) % mod == hhash)
            {
                cout << l << endl;
            }
            // cout << hhash << endl;
        }
        cout << endl;
    }

    return 0;
}