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

vector<int>arr1,arr2;

void solve()
{
    int n, dum;
    cin >> n;

    REP(i,0,n)
    {
        cin >> dum;
        arr1.push_back(dum);
    }

    REP(i,0,n-1)
    {
        cin >> dum;
        arr2.push_back(dum);
    }

    sort(all(arr1));
    sort(all(arr2));

    bool flag = true;

    REP(i,0,arr2.size())
    {
        if(arr1[i] != arr2[i])
        {
            cout << arr1[i] << endl;
            flag = false;
            break;
        }
    }

    if(flag)
    {
        cout << arr1.back() << endl;
    }

    arr1.clear();

    REP(i,0,n-2)
    {
        cin >> dum;
        arr1.push_back(dum);
    }

    sort(all(arr1));

    flag = true;

    REP(i,0,arr1.size())
    {
        if(arr1[i] != arr2[i])
        {
            cout << arr2[i] << endl;
            flag = false;
            break;
        }
    }

    if(flag)
    {
        cout << arr2.back() << endl;
    }
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