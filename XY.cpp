#include "xy.h"

XY::XY()
	: x(0), y(0)
{

}

XY::XY(int _x, int _y)
	: x(_x)
	, y(_y)
{
}


XY operator + (const XY& lhs, const XY& rhs)
{
	return XY(
		lhs.x + rhs.x, 
		lhs.y + rhs.y);
}

XY operator - (const XY& lhs, const XY& rhs)
{
	return XY(
		lhs.x - rhs.x, 
		lhs.y - rhs.y);
}
