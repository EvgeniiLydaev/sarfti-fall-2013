#include <iostream>
#include <conio.h>
#include <windows.h>
#define _USE_MATH_DEFINES 
#include <cmath> 
using namespace std;

// �����, ����������� ���:
class Sphere
{
protected:
	double r; // ������ , ��� ����������� �� ���� ������� ����� �������� ���������
public:
	// �����������:
	Sphere(double _r=0)
	{ r = _r;}
	double GetRad() {return r;}
	double Square() //������� ����������� �����
	{
		return 4*M_PI*r*r;
	}
};

// �����, ����������� ������� (����������� �� ������ Sphere):
class Cilinder : public Sphere
{
	double h; // ������
public:
	Cilinder(){h=0;}
	// �������� �����������:
	Cilinder(double _r, double _h):
	Sphere (_r) // ����� ����� ������������ �������� ������
	{h = _h;}
	double Volume() {return M_PI*r*r*h;} // ����� �������� ����������� � �������������� r(������ ���������) protected ���� ������������� ������.
	double GetH() {return h;}
};
// ������ ������������� �������:
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
	Sphere sph(10); 
	Cilinder cl(15, 10);
	cout<<"������� ����������� ����� �������� "<<sph.GetRad()<< " ����� "<<sph.Square()<<endl;
	cout<<"����� �������� � �������� ��������� "<<cl.GetRad()<< " � ������� "<<cl.GetH()<<" ����� "<<cl.Volume();	
	_getch();
	return 0;
}