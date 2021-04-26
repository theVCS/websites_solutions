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
#define maxN 2011
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll arr[maxN];
ll prefix[maxN];
ll suffix[maxN];

void solve()
{
    int n;
    cin >> n;

    REP(i, 1, n)
    {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] ^ arr[i];
    }

    suffix[n] = arr[n];

    RREP(i, n - 1, 1)
    suffix[i] = suffix[i + 1] ^ arr[i];

    if (prefix[n] == 0)
    {
        cout << "YES" << endl;
        return;
    }

    REP(i, 2, n - 1)
    {
        REP(j, i + 1, n)
        {
            if (prefix[i - 1] == suffix[j] && (prefix[j - 1] ^ prefix[i - 1]) == prefix[i - 1])
            {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
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

    cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}