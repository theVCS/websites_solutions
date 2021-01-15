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

stack<ll> st;

bool recur(ll a, ll b)
{
    if (a > b)
    {
        return false;
    }
    else if (a == b)
    {
        st.push(a);
        return true;
    }
    else
    {
        bool temp1 = recur(a * 2, b);
        bool temp2 = recur(10 * a + 1, b);

        if (temp1)
        {
            st.push(a);
        }
        else if (temp2)
        {
            st.push(a);
        }

        return temp2 || temp1;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b;

    cin >> a >> b;

    if (recur(a, b))
    {
        cout << "YES" << endl;
        cout << st.size() << endl;

        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
    }
    else
    {
        cout << "NO";
    }

    return 0;
}