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

vector<int> vec;
string str1;
string str2;
ll dp[19];
int N;
int b;

ll digitDP(int pos, int flag1 = 1, int flag2 = 1, int nonZero=0)
{
    if (pos == -1)
        return 1;

    ll &res = dp[pos];

    if (flag1 == 0 && flag2 == 0 && res != -1)
        return res;

    ll ans = 0;

    int lb = flag1 ? (str1[pos] - '0') : 0;
    int ub = flag2 ? (str2[pos] - '0') : b-1;

    for(int i: vec)
    {
        if(i>=lb&&i<=ub)
        ans += digitDP(pos - 1, (i == lb && flag1), (i == ub & flag2), nonZero||i);
    }

    return flag1 == 0 && flag2 == 0 ? res = ans : ans;
}

string toBaseB(ll num, int base)
{
    string res;

    while (num)
    {
        res.push_back(char('0'+(num%base)));
        num /= base;
    }
    
    return res;
}

void solve()
{
    while (true)
    {
        memset(dp, -1, sizeof(dp));
        vec.clear();
        
        ll number1, number2;
        string str;

        cin>>number1>>number2;
        cin >> b;
        cin >> str;
        
        if (str[0] == '*')
        {
            return;
        }

        str1=toBaseB(number1,b);
        str2=toBaseB(number2,b);

        while (str1.size() < str2.size())
        {
            str1.push_back('0');
        }

        REP(i, 0, b - 1)
        if (str[i] == 'S')
            vec.push_back(i);

        N = str1.size();
        ll ans = digitDP(N - 1);
        // cout<<str1<<" "<<str2<<endl; 
        cout << ans << endl;
    }
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
