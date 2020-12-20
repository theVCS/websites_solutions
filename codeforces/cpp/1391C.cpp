#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll fact[maxN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fact[0] = fact[1] = 1;

    int n;
    ll p = 1;

    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * i * 1LL) % mod;
        p = (p * 2) % mod;
    }

    // cout << fact[n] << " " << p;
    cout << (mod + fact[n] - p) % mod;

    return 0;
}