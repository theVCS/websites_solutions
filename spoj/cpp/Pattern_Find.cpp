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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

string s, p;
ll dp[maxN], po[maxN];

ll getHash(string s)
{
    ll res = 0;
    ll p = 1, power = 29;

    for (int i = 0; i < s.size(); i++)
    {
        res = (res + (s[i] - 'a' + 1) * p) % mod;
        p = (p * power) % mod;
    }

    return res;
}

void init(string s)
{
    po[0] = 1;
    dp[0] = s[0] - 'a' + 1;
    ll p = 29;
    ll power = 29;

    for (int i = 1; i < s.size(); i++)
    {
        po[i] = power;
        dp[i] = (dp[i - 1] + (s[i] - 'a' + 1) * power) % mod;
        power = (p * power) % mod;
    }
}

ll subHash(int l, int r)
{
    ll res = dp[r];

    if (l > 0)
        res = (res - dp[l - 1] + mod) % mod;

    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        vector<int> ans;
        cin >> s >> p;

        init(s);
        ll pHash = getHash(p);

        for (int l = 0, r = p.size() - 1; r < s.size(); l++, r++)
        {
            if ((pHash * po[l]) % mod == subHash(l, r))
            {
                ans.push_back(l + 1);
            }
        }

        if (ans.size())
        {
            cout << ans.size() << endl;
            for (int e : ans)
                cout << e << " ";
            cout << endl;
        }
        else
        {
            cout << "Not Found" << endl;
        }
        cout << endl;
    }

    return 0;
}