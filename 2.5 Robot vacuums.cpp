#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
//2.4扫地机器人 
//10 2
//5
//2
//10
int n,k,i;
int s[10];
bool check(int mid)
{
	int pos=0;
	for(int i=0;i<k;i++)
	{
		int t=mid;//每次都要重置t 
		if(pos<s[i]) t=t-(s[i]-pos-1)*2;
		if(t<0) return false;
		pos=s[i]+t/2;
	}
	if(pos<n) return false;
	return true;
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<k;i++)
	{
		int m;
		cin>>m;
		s[i]=m;
	}
	sort(s,s+k);
	int l=0,r=2*n,ans=2*n;
	while(l<=r)//不要掉下“=" 
	{
		int mid=(l+r)/2;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans<<endl;
	
	return 0;
}
