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

int n, k;
int arr[maxN];

void solve()
{
    int dum;

    cin >> n >> k;

    REP(i, 0, n)
    {
        cin >> dum;
        arr[dum % k]++;
    }

    int cnt = 0;

    REP(i, 0, k / 2 + 1)
    {
        int a = i;
        int b = (k - i) % k;

        int minCnt = min(arr[a], arr[b]);

        if(minCnt == 0)continue;

        if(a == b)
            arr[a] = 0;
        else
        {
            

            if(arr[a] > minCnt)arr[a]--;
            if(arr[b] > minCnt)arr[b]--;

            arr[a]-=minCnt;
            arr[b]-=minCnt;
        }

        cnt++;
    }

    REP(i, 0, k)
    {
        cnt += arr[i];
        arr[i] = 0;
    }

    cout << cnt << endl;
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