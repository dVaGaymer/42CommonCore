#include "Point.hpp"

Point::Point()
	:_x(0), _y(0){}

Point::Point(float const x, float const y)
	:_x(x), _y(y){}

Point::Point(const Point &o)
	:_x(o._x), _y(o._y){}

Point::~Point(){}

Fixed const	Point::getX() const { return (this->_x); }
Fixed const	Point::getY() const { return (this->_y); }

Point const & Point::operator=(Point const &o){ return (o); }

/*Triangle area = 1/2*|x1(y2-y3)+x2(y3-y1)+x3(y1-y2)|*/
Fixed	area(Point const a, Point const b, Point const c)
{
	Fixed	t_area;

	t_area = Fixed(0.5f) * ((a.getX()*(b.getY() - c.getY())) +
					(b.getX()*(c.getY() - a.getY())) +
					(c.getX()*(a.getY() - b.getY())));
	return (t_area);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	area_triangle = area(a, b, c);
	Fixed	area_1 = area(point, b, c);
	area_1 = (area_1) < 0 ? area_1 * -1 : area_1;
	Fixed	area_2 = area(a, point, c);
	area_2 = (area_2) < 0 ? area_2 * -1 : area_2;
	Fixed	area_3 = area(a, b, point);
	area_3 = (area_3) < 0 ? area_3 * -1 : area_3;

	Fixed	area_total = area_1 + area_2 + area_3;
	return (area_total <= area_triangle);
}
