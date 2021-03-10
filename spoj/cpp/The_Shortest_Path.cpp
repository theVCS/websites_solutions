#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 10001
#define endl "\n"
#define INF 100000000000000001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

map<string, int> mp;
vector<pair<int, ll>> arr[maxN];
ll dis[maxN];

void dikstras(int n, int src, int des)
{
    REP(i, 1, n + 1)
    dis[i] = INF;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push({0, src});
    dis[src] = 0;

    while (!q.empty())
    {
        int node = q.top().second;
        ll nodeDis = q.top().first;
        q.pop();

        if (node == des)
            return;

        for (pair<int, ll> child : arr[node])
        {
            if (dis[child.first] > nodeDis + child.second)
            {
                dis[child.first] = nodeDis + child.second;
                q.push({dis[child.first], child.first});
            }
        }
    }
}

void solve()
{
    mp.clear();

    int n;
    char str[20];
    scanf("%d", &n);

    REP(i, 0, n)
    {
        arr[i+1].clear();

        scanf("%s", str);
        mp[str] = i + 1;
        int k, b;
        ll c;
        scanf("%d", &k);

        while (k--)
        {
            scanf("%d %lld", &b, &c);
            arr[i + 1].push_back({b, c});
        }
    }

    int q;
    scanf("%d", &q);

    while (q--)
    {
        char s1[20], s2[20];
        scanf("%s %s", s1, s2);
        int src = mp[s1];
        int des = mp[s2];
        dikstras(n, src, des);
        printf("%lld\n", dis[des]);
    }
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    //cin >> t;
    scanf("%d", &t);

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}