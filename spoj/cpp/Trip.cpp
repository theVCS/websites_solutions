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

string s, t;

const int sz = 81;
int dp[sz][sz];
set<string> st;

template <class T>
class LongestCommonSubsequence
{
    T a, b;
    string res;

public:
    LongestCommonSubsequence(T &A, T &B)
    {
        a = A, b = B;
    }

    int lcsLength()
    {
        int n = a.size();
        int m = b.size();

        REP(i, 0, n)
        dp[i][0] = 0;
        REP(j, 0, m)
        dp[0][j] = 0;

        REP(i, 1, n)
        {
            REP(j, 1, m)
            {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }

    void allSeqs(int I = 1, int J = 1, int d = 0)
    {
        // cout<<I<<" "<<J<<' '<<d<<endl;
        int n = a.size();
        int m = b.size();

        if(dp[n][m]==d)
        {
            cout<<res<<endl;
            return;
        }

        if(I>n||J>m)return;

        for(char c='a';c<='z';c++)
        {
            bool done=false;

            REP(i,I,n)
            {
                if(c==a[i-1])
                {
                    REP(j,J,m)
                    {
                        if(b[j-1]==c && dp[i][j] == d+1)
                        {
                            res.push_back(c);
                            allSeqs(i+1,j+1,d+1);
                            res.pop_back();
                            done = true;
                            break;
                        }
                    }
                }

                if(done)break;
            }
        }
    }
};

void solve()
{
    cin >> s >> t;
    LongestCommonSubsequence<string> obj(s, t);
    int x = obj.lcsLength();
    obj.allSeqs();
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
