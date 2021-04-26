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
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN];
int ft[maxN];

int query(int index)
{
    int res = 0;

    while (index)
    {
        res = max(res, ft[index]);
        index -= (index & -index);
    }
    return res;
}

void update(int index, int val)
{
    while (index < maxN)
    {
        ft[index] = max(ft[index], val);
        index += (index & -index);
    }
}

void solve()
{
    int n;
    cin >> n;

    REP(i, 1, n + 1)
    cin >> arr[i];

    int res = 0;

    REP(i, 1, n + 1)
    {
        int pres = query(arr[i]);
        res = max(res, pres + 1);
        update(arr[i], pres+1);
    }
    cout << res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}