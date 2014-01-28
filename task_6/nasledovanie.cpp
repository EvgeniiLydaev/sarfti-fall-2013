#define _USE_MATH_DEFINES
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

class Line
{// �������� ������: ���������� ������ � ����� �������:
protected:
	int x1, y1, x2, y2;
	// �������:
public:
	/* ��������� ��������� �� ��������� ����� ���������� ��� ������������(�� ��������� � ��������) � ����: */
	Line(int _x1=0, int _y1=0, int _x2=0, int _y2=0)
	{	
		x1 = _x1; y1 = _y1; x2 = _x2, y2 = _y2;
	}
	//����������� �����������:
	Line(const Line& ln)
	{
		x1 = ln.x1; y1 = ln.y1; x2 = ln.x2; y2 = ln.y2;
	}
	// ������� �����-������:
	void Input()
	{
		cin >> x1 >> y1 >> x2 >> y2;		
	}
	void Output()
	{
		cout << "���������� �������: ";
		cout << "("<<x1 << ";" << y1 << ")" << " : (" <<x2<< ";"<<y2<<")"<< endl;
	}
	// ������� �������:
	int GetX1(){return x1;}
	int GetY1() {return y1;}
	int GetX2() {return x2;}
	int GetY2() {return y2;}
	//��������� ������������������ ���� ��������
	bool isPerpendicular(const Line& ln){
		int condition = (x2-x1)*(ln.x2-ln.x1)+(y2-y1)*(ln.y2-ln.y1); 
		if (condition == 0)
			return true;
		return false;
	}
};
class Triangle:private Line//������������
{
	int x3, y3;
public:
	Triangle(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0, int _x3 = 0, int _y3 = 0)
	{
		x1 = _x1; x2 =_x2; x3 = _x3;
		y1 = _y1; y2 = _y2; y3 = _y3;
	}
	// ������� �����-������:
	void Input()
	{ 	
		cout << "������� ���������� ������ ������������ (x1 y1 x2 y2 x3 y3) ";
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;		
	}
	void Output()
	{
		cout << "���������� ������ ������������: ";
		cout << "("<<x1 << ";" << y1 << ")" << " : (" <<x2<< ";"<<y2<<")"<<  " : (" <<x3<< ";"<<y3<<")"<<endl;
	}
	//����������� �����������:
	Triangle(const Triangle& tr)
	{
		x1 = tr.x1; y1 = tr.y1; x2 = tr.x2; y2 = tr.y2; x3 = tr.x3; y3 =tr.y3;
	}
	double LengthAB(){return sqrt(pow(double(x2 - x1), 2) + pow(double(y2 - y1), 2));}
	double LengthBC(){return sqrt(pow(double(x3 - x2), 2) + pow(double(y3 - y2), 2));}
	double LengthCA(){return sqrt(pow(double(x1 - x3), 2) + pow(double(y1 - y3), 2));}
	double Perimetr(){return LengthAB()+LengthBC()+LengthCA();}
	double Square(){return 0.5*abs((x1-x3)*(y2-y3)-(x2-x3)*(y1-y3));}
};

int main()
{
	////��������� ������� � ������������ ����������: 
	//if(SetConsoleCP(1251)==0)
	//	//�������� ������������ ��������� ��������� �������� ��� �����
	//{
	//	cerr<<"Fialed to set codepage!"<<endl;
	//	/* ���� �� ������� ���������� ������� ��������, ����� ��������� �� ������ */
	//}
	//if(SetConsoleOutputCP(1251)==0)//���� ����� ��� ������
	//{
	//	cerr<<"Failed to set OUTPUT page!"<<endl;
	//}	
	setlocale(LC_ALL, "Russian");

	Triangle tr;
	tr.Input();
	tr.Output();
	cout<<"������� ������������ = "<<tr.Square() << " , �������� = "<< tr.Perimetr() <<endl;

	_getch(); 
	return 0;
}
