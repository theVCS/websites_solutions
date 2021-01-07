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
int reorder[maxN], resArr[maxN];
bool vis[maxN];
queue<int>resq;

bool cmp(int a, int b)
{
    if (reorder[a] < reorder[b])
    {
        return true;
    }

    return false;
}

void bfs(int node = 1)
{
    queue<int> q;
    q.push(node);
    vis[node] = true;
    resq.push(node);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int child : arr[cur])
        {
            if (!vis[child])
            {
                vis[child] = true;
                resq.push(child);
                q.push(child);
            }
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
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    REP(i, 1, n + 1)
    {
        cin >> resArr[i];
        reorder[resArr[i]] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        sort(arr[i].begin(), arr[i].end(), cmp);
    }

    bfs();

    int index = 1;

    while (!resq.empty())
    {
        if (resq.front() != resArr[index])
        {
            cout << "No";
            return 0;
        }
        resq.pop();
        index++;
    }
        
    cout << "Yes";

    return 0;
}