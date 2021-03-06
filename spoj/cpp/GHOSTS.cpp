#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool vis[10001];
vector<int> arr[10001];
vector<pair<int, int>> in;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;

    cin >> n >> m;

    REP(i, 1, m + 1)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        in.push_back({a, b});
    }

    for (pair<int, int> e : in)
    {
        if (vis[e.second] && vis[e.first])
        {
            cout << e.first << " " << e.second << endl;
        }

        vis[e.first] = true;
        vis[e.second] = true;
    }

    cout << 0 << " " << 0;

    return 0;
}