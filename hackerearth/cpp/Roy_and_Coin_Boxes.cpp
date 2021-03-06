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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN];
int fre[maxN];

void solve()
{
    int n, m, l, r;
    cin >> n;
    cin >> m;

    REP(i, 1, m)
    {
        cin >> l >> r;
        arr[l] += 1;
        arr[r + 1] -= 1;
    }

    int maxFre = -INF;

    REP(i, 1, n)
    {
        arr[i] += arr[i - 1];
        fre[arr[i]]++;
        maxFre = max(maxFre, arr[i]);
        // cout << arr[i] << " ";
    }

    REP(i, 1, maxFre)
    fre[i] += fre[i - 1];

    int q, x;
    cin >> q;

    while (q--)
    {
        cin >> x;

        if (x > maxFre)
            cout << 0 << endl;
        else
            cout << fre[maxFre] - fre[x - 1] << endl;
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