#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1010
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, m;
int arr[maxN][maxN];
int horPre[maxN][maxN];
int verPre[maxN][maxN];
int horSuf[maxN][maxN];
int verSuf[maxN][maxN];

void solve()
{
    cin >> n >> m;

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            cin >> arr[i][j];
            horPre[i][j] = horPre[i][j - 1] + arr[i][j];
        }
    }

    REP(i, 1, n + 1)
    for (int j = m; j > 0; j--)
    {
        horSuf[i][j] = horSuf[i][j + 1] + arr[i][j];
    }

    REP(j, 1, m + 1)
    REP(i, 1, n + 1)
    verPre[i][j] = verPre[i - 1][j] + arr[i][j];

    REP(j, 1, m + 1)
    for (int i = n; i > 0; i--)
        verSuf[i][j] = verSuf[i + 1][j] + arr[i][j];

    // REP(i, 1, n + 1)
    // {
    //     REP(j, 1, m + 1)
    //     cout << verSuf[i][j] << " ";
    //     cout << endl;
    // }

    int cnt = 0;

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            if (arr[i][j] == 1)
                continue;

            if (verPre[i-1][j])
                cnt++;
            if (verSuf[i+1][j])
                cnt++;
            if (horSuf[i][j+1])
                cnt++;
            if (horPre[i][j-1])
                cnt++;
        }
    }

    cout << cnt;
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