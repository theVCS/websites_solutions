#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

map<int, bool> fib;
bool flag;
int subSize[maxN], n;

void init()
{
    int a = 1, b = 1;
    fib[a] = true;

    while (b <= maxN)
    {
        int temp = a;
        a = b;
        b = temp + a;
        fib[b] = true;
    }
}

vector<int> arr[maxN];

void dfs(int node, int par = -1)
{
    subSize[node] = 1;

    for (int child : arr[node])
    {
        if (child == par)
            continue;

        dfs(child, node);

        subSize[node] += subSize[child];
    }

    if (fib[subSize[node]] && fib[n - subSize[node]])
        flag = true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int a, b;

    cin >> n;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    dfs(1);

    if ((fib[n] && flag) || n == 1)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}