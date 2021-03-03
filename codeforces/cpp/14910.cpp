#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q, code, x, one = 0, zero = 0;

    cin >> n >> q;

    REP(i, 1, n + 1)
    {
        cin >> code;
        arr[i] = code;

        if (code)
            one++;
        else
            zero++;
    }

    while (q--)
    {
        cin >> code;

        if (code == 1)
        {
            cin >> x;

            if (arr[x] == 1)
            {
                one--;
                zero++;
                arr[x] = 0;
            }
            else
            {
                one++;
                zero--;
                arr[x] = 1;
            }
        }
        else
        {
            cin >> x;

            if (x <= one)
                cout << 1 << endl;
            else
            {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}