#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, -1, 0, 1};
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, n, k, a, lm, cnt;

    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        cnt = 0;
        lm = 0;

        while (n--)
        {
            cnt++;
            cin >> a;
            a += lm;
            lm = a - k;

            if (lm < 0)
            {
                break;
            }
        }

        if (n > 0)
        {
            while (n--)
            {
                cin >> a;
            }
        }

        if (lm >= 0)
        {
            cnt += (lm / k) + 1;
        }

        cout << cnt << endl;
    }

    return 0;
}