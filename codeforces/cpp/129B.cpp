#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 101
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, cnt, ans = 0;

    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    while (true)
    {
        cnt = 0;
        vector<int> res;

        REP(i, 1, n + 1)
        {
            if (arr[i].size() == 1)
            {
                cnt++;
                res.push_back(i);
            }
        }

        if (cnt)
        {
            ans++;

            for (int e : res)
            {
                int a = e;
                int b = arr[a][0];

                arr[a].clear();
                arr[b].erase(remove(arr[b].begin(), arr[b].end(), a), arr[b].end());
            }
        }
        else
            break;
    }

    cout << ans;

    return 0;
}