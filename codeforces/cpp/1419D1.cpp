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

int arr[maxN];
int res[maxN];

void solve()
{
    int n;

    cin >> n;

    cout << n / 2 - 1 + (n % 2) << endl;

    REP(i, 1, n + 1)
    cin >> arr[i];

    sort(arr + 1, arr + 1 + n);

    int i = 1, j = 2, I = 1;
    while (i <= n && j <= n)
    {
        res[I] = arr[j], j+=2, I++;
        res[I] = arr[i], i+=2, I++;
    }
    
    while (i <= n)
    {
        res[I] = arr[i], i+=2, I++;
    }
    
    while (j <= n)
    {
        res[I] = arr[j], j+=2, I++;
    }
    

    REP(i,1,n+1)cout << res[i] << " ";
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