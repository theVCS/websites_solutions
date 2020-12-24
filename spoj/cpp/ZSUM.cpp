#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 10000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binexp(ll a, ll pow, ll m = mod)
{
    ll res = 1;

    while (pow)
    {
        if (pow % 2)
        {
            res = (res * a) % m;
            pow--;
        }

        pow /= 2;
        a = (a * a) % m;
    }

    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, k;

    cin >> n >> k;

    while (n)
    {
        cout << (binexp(n, k) + binexp(n, n) + 2 * binexp(n - 1, k) + 2 * binexp(n - 1, n - 1)) % mod << endl;
        cin >> n >> k;
    }

    return 0;
}