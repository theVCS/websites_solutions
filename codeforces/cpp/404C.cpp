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
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
vector<pii> edges;

void solve()
{
    int n, k, dum, mxLevel = 0;

    cin >> n >> k;

    REP(i, 0, n)
    {
        cin >> dum;
        arr[dum].push_back(i + 1);
        mxLevel = max(mxLevel, dum);
    }

    if (arr[0].size() != 1)
    {
        cout << -1;
        return;
    }

    REP(i, 0, mxLevel)
    {
        if (i == 0)
        {
            if (1LL * arr[1].size() <= 1LL * arr[0].size() * k)
            {
                for (int e : arr[1])
                {
                    edges.push_back({e, arr[0][0]});
                }
            }
            else
            {
                cout << -1;
                return;
            }
        }
        else if (1LL * arr[i + 1].size() <= 1LL * arr[i].size() * (k - 1))
        {
            int k = 0, j = 0;
            int cnt = 0;

            while (true)
            {
                if (j == arr[i + 1].size())
                    break;
                if (cnt == k - 1)
                    cnt = 0, k++;

                edges.push_back({arr[i + 1][j], arr[i][k]});
                j++;
                cnt++;
            }
        }
        else
        {
            cout << -1;
            return;
        }
    }

    cout << edges.size() << endl;
    for (pii e : edges)
        cout << e.first << " " << e.second << endl;
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