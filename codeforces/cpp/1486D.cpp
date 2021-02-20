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
vector<int> segTree[maxN * 4];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si].push_back(arr[ss]);
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);

        int i = 0, j = 0;

        while (i < segTree[2 * si].size() && j < segTree[2 * si + 1].size())
            if (segTree[2 * si][i] < segTree[2 * si + 1][j])
                segTree[si].push_back(segTree[2 * si][i]), i++;
            else
                segTree[si].push_back(segTree[2 * si + 1][j]), j++;

        while (i < segTree[2 * si].size())
            segTree[si].push_back(segTree[2 * si][i]), i++;
        while (j < segTree[2 * si + 1].size())
            segTree[si].push_back(segTree[2 * si + 1][j]), j++;
    }
}

int query(int si, int ss, int se, int qs, int qe)
{
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;

    cin >> n >> k;

    REP(i, 1, n + 1)
    {
        cin >> arr[i];
    }

    build(1,1,n);

    return 0;
}