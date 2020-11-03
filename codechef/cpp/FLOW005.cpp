#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, -1, 0, 1};
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int arr[] = {1, 2, 5, 10, 50, 100};

int noteFinder(int n)
{
    int cnt = 0, index = 5;

    while (n || n >= arr[index])
    {
        cnt += (n / arr[index]);
        n %= arr[index];
        index--;
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << noteFinder(n) << endl;
    }

    return 0;
}