#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxN 10001
#define REP(i, a, b) for (int i = a; i < b; i++)
ll phi[maxN];

void init()
{
    for (ll i = 1; i < maxN; i++)
    {
        phi[i] = i;
    }

    for (ll i = 2; i < maxN; i++)
    {
        if (phi[i] == i)
        {
            for (ll j = i; j < maxN; j += i)
            {
                phi[j] /= i;
                phi[j] *= i - 1;
            }
        }
    }

    for (ll i = 1; i < maxN; i++)
    {
        phi[i] += phi[i - 1];
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    int t;
    ll n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << phi[n] * phi[n] << endl;
    }

    return 0;
}