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
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct query
{
    int x;
    char c;
} arr[maxN];

map<int, int> mp;
int mp2[maxN];
bool use[maxN];

int ft[maxN];

int query(int index)
{
    int sum = 0;

    while (index)
    {
        sum += ft[index];
        index -= (index & -index);
    }

    return sum;
}

void update(int index, int val)
{
    while (index < maxN)
    {
        ft[index] += val;
        index += (index & -index);
    }
}

void solve()
{
    int n, timer = 0;
    cin >> n;

    REP(i, 1, n + 1)
    {
        cin >> arr[i].c >> arr[i].x;

        if (arr[i].c == 'I' || arr[i].c == 'D' || arr[i].c == 'C')
            mp[arr[i].x];
    }

    for (auto &e : mp)
    {
        e.second = ++timer;
        mp2[timer] = e.first;
    }

    REP(i, 1, n + 1)
    {
        if (arr[i].c == 'I' || arr[i].c == 'D' || arr[i].c == 'C')
            arr[i].x = mp[arr[i].x];
    }

    REP(i, 1, n + 1)
    {
        if (arr[i].c == 'I')
        {
            if (use[arr[i].x] == false)
            {
                update(arr[i].x, 1);
                use[arr[i].x] = true;
            }
        }
        else if (arr[i].c == 'D')
        {
            if (use[arr[i].x] == true)
            {
                update(arr[i].x, -1);
                use[arr[i].x] = false;
            }
        }
        else if (arr[i].c == 'K')
        {
            int start = 1, end = n;
            int k = arr[i].x;
            bool flag = true;

            while (start <= end)
            {
                int mid = (start + end) / 2;
                int curr = query(mid);
                int prev = query(mid - 1);

                if (curr == k && (mid == 1 || prev == k - 1))
                {
                    flag = false;
                    cout << mp2[mid] << endl;
                    break;
                }
                else if (curr < k)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            if (flag)
                cout << "invalid" << endl;
        }
        else
        {
            cout << query(arr[i].x - 1) << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}