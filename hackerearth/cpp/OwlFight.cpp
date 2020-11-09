#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
int arr[maxN];

int find(int a)
{
    if (arr[a] < 0)
    {
        return a;
    }
    else
    {
        return arr[a] = find(arr[a]);
    }
}

void myUnion(int a, int b)
{
    if (a < b)
    {
        swap(a, b);
    }

    arr[a] += arr[b];
    arr[b] = a;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, c;

    cin >> n >> m;

    REP(i, 1, n + 1)
    {
        arr[i] = -1;
    }

    REP(i, 0, m)
    {
        cin >> a >> b;
        a = find(a), b = find(b);

        if (a != b)
        {
            myUnion(a, b);
        }
    }

    cin >> c;

    while (c--)
    {
        cin >> a >> b;
        int ap = find(a);
        int bp = find(b);

        if (ap == bp)
        {
            cout << "TIE" << endl;
        }
        else
        {
            if (ap > bp)
            {
                cout << a << endl;
            }
            else
            {
                cout << b << endl;
            }
        }
    }

    return 0;
}