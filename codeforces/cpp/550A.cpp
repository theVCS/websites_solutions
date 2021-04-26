#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 1000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

string str;
vector<int> first, second;

void solve()
{
    cin >> str;

    if(str.size() == 1)
    {
        cout<<"NO";
        return;
    }

    REP(i, 0, str.size() - 2)
    {
        if (str[i] == 'A' && str[i + 1] == 'B')
            first.push_back(i);
        if (str[i] == 'B' && str[i + 1] == 'A')
            second.push_back(i);
    }

    for (int ele : first)
    {
        int index = lower_bound(all(second), ele + 2) - second.begin();

        if(index < second.size())
        {
            cout<<"YES";
            return;
        }
    }

    for (int ele : second)
    {
        int index = lower_bound(all(first), ele + 2) - first.begin();

        if(index < first.size())
        {
            cout<<"YES";
            return;
        }
    }

    cout<<"NO";
    // cout<<(lower_bound(all(first),15) - first.begin());
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