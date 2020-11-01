#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
vector<int> arr[100000];
bool vis[100000];
vector<int> primes;
int dis[10000];

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

bool isValid(int a, int b)
{
    int cnt = 0;

    while (a)
    {
        if (a % 10 != b % 10)
        {
            cnt++;
        }
        a /= 10;
        b /= 10;
    }

    if (cnt == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void graphBuilder()
{
    for (int i = 1000; i <= 9999; i++)
    {
        if (isPrime(i))
        {
            primes.push_back(i);
        }
    }

    for (int i = 0; i < primes.size(); i++)
    {
        for (int j = i + 1; j < primes.size(); j++)
        {
            if (isValid(primes[i], primes[j]))
            {
                arr[primes[i]].push_back(primes[j]);
                arr[primes[j]].push_back(primes[i]);
            }
        }
    }
}

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int child : arr[curr])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                dis[child] = dis[curr] + 1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    graphBuilder();

    int t, a, b;
    cin >> t;

    while (t--)
    {
        for (int i = 1000; i <= 9999; i++)
        {
            vis[i] = false;
            dis[i] = -1;
        }

        cin >> a >> b;

        bfs(a);

        if (dis[b] == -1)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << dis[b] << endl;
        }
    }

    return 0;
}