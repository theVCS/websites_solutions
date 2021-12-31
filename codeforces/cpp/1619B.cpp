#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 1000001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

set<ll> st;
vector<int>vec;

void init()
{
    ll i = 1;

    while (i * i <= 1000000000)
    {
        st.insert(i * i);
        i++;
    }

    i = 1;

    while (i * i * i <= 1000000000)
    {
        st.insert(i * i * i);
        i++;
    }

    for(ll e: st)vec.push_back(e);
}

void solve()
{
    ll n;
    cin>>n;

    int start = 0, end = vec.size()-1;

    while (start<=end)
    {
        int mid = (start+end)/2;

        if(vec[mid]<=n && (mid==end||vec[mid+1]>n))
        {
            cout<<mid+1<<endl;
            return;
        }
        else if(vec[mid]<=n)
            start=mid+1;
        else end=mid-1;
    }
    
    cout<<0<<endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    init();
    int t = 1;

    cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}