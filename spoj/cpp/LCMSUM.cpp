#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define maxN 1000100
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

void display(ll a)
{
    ll sum = 0;

    for (ll i = 1; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            sum += i * phi[a / i];
            if (i != (a / i))
            {
                sum += (a / i) * phi[i];
            }
        }
    }
    cout<<sum<<endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    ll t, n, res;

    scanf("%lld", &t);

    while (t--)
    {
        scanf("%lld", &n);
        display(n);
    }

    return 0;
}