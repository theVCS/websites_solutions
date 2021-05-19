#include <iostream>
using namespace std;
#define lli long long int
lli count=0;
void factorcount(lli m,lli b)
{
    for(lli a=1;a<b;a++)
    {
        if((m-m%b)%a==0)
        {
            // cout<<a<<" "<<b<<endl;
            count++;
        }
    }
}
void ans()
{
    lli n,m;
    cin>>n>>m;
    for(lli b=n;b>1;b--)
    {
        factorcount(m,b);
    }
}
int main() 
{
    lli t;
    cin>>t;
    while(t--)
    {
        count=0;
        ans();
        cout<<count<<endl;
    }
	// your code goes here
	return 0;
}