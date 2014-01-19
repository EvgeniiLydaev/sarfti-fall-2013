#define _USE_MATH_DEFINES 
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

// �����, ����������� �����:
class Point
{

private:
	//������������� ������� ����� � ������
	//---------------------------------------------------------
	friend istream& operator >> (istream& is, Point& p)
	{
		cout << "������� ���������� ����� ";
		return is >> p.x >> p.y;
	}
	friend ostream& operator << (ostream& os, const Point& p)
	{
		return os << "��������� �����: [" <<
			p.x << ", " << p.y << "]\n";
	}
	//----------------------------------------------------------------
public:

	int x, y;
	//�����������
	Point(int _x=0, int _y=0)
	{ x = _x; y =_y;}
	//����������� �����������:
	Point(const Point& pt)
	{
		x= pt.x; y = pt.y;
	}
};

// �����, ����������� ���������� ������������ �� ������ Point
class Circle: public Point // ����� Point �������� ������� ��� ������ Circle
{
	friend istream& operator >> (istream& is, Circle& c)
	{
		cout << "������� ���������� ������ � ������ ";
		return is >> c.x >> c.y >> c.r;
	}
	friend ostream& operator << (ostream& os, const Circle& c)
	{
		return os << "������: " << c.r << ", " <<  Point(c.x, c.y); 
		// ������ ������������� ������� �������� ������

	}
	//----------------------------------------------------------------
protected:
	double r; // ������ ����������
public:
	// �����������:
	Circle (double _x = 0, double _y = 0, double _r = 0): Point (_x, _y)
	{ r = _r;}
	double Area ()
	{return M_PI* r *r;} // ������� �����
};


int main()
{
	//��������� ������� � ������������ ����������: 
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

	Point from, to;
	cin>>from;
	cin>>to;
	Line ln (from, to);
	ln.Output();
	cout<<"����� ������� = "<<ln.Lenght()<<endl;
	Circle cr;
	cin>>cr;
	cout<<cr<<"������� ���������� "<<cr.Area()<<endl;
	_getch();
	return 0;
}