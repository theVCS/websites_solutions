#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN];

struct info
{
    int num;
    int index;
} prefix[maxN], suffix[maxN];

void solve()
{
    int n;
    cin >> n;

    prefix[0].num = suffix[n + 1].num = INF;

    REP(i, 1, n + 1)
    cin >> arr[i];

    REP(i, 1, n + 1)
    {
        if (arr[i] < prefix[i - 1].num)
        {
            prefix[i].num = arr[i];
            prefix[i].index = i;
        }
        else
        {
            prefix[i] = prefix[i - 1];
        }
    }

    for (int i = n; i >= 1; i--)
    {
        if (arr[i] < suffix[i + 1].num)
        {
            suffix[i].num = arr[i];
            suffix[i].index = i;
        }
        else
        {
            suffix[i] = suffix[i + 1];
        }
    }

    REP(i, 2, n)
    {
        int mn1 = prefix[i - 1].num;
        int mn2 = suffix[i + 1].num;

        if(arr[i] > mn1 && arr[i] > mn2)
        {
            cout << "YES" << endl;
            cout << prefix[i - 1].index << " " << i << " " << suffix[i + 1].index << endl;
            return;
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