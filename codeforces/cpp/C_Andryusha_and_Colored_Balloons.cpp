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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
int res[maxN], maxCol;

void dfs(int node = 1, int par = 0)
{
    int col = 1;

    for (int child : arr[node])
    {
        if (child != par)
        {
            while (col == res[par] || col == res[node])
            {
                col++;
            }
            maxCol = max(maxCol, col);
            res[child] = col;
            dfs(child, node);
            col++;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b;

    cin >> n;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    res[1] = 1;

    dfs();

    cout << maxCol << endl;

    REP(i, 1, n + 1)
    {
        cout << res[i] << " ";
    }

    return 0;
}