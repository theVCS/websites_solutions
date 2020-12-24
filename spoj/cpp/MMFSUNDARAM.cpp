#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 50001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll i, j, n;

    cin >> n;

    ll len = (n + 1) / 2;

    vector<bool>sieve(len, false);

    for (i = 1; i < len; i++)
    {
        j = i;
        while ((i + j + 2 * i * j) < len)
        {
            sieve[(i + j + (2 * i * j))] = true;
            j++;
        }
    }

    cout << 2 << " ";

    for (i = 1; i < len; i++)
    {
        if (sieve[i] == false && (2 * i + 1) <= n)
        {
            cout << (2 * i + 1) << " ";
        }
    }

    return 0;
}