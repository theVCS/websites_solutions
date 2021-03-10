#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 500001
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct jedi
{
    ll sum, minSum;
    int index;
} jd[maxN];
ll ans[maxN];

bool cmp(jedi a, jedi b)
{
    return a.minSum < b.minSum;
}

void binarySearchCount(int n, int i)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (jd[mid].minSum <= jd[i].sum)
        {
            ans[jd[i].index] = mid;
            if (mid < i)
                ans[jd[i].index]++;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
}

void solve()
{
    int n;
    ll arr[3];

    cin >> n;

    REP(i, 0, n)
    {
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr,arr+3);
        jd[i].sum = arr[0] + arr[1] + arr[2];
        jd[i].minSum = arr[0] + arr[1] + 2;
        jd[i].index = i;
    }

    sort(jd, jd + n, cmp);

    REP(i, 0, n)
    {
        binarySearchCount(n, i);
    }

    REP(i, 0, n)
    cout << ans[i] << " ";
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