#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100011
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int t[maxN];
int prefix[maxN];
int suffix[maxN];

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    ifstream filptr("input.txt");
    ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int n;
    filptr >> n;

    REP(i, 1, n + 1)
    filptr >> t[i];

    REP(i, 1, n + 1)
    prefix[i] = prefix[i - 1] + int(t[i] >= 0);

    for (int i = n; i > 0; i--)
    {
        suffix[i] = suffix[i + 1] + int(t[i] <= 0);
    }

    int index = 1;
    int res = INT_MAX;

    // changing all elements to negative to the left of index
    // changing all elements to positive to the right of index including index
    while (index <= n + 1)
    {
        int cnt1 = prefix[index - 1];
        int cnt2 = suffix[index];
        res = min(res, cnt1 + cnt2);
        index++;
    }
    outpter << res;

    filptr.close();
    outpter.close();

    return 0;
}