#include <bits/stdc++.h>
using namespace std;
#define ll long long

void find(ll n, ll m)
{
    if (n <= 2 * m)
        cout << 0 << " ";
    else
        cout << n - 2 * m << " ";

    ll i;

    for (i = 0; i <= n; i++)
    {
        if (i * (i - 1) / 2 >= m)
            break;
    }

    cout << n - i << endl;
}

int main()
{
    ll n, m;

    cin >> n >> m;

    find(n, m);
    
    return 0;
}