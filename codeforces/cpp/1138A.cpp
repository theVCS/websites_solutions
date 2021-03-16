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
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN];

bool isValid(int k, int n)
{
    int ele = arr[0];
    int cnt = 0;
    int i = 0;

    while (i < n)
    {
        int c = 0;

        while (i < n && arr[i] == ele)
        {
            c++;
            i++;
        }

        if (cnt >= k / 2 && c >= k / 2)
            return true;

        cnt = c, ele = arr[i];
    }
    return false;
}

void solve()
{
    int n;

    cin >> n;

    REP(i, 0, n)
    cin >> arr[i];

    int start = 0, end = n - (n % 2);

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (mid % 2)
        {
            if (isValid(mid + 1, n))
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        else
        {
            if (isValid(mid, n))
            {
                if (isValid(mid + 2, n) == false)
                {
                    cout << mid;
                    return;
                }
                start = mid + 2;
            }
            else
            {
                end = mid - 2;
            }
        }
    }

    cout << 0;
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