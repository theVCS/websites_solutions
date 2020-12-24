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
    ll sum;

    cin >> t;

    while (t--)
    {
        cin >> n;

        sum = 0;

        vector<int> men;
        vector<int> women;

        REP(i, 0, n)
        {
            cin >> dum;
            men.push_back(dum);
        }

        sort(men.begin(), men.end());

        REP(i, 0, n)
        {
            cin >> dum;
            women.push_back(dum);
        }

        sort(women.begin(), women.end());

        REP(i, 0, n)
        {
            sum += men[i] * women[i];
        }

        cout << sum << endl;
    }

    return 0;
}