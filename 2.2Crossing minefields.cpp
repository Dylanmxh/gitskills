#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
//2.2 穿越雷区  A + - + - - + - - + - + + + - + - + - + B + - + -
//方法一 bfs 
int a[100][100],v[100][100];
int n;
pair<int,int>st,ed;
int r[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct node
{
	int x,y,cnt;
};
bool check(int x,int y)
{
	if(x>n||x<1||y>n||y<1||v[x][y]) return false;
	return true;
}
bfs(int x,int y)
{
	queue<node>que;
	que.push(node{x,y,0});
	v[x][y]=1;
	while(!que.empty())
	{
		node u=que.front();
		if(u.x==ed.first && u.y==ed.second) return u.cnt;
		que.pop();
		int x=u.x,y=u.y;
		for(int i=0;i<=3;i++)
		{
			int tx=x+r[i][0];
			int ty=y+r[i][1];
			if(a[tx][ty]==a[x][y]||!check(tx,ty)) continue;
			v[tx][ty]=1;
			
			que.push(node{tx,ty,u.cnt+1});
		}
	}
	return -1;
}

int main()
{
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char x;
			cin>>x;
			if(x=='A')
			{
				a[i][j]=-1;
				st.first=i;
				st.second=j;
			 } 
			if(x=='B')
			{
				a[i][j]=-1;
				ed.first=i;
				ed.second=j;
			 }
			if(x=='+') a[i][j]=1;
			else a[i][j]=0;
		}
	}
	cout<<bfs(st.first,st.second);
	return 0;
}
 
//方法二 dfs
/*int n, a[1000][1000]; //标记+ - A B 
int vis[1000][1000]; //记录走到该位置时的步数； 
int ans;//最短步数
int r[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
pair<int,int>st,ed;
bool check(int x,int y)
{
	if(x>n||x<1||y>n||y<1) return false;
	return true;
}
void dfs(int x,int y,int cnt)
{
	if(cnt>ans) return;
	if(cnt>vis[x][y]) return;
	if(x==ed.first && y==ed.second)
	{
		ans=cnt;
		return;
	}
	vis[x][y]=cnt;
	for(int i=0;i<=3;i++)
		{
			int tx=x+r[i][0];
			int ty=y+r[i][1];
			if(a[tx][ty]==a[x][y]||!check(tx,ty)) continue;
			dfs(tx,ty,cnt+1);
		}
}
int main()
{
	cin>>n;
	ans=0x3f3f3f3f;//无穷大的意思 0x3f3f3f3f
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) vis[i][j]=0x3f3f3f3f;//容易忽略的地方 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char x;
			cin>>x;
			if(x=='A')
			{
				a[i][j]=-1;
				st.first=i;
				st.second=j;
			 } 
			if(x=='B')
			{
				a[i][j]=-1;
				ed.first=i;
				ed.second=j;
			 }
			if(x=='+') a[i][j]=1;
			else a[i][j]=0;
		}
	}
	dfs(st.first,st.second,0);
	cout<<ans<<endl;
	return 0;
}
*/
