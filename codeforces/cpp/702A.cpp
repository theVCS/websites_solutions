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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    ll arr[n];

    REP(i, 0, n)
        cin >> arr[i];

    int i = 0, j = 1, ans = 0, temp = 0;

    while (i < n && j < n)
    {
        if (arr[i] < arr[j])
        {
            temp++;
        }
        else
        {
            ans = max(temp, ans);
            temp = 0;
        }
        i++, j++;
    }

    ans = max(ans, temp);

    cout << ans + 1;

    return 0;
}