#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m, i = 1, x, y;
    ll sum[5], arr[5];
    memset(arr, 0, 5);

    cin >> n >> m;

    if (n > m)
    {
        swap(n, m);
    }
    // kept n smaller

    while (i <= 5)
    {
        y = 5 - i;
        sum[i - 1] = ((m - y) / 5) + 1;
        i++;
    }

    x = n / 5;

    i = 5;
    while (i)
    {
        arr[i - 1] = x * sum[i - 1];
        i--;
    }

    if (m > 5)
    {
        i = m % 5;

        while (i)
        {
            arr[i - 1] += sum[i - 1];
            i--;
        }
    }

    cout << arr[0] + arr[1] + arr[2] + arr[3] + arr[4];

    return 0;
}