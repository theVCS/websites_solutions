#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, arr[maxN];
int check1[maxN], check2[maxN];
int prefix[maxN], suffix[maxN];

void init()
{
    REP(i, 0, n + 1)
    {
        check1[i] = check2[i] = false;
    }

    int l = 0, r = 0;

    REP(i, 0, n)
    {
        check1[arr[i]] = true;
        check2[arr[n - i - 1]] = true;

        while (check1[l])
        {
            l++;
        }
        while (check2[r])
        {
            r++;
        }

        prefix[i] = l;
        suffix[n - 1 - i] = r;
    }
}

int dp(int x, int y)
{
    if (x > y)
    {
        return 0;
    }
    int res = 0;

    for (int k = x; k < y; k++)
    {
        int temp1 = dp(x, k);
        int temp2 = dp(k + 1, y);

        if (prefix[k] == suffix[k + 1])
        {
            res++;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        cin >> n;

        REP(i, 0, n)
        cin >> arr[i];

        init();

        // REP(i, 0, n)
        // {
        //     cout << prefix[i] << " ";
        // }
        // cout << endl;

        // REP(i, 0, n)
        // {
        //     cout << suffix[i] << " ";
        // }
        // cout << endl;
    }

    return 0;
}