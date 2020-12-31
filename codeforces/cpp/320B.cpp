#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 101
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];

void dfs(int node)
{
    vis[node] = true;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q, k, a, b;
    vector<pair<int, int>> interval;

    cin >> q;

    while (q--)
    {
        cin >> k >> a >> b;

        if (k == 1)
        {
            REP(i, 1, interval.size() + 1)
            {
                if ((interval[i - 1].first < a && interval[i - 1].second > a) || (interval[i - 1].first < b && interval[i - 1].second > b))
                {
                    arr[interval.size() + 1].push_back(i);
                }

                if ((a < interval[i - 1].first && interval[i - 1].first < b) || (a < interval[i - 1].second && interval[i - 1].second < b))
                {
                    arr[i].push_back(interval.size() + 1);
                }
            }
            interval.push_back({a, b});
        }
        else
        {
            dfs(a);

            if (vis[b])
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }

            REP(i, 0, 101)
            vis[i] = false;
        }
    }

    return 0;
}