#include <bits/stdc++.h>
#include <boost/lexical_cast.hpp>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;
#define ll long long int
#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bint binExp(bint a, bint pow)
{
    bint res = 1;

    while (pow)
    {
        if (pow % 2)
        {
            res = res * a;
        }
        a = a * a;
        pow /= 2;
    }
    return res;
}

bint binexp(bint a, bint pow, bint m)
{
    bint res = 1;

    while (pow)
    {
        if (pow % 2)
        {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        pow /= 2;
    }
    return res;
}

bool isComposite(bint a, bint d, bint s, bint n)
{
    bint res = binexp(a, d, n);

    if (res == 1 || res == n - 1)
    {
        return false;
    }

    for (bint i = 1; i < s; i++)
    {
        res = (res * res) % n;

        if (res == n - 1)
        {
            return false;
        }
    }
    return true;
}

bool millerRabin(bint n)
{
    if (n != 2 && (n < 2 || n % 2 == 0))
    {
        return false;
    }

    bint d = n - 1, s = 0;

    while (d % 2 == 0)
    {
        d /= 2;
        s++;
    }

    for (bint a : {2, 3, 5, 7, 11, 13, 17, 19, 13, 29, 31, 37, 41, 43, 47, 53, 57})
    {
        if (n == a)
        {
            return true;
        }

        if (isComposite(a, d, s, n))
        {
            return false;
        }
    }
    return true;
}

// int counter(string n)
// {
//     // map<pair<pair<cpp_int, cpp_int>, cpp_int>, bool> check;
//     string a, b, c;
//     int cnt = 0;
//     bint k, l, m;

//     for (int i = 0; i < n.size(); i++)
//     {
//         for (int j = i; j < n.size() - 1; j++)
//         {
//             a = n.substr(0, i);
//             b = n.substr(i, j - i + 1);
//             c = n.substr(j + 1, n.size() - j - 1);

//             // k = cpp_int(a);
//             // l = cpp_int(b);
//             // m = cpp_int(c);

//             // if (millerRabin(k) || millerRabin(l) || millerRabin(m))
//             // {
//             //     cnt++;
//             // }

//             cout << "a = " << a << " b = " << b << " c = " << c << endl;
//             cout << endl;
//         }
//     }

//     if (millerRabin(cpp_int(n)))
//     {
//         cnt++;
//     }

//     return cnt;
// }

int counter(string str, int n)
{
    int cnt = 0;

    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;

            if (millerRabin(bint(str.substr(i, j - i + 1))))
            {
                cnt++;
            }

            // for (int k = i; k <= j; k++)
            //     cout << str[k];

            // cout << endl;
        }
    }

    return cnt;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string n;

    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << counter(n, n.size()) << endl;
    }

    return 0;
}