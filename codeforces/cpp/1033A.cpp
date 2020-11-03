#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
int dx[] = {-1, 0, 1, 0, -1, 1, -1, 1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
int arr[maxN][maxN], n, ax, ay, bx, by, cx, cy;
// bool vis[maxN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;

    if ((ax > bx && ax < cx) || (ay > by && ay < cy) || (ax < bx && ax > cx) || (ay < by && ay > cy))
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }

    return 0;
}