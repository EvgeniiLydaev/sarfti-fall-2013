#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
//������� ��� ���������� ���������� ���� ����������� ����� ����
int calculate(int *massiv, int size) 
{
	int i, water = 0, result = 0, last_wall = 0;
	int current_height = massiv[0];
	//�������� � ������ �����������
	for (i = 1; i < size; i++) 
	{
		if (massiv[i] >= current_height) 
		{
			result += water;
			water = 0;
			current_height = massiv[i];
			last_wall = i;
		} 
		else 
		{
			water += current_height - massiv[i];            
		}
	}
	//�������� � �������� �����������
	current_height = massiv[size - 1];
	water = 0;
	for (i = size - 2; i >= last_wall; i--) 
	{
		if (massiv[i] >= current_height) 
		{
			result += water;
			water = 0;
			current_height = massiv[i];
		}
		else 
		{
			water += current_height - massiv[i];            
		}
	}
	result += water;
	return result;
}
int main()
{
	setlocale(LC_ALL, "Russian");//��������� �������� �����
	int size;
	cout<<"������� ���������� ����: ";
	cin>>size;
	int *massiv = new int[size];//�������� ������ {2,1,6,3,1,2,5,4,5} = 11
	cout<<"������� ������ ����:"<<endl;
	for (int i = 0 ; i < size; i++)
	{
		cout<<i+1<<": ";
		cin>>massiv[i];
	}
	cout<<"���������� ���� ����������� ����� ���� = "<<calculate(massiv,9)<<endl;
	delete []massiv;
	_getch();
	return 0;
}