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

vector<string> arr[27];
map<string, bool> present;

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t, n;
    char s[20];

    // cin >> t;
    scanf("%d", &t);

    while (t--)
    {
        int cnt = 0;

        present.clear();

        // cin >> n;
        scanf("%d", &n);

        REP(i, 0, n)
        {
            cin >> s;
            // gets(s);
            arr[s[0] - 'a'].push_back(s);
            present[s] = true;
        }

        REP(i, 0, 26)
        {
            for (string ele : arr[i])
            {
                REP(j, i + 1, 26)
                {
                    char c = 'a' + j;
                    swap(ele[0], c);

                    if (present[ele] == false)
                    {
                        for (string e : arr[j])
                        {
                            swap(c, e[0]);

                            if (present[e] == false)
                                cnt += 2;

                            swap(c, e[0]);
                        }
                    }

                    swap(ele[0], c);
                }
            }

            arr[i].clear();
        }

        // cout << cnt << endl;
        printf("%d\n", cnt);
    }

    return 0;
}