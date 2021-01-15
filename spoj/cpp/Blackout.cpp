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

int arr[2010][2010];
ll people[1010];
int area[1010];
int ind;
int t[1010][1010];

void matSum(int x1, int y1, int x2, int y2)
{
    ll sum = 0;
    int are = (x2 - x1 + 1) * (y2 - y1 + 1);

    for (int i = x1; i <= x2; i++)
    {
        sum += (arr[i][y2] - arr[i][y1 - 1]);
    }
    people[ind] = sum;
    area[ind] = are;
    ind++;
}

int knapSack(int k, int n = ind)
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < k + 1; j++)
        {
            if (people[i - 1] <= j)
            {
                t[i][j] = max(area[i - 1] + t[i - 1][j - people[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][k];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, q, k, x1, y1, x2, y2;

    cin >> n >> m >> q >> k;
    // scanf("%d%d%d%d", &n, &m, &q, &k);

    REP(i, 1, n + 1)
    REP(j, 1, m + 1)
    {
        // scanf("%d", &arr[i][j]);
        cin >> arr[i][j];
        arr[i][j] += arr[i][j - 1];
    }

    while (q--)
    {
        cin >> x1 >> y1;
        cin >> x2 >> y2;

        matSum(x1, y1, x2, y2);

        // cout << people[index - 1] << " " << area[index - 1] << endl;
    }

    // printf("%d", knapSack(k));
    cout << knapSack(k);

    return 0;
}