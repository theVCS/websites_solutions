#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
vector<int> arr[maxN];
int cnt[maxN];

int dfs(int n)
{

    if (cnt[n] == 2)
    {
        return n;
    }
    else
    {
        cnt[n]++;
        return dfs(arr[n][0]);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        arr[i].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dfs(i) << " ";
        memset(cnt, 0, maxN);
    }

    return 0;
}