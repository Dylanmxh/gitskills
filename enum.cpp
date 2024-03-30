#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

/*
[问题描述]
小蓝有很多数字卡片，每张卡片上都是一个数字(0到9)。
小蓝准备用这些卡片来拼一些数，他想从1开始拼出正整数，每拼一个，就保存起来，卡片就不能用来拼其他数了。
小蓝想知道自己能从1拼到多少。
例如，当小蓝有30张卡片，其中0到9各3张，则小蓝可以拼出1到10，但是拼11时卡片1已经只有一张了，不够拼出 11。
现在小蓝手里有0到9的卡片各2021张，共20210张，请问小蓝可以从1拼到多少?*/

int con[10];
bool check(int num)
{
	
	
	while(num)
	{
		int a=num%10;
		con[a]--;
		if(con[a]==0) return true;
		num=num/10;
	}
	return false;
}

int main ()
{
	for(int i=0;i<=9;i++) con[i]=2021;
	for(int i=1; ;i++)
	{
		if(check(i)) 
		{
			cout<<i<<endl;
			break;
		}
	} 
	return 0; 
 } 






/*
(一)
int mon[13]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; 
// 检查是否是回文数
bool check2(int date)
{
	string s= to_string(date);
	if(s[0]==s[7]&&s[1]==s[6]&&s[2]==s[5]&&s[3]==s[4])	return true;
	return false;
 } 
 // 检查是否是ABABBABA回文数
bool check3(int date)
{
	string s=to_string(date);
	if(s[0]==s[2] && s[2]==s[5] && s[5]==s[7] && s[1]==s[3] && s[3]==s[4] && s[4]==s[6])	return true;
	return false;
 } 
 
 int main()
 {
 	int date,a=0;
 	cin>>date;

	int y= date/10000, m=date/100%100,d=date%100;
	for(int i=y; ;i++)
	{
		if(i%400==0||(i%100!=0&&i%4==0)) mon[2]=29;
		int j=(i==y) ? m:1;
		for(;j<=12;j++)
		{
			int k=(j==m)? (d+1):1;
			for(;k<=mon[j];k++)
			{
				int date=i*10000+j*100+k;
				if(check2(date)&&a==0) a=date;
				if(check2(date)&&check3(date)){
					cout<<a<<endl;
					cout<<date<<endl;
					return 0;
				} 
			 	
			 } 
		} 
	}
	return 0;
 }
 */ 
// (二)
/*int mon[13]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; 
string check(int date)
{
	string n=to_string(date);
	string s=to_string(date);
	reverse(s.begin(),s.end());
	n=n+s;
	int y=stoi(n.substr(0,4)),m=stoi(n.substr(4,2)),d=stoi(n.substr(6,2));
	if(y%400==0||(y%100!=0&&y%4==0)) mon[2]=29;
	if(m<1||m>12||d<0||d>mon[m]) return "-1";
	return n;
}
 // 检查是否是ABABBABA回文数
string check3(string s)
{
	if(s[0]==s[2] && s[2]==s[5] && s[5]==s[7] && s[1]==s[3] && s[3]==s[4] && s[4]==s[6])	return s;
	return "-1";
 }
int main()
{
	int date,a;
	string b="";
	cin>>date;
	a=date/10000;
	for(int i=a; ;i++)
	{
		if(check(i)=="-1"||(check(i)==to_string(date))) continue;
		if(b=="") b=check(i);
		if(check3(check(i))!="-1")
		{			
			cout<<b<<endl<<check3(check(i))<<endl;
			return 0;
		}
	}
	return 0;
}
*/

//1.4既约分数
//一、问题描述：
//运行最大公约数的常用算法
//
//二、问题分析与设计：
//1.辗转相除法（又名欧几里德法）
//
//①函数嵌套调用
//
//其算法过程为： 前提：设两数为a,b设其中a 做被除数,b做除数，temp为余数
//1、大数放a中、小数放b中；
//2、求a/b的余数；
//3、若temp=0则b为最大公约数；
//4、如果temp!=0则把b的值给a、temp的值给b；
//5、返回第二步；
/*int gcd(int a,int b) 
{
	if(a%b) return gcd(b,a%b);
	return b;
}

int main()
{
	int cont=0;
	for(int i=1;i<=2020;i++)
	{
		for(int j=i+1;j<=2020;j++)
		{
			
			if(gcd(j,i)==1) cont++;
		}
	}
	cout<<2*cont+1<<endl;
	return 0;
}
*/
//1.5数的分解 
//方法一 
//bool judge(int a)
//{
//	int b=a/10,c=a%10;
//	if(c==2||c==4) return false;
//	if(b==0) return true;	
//	return judge(b);
//}
//int main()
//{
//	int count=0;
//	for(int i=1;i<=2016;i++)
//	{
//		if(judge(i))
//		{
//			for(int j=i+1;i+j<2019;j++)
//			{
//				if(judge(j))
//				{
//					int k=2019-i-j;
//					if(judge(k)&&k>j)
//					count++;
//				}
//			}
//		}
//	}
//	cout<<count<<endl;
//	return 0;
//}
//这是一行注释 
