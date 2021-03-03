#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 500001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll arr[maxN];
int front;
// ll dp[maxN];

ll fun(int n, bool madeZero = false, bool rangeSet = false)
{
    if (n <= front || n <= 0)
    {
        return 0;
    }
    else
    {
        ll q;

        if (rangeSet)
            q = arr[n - 1] + fun(n - 1, false, true);
        else if (madeZero)
        {
            ll q1 = arr[n - 1] + fun(n - 1, false, true);
            ll q2 = fun(n - 1, true, false);
            q = max(q1, q2);
        }
        else
        {
            ll q1 = arr[n - 1] + fun(n - 1, false, false);
            ll q2 = fun(n - 1, true, false);
            q = max(q1, q2);
        }

        return q;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;
        bool flag = true;
        int index = 0;

        REP(i, 0, n)
        {
            cin >> arr[i];
        }

        int i = 0;

        while (i < n && arr[i] < 0)
        {
            i++;
        }
        front = i;

        while (n >= 0 && arr[n - 1] < 0)
        {
            n--;
        }

        cout << fun(n) << endl;
    }

    return 0;
}