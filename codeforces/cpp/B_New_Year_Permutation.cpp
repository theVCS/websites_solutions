#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 301
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
vector<int> cc[maxN];
int ccPos[maxN];
int ccn = 1;
bool vis[maxN];

void dfs(int node)
{
    vis[node] = true;
    ccPos[node] = ccn;
    cc[ccn].push_back(node);

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

    int n;
    char dum;

    cin >> n;

    int arr1[n + 1];

    REP(i, 1, n + 1)
    cin >> arr1[i];

    REP(i, 1, n + 1)
    {
        REP(j, 1, n + 1)
        {
            cin >> dum;

            if (dum == '1')
            {
                arr[arr1[i]].push_back(arr1[j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            sort(cc[ccn].begin(), cc[ccn].end(), greater<>());
            ccn++;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        cout << cc[ccPos[arr1[i]]].back() << " ";
        cc[ccPos[arr1[i]]].pop_back();
    }

    return 0;
}