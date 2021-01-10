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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;

    cin >> n >> k;

    string s;
    int dum;
    map<int, int> fre;
    int res = 0;

    for (int i = 0; i < k; i++)
    {
        cin >> s;

        if (s == "CLOSEALL")
        {
            res = 0;
            fre.clear();
            cout << res << endl;
        }
        else
        {
            cin >> dum;
            fre[dum]++;

            if (fre[dum] % 2)
            {
                res++;
            }
            else
            {
                res--;
            }
            cout << res << endl;
        }
    }

    return 0;
}