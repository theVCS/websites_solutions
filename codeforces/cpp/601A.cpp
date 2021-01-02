#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 79801
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> road[maxN], rail[maxN];
bool visroad[maxN], visrail[maxN];
int distroad[maxN], distrail[maxN], timer;

void bfs(int node = 1)
{
    visrail[node] = true;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int child : rail[curr])
        {
            if (!visrail[child])
            {
                visrail[child] = true;
                distrail[child] = 1 + distrail[curr];
                q.push(child);
            }
        }
    }
}

void bfs1(int node = 1)
{
    visroad[node] = true;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int child : road[curr])
        {
            if (!visroad[child])
            {
                visroad[child] = true;
                distroad[child] = 1 + distroad[curr];
                q.push(child);

                if (distroad[child] == distrail[child])
                {
                    timer++;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<pair<int, int>, bool> checker;

    int n, m, a, b;

    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        rail[a].push_back(b);
        rail[b].push_back(a);
        checker[{a, b}] = true;
    }

    REP(i, 1, n + 1)
    {
        REP(j, i + 1, n + 1)
        {
            if (!(checker[{i, j}] || checker[{j, i}]))
            {
                road[i].push_back(j);
                road[j].push_back(i);
            }
        }
    }

    bfs();
    bfs1();

    if (distroad[n] && distrail[n])
    {
        if (timer && distroad[n] == distrail[n])
        {
            timer--;
        }

        cout << max(distrail[n] + 2 * timer, distroad[n] + 2 * timer);
    }
    else
    {
        cout << -1;
    }

    return 0;
}