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

    int n, n1, n2, dum;
    double res = 0, dumRes = 0;
    vector<int> arr;

    cin >> n >> n1 >> n2;

    if (n1 > n2)
    {
        swap(n1, n2);
    }

    while (n--)
    {
        cin >> dum;
        arr.push_back(dum);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n1; i++)
    {
        dum = arr.back();
        arr.pop_back();

        dumRes += dum;
    }

    res += dumRes * 1.0 / n1;
    dumRes = 0;

    for (int i = 0; i < n2; i++)
    {
        dum = arr.back();
        arr.pop_back();

        dumRes += dum;
    }

    res += dumRes * 1.0 / n2;

    printf("%0.6f", res);

    return 0;
}