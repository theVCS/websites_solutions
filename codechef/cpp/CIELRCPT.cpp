#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int arr[12];

void minFinder(int &n)
{
    for (int i = 11; i >= 0; i--)
    {
        if (arr[i] <= n)
        {
            n -= arr[i];
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    arr[0] = 1;

    for (int i = 1; i < 12; i++)
    {
        arr[i] = 2 * arr[i - 1];
    }

    int t, n, cnt;

    cin >> t;

    while (t--)
    {
        cnt = 0;
        cin >> n;

        while (n)
        {
            minFinder(n);
            cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}