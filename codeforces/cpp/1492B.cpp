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

int arr[maxN];
int label[maxN];
int segTree[4 * maxN];
bool use[maxN];

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

void update(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
    {
        return;
    }
    if (qs <= ss && qe >= se)
    {
        segTree[si] = INT_MIN;
        return;
    }
    int mid = (ss + se) / 2;
    update(2 * si, ss, mid, qs, qe);
    update(2 * si + 1, mid + 1, se, qs, qe);
    segTree[si] = max(segTree[2 * si], segTree[2 * si + 1]);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        REP(i, 1, n + 1)
        {
            cin >> arr[i];
            label[arr[i]] = i;
        }

        build(1, 1, n);
        // cout << segTree[1];
        int index = label[segTree[1]];
        int end = n;

        while (end)
        {
            for (int i = index; i <= end; i++)
            {
                cout << arr[i] << " ";
            }

            update(1, 1, n, index, end);
            end = index - 1;
            index = label[segTree[1]];
        }
        cout << endl;
    }

    return 0;
}