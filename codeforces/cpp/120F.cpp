#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 101
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
int nodeX, dis;

void dfs(int node = 1, int par = -1, int lev = 0)
{
    if (dis < lev)
    {
        dis = lev;
        nodeX = node;
    }

    for(int child: arr[node])
    {
        if (child != par)
        {
            dfs(child, node, lev + 1);
        }
    }
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ifstream filptr("input.txt");
    ofstream outpter("output.txt");
    int n, ni, a, b;

    int res = 0;

    filptr >> n;

    while (n--)
    {
        filptr >> ni;

        dis = 0, nodeX = 1;
        REP(i,1,ni + 1)arr[i].clear();

        REP(i, 0, ni - 1)
        {
            filptr >> a >> b;
            arr[a].push_back(b), arr[b].push_back(a);
        }

        dfs();
        dfs(nodeX);

        res += dis;
    }

    outpter << res;

    filptr.close();
    outpter.close();

    return 0;
}