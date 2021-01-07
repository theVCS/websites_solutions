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

vector<pii> arr[maxN];

int dfs(int node, vector<int> &vec, int par = -1)
{
    int cnt = 0, dcnt;

    for (pair<int, int> child : arr[node])
    {
        if (child.first != par)
        {
            dcnt = dfs(child.first, vec, node);

            if (child.second == 2)
            {
                if (dcnt == 0)
                {
                    vec.push_back(child.first);
                }
                cnt++;
            }
        }
    }

    return cnt;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b, c;

    cin >> n;

    REP(i, 0, n - 1)
    {
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }

    vector<int> res;
    int cnt = dfs(1, res);

    cout << res.size() << endl;

    for (int e : res)
    {
        cout << e << " ";
    }

    return 0;
}