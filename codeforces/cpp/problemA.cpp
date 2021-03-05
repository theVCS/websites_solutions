#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct segment
{
    int maxVal, minVal;
} segTree[4 * maxN];

int arr[maxN];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si].maxVal = segTree[si].minVal = arr[ss];
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        segTree[si].maxVal = max(segTree[2 * si].maxVal, segTree[2 * si + 1].maxVal);
        segTree[si].minVal = min(segTree[2 * si].minVal, segTree[2 * si + 1].minVal);
    }
}

void update(int si, int ss, int se, int qi)
{
    if (ss == se)
    {
        segTree[si].maxVal = segTree[si].minVal = arr[ss];
        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
    {
        update(2 * si, ss, mid, qi);
    }
    else
    {
        update(2 * si, mid + 1, se, qi);
    }

    segTree[si].maxVal = max(segTree[2 * si].maxVal, segTree[2 * si + 1].maxVal);
    segTree[si].minVal = min(segTree[2 * si].minVal, segTree[2 * si + 1].minVal);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        int n, m, code, a, b;

        cin >> n >> m;

        REP(i, 1, n + 1)
        cin >> arr[i];

        build(1, 1, n);

        cout << segTree[1].maxVal << " " << segTree[1].minVal << endl;
        cout << segTree[1].maxVal << " " << segTree[1].minVal << endl;

        while (m--)
        {
            cin >> code;

            if (code == 1)
            {
                cin >> a >> b;
                arr[a] = b;
                update(1, 1, n, a);
            }
            else
            {
                cout << segTree[1].maxVal - segTree[1].minVal + 1 << endl;
            }
        }
    }

    return 0;
}