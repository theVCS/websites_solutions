#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 101
#define INF 1000000000
#define endl "\n"
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

int arr[maxN];

int indexFinder(int i, int n)
{
    int val = INF, index = -1;

    REP(k, i, n + 1)
    {
        if (val > arr[k])
        {
            val = arr[k];
            index = k;
        }
    }

    return index;
}

void solve()
{
    int n;

    cin >> n;

    REP(i, 1, n + 1)
        cin >> arr[i];

    int res = 0;

    REP(i, 1, n)
    {
        int a = i;
        int b = indexFinder(i, n);

        res += b - a + 1;

        while (a < b)
        {
            swap(arr[a], arr[b]);
            a++;
            b--;
        }
    }

    cout << res << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream fi("input.txt");
    // ofstream fo("output.txt");

    // fi >> input;
    // fo << output;

    int t = 1;

    cin >> t;

    REP(i, 1, t + 1)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}