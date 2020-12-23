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

vector<ll> primefact;

void sieve(int len)
{
    bool isPrime[len + 1];

    for (int i = 0; i < len + 1; i++)
    {
        isPrime[i] = true;
    }

    for (int i = 2; i * i <= len + 1; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * i; j < len + 1; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i < len + 1; i++)
    {
        if (isPrime[i])
        {
            primefact.push_back(i);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll u, l, dum;

    cin >> l >> u;
    ll len = u - l + 1;
    ll phi[len];
    dum = u;

    sieve(sqrt(u));

    for (int i = 0; i < len; i++)
    {
        phi[i] = i + l;
    }

    bool flag;

    for (ll i = 0; i < len; i++)
    {
        flag = true;

        for (ll fact : primefact)
        {
            if (phi[i] % fact == 0)
            {
                flag = false;
            }
        }

        if (flag && phi[i] != 1)
        {
            primefact.push_back(phi[i]);
        }
    }

    for (ll i = 0; i < len; i++)
    {
        flag = true;

        for (ll fact : primefact)
        {
            if (phi[i] % fact == 0)
            {
                phi[i] /= fact;
                phi[i] *= fact - 1;
            }
        }
    }

    for (ll i = 0; i < len; i++)
    {
        cout << phi[i] << endl;
    }

    return 0;
}