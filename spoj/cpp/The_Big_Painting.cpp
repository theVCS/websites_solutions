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
 
int hp, wp, hm, wm;
char paint[2001][2001], master[2001][2001];
ll power[4050];
ll painthash[2001], masterHash[2001][2001];
 
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int cnt = 0;
    ll mashash, phash;
    // vector<pii> cord;
 
    power[0] = 1, power[1] = 31, power[2] = 961;
 
    cin >> hp >> wp >> hm >> wm;
 
    REP(i, 1, hp + 1)
    {
        phash = 0;
        for (int j = 1; j <= wp; j++)
        {
            cin >> paint[i][j];
            phash = (phash + (paint[i][j] - '0' + 1) * power[i + j]) % mod;
            power[i + j + 1] = (power[i + j] * 31) % mod;
        }
        painthash[i] = phash;
    }
 
    REP(i, 1, hm + 1)
    {
        mashash = 0;
        for (int j = 1; j <= wm; j++)
        {
            cin >> master[i][j];
            mashash = (mashash + (master[i][j] - '0' + 1) * power[i + j]) % mod;
            masterHash[i][j] = mashash;
            power[i + j + 1] = (power[i + j] * 31) % mod;
        }
    }
 
    bool flag;
 
    for (int lr = 1, rr = hp; rr <= hm; rr++, lr++)
    {
        for (int lc = 1, rc = wp; rc <= wm; rc++, lc++)
        {
            if (master[lr][lc] == paint[1][1])
            {
                flag = true;
 
                for (int i = lr; i <= rr; i++)
                {
                    mashash = (masterHash[i][rc] - masterHash[i][lc - 1] + mod) % mod;
                    phash = (painthash[i - lr + 1] * power[lc + lr - 2]) % mod;
 
                    if (mashash != phash)
                    {
                        flag = false;
                        break;
                    }
                }
 
                if (flag)
                {
                    cnt++;
                }
            }
        }
    }
 
    cout << cnt;
 
    return 0;
} 