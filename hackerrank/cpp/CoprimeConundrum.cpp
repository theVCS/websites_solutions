#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b)            \
    for (int i = a; i < b; i++) \
    .

ll funcount(ll n)
{
    ll d1, d2, cnt = 0;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            d1 = i;
            d2 = n / i;

            if (__gcd(d1, d2) == 1)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, cnt = 0, perHead, maxc = 0;
    cin >> n;

    for (ll i = 100000000; i <= 1000000000; i++)
    {
        perHead = funcount(i);
        maxc = max(maxc, perHead);
        cnt += perHead;
        if (perHead > 0)
        {
            cout << i << "-> " << perHead << endl;
        }
    }
    cout << "maximum value of function is " << maxc << endl;
    cout << "total count is " << cnt;

    return 0;
}