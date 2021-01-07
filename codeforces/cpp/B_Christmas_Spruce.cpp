#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1050
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int outdegree[maxN], leafCount[maxN];
vector<int> arr[maxN];

bool dfs(int node, int par = -1)
{
    int size = 0;

    for (int child : arr[node])
    {
        if (child != par)
        {
            if (!dfs(child, node))
            {
                return false;
            }
        }
        if (outdegree[child] == 0)
        {
            size++;
        }
    }

    if (size >= 3 || (size == 0 && arr[node].size() == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a;

    cin >> n;

    REP(i, 1, n)
    {
        cin >> a;
        outdegree[a]++;
        arr[a].push_back(i + 1);
    }

    if (dfs(1))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    

    return 0;
}