#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

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
