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

ll arr[1000000001];

ll maxMon(ll n)
{
    int exc = (n / 2) + (n / 3) + (n / 4);

    if (arr[n])
    {
        return arr[n];
    }
    else if (exc > n)
    {
        return arr[n] = maxMon(n / 2) + maxMon(n / 3) + maxMon(n / 4);
    }
    else
    {
        return arr[n] = n;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;

    while (cin >> n)
    {
        cout << maxMon(n) << endl;
    }

    return 0;
}