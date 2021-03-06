#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

void solve()
{
    int n, dum;

    cin >> n;
    vector<int> even, odd;

    REP(i, 1, n + 1)
    {
        cin >> dum;

        if (dum % 2)
            odd.push_back(i);
        else
            even.push_back(i);
    }

    if (even.size() == 0 && odd.size() == 1)
    {
        cout << -1 << endl;
        return;
    }

    if(even.size())
    {
        cout << 1 << endl;
        cout << even[0] << endl;
        return;
    }
    
    cout << 2 << endl;
    cout << odd[0] << " " << odd[1] << endl;
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