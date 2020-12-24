#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, dum, sum, res;
    cin >> n;

    while (n != -1)
    {
        vector<int> arr;
        sum = 0;
        res = 0;

        REP(i, 0, n)
        {
            cin >> dum;
            sum += dum;
            arr.push_back(dum);
        }

        if (sum % n)
        {
            cout << -1 << endl;
        }
        else
        {
            sum /= n;

            for (int e : arr)
            {
                if (e < sum)
                {
                    res += sum - e;
                }
            }

            cout << res << endl;
        }
        cin >> n;
    }

    return 0;
}