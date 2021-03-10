#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int,int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define endl "\n"
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<pii>arr[maxN];
priority_queue<pii,vector<pii>,greater<pii>>;
int dist[maxN];
    
void solve()
{
    int n, m, q, a, b, c;

    cin >> n >> m >> q;

    REP(i,0,m)
    {
        cin >> a >> b >> c;
        arr[a].push_back({b,c}), arr[b].push_back({a,c});
    }
}
    
int main(int argc, char const *argv[]){
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