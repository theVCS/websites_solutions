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

int TL, PL;
string T, P;

bool match(int l)
{
    for (int i = 0; i < PL; i++)
    {
        if (T[l + i] != P[i])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, T);
    TL = T.size();

    P = "to the";
    PL = 6;

    for (int L = 0, R = PL - 1; R < TL; L++, R++)
    {
        // cout << R << endl;
        if (match(L))
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}