#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 5001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<pii> res;
vector<int> arr[maxN];
int subSize[maxN], n;
map<pii, bool> check;

int dfs(int node = 1, int par = -1)
{
    int size = 1;

    for (int child : arr[node])
    {
        if (child != par)
        {
            size += dfs(child, node);
        }
    }

    subSize[node] = size;
    return size;
}

void knap(vector<int> arr)
{
    int sum = n - 1, n = arr.size();

    bool t[n + 1][sum + 1];

    for (int i = 0; i < sum + 1; i++)
    {
        t[0][i] = false;
    }
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = true;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    for (int i = 1; i < sum; i++)
    {
        if (t[n][i])
        {
            if (check[{i, sum - i}] == false)
            {
                check[{i, sum - i}] = true;
                res.push_back({i, sum - i});
            }

            if (check[{sum - i, i}] == false)
            {
                check[{sum - i, i}] = true;
                res.push_back({sum - i, i});
            }
        }
    }
}

void solve(int node = 1, int par = -1)
{
    vector<int> childSize;

    for (int child : arr[node])
    {
        if (child != par)
        {
            childSize.push_back(subSize[child]);
            solve(child, node);
        }
    }

    int restSize = n - subSize[node];

    if (restSize > 0)
    {
        childSize.push_back(restSize);
    }

    if (childSize.size() > 1)
    {
        // cout << node << " -> " << endl;
        knap(childSize);
    }

    // for (int e : childSize)
    //     cout << e << " ";
    // cout << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;

    cin >> n;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    subSize[1] = dfs();
    solve();

    sort(res.begin(), res.end());

    cout << res.size() << endl;

    for (pii e : res)
    {
        cout << e.first << " " << e.second << endl;
    }

    return 0;
}