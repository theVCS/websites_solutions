#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define maxN 1000001
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
}

void display(int a)
{
    ll sum = 0;

    for (ll i = 1; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            sum += i * phi[i];
            if (i != (a / i))
            {
                sum += (a / i) * phi[a / i];
            }
        }
    }
    cout << ((sum + 1) * a) / 2 << "\n";
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    ll t, n, res;

    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);
        display(n);
    }

    return 0;
}