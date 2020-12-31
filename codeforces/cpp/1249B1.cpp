#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 201
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr(maxN, -1);

int find(int a)
{
    if (arr[a] < 0)
    {
        return a;
    }
    return arr[a] = find(arr[a]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x != y)
    {
        if (x > y)
        {
            swap(x, y);
        }
        arr[x] += arr[y];
        arr[y] = x;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q, n, a;

    cin >> q;

    while (q--)
    {
        cin >> n;

        REP(i, 1, n + 1)
        {
            cin >> a;
            merge(a, i);
        }

        REP(i, 1, n + 1)
        {
            cout << abs(arr[find(i)]) << " ";
        }
        cout << endl;

        REP(i, 0, n + 1)
        arr[i] = -1;
    }

    return 0;
}