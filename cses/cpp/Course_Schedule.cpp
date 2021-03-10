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
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
int indegree[maxN];

void kahn(int n)
{
    queue<int> q;

    REP(i, 1, n + 1)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> res;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        res.push_back(node);

        for (int child : arr[node])
        {
            indegree[child]--;

            if (indegree[child] == 0)
                q.push(child);
        }
    }

    if (res.size() == n)
        for (int e : res)
            cout << e << " ";
    else
        cout << "IMPOSSIBLE";
}

void solve()
{
    int n, m, a, b;

    cin >> n >> m;

    REP(i, 0, m)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        indegree[b]++;
    }

    kahn(n);
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

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}