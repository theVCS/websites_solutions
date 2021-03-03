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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];
int cc, label[maxN];
int par[maxN];

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = true;
    label[node] = cc;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int child : arr[node])
        {
            if (vis[child])
                continue;
            vis[child] = true;
            par[child] = node;
            label[child] = cc;
            q.push(child);
        }
    }
    cc++;
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

    for (int i = n; i > 0; i--)
    {
        if (vis[i] == false)
            bfs(i);
    }

    if (label[1] == label[n])
    {
        vector<int> path;
        
        int n = 1;

        while (n)
        {
            path.push_back(n);
            n = par[n];
        }

        cout << path.size() << endl;

        for (int e : path)
            cout << e << " ";
    }
    else
    {
        cout << "IMPOSSIBLE";
    }

    return 0;
}