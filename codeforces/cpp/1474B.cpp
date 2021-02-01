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

int sieve[maxN];
vector<int> arr[maxN];

void init()
{
    for (int i = 2; i < maxN; i++)
    {
        if (sieve[i] == 0)
        {
            for (int j = i; j < maxN; j += i)
            {
                sieve[j] = i;
            }
        }
    }
}

map<int, int> divCal(int n)
{
    map<int, int> div;

    while (sieve[n])
    {
        div[sieve[n]]++;
        n /= sieve[n];
    }
    return div;
}

void calculate(int n)
{
    int tot_div = 1, root1, root2, diff;
    map<int, int> div = divCal(n);

    for (auto e : div)
    {
        tot_div *= (e.second + 1);

        if (tot_div >= 4)
        {
            root1 = sqrt(n);

            while(n % root1)root1--;
            
            root2 = n / root1;
            diff = min(abs(root2 - root1), root1 - 1);
            arr[diff].push_back(n);

            break;
        }
    }
}

void init2()
{
    init();

    map<int, int> div;

    for (int i = 2; i < maxN; i++)
    {
        calculate(i);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init2();

    int t, d;

    cin >> t;

    while (t--)
    {
        cin >> d;
        cout << arr[d][0] << endl;
    }

    // for (int i = 0; i < 500; i++)
    // {
    //     if (arr[i].size())
    //     {
    //         cout << i << " -> " << arr[i][0] << endl;
    //     }
    // }

    // init();
    // calculate(6);

    return 0;
}