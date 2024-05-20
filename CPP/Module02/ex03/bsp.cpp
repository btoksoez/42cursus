#include "Point.hpp"
/* bsp calculates the size of the triangles abc, abp, apc, and pbc.
if the sum of the latter 3 is equal to the first one, p must be inside.
then it checks that it's not on the edge (no triangle has surface area 0)
and returns true or false
*/

Fixed getSize(Point const a, Point const b, Point const c)
{
	Fixed	size;

	size = Fixed(0.5f) * abs(a.getX()*b.getY() + b.getX()*c.getY() + c.getX()*a.getY() - a.getX()*c.getY() - c.getX()*b.getY() - b.getX()*a.getY());
	return (size);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	t = getSize(a, b, c);
	Fixed	t1 = getSize(a, b, point);
	Fixed	t2 = getSize(a, point, c);
	Fixed	t3 = getSize(point, b, c);

	// std::cout << t << std::endl;
	// std::cout << t1 << std::endl;
	// std::cout << t2 << std::endl;
	// std::cout << t3 << std::endl;
	// std::cout << "total: " << (t1 + t2 + t3) << std::endl;

	if (t1 != Fixed(0) && t2 != Fixed(0) && t3 != Fixed(0)&& (t1 + t2 + t3) == t)
		return (true);
	return (false);
}
