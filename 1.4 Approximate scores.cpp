#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

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
