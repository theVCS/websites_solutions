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
    string n1, sum;
    cin >> n1 >> sum;
    string res;

    int sum_index = sum.size() - 1, n1_index = n1.size() - 1;

    while (n1_index >= 0)
    {
        if(n1[n1_index]>sum[sum_index])
        {
            ll val = (sum[sum_index]-'0') + 10*(sum[sum_index-1]-'0');
            int c = (val - (n1[n1_index]-'0'));
            // cout<<c<<endl;

            if(c>9||c<0)
            {
                cout<<-1<<endl;
                return;
            }
            
            char h = char(c+'0');
            res.push_back(h);
            sum_index-=2;
        }
        else
        {
            ll val = (sum[sum_index]-'0');
            int c = (val - (n1[n1_index]-'0'));
            
            // cout<<c<<endl;
            if(c>9||c<0)
            {
                cout<<-1<<endl;
                return;
            }
            
            char h = char(c+'0');
            res.push_back(h);
            sum_index-=1;
        }

        n1_index--;
    }

    while (sum_index>=0)
    {
        res.push_back(sum[sum_index--]);
    }

    reverse(all(res));

    bool flag=true;
    string n2;


    for(char c: res)
    {
        if(c=='0' && flag)continue;
        flag=false;
        n2.push_back(c);
    }
    
    
    cout<<n2<<endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t = 1;

    cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}