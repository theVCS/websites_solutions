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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
int dep;
vector<int> depth[maxN];

void dfs(int node, int par = -1, int l = 0)
{
    depth[l].push_back(node);
    dep = max(dep, l);

    for (int child : arr[node])
    {
        if (child != par)
        {
            dfs(child, node, l + 1);
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

    dfs(1);

    for (int i = 0; i < dep + 1; i++)
    {
        cout << i << endl;
        for (int child : depth[i])
        {
            cout << child << " ";
        }
        cout << endl;
    }

    return 0;
}