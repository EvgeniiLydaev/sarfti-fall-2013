//POINT.H
//Определение класса Point
#ifndef POINT_H
#define POINT_H
using namespace std;

class Point
  {
    friend ostream &operator<<(ostream &, const Point &);
  public:
     Point(double=0, double=0);//конструктор по умолчанию
     void setPoint(double, double);//установка координат
     double getX() const { return x; }//получение координаты х
     double getY() const { return y; }//получение координаты у
  protected://доступно производным классам
    double x, y;//координаты point
    };
#endif
