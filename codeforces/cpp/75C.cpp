#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (ll i = a; i < b; i++)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll a, b, l, h, result;
    cin >> a >> b;
    ll GCD = __gcd(a, b);

    vector<ll> div;

    for (ll i = 1; i * i <= GCD; i++)
    {
        if (GCD % i == 0)
        {
            div.push_back(i);
            if (i * i != GCD)
            {
                div.push_back(GCD / i);
            }
        }
    }

    cin >> n;

    while (n--)
    {
        result = -1;
        cin >> l >> h;

        for (int i = 0; i < div.size(); i++)
        {
            if (div[i] >= l && div[i] <= h)
            {
                result = max(div[i], result);
            }
        }
        cout << result << endl;
    }

    return 0;
}