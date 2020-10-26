#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

int count(ll n)
{
    int cnt = 0, msb;

    for (int i = 0; i < 64; i++)
    {
        if (n & (1LL << i))
        {
            msb = i;
        }
    }

    for (int i = 0; i <= msb; i++)
    {
        if (!(n & (1LL << i)))
        {
            cnt++;
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    ll n;

    cin >> t;

    while (t--)
    {
        cin >> n;
        cout<<count(n)<<endl;
    }

    return 0;
}