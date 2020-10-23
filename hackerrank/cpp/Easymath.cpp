#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

int nodigit(int n)
{
    int cnt = 0;

    while (n)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}

void fun(ll a)
{
    int _pow2 = 0;
    int _pow5 = 0;

    while (a % 2 == 0)
    {
        _pow2++;
        a /= 2;
    }

    while (a % 5 == 0)
    {
        _pow5++;
        a /= 5;
    }

    _pow5 = max(_pow5, _pow2 - 2);
    _pow2 = nodigit(a);

    cout << 2 * _pow2 + _pow5 << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin>>t;

    while (t--)
    {
        cin>>n;
        fun(n);
    }
    

    return 0;
}