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

vector<int> arr[maxN];
int subSize[maxN];
int centroid2, n;

void dfs(int node = 1, int par = -1)
{
    subSize[node] = 1;

    for (int child : arr[node])
    {
        if (child == par)
            continue;

        dfs(child, node);

        subSize[node] += subSize[child];
    }

    if (n % 2 == 0 && subSize[node] == n / 2)
        centroid2 = node;
}

int cenCal(int node = 1, int par = -1)
{
    for (int child : arr[node])
    {
        if (child == par)
            continue;

        if (subSize[child] > n / 2)
            return cenCal(child, node);
    }

    return node;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, a, b;

    cin >> t;

    while (t--)
    {
        cin >> n;

        REP(i, 1, n + 1)
        arr[i].clear();

        REP(i, 0, n - 1)
        {
            cin >> a >> b;
            arr[a].push_back(b), arr[b].push_back(a);
        }

        centroid2 = -1;
        dfs();
        int centroid1 = cenCal();

        if (centroid2 == -1)
        {
            cout << centroid1 << " " << arr[centroid1][0] << endl;
            cout << centroid1 << " " << arr[centroid1][0] << endl;
        }
        else
        {   
            int child = arr[centroid1][0];

            if(child == centroid2)child = arr[centroid1][1];

            cout << centroid1 << " " << child << endl;
            cout << centroid2 << " " << child << endl;
        }
    }

    return 0;
}