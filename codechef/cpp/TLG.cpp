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

    int n, winner, index = 0;
    vector<ll> p1, p2, lead;
    ll maxLead = 0, dum;
    cin >> n;

    n--;
    cin >> dum;
    p1.push_back(dum);

    cin >> dum;
    p2.push_back(dum);

    if (p1[0] > p2[0])
    {
        winner = 1;
        maxLead = p1[0] - p2[0];
    }
    else
    {
        winner = 2;
        maxLead = p2[0] - p1[0];
    }

    while (n--)
    {
        cin >> dum;
        p1.push_back(dum + p1[index]);

        cin >> dum;
        p2.push_back(dum + p2[index]);

        index++;

        if (abs(p1[index] - p2[index]) > maxLead)
        {
            if (p1[index] > p2[index])
            {
                winner = 1;
                maxLead = p1[index] - p2[index];
            }
            else
            {
                winner = 2;
                maxLead = p2[index] - p1[index];
            }
        }
    }

    cout<<winner<<" "<<maxLead;

    return 0;
}