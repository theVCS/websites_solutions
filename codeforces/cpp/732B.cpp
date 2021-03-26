#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 501
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, k, val;
int arr[maxN];
int arr2[maxN];

int walks(int index, int n)
{
    if (index > n)
    {
        return 0;
    }
    else if (index == 1)
    {
        int res = INF;

        REP(i, arr[index], k + 1)
        {
            arr2[index] = i;

            int temp = walks(2,n) + i - arr[1];

            if(temp < res)
            {
                res = temp;
                val = i;
            }
        }

        if(res == INF)
        {
            val = arr[1];
            res = 0;
        }
    
        return res;
    }
    else
    {
        int diff = k - arr2[index - 1];

        if (diff > arr[index])
        {
            int temp = arr[index];
            arr2[index] = diff;
            return diff - temp + walks(index + 1, n);
        }
        else
        {
            arr2[index] = arr[index];
            return walks(index + 1, n);
        }
    }
}

void solve()
{
    cin >> n >> k;

    REP(i, 1, n + 1)
    cin >> arr[i];

    cout << walks(1, n) << endl;

    arr[1] = val;

    cout << arr[1] << " ";

    REP(i,2,n+1)
    {
        int diff = k - arr[i - 1];

        if(diff > arr[i])arr[i] = diff;

        cout << arr[i] << " ";
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}