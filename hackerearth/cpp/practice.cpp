#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<string> v;
    string x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    string beg, mid, end;
    for (ll i = 0; i < n; i++)
    {
        ll first = v[i].find_first_of('*');
        ll last = v[i].find_last_of('*');

        for (ll z = beg.size(); z < first; z++)
        {
            beg += v[i][z];
        }

        for (ll z = end.size(); v[i].size() - 1 - z > last; z++)
        {
            end += v[i][v[i].size() - 1 - z];
        }
        for (ll z = first + 1; z < last; z++)
        {
            if (v[i][z] != '*')
                mid += v[i][z];
        }
    }

    reverse(end.begin(), end.end());
    cout << beg + mid + end;

    return 0;
}