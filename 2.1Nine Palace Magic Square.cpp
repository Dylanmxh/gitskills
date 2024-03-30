#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;


//2.1 九宫幻方
//方法一--全排列  0 7 2 0 5 0 0 3 0         4 9 2 3 5 7 8 1 6
int p[10],a[3][3],c[3][3],d[3][3];
int main()
{
	int count=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=9;i++) p[i]=i;
	do{		
//		一维矩阵转二维
		int *b[4];
		for(int i=1;i<=3;i++)b[i]=&p[(i-1)*3+1]; 
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++) c[i][j]=b[i+1][j];
		}
		bool flag=true;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(!a[i][j]) continue;
				if(c[i][j]!=a[i][j]) flag=false;
			}
		}
		if(flag==false) continue;
		
		bool f=true;
		int sum=c[0][0]+c[1][1]+c[2][2];
		if(sum!=c[2][0]+c[1][1]+c[0][2]) continue;
//		cout<<sum<<endl;
		
		for(int i=0;i<3;i++)
		{
			int htemp=0,ltemp=0;
			for(int j=0;j<3;j++) htemp+=c[i][j],ltemp+=c[j][i];
			cout<<htemp<<" "<<ltemp<<endl; 
			if(htemp!=sum||ltemp!=sum) 
			{
				f=false;
				break;
			}
			
		}
		if(f)
		{
			count++;
			for(int i=0;i<3;i++)
			{
			for(int j=0;j<3;j++) d[i][j]=c[i][j];
			}
		 } 
		cout<<"count="<<count<<endl;
//		for(int i=0;i<3;i++)
//		{
//			for(int j=0;j<3;j++)
//			{
//				cout<<c[i][j];
//			}
//		}
//		cout<<endl;
		if(count>1) return cout<<"Too Many"<<endl,0;
		
	}while(next_permutation(p+1,p+1+9));
	if(count==1)
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				cout<<d[i][j];
			}
		}	
	}
	
	return 0;
 } 

// 方法二 DFS
/* int vis[10],a[3][3],ans[3][3];
 int n=0,con=0;
 pair<int,int>p[10];
bool check(int c [][3])
{
	int sum=c[0][0]+c[1][1]+c[2][2];
	if(sum!=c[2][0]+c[1][1]+c[0][2]) return false;
	for(int i=0;i<3;i++)
	{
		int htemp=0,ltemp=0;
		for(int j=0;j<3;j++) htemp+=c[i][j],ltemp+=c[j][i];
//		cout<<htemp<<" "<<ltemp<<endl; 
		if(htemp!=sum||ltemp!=sum) return false;
	}
	return true;
} 
void dfs(int now,int n,int a[][3])
{
	if(now>n)
	{
		if(check(a))
		{
			con++;
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++) ans[i][j]=a[i][j];
			}
		}
	return;
	}
	int x=p[now].first, y=p[now].second;
	for(int i=1;i<=9;i++)
	{
		if(vis[i]) continue;
		a[x][y]=i;
		vis[i]=1;
		dfs(now+1,n,a);
//		回溯 
		a[x][y]=0;
		vis[i]=0;
	}
}
int main()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(!a[i][j]) p[++n]=make_pair(i,j);
			else vis[a[i][j]]=1;
		}
	}
	dfs(1,n,a);
	if(con==1)
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				cout<<ans[i][j];
			}
		}
	}
	if(con>1) cout<<"Too Many!"<<endl;
	return 0;
}
*/
