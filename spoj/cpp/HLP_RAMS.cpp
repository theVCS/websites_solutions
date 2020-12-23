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

ll oddteller(ll n)
{
    ll res = 1;

    for (int i = 0; i < 64; i++)
    {
        if (1LL << i & n)
        {
            res *= 2;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    ll n, odd;

    cin >> t;

    while (t--)
    {
        cin >> n;
        odd = oddteller(n);

        cout << n + 1 - odd << " " << odd << endl;
    }

    return 0;
}