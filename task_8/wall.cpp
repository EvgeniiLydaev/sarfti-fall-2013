#include <conio.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int how_water(int *mass,int sz) //�-� ������� ���-�� ���� � �����
{
	int l_wall=0,r_wall=0,l=0,water=0;
	--sz;
	while(l<sz) // ���� ������ ������� ������ ��� 
	{
		if(mass[sz]>r_wall) r_wall=mass[sz]; // ���� ��������� ����� ������ ��� ����� ������� ���������, �� ��� ����� �������
		if(mass[l]>l_wall) l_wall=mass[l]; // ���� ������� ����� ������ ��� ����� �� ������ �������� ������ ������� �����
		if(l_wall>=r_wall) water+=r_wall-mass[sz--]; // ���� ����� ����� ������ ��� ����� ����� ������� ��������� ������ �� ���������� ����
		else water+=l_wall-mass[l++]; // ����� ������ ���� ����
	}
	return water;
}

int main()
{
	int sz,i;
	cout<<"Input massiv size: ";
	cin>>sz;
	int *mass=new int[sz];
	cout<<"Input wall size:\n";
	for(i=0;i<sz;++i)
	{
		cout<<i+1<<": ";
		cin>>mass[i];
	}
	cout<<"Water: "<<how_water(mass,sz)<<endl;
	return 0;
}