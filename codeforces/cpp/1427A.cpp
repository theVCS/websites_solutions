#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

bool isPos(int arr[], int n)
{
    int sum = arr[0];

    REP(i, 1, n)
    {
        if (sum == 0)
        {
            return false;
        }

        sum += arr[i];
    }

    return true;
}

void display(int arr[], int n)
{
    REP(i, 0., n)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, sump = 0, sumn = 0;

    cin >> t;

    while (t--)
    {
        cin >> n;
        int arr[n];

        REP(i, 0, n)
        {
            cin >> arr[i];

            if (arr[i] > 0)
            {
                sump += arr[i];
            }
            else
            {
                sumn += -1 * arr[i];
            }
        }

        if (sump < sumn)
        {
            sort(arr, arr + n, greater<int>());
        }
        else
        {
            sort(arr, arr + n);
        }

        if (isPos(arr, n))
        {
            cout << "YES" << endl;
            display(arr, n);
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}