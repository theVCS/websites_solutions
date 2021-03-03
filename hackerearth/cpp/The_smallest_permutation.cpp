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

struct ele
{
    int val, index;
} a[maxN], b[maxN];

bool cmp(ele a, ele b)
{
    return a.val < b.val;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;

    cin >> t;

    while (t--)
    {
        int dum;
        cin >> n;

        REP(i, 0, n)
        {
            cin >> dum;
            a[i].val = dum;
            a[i].index = i;
            b[i].val = dum;
            b[i].index = i;
        }

        sort(b, b + n, cmp);

        bool flag = true;

        for (int i = 0; i < n - 2; i++)
        {
            if (flag)
            {
                if (a[i].val != b[i].val)
                {
                    flag = false;
                    swap(a[i].val, b[i].val);
                    swap(a[b[i].index].val, b[i].val);
                }

                cout << a[i].val << " ";
            }
            else
            {
                cout << a[i].val << " ";
            }
        }

        if (flag)
            swap(a[n - 2].val, a[n - 1].val);

        cout << a[n - 2].val << " " << a[n - 1].val << endl;
    }

    return 0;
}