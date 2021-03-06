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

int arr[maxN];
int segTree[4 * maxN];
int ans;

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si] = arr[ss];
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        segTree[si] = max(segTree[2 * si], segTree[2 * si + 1]);
    }
}

void query(int si, int ss, int se, int c)
{
    if (ss == se)
    {
        if (segTree[si] >= c)
        {
            segTree[si] -= c;
            ans = ss;
        }
        else
            ans = 0;
        return;
    }

    int left = 2 * si;
    int right = left + 1;
    int mid = (ss + se) / 2;

    if (segTree[left] >= c)
    {
        query(left, ss, mid, c);
    }
    else if (segTree[right] >= c)
    {
        query(right, mid + 1, se, c);
    }
    else
    {
        ans = 0;
    }

    segTree[si] = max(segTree[2 * si], segTree[2 * si + 1]);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, c;

    cin >> n >> m;

    REP(i, 1, n + 1)
    cin >> arr[i];

    build(1, 1, n);

    while (m--)
    {
        cin >> c;
        query(1, 1, n, c);
        cout << ans << " ";
    }

    return 0;
}