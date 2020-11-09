#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, res, m, index;

    cin >> t;

    while (t--)
    {
        res = 0;
        m = 0;

        cin >> n;

        int arr[n];

        REP(i, 0, n)
        {
            cin >> arr[i];
            
            if (m < arr[i])
            {
                index = i;
                m = arr[i];
            }
        }

        swap(arr[n - 1], arr[index]);        

        while (n > 0)
        {
            if (arr[n - 1] >= 0)
            {
                res += arr[n - 1];

                if (n > 2)
                {
                    arr[n - 3] -= arr[n - 1] - arr[n - 2];
                }

                n -= 2;
            }
            else
            {
                if (n > 1)
                {
                    arr[n - 2] += arr[n - 1];
                }
                n--;
            }
        }

        cout << res << endl;
    }

    return 0;
}