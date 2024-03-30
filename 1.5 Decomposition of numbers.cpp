#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

//1.5数的分解 
//方法一 
bool judge(int a)
{
	int b=a/10,c=a%10;
	if(c==2||c==4) return false;
	if(b==0) return true;	
	return judge(b);
}
int main()
{
	int count=0;
	for(int i=1;i<=2016;i++)
	{
		if(judge(i))
		{
			for(int j=i+1;i+j<2019;j++)
			{
				if(judge(j))
				{
					int k=2019-i-j;
					if(judge(k)&&k>j)
					count++;
				}
			}
		}
	}
	cout<<count<<endl;
	return 0;
}
