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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n;
vector<int> arr[maxN], notSame;
int giveV[maxN], reqV[maxN];
vector<int> sol;

void dfs(int node = 1, int par = -1, int odd = 0, int even = 0, int lev = 0)
{
    if (lev % 2)
    {
        if (giveV[node] != reqV[node] && !odd)
        {
            sol.push_back(node);
            odd ^= 1;
        }
        else if (giveV[node] == reqV[node] && odd)
        {
            sol.push_back(node);
            odd ^= 1;
        }
    }
    else
    {
        if (giveV[node] != reqV[node] && !even)
        {
            sol.push_back(node);
            even ^= 1;
        }
        else if (giveV[node] == reqV[node] && even)
        {
            sol.push_back(node);
            even ^= 1;
        }
    }

    for (int child : arr[node])
    {
        if (child != par)
        {
            dfs(child, node, odd, even, lev + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;

    cin >> n;

    REP(i, 1, n)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    REP(i, 1, n + 1)
    cin >> giveV[i];

    REP(i, 1, n + 1)
    cin >> reqV[i];

    dfs();

    cout << sol.size() << endl;

    for (int e : sol)
    {
        cout << e << endl;
    }

    return 0;
}