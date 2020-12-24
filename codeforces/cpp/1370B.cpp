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

    int t, n, dum;

    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<int> odd;
        vector<int> even;

        for (int i = 1; i <= 2 * n; i++)
        {
            cin >> dum;

            if (dum % 2)
            {
                odd.push_back(i);
            }
            else
            {
                even.push_back(i);
            }
        }

        if (odd.size() % 2)
        {
            odd.pop_back();
        }

        if (even.size() % 2)
        {
            even.pop_back();
        }

        even.insert(even.end(), odd.begin(), odd.end());

        dum = 0;

        while (n - 1)
        {
            cout << even[dum] << " " << even[dum + 1] << endl;
            dum += 2;
            n--;
        }
    }

    return 0;
}