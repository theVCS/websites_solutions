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

vector<int> arr;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        int n, k, dum;
        cin >> n >> k;

        arr.clear();

        while (n--)
        {
            cin >> dum;

            if (dum && k % dum == 0)
                arr.push_back(dum);
        }

        sort(all(arr));

        bool flag = true;
        n = arr.size();

        REP(i, 0, n - 1)
        {
            int e1 = arr[i];
            int e2 = k / e1;

            if (e2 < e1)
                break;

            if (find(arr.begin() + i + 1, arr.end(), e2) != arr.end())
            {
                cout << e1 << " " << e2 << endl;
                flag = false;
                break;
            }
        }

        if (flag)
            cout << -1 << endl;
    }

    return 0;
}