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
vector<pii> arr[maxN];
int dist[maxN];

int minDistance(vector<pair<int, int>> gr[], int n,
                int dist[], int vis[], int a[], int k)
{
    // Keeps minimum element on top
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;

    // To keep required answer
    int ans = INT_MAX;

    for (int i = 1; i <= n; i++)
    {
        if (!a[i])
            continue;

        for (int j = 1; j <= n; j++)
        {
            dist[j] = MAXI;
            vis[j] = 0;
        }

        // Distance from ith vertex to ith is zero
        dist[i] = 0;

        // Make queue empty
        while (!q.empty())
            q.pop();

        // Push the ith vertex
        q.push({0, i});

        // Count the good vertices
        int good = 0;

        while (!q.empty())
        {
            // Take the top element
            int v = q.top().second;

            // Remove it
            q.pop();

            // If it is already visited
            if (vis[v])
                continue;
            vis[v] = 1;

            // Count good vertices
            good += a[v];

            // If distance from vth vertex
            // is greater than ans
            if (dist[v] > ans)
                break;

            // If two good vertices are found
            if (good == 2 and a[v])
            {
                ans = min(ans, dist[v]);
                break;
            }

            // Go to all adjacent vertices
            for (int j = 0; j < gr[v].size(); j++)
            {
                int to = gr[v][j].first;
                int weight = gr[v][j].second;

                // if distance is less
                if (dist[v] + weight < dist[to])
                {
                    dist[to] = dist[v] + weight;
                    q.push({dist[to], to});
                }
            }
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}