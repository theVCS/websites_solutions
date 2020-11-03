#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001

vector<int> arr[maxN];
bool vis[maxN];
int intime[maxN];
vector<int> res;

bool kahn(int n)
{
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 1; i <= n; i++)
    {
        if (intime[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curr = q.top();
        res.push_back(curr);
        q.pop();

        for (int node : arr[curr])
        {
            intime[node]--;

            if (intime[node] == 0)
            {
                q.push(node);
            }
        }
    }

    return res.size() == n;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e, a, b;
    cin >> n >> e;

    while (e--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        intime[b]++;
    }

    if (kahn(n))
    {
        for (int p : res)
        {
            cout << p << " ";
        }
    }
    else
    {
        cout << "Sandro fails." << endl;
    }

    return 0;
}