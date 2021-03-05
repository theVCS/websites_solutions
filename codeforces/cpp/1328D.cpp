#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN], ans[maxN];

void solve()
{
    int n;
    cin >> n;

    bool flag = true;

    cin >> arr[0];

    REP(i, 1, n)
    {
        cin >> arr[i];

        if (arr[i] != arr[i - 1])
            flag = false;
    }

    if (flag)
    {
        cout << 1 << endl;
        REP(i, 0, n)
        cout << 1 << " ";
        cout << endl;
        return;
    }

    if (n % 2 == 0)
    {
        cout << 2 << endl;
        int c = 0;
        REP(i, 0, n)
        {
            cout << c + 1 << " ";
            c ^= 1;
        }
        return;
    }

    REP(i, 0, n)
    {
        if (arr[i] == arr[(i + 1) % n])
        {
            cout << 2 << endl;

            int c = 0;
            for (int j = i + 1; j < n; j++)
            {
                ans[j] = c + 1;
                c ^= 1;
            }

            c = 0;
            for (int j = i; j >= 0; j--)
            {
                ans[j] = c + 1;
                c ^= 1;
            }

            REP(i, 0, n)
            cout << ans[i] << " ";
            cout << endl;
            return;
        }
    }

    int c = 0;
    cout << 3 << endl;
    REP(i, 0, n - 1)
    {
        cout << c + 1 << " ";
        c ^= 1;
    }
    cout << 3 << endl;
    return;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}