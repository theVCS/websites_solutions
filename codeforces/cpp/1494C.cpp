#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct segment
{
    int l, r, boxes;
} seg[maxN];

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

        vector<int> boxes;
        int boxCount = 0;
        map<int, int> mp;
        int prev = INT_MIN, dum, index = -1;
        bool flag = true;

        REP(i, 0, n)
        {
            cin >> dum;

            if (dum > 0 && flag)
                boxCount = 0, flag = false;
            mp[dum] = ++boxCount;
            boxes.push_back(dum);
        }

        // special index
        REP(i, 0, m)
        {
            cin >> dum;

            if (dum == prev + 1)
            {
                seg[index].r = dum;
                int index = lower_bound(all(boxes), dum) - boxes.begin();
                seg[index].boxes = mp[boxes[index]];
            }
            else
            {
                index++;
                seg[index].l = seg[index].r = dum;
                int index = lower_bound(all(boxes), dum) - boxes.begin();
                seg[index].boxes = mp[boxes[index]];
            }

            prev = dum;
        }

        REP(i, 0, index + 1)
        cout << seg[i].l << " " << seg[i].r << " " << seg[i].boxes << endl;
    }

    return 0;
}