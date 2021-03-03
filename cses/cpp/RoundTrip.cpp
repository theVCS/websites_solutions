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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

vector<int> arr[maxN];
bool vis[maxN];
vector<int> path;
int ini = -1, ind;

void dfs(int node = 1, int par = -1)
{
    vis[node] = true;

    for (int child : arr[node])
    {
        if (child == par)
            continue;
        else if (vis[child])
        {
            if (ind == 0)
            {
                ini = child;
                ind++;
                path.push_back(child);
            }
        }
        else
        {
            dfs(child, node);

            if (ini != -1)
                path.push_back(child);

            if (ini == child)
                ini = -1;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;

    cin >> n >> m;

    REP(i, 0, m)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    dfs();

    if (ind)
    {
        cout << path.size() << endl;
        for (int child : path)
            cout << child << " ";
    }
    else
    {
        cout << "IMPOSSIBLE";
    }

    return 0;
}