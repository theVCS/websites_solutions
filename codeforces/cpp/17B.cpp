#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 10001
#define endl "\n"
#define INF 99999999
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

void solve()
{
    int n, m;
    int a, b, c;
    scanf("%d", &n);
    vector<int> q(n);
    vector<int> sp(n, 99999999);

    for (int i = 0; i < n; ++i)
        scanf("%d", &q[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        a--;
        b--;
        if (q[a] > q[b])
            if (sp[b] > c)
                sp[b] = c;
    }

    int tt = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (sp[i] == 99999999)
            tt++;
        else
            sum += sp[i];
    }
    if (tt == 1)
        printf("%d\n", sum);
    else
        printf("-1\n");
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