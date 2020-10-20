#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

bool isPos(int arr[], int n)
{
    REP(i, 0, n - 1)
    {
        if (arr[i + 1] - arr[i] > 1)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;
        int arr[n];

        REP(i, 0, n)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        if (isPos(arr, n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}