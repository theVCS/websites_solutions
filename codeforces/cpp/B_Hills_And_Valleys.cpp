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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n;
ll arr[300001];

bool isPos(int i)
{
    if ((arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) || (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]))
    {
        return true;
    }
    return false;
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
        int cnt = 0;
        bool two = false, three = false;

        cin >> n;

        REP(i, 1, n + 1)
        cin >> arr[i];

        for (int i = 2; i <= n - 1; i++)
        {
            if (isPos(i))
            {
                cnt++;
            }

            if (i < n - 2 && isPos(i) && isPos(i + 1) && isPos(i + 2) && arr[i + 2] < arr[i])
            {
                three = true;
            }

            if (i <= n - 2 && isPos(i) && isPos(i + 1))
            {
                two = true;
            }
        }

        if (three)
        {
            cnt -= 3;
        }
        else if (two)
        {
            cnt -= 2;
        }
        else if (cnt)
        {
            cnt -= 1;
        }

        cout << cnt << endl;
    }

    return 0;
}