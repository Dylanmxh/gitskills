#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
//2.4�Թ������� . . . X X # # % # . . . . # . . # # # . . . . . .
//����һ����N��N��������ɵ��Թ��Լ�һ������K���Թ�����������Ͻǣ��յ���
//���½ǣ�С����Ҫ������ߵ��յ㡣
//�Թ��еĸ��������¼������͡�
//��1����ͨ�ĸ��ӣ���Ϊ��.���������Ծ�����
//��2��ǽ�ڣ���Ϊ��#�������޷�������
//(3��ӵ���޵е��ߵĸ��ӣ���Ϊ��%��)�����Ծ������������������ K ���������޵�״
//̬�������ӻ��Ϊ��ͨ�ĸ��ӡ�
//��4�����壨��Ϊ��X�������������޵�״̬����Ծ��������򲻿ɾ�����
//С����ÿһ�������ƶ�����ǰλ���ϡ��¡��������ڵĸ����ϣ���ǰ������Щ���ӿ�
//�Ծ�����
//���ʴ�����ߵ��յ�����ٲ����Ƕ��٣��������뿪������� ��1��?
//��֤�����յ�һ������ͨ�ĸ��ӡ�
int m,n;
int a[1000][1000],vis[1000][1000];
int s[1000][1000];//��¼��������ʱ���Ŀɱ����޵�״̬�Ĳ��� 
int r[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct node{
	int x,y;
	int cnt;
	int status;
};
bool check(int x,int y)
{
	if(x>m||x<1||y>m||y<1||a[x][y]==2) return false;//ǽ�� 
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
			if(a[tx][ty]==4)//�޵е��� 
			{
				vis[tx][ty]=1;
				
				que.push(node{tx,ty,u.cnt+1,n}) ;
			}
			if(a[tx][ty]==3)//����
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

