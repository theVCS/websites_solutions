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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
int col[maxN], rnode = -1;
map<int, int> colCounter[maxN], mcolCounter;
int n, a, b;

map<int, int> dfs(int node = 1, int par = -1)
{
    map<int, int> mainCounter = mcolCounter;
    bool flag = true;

    for (int child : arr[node])
    {
        if (child != par)
        {
            map<int, int> m1 = dfs(child, node);

            for (auto e : m1)
            {
                colCounter[node][e.first] += e.second;
            }

            if (colCounter[child].size() != 1)
            {
                flag = false;
            }
            else
            {
                for (auto e : colCounter[child])
                {
                    mainCounter[e.first] -= e.second;

                    if (mainCounter[e.first] == 0)
                    {
                        mainCounter.erase(e.first);
                    }
                }
            }
        }
    }

    mainCounter[col[node]]--;

    if (mainCounter[col[node]] == 0)
    {
        mainCounter.erase(col[node]);
    }

    if (flag)
    {
        if (mainCounter.size() == 1)
        {
            rnode = node;
        }
    }

    colCounter[node][col[node]]++;
    return colCounter[node];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    REP(i, 1, n + 1)
    {
        cin >> col[i];
        mcolCounter[col[i]]++;
    }

    map<int, int> dum = dfs();

    if (rnode == -1)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES" << endl;
        cout << rnode;
    }

    // REP(i, 1, n + 1)
    // {
    //     cout << i << "-> " << endl;
    //     for (auto e : colCounter[i])
    //     {
    //         cout << e.first << " " << e.second << endl;
    //     }
    //     cout << endl;
    // }

    return 0;
}