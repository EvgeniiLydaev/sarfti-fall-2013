//����� ����������� ����� � ������������ � ���� ����c Point 
class Line
{// �������� ������: ���������� ������ � ����� �������:
	Point from, to;
	// �������:
public:
	//�����������
	Line(Point a, Point b)
	{	
		from = a;
		to = b;
	}
	//����������� �����������:
	Line(const Line& ln)
	{
		from = ln.from; to = ln.to;
	}
	// ������� �����-������:
	void Input()
	{ 	
		cout << "������� ��������� � �������� ����� ������� (x1 y1 x2 y2) ";
		cin >> from >> to;		
	}
	void Output()
	{
		cout << "���������� �������: ";
		cout << "("<<from.x << ";" << from.y << ")" << " : (" <<to.x<< ";"<<to.y<<")"<< endl;
	}
	// ������� �������:
	Point GetFrom(){return from;}
	Point GetTo() {return to;}
	//���������� ����� �������
	double Lenght()
	{
		return sqrt(pow(double(to.y-from.y), 2)+pow(double(to.x-from.x),2));
	}

};