#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, -1, 0, 1};
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll fact[21];
    fact[0] = fact[1] = 1;

    for (int i = 2; i < 21; i++)
    {
        fact[i] = fact[i - 1] * i;
    }

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        cout << fact[n] << endl;
    }

    return 0;
}