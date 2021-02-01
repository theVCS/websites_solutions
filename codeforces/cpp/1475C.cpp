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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> girls[maxN];
int boys[maxN];
bool vis[maxN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, a, b, k, g;

    cin >> t;

    while (t--)
    {
        cin >> a >> b >> k;

        REP(i, 0, max(a, b) + 1)
        {
            girls[i].clear();
            vis[i] = false;
        }

        REP(i, 1, k + 1)
        cin >> boys[i];

        REP(i, 1, k + 1)
        {
            cin >> g;
            girls[boys[i]].push_back(g);
        }

        int cnt = 0;

        for (int i = 1; i < a + 1; i++)
        {
            for (int girl : girls[i])
            {
                if (vis[girl] == false)
                {
                    vis[girl] = true;
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}