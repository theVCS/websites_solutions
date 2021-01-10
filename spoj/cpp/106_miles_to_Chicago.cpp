#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 5000
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct edge
{
    int a, b, w;
};
edge e[maxN];
vector<int> dist(101, INT_MIN);
int parent[101];

void solve(int m)
{
    bool flag;
    dist[1] = 0;

    while (true)
    {
        flag = true;
        for (int i = 0; i < m; i++)
        {
            if (dist[e[i].a] > INT_MIN)
            {
                if (dist[e[i].b] < dist[e[i].a] + e[i].w)
                {
                    dist[e[i].b] = dist[e[i].a] + e[i].w;
                    flag = false;
                    parent[e[i].b] = e[i].a;
                }
            }
        }

        if (flag)
        {
            break;
        }
    }
}

float prob(int n)
{
    int curr, par;
    curr = n;
    par = parent[n];

    float prob = 1;

    while (par >= 1)
    {
        prob *= (dist[curr] - dist[par]) / 100;
        curr = par;
        par = parent[curr];
    }

    return prob;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    while (true)
    {
        cin >> n;

        if (n == 0)
        {
            return 0;
        }
        cin >> m;

        REP(i, 0, m)
        {
            cin >> e[i].a >> e[i].b >> e[i].w;

            if (e[i].b == 1)
            {
                swap(e[i].a, e[i].b);
            }
        }

        solve(m);

        cout << prob(n);
    }

    return 0;
}