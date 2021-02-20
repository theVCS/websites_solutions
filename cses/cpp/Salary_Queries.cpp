#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200011
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll arr[maxN];
vector<ll> vec;

int main(int argc, char const *argv[])
{
    int n, m;
    char c[2];
    ll a, b;

    scanf("%d %d", &n, &m);

    REP(i, 1, n + 1)
    {
        scanf("%lld", arr + i);
        vec.push_back(arr[i]);
    }

    sort(vec.begin(), vec.end());

    while (m--)
    {
        scanf("%s", c);
        scanf("%lld %lld", &a, &b);

        if (c[0] == '!')
        {
            vec.erase(lower_bound(vec.begin(), vec.end(), arr[a]));
            vec.insert(upper_bound(vec.begin(), vec.end(), b), b);
            arr[a] = b;
        }
        else
        {
            printf("%d\n", upper_bound(vec.begin(), vec.end(), b) - lower_bound(vec.begin(), vec.end(), a));
        }
    }

    return 0;
}