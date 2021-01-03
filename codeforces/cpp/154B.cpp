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

int sieve[maxN];
vector<int> arr[maxN];
bool active[maxN];

void init()
{
    for (int i = 2; i < maxN; i++)
    {
        if (!sieve[i])
        {
            for (int j = i; j < maxN; j+=i)
            {
                sieve[j] = i;
            }
        }
    }
}

set<int> div(int a)
{
    set<int> s;

    while (sieve[a])
    {
        s.insert(sieve[a]);
        a = a / sieve[a];
    }
    return s;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int n, m, k;
    char c;

    cin >> n >> m;

    while (m--)
    {
        cin >> c >> k;

        if (c == '+')
        {
            if (active[k])
            {
                cout << "Already on" << endl;
            }
            else
            {
                bool flag = true;
                set<int> s;
                s = div(k);

                for (int e : s)
                {
                    if (arr[e].size())
                    {
                        cout << "Conflict with " << arr[e][0] << endl;
                        flag = false;
                        break;
                    }
                }

                if (flag)
                {
                    for (int e : s)
                    {
                        arr[e].push_back(k);
                    }
                    active[k] = true;
                    cout << "Success" << endl;
                }
            }
        }
        else
        {
            if (!active[k])
            {
                cout << "Already off" << endl;
            }
            else
            {
                set<int> s;
                s = div(k);

                for (int e : s)
                {
                    arr[e].pop_back();
                }

                active[k] = false;
                cout << "Success" << endl;
            }
        }
    }

    return 0;
}