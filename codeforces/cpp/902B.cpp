#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 10001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr(maxN);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, pi, ans = 1;

    cin >> n;

    int col[n + 1];

    REP(i, 2, n + 1)
    {
        cin >> pi;
        arr[i] = pi;
    }

    REP(i, 1, n + 1)
    {
        cin >> col[i];
    }

    REP(i, 2, n + 1)
    {
        if (col[arr[i]] != col[i])
        {
            ans++;
        }
    }

    cout << ans;

    return 0;
}