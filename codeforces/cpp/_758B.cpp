#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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

    map<char, char> arr;
    string s, dum;

    arr['R'] = arr['B'] = arr['G'] = arr['Y'] = arr['!'] = '!';

    cin >> s;
    dum = s;

    while (arr['R'] == '!' || arr['B'] == '!' || arr['G'] == '!' || arr['Y'] == '!')
    {
        for (int i = 0; i < dum.size(); i++)
        {
            if (dum[i] != '!' && i < dum.size() - 1)
            {
                arr[dum[i]] = (char)dum[i + 1];
            }
            else
            {
                if (i > 0)
                {
                    dum[i] = arr[dum[i - 1]];
                }
            }
        }
        cout << "R -> " << arr['R'] << endl;
        cout << "B -> " << arr['B'] << endl;
        cout << "G -> " << arr['G'] << endl;
        cout << "Y -> " << arr['Y'] << endl;
        cout << dum << endl;
        cout << endl;
    }

    return 0;
}