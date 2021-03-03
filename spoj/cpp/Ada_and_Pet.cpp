#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 500001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int pi[maxN];

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t, k, n;
    char s[maxN];

    scanf("%d", &t);

    while (t--)
    {
        scanf("%s", s);
        scanf("%d", &k);
        n = strlen(s);

        REP(i, 1, n)
        {
            int j = pi[i - 1];

            while (j && s[i] != s[j])
                j = pi[j - 1];

            if (s[i] == s[j])
                j++;

            pi[i] = j;
        }

        printf("%lld\n", k * 1LL * n - (k - 1) * 1LL * pi[n - 1]);
    }

    return 0;
}