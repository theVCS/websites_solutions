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

    int t;

    cin >> t;

    while (t--)
    {
        int n, m;

        cin >> n >> m;

        map<int, int> age, candies;
        int dum;

        REP(i, 0, n)
        {
            cin >> dum;
            age[dum]++;
        }

        REP(i, 0, m)
        {
            cin >> dum;
            candies[dum]++;
        }

        bool flag = true;

        for (auto stu : age)
        {
            auto it = candies.begin();

            while (true)
            {
                if (candies.size() == 0)
                    break;

                it = candies.begin();

                if (stu.second > it->second)
                    candies.erase(it);
                else
                    break;
            }

            if (candies.size() == 0)
            {
                cout << "NO\n";
                flag = false;
                break;
            }

            candies.erase(it);
        }

        if (flag)
        {
            cout << "YES\n";
        }
    }

    return 0;
}