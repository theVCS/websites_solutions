#include<iostream>
using namespace std;
int main(int argc, char const *argv[]){
    long long sum = 0, n, k, val;
    // cin>>n>>k;
    scanf("%lld", &n);
    scanf("%lld", &k);
    for (long long i = 0; i < n; i++)
    {
        // cin>>val;
        scanf("%lld", &val);
        sum += val % k == 0 ? 1 : 0;
    }
    cout<<sum;
    return 0;
}