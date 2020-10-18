#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, a = 8, result = 1;
    cin >> n;

    while (n)
    {
        if (n % 2)
        {
            n--;
            result = (result * a) % 10;
        }
        n /= 2;
        a = (a * a) % 10;
    }

    cout << result;
    return 0;
}