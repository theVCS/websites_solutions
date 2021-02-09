#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

char arr[maxN][maxN];
int treeCount[maxN][maxN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, sx, sy, ex, ey;

    cin >> n >> m;

    REP(i, 1, n + 1)
    {
        REP(j, 1, n + 1)
        {
            cin >> arr[i][j];
            treeCount[i][j] = int(arr[i][j] == '*') + treeCount[i][j - 1];
        }
    }

    int cnt;

    while (m--)
    {
        cnt = 0;

        cin >> sx >> sy >> ex >> ey;

        for (int i = sx; i <= ex; i++)
        {   
            cnt += (treeCount[i][ey] - treeCount[i][sy - 1]);
        }

        cout << cnt << endl;
    }

    return 0;
}