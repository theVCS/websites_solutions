#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
map<ll, ll> primes;
ll totalDiv = 1;

void primeGen(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            primes[i] = cnt;
            totalDiv *= (cnt + 1);
        }
    }

    if (n > 1)
    {
        primes[n] = 1;
        totalDiv *= 2;
    }
}

void fun1(ll k)
{
    ll div = 1, cnt;
    for (auto i : primes)
    {
        cnt = 0;

        while (k % i.first == 0)
        {
            cnt++;
            k /= i.first;
        }

        div *= min(cnt, i.second) + 1;
    }

    cout << div << endl;
}

void fun2(ll k)
{
    ll div = 1, cnt;
    for (auto i : primes)
    {
        cnt = 0;
        while (k % i.first == 0)
        {
            cnt++;
            k /= i.first;
        }

        if (cnt == 0)
        {
            break;
        }

        div *= (i.second - cnt + 1);
    }

    if (k > 1)
    {
        div = 0;
    }

    cout << div << endl;
}

void fun3(ll k)
{
    ll div = 1, cnt;
    for (auto i : primes)
    {
        cnt = 0;
        while (k % i.first == 0)
        {
            cnt++;
            k /= i.first;
        }

        if (div > i.second)
        {
            div = 0;
            break;
        }

        div *= (i.second - cnt + 1);
    }

    if (k > 1)
    {
        div = 0;
    }

    cout << totalDiv - div << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    int q, t;

    cin >> n >> q;
    primeGen(n);

    while (q--)
    {
        cin >> t >> k;

        if (t == 1)
        {
            fun1(k);
        }
        else if (t == 2)
        {
            fun2(k);
        }
        else
        {
            fun3(k);
        }
    }

    return 0;
}