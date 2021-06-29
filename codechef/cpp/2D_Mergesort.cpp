#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 1000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define printd(x) cout << fixed << setprecision(10) << x
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        power >>= 1;
    }
    return res;
}

int n, m;
int arr[1001][1001];
int helper[1001];

void rowMerger(int cs, int ce, int rs, int re)
{
    int midc = (cs + ce) / 2;

    REP(row, rs, re)
    {
        int i = cs, j = midc + 1, index = 0;

        while (i <= midc && j <= ce)
        {
            if (arr[row][i] > arr[row][j])
                helper[++index] = arr[row][j++];
            else
                helper[++index] = arr[row][i++];
        }

        while (i <= midc)
        {
            helper[++index] = arr[row][i++];
        }

        while (j <= ce)
        {
            helper[++index] = arr[row][j++];
        }

        while (index)
        {
            arr[row][index + cs - 1] = helper[index];
            index--;
        }
    }
}

void colMerger(int rs, int re, int cs, int ce)
{
    int midr = (rs + re) / 2;

    REP(col, cs, ce)
    {
        int i = rs, j = midr + 1, index = 0;

        while (i <= midr && j <= re)
        {
            if (arr[i][col] > arr[j][col])
                helper[++index] = arr[j++][col];
            else
                helper[++index] = arr[i++][col];
        }

        while (i <= midr)
        {
            helper[++index] = arr[i++][col];
        }

        while (j <= re)
        {
            helper[++index] = arr[j++][col];
        }

        while (index)
        {
            arr[index + rs - 1][col] = helper[index];
            index--;
        }
    }
}

void mergeSort(int x1, int x2, int y1, int y2)
{
    if (x1 < x2 || y1 < y2)
    {
        int midx = (x1 + x2) / 2;
        int midy = (y1 + y2) / 2;

        mergeSort(x1, midx, y1, midy);
        mergeSort(x1, midx, midy + 1, y2);
        mergeSort(midx + 1, x2, y1, midy);
        mergeSort(midx + 1, x2, midy + 1, y2);

        rowMerger(y1, y2, x1, midx);
        rowMerger(y1, y2, midx + 1, x2);
        colMerger(x1, x2, y1, midy);
        colMerger(x1, x2, midy + 1, y2);
    }
}

void solve()
{
    cin >> n >> m;

    REP(i, 1, n)
    REP(j, 1, m)
    cin >> arr[i][j];

    mergeSort(1, n, 1, m);

    REP(i, 1, n)
    {
        REP(j, 1, m)
        {
            cout << arr[i][j] << " ";
        }
        // cout<<endl;
    }
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