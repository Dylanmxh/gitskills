#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

/*
[��������]
С���кܶ����ֿ�Ƭ��ÿ�ſ�Ƭ�϶���һ������(0��9)��
С��׼������Щ��Ƭ��ƴһЩ���������1��ʼƴ����������ÿƴһ�����ͱ�����������Ƭ�Ͳ�������ƴ�������ˡ�
С����֪���Լ��ܴ�1ƴ�����١�
���磬��С����30�ſ�Ƭ������0��9��3�ţ���С������ƴ��1��10������ƴ11ʱ��Ƭ1�Ѿ�ֻ��һ���ˣ�����ƴ�� 11��
����С��������0��9�Ŀ�Ƭ��2021�ţ���20210�ţ�����С�����Դ�1ƴ������?*/

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
(һ)
int mon[13]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; 
// ����Ƿ��ǻ�����
bool check2(int date)
{
	string s= to_string(date);
	if(s[0]==s[7]&&s[1]==s[6]&&s[2]==s[5]&&s[3]==s[4])	return true;
	return false;
 } 
 // ����Ƿ���ABABBABA������
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
// (��)
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
 // ����Ƿ���ABABBABA������
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

//1.4��Լ����
//һ������������
//�������Լ���ĳ����㷨
//
//���������������ƣ�
//1.շת�����������ŷ����·���
//
//�ٺ���Ƕ�׵���
//
//���㷨����Ϊ�� ǰ�᣺������Ϊa,b������a ��������,b��������tempΪ����
//1��������a�С�С����b�У�
//2����a/b��������
//3����temp=0��bΪ���Լ����
//4�����temp!=0���b��ֵ��a��temp��ֵ��b��
//5�����صڶ�����
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
//1.5���ķֽ� 
//����һ 
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
//����һ��ע�� 
