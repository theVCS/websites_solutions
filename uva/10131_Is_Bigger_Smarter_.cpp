#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 1000001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

const int sz = 1001;

struct elephant
{
    int w, iq, index;
} arr[sz];

bool cmp(elephant &a, elephant &b)
{
    return a.w < b.w;
}

int ans[sz];
int ft[1001];
map<int, int> mp;

void solve()
{
    int w, iq;
    int n = 0;

    while (cin >> w >> iq)
    {
        n++;
        arr[n].index = n;
        arr[n].iq = iq;
        arr[n].w = w;
        mp[arr[n].iq];
    }

    int timer = 0;

    for (auto &e : mp)
        e.second = ++timer;

    sort(arr + 1, arr + 1 + n, cmp);

    int index = 0, i = 1;

    while (i <= n)
    {
        index++;
        int j = i + 1;

        while (j <= n && arr[j].w == arr[i].w)
            arr[j].w = index, arr[j].iq = mp[arr[j].iq], j++;

        arr[i].iq = mp[arr[i].iq];
        arr[i].w = index;
        i = j;
    }


    int MX = -1;
    int INDEX = -1;

    REP(i,1,n)
    {
        // need to search from 1 to arr[i].w - 1 and find the index where arr[index].iq < arr[index].iq and ft[index] is max
        int index = -1;
        int mx = -1;
        int j = 1;

        while(arr[j].w<arr[i].w)
        {
            if(ft[j]>mx&&arr[j].iq>arr[i].iq)index=j;
            j++;
        }

        ft[i]=index>0?ft[index]+1:1;
        ans[i]=index;
    
        if(MX < ft[i])
        {
            MX = ft[i];
            INDEX = i;
        }
    }

    // REP(i,1,n)cout<<arr[i].w<<" "<<arr[i].iq<<endl;

    vector<int>myRes;

    while (INDEX>0)
    {
        myRes.push_back(arr[INDEX].index);
        INDEX=ans[INDEX];
    }
    
    cout<<myRes.size()<<endl;
    RREP(i,myRes.size()-1,0)cout<<myRes[i]<<endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t = 1;

    // cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}