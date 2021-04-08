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
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct project
{
    int start, end;
    ll price;
} arr[maxN];
int n;

bool cmp(project a, project b)
{
    return a.end < b.end;
}

int bs(int lindex)
{
    int maxDay = arr[lindex].start;
    int start = 1, end = lindex - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid].end < maxDay && arr[mid + 1].end >= maxDay)
        {
            return mid;
        }
        else if (arr[mid].end >= maxDay)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

ll dp[maxN];

ll fun(int index)
{
    if (index <= 0)
        return 0;
    else if (dp[index] != -1)
        return dp[index];
    else
    {
        return dp[index] = max(arr[index].price + fun(bs(index)), fun(index - 1));
    }
}

void solve()
{
    cin >> n;

    REP(i, 1, n + 1)
    {
        cin >> arr[i].start >> arr[i].end >> arr[i].price;
        dp[i] = -1;
    }

    sort(arr + 1, arr + 1 + n, cmp);

    cout << fun(n);
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