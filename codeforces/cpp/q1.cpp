#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 129
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct partic
{
    string name;
    int s;
    int p;
} participant[130];

bool cmp(partic a, partic b)
{
    if (a.s == b.s)
        return a.p < b.p;
    return (a.s > b.s);
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
        int n;

        cin >> n;

        REP(i, 0, n)
        {
            cin >> participant[i].name >> participant[i].s >> participant[i].p;
        }

        sort(participant, participant + n, cmp);

        cout << participant[0].name << endl;
    }

    return 0;
}