#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

void show(int a)
{
    if (a == 999 || a == 1000)
    {
        cout<<1;
    }
    else
    {
        cout<<a + 2;
    }
    
}

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    
    int a;
    cin>>a;
    show(a);

    return 0;
}