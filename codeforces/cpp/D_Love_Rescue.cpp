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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[27];
vector<pii> res;

void dfs(int node)
{
    vis[node] = true;

    for(int child : arr[node])
    {
        if (!vis[child])
        {
            res.push_back({node, child});
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
    string s1, s2;

    cin >> n;

    cin >> s1 >> s2;

    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            arr[s1[i] - 96].push_back(s2[i] - 96);
            arr[s2[i] - 96].push_back(s1[i] - 96);
        }
    }

    for (int i = 1; i < 27; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    cout << res.size() << endl;

    for (pair<int, int> e : res)
    {
        cout << char(e.first + 96) << " " << char(e.second + 96) << endl;
    }

    return 0;
}