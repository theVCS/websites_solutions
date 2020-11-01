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

    int x;
    cin >> x;

    if (x == 1 || x == 0)
    {
        cout << x;
    }
    else
    {
        int cnt = 0;

        while (x % 2 == 0)
        {
            x /= 2;
            cnt++;
        }

        cout<< 2 * cnt * 1LL;
    }

    return 0;
}