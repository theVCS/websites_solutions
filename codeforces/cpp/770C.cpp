#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> ms, res;
vector<int> arr[maxN];
bool vis[maxN];
int indegree[maxN], n;

void kahn()
{
    queue<int> q;

    REP(i, 1, n + 1)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curr = q.front();
        res.push_back(curr);
        q.pop();

        for (int child : arr[curr])
        {
            indegree[child]--;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, dum;

    cin >> n >> k;

    while (k--)
    {
        cin >> dum;
        ms.push_back(dum);
    }

    REP(i, 1, n + 1)
    {
        cin >> k;

        while (k--)
        {
            cin >> dum;
            arr[dum].push_back(i);
            indegree[i]++;
        }
    }

    kahn();

    for (int e : res)
    {
        cout << e << " ";
    }

    return 0;
}