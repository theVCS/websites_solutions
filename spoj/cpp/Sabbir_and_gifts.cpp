#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> a(100005);
ll sum[100005];
int main()
{
	int n;
	cin>>n;
	int i,j,q;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(),a.begin()+n);
	sum[0] = a[0];
	for(i=1;i<n;i++)
		sum[i] = sum[i-1] + a[i];
	cin>>q;
	while(q--)
	{
        int l,r;
        cin>>l>>r;
        vector<int>::iterator it1,it2;
        it1 = lower_bound(a.begin(),a.begin()+n,l);
        it2 = upper_bound(a.begin(),a.begin()+n,r);
        //cout<<it1 - a.begin()<<endl;
        //cout<<it2 - a.begin()<<endl;
        int v1 = it1 - a.begin();
        int v2 = it2 - a.begin();
        if(a[v2]!=r)
			v2--;
		if(v1==0)
			cout<<sum[v2]<<endl;
		else
			cout<<sum[v2]-sum[v1-1]<<endl;
        //<<sum[v2] - sum[v1]<<endl;
	}
}
