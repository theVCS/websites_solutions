#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t;
    bool flag;

    cin >> t;

    while (t--)
    {
        cin >> n;
        flag = true;

        ll arr[n + 5];

        REP(i, 0, n)
        {
            cin >> arr[i];
        }

        REP(i, 0, n)
        {
            if (arr[i] < i)
            {
                cout << "NO" << endl;
                flag = false;
                break;
            }

            arr[i + 1] += arr[i] - i;
        }

        if (flag)
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}