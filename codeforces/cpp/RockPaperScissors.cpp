#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
#define all(x) (x).begin(), (x).end()

int rock[maxN], paper[maxN], scissors[maxN];

int fun(string s, int n)
{
    int res = 0;

    // intitialization
    REP(i, 1, n + 1)
    {
        if (s[i - 1] == 'R')
        {
            rock[i] = rock[i - 1] + 1;
            scissors[i] = scissors[i - 1];
            paper[i] = paper[i - 1];
        }
        else if (s[i - 1] == 'P')
        {
            paper[i] = 1 + paper[i - 1];
            scissors[i] = scissors[i - 1];
            rock[i] = rock[i - 1];
        }
        else
        {
            scissors[i] = 1 + scissors[i - 1];
            paper[i] = paper[i - 1];
            rock[i] = rock[i - 1];
        }
    }

    for (int x = 0; x <= n; x++)
    {
        for (int y = x; y <= n; y++)
        {
            int win = scissors[x] + (rock[y] - rock[x]) + (paper[n] - paper[y]);
            int loss = paper[x] + (scissors[y] - scissors[x]) + (rock[n] - rock[y]);

            if (win > loss)
                res++;
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    string s;

    cin >> t;

    while (t--)
    {
        cin >> n;
        cin >> s;
        cout << fun(s, n) << endl;
    }

    return 0;
}