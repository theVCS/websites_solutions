#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 300001
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct node
{
    ll degree;
    ll xorVal;
} arr[maxN];

vector<pair<ll, ll>> edge;
queue<pair<ll, ll>> q;

void solve()
{
    ll n;

    cin >> n;

    REP(i, 0, n)
    {
        cin >> arr[i].degree >> arr[i].xorVal;

        if (arr[i].degree == 1)
        {
            // there is a edge between arr[i].xor and i;
            q.push({i, arr[i].xorVal});
        }
    }

    while (!q.empty())
    {
        ll node = q.front().first;
        ll par = q.front().second;
        q.pop();

        if (arr[node].degree == 0)
            continue;

        edge.push_back({node, par});
        arr[node].degree--;
        arr[node].xorVal = 0;

        arr[par].xorVal ^= node;

        if (--arr[par].degree == 1)
            q.push({par, arr[par].xorVal});
    }

    cout << edge.size() << endl;

    for (pii e : edge)
    {
        cout << e.first << " " << e.second << endl;
    }
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