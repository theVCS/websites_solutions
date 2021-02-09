// ques5
// https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/primestring/

#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool isPrime[maxN];

void init()
{
    isPrime[0] = isPrime[1] = true;
    for (int i = 2; i * i <= maxN; i++)
    {
        if (isPrime[i] == false)
        {
            for (int j = i * i; j < maxN; j += i)
            {
                isPrime[j] = true;
            }
        }
    }
}

bool isPrimeString(string s)
{
    map<char, int> fre;
    int disChar = 0;

    for (char c : s)
    {
        if (fre[c] == 0)
        {
            disChar++;
        }

        fre[c]++;
    }

    if (isPrime[disChar])
        return false;

    for (auto it : fre)
    {
        if (isPrime[it.second])
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

    init();

    int t;
    string s;

    cin >> t;

    while (t--)
    {
        cin >> s;

        if (isPrimeString(s))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}