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

    int t, n, dum, len;

    cin >> t;

    while (t--)
    {
        len = 2;
        cin >> n;

        vector<int> even;
        vector<int> odd;

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

        for (int i = 0; i < odd.size(); i += 2)
        {
            if (i + 1 != odd.size())
            {
                cout << odd[i] << " " << odd[i + 1] << endl;
            }
            else
            {
                len = 1;
            }
        }

        if (even.size())
        {
            for (int i = 0; i < even.size() - len; i += 2)
            {
                cout << even[i] << " " << even[i + 1] << endl;
            }
        }
    }

    return 0;
}