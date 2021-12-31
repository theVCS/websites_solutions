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

void solve()
{
    string s;
    cin >> s;

    int prefix[20] = {0};

    REP(i, 0, s.size() - 1)
    prefix[i] = (i ? prefix[i - 1] : 0) + (s[i] - '0');
    ll ans = prefix[s.size()-1];

    RREP(i, s.size() - 1, 0)
    {
        if(s[i]=='0')continue;
        ll nans = (i?prefix[i-1]:0)+(s[i]-'0'-1)+9*(s.size()-i-1);

        if(nans>ans)
        {
            ans=nans;
            s[i]=s[i]-1;

            REP(j,i+1,s.size()-1)
            {
                s[j]='9';
            }
        }
    }

    bool flag=true;
    string res;

    for(char &c: s)
    {
        if(c=='0' && flag)continue;
        flag=false;
        res.push_back(c);
    }

    cout<<res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t = 1;

    // cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}