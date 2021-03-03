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

ll dp[3001], powPrime[3001];
char str[3001];
char pat[500001];

void init(int n)
{
    ll p = 31, power = 31;
    dp[0] = str[0] - 'a' + 1;
    powPrime[0] = 1;

    for (int i = 1; i < n; i++)
    {
        dp[i] = (dp[i - 1] + (str[i] - 'a' + 1) * p) % mod;
        powPrime[i] = p;
        p = (p * power) % mod;
    }
}

ll getHash(char str[], int n)
{
    ll res = 0;

    for (int i = 0; i < n; i++)
    {
        res = (res + (str[i] - 'a' + 1) * powPrime[i]) % mod;
    }

    return res;
}

ll subHash(int l, int r)
{
    ll res = dp[r];

    if (l)
        res = (res - dp[l - 1] + mod) % mod;

    return res;
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int n, q;

    scanf("%d %d", &n, &q);
    scanf("%s", str);

    init(n);

    while (q--)
    {
        scanf("%s", pat);
        int m = strlen(pat);

        if (m > n)
            break;

        ll pHash = getHash(pat, m);
        int cnt = 0;

        for (int l = 0, r = m - 1; r < n; l++, r++)
            if (subHash(l, r) == (pHash * powPrime[l]) % mod)
                cnt++;

        printf("%d\n", cnt);
    }

    return 0;
}