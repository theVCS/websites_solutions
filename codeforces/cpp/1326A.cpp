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

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        if (n == 1)
        {
            cout << -1;
        }
        else
        {
            if (((n - 1) * 2) % 3)
            {
                n--;
                while (n--)
                {
                    cout << 2;
                }
                cout << 3;
            }
            else
            {
                n -= 2;

                cout << 3;
                while (n--)
                {
                    cout << 2;
                }
                cout << 3;
            }
        }

        cout << endl;
    }

    return 0;
}