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
    #define all(x) (x).begin(), (x).end()
    //int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    //int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    //int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
    //int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

    int main(int argc, char const *argv[])
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int t;  

        cin >> t;

        while (t--)
        {
            int n, u, r, d, l;
            cin >> n >> u >> r >> d >> l;

            int du = u, dr = r, dd = d, dl = l;

            if (u == n)
                dl--, dr--;
            if (u == n - 1)
            {
                if (dl > dr)
                    dl--;
                else
                    dr--;
            }

            if (r == n)
                du--, dd--;
            if (r == n - 1)
            {
                if (du > dd)
                    du--;
                else
                    dd--;
            }

            if (d == n)
                dr--, dl--;
            if (d == n - 1)
            {
                if (dl > dr)
                    dl--;
                else
                    dr--;
            }

            if (l == n)
                du--, dd--;
            if (l == n - 1)
            {
                if (du > dd)
                    du--;
                else
                    dd--;
            }

            if (du < 0 || dl < 0 || dd < 0 || dr < 0)
                cout << "NO\n";
            else
                cout << "YES\n";
        }

        return 0;
    }