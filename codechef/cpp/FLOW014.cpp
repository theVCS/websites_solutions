#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    float har, cc, ten;
    int grade;

    cin >> t;

    while (t--)
    {
        cin >> har >> cc >> ten;

        if (har > 50 && cc < 0.7 && ten > 5600)
        {
            grade = 10;
        }
        else if (har > 50 && cc < 0.7)
        {
            grade = 9;
        }
        else if (cc < 0.7 && ten > 5600)
        {
            grade = 8;
        }
        else if (har > 50 && ten > 5600)
        {
            grade = 7;
        }
        else if (har > 50 || cc < 0.7 || ten > 5600)
        {
            grade = 6;
        }
        else
        {
            grade = 5;
        }

        cout << grade << endl;
    }

    return 0;
}