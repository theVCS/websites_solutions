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
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN];
vector<int> pos, neg;

void solve()
{
    int n, dum;
    cin >> n;

    arr[0] = 1;
    REP(i, 1, n + 1)
    {
        cin >> dum;
        arr[i] = (dum / abs(dum)) * arr[i - 1];

        if (arr[i] > 0)
            pos.push_back(i);
        else
            neg.push_back(i);
    }

    ll posWays = 0, negWays = 0;

    REP(i, 1, n + 1)
    {
        // reached at index i now need to choose some index j > i
        if (arr[i - 1] > 0)
        {
            // finding +ve product
            posWays += pos.size() - (lower_bound(all(pos), i + 1) - pos.begin()) + (arr[i] * arr[i - 1] > 0);
            //finding negative product
            negWays += neg.size() - (lower_bound(all(neg), i + 1) - neg.begin()) + +(arr[i] * arr[i - 1] < 0);
        }
        else
        {
            // finding +ve product
            posWays += neg.size() - (lower_bound(all(neg), i + 1) - neg.begin()) + (arr[i] * arr[i - 1] > 0);
            //finding negative product
            negWays += pos.size() - (lower_bound(all(pos), i + 1) - pos.begin()) + (arr[i] * arr[i - 1] < 0);
        }
    }
    cout << negWays << " " << posWays << endl;
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