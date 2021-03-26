#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 151
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct team
{
    int ques;
    int penalty;
} arr[maxN];

bool cmp(team a, team b)
{
    if (a.ques == b.ques)
        return a.penalty < b.penalty;
    return a.ques > b.ques;
}

int parent[maxN];

int find(int a)
{
    if (parent[a] < 0)
        return a;
    else
        return parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    a = find(a), b = find(b);

    if (a == b)
        return;

    if (parent[a] > parent[b])
        swap(a, b);

    parent[a] += parent[b];
    parent[b] = a;
}

void solve()
{
    int n, k;

    cin >> n >> k;

    REP(i, 0, n)
    {
        cin >> arr[i].ques >> arr[i].penalty;
        parent[i + 1] = -1;
    }

    sort(arr, arr + n, cmp);

    REP(i, 1, n)
    {
        if (arr[i].ques == arr[i - 1].ques && arr[i].penalty == arr[i - 1].penalty)
        {
            merge(i + 1, i);
        }
    }

    cout << -1 * parent[find(k)];
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