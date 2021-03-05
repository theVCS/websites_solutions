#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 700001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int perA[maxN], perB[maxN], perAlab[maxN], perBlab[maxN];
vector<int> segTree1[4 * maxN], segTree2[4 * maxN];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree1[si].push_back(perA[ss]);
        segTree2[si].push_back(perB[ss]);
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        merge(all(segTree1[2 * si]), all(segTree1[2 * si + 1]), back_inserter(segTree1[si]));
        merge(all(segTree2[2 * si]), all(segTree2[2 * si + 1]), back_inserter(segTree2[si]));
    }
}

int upperQuery(int si, int ss, int se, int qs, int qe, int val)
{
    if (ss > qe || se < qs)
        return 0;

    if (qs <= ss && qe >= se)
    {
        return lower_bound(all(segTree1[si]), val) - segTree1[si].begin();
    }
    int mid = (ss + se) / 2;
    return upperQuery(2 * si, ss, mid, qs, qe, val) + upperQuery(2 * si + 1, mid + 1, se, qs, qe, val);
}

int lowerQuery(int si, int ss, int se, int qs, int qe, int val)
{
    if (ss > qe || se < qs)
        return 0;

    if (qs <= ss && qe >= se)
    {
        return lower_bound(all(segTree2[si]), val) - segTree2[si].begin();
    }
    int mid = (ss + se) / 2;
    return lowerQuery(2 * si, ss, mid, qs, qe, val) + lowerQuery(2 * si + 1, mid + 1, se, qs, qe, val);
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

        REP(i, 0, 4 * n + 1)
        segTree1[i].clear(), segTree2[i].clear();

        REP(i, 1, n + 1)
        {
            cin >> perA[i];
            perAlab[perA[i]] = i;
        }
        REP(i, 1, n + 1)
        {
            cin >> perB[i];
            perBlab[perB[i]] = i;
        }

        build(1, 1, n);

        int res = 0;
        REP(i, 1, n + 1)
        {
            int index1 = perAlab[i];
            int index2 = perBlab[i];

            int left1, right1;
            int left2, right2;

            // finding number of numbers less than i in left
            left1 = upperQuery(1, 1, n, 1, index1 - 1, i);
            right2 = lowerQuery(1, 1, n, index2 + 1, n, i);
            res += min(left1, right2);

            right1 = upperQuery(1, 1, n, index1 + 1, n, i);
            left2 = lowerQuery(1, 1, n, 1, index2 - 1, i);
            res += min(right1, left2);
        }

        cout << res << endl;
    }

    return 0;
}