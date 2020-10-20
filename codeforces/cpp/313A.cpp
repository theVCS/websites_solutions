#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

void show(ll n)
{
    if (n > 0)
    {
        cout << n;
    }
    else
    {
        n *= -1;
        ll lastDig = n % 10;
        ll digit1 = n / 10;
        ll digit2 = (n / 100) * 10 + lastDig;

        if (digit1 < digit2)
        {
            cout << -1 * digit1;
        }
        else
        {
            cout << -1 * digit2;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n;
    cin>>n;
    show(n);

    return 0;
}