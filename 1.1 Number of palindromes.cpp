#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

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
