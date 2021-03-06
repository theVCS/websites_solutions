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

int N;
vector<int>vec;
ll dp[10][10];

ll fun(int n = 0, int prev = -1)
{
    if(n == N)
    {
        return 1;
    }
    else if(prev == -1)
    {
        ll res = 0;

        for(int ele: vec)
        {
            res += fun(n + 1, ele);
        }

        return res;
    }
    else
    {
        ll res = 0;

        for(int ele: vec)
        {
            if(abs(prev - ele) <= 2)
            {
                res+=fun(n+1,ele);
            }
        }

        return res;
    }
}

void solve()
{
    int m, dum;
    cin>>m>>N;

    vec.clear();

    REP(i,1,m)
    {
        cin>>dum;
        vec.push_back(dum);
    }

    cout<<fun()<<endl;
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

    REP(i,1,t)
    {
        cout<<"Case "<< i << ": ";
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}