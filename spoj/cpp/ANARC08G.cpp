#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, -1, 0, 1};
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, cnt = 1;

    while (true)
    {
        cin >> n;

        if (n == 0)
        {
            break;
        }
        

        int arr[n][n];
        int rowS, colS, res = 0, tot = 0;

        REP(i, 0, n)
        {
            REP(j, 0, n)
            {
                cin >> arr[i][j];
                tot += arr[i][j];
            }
        }

        REP(i, 0, n)
        {
            rowS = 0;
            colS = 0;

            REP(j, 0, n)
            {
                rowS += arr[i][j];
                colS += arr[j][i];
            }

            res += max(0, colS - rowS);
        }

        cout << cnt << ". " << tot << " " << res << endl;
        cnt++;
    }

    return 0;
}