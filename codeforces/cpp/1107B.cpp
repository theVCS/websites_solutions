#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int n;
    cin >> n;
    ll k, x;

    while (n--)
    {
        cin >> k >> x;
        cout << (k - 1) * 9 + x << endl;
    }

    return 0;
}