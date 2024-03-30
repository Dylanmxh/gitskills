#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
//2.4迷宫与陷阱 . . . X X # # % # . . . . # . . # # # . . . . . .
//给定一个由N×N个格子组成的迷宫以及一个常数K，迷宫的起点在左上角，终点在
//右下角，小明需要从起点走到终点。
//迷宫中的格子有以下几种类型。
//（1）普通的格子（记为“.”）：可以经过。
//（2）墙壁（记为“#”）：无法经过。
//(3）拥有无敌道具的格子（记为“%”)：可以经过，经过后接下来的 K 步将处于无敌状
//态，但格子会变为普通的格子。
//（4）陷阱（记为“X”）：若处于无敌状态则可以经过，否则不可经过。
//小明的每一步可以移动到当前位置上、下、左、右相邻的格子上，但前提是这些格子可
//以经过。
//请问从起点走到终点的最少步数是多少（若不能离开，则输出 —1）?
//保证起点和终点一定是普通的格子。
int m,n;
int a[1000][1000],vis[1000][1000];
int s[1000][1000];//记录经过格子时最大的可保持无敌状态的步数 
int r[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct node{
	int x,y;
	int cnt;
	int status;
};
bool check(int x,int y)
{
	if(x>m||x<1||y>m||y<1||a[x][y]==2) return false;//墙壁 
	return true;
}
int bfs()
{
	queue<node>que;
	que.push(node{1,1,0,0});
	vis[1][1]=1;
	while(!que.empty())
	{
		node u=que.front();
		que.pop();
		if(u.x==m&&u.y==m) return u.cnt;
		int x=u.x,y=u.y;
		for(int i=0;i<4;i++)
		{
			int tx=x+r[i][0];
			int ty=y+r[i][1];
			if(!check(tx,ty)) continue;
			int status=max(0,u.status-1);	
			if(a[tx][ty]==4)//无敌道具 
			{
				vis[tx][ty]=1;
				
				que.push(node{tx,ty,u.cnt+1,n}) ;
			}
			if(a[tx][ty]==3)//陷阱
			{
				if(u.status==0) continue;
				a[tx][ty]=1;
				vis[tx][ty]=1;
				s[tx][ty]=status;
				que.push(node{tx,ty,u.cnt+1,status});
			 } 
			else
			{
				if(!vis[tx][ty])
				{
					vis[tx][ty]=1;
					s[tx][ty]=status;
					que.push(node{tx,ty,u.cnt+1,status});
					continue;
				}
				if(status<=s[tx][ty]) continue;
				s[tx][ty]=status;
				que.push(node{tx,ty,u.cnt+1,status}); 
			}
		}
	}
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char x;
			cin>>x;
			if(x=='.')a[i][j]=1;
			if(x=='#')a[i][j]=2;
			if(x=='X')a[i][j]=3;
			if(x=='%')a[i][j]=4;
		 } 
	}
	cout<<bfs()<<endl;
	return 0;
 } 

