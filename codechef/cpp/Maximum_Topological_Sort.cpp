#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 500001
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
int leafCount[maxN];

void dfs0(int node, int par = -1)
{
    bool flag = true;

    for (int child : arr[node])
    {
        if (child == par)
            continue;
        
        dfs0(child, node);
        
        leafCount[node] += leafCount[child];
        flag = false;
    }

    if(flag)leafCount[node] = 1;
}

void dfs1(int node, int par = -1)
{
    if(par != -1)
    {
        int parAns = leafCount[par] - leafCount[node];
        leafCount[node] += parAns;        
    }

    for(int child: arr[node])
    {
        if(child == par)continue;
        dfs1(child, node);
    }
}

void solve()
{
    int n, k, a, b;

    cin >> n >> k;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    dfs0(1);
    dfs1(1);

    REP(i,1,n+1)cout << i << " -> " << leafCount[i] << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}