#pragma once

struct XY
{
	int x;
	int y;

	XY();
	XY(int _x, int _y);
};

XY operator + (const XY& lhs, const XY& rhs);
XY operator - (const XY& lhs, const XY& rhs);