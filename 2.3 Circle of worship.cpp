#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

//2.3 Ð¡ÅóÓÑ³ç°ÝÈ¦ 
int n,a[100][100];
int ans;
struct child{
	int i;
	int ad;
	bool visit;
	int m;
};
int dfs(child c[],int i)
{
	c[i].visit=true;
	int k=c[i].ad; 
	if(c[k].visit) return c[i].m-c[k].m+1; //ans=ans>(c[i].m-c[k].m+1)?(c[i].m-c[k].m+1):ans
	else {
		c[k].m=c[i].m+1;
	}
	dfs(c,k);
}
int main()
{
	cin>>n;
	child c[n+1];
	for(int i=1;i<=n;i++)
	{
		int j;
		cin>>j;
		c[i].i=i,c[i].ad=j,c[i].visit=false;
	}
	for(int i=1;i<+n;i++)
	{
		if(!c[i].visit) ans = max(ans, dfs(c, i));
	}
	cout<<ans<<endl;
 } 

