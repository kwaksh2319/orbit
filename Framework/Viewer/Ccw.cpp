#include"Framework.h"
#include"Ccw.h"
#define EPSILON 0.0001
Ccw::Ccw()
{
}

Ccw::~Ccw()
{
}
double Ccw::cross(Vector3 a, Vector3 b)
{
	//Vector3 p;
	//D3DXVec3Cross(, &a, &b);
	return   a.x*b.y - a.y * b.x;
}



double Ccw::ccw(Vector3 a, Vector3 b)
{
	return cross(a,b);
}

double Ccw::ccw(Vector3 p, Vector3 a, Vector3 b)
{
	return ccw(a-p, b-p);
}

bool Ccw::paralleSegments(Vector3 a, Vector3 b, Vector3 c, Vector3 d, Vector3 & p)
{
	if (b < a) swap(a, b);
	if (d < c) swap(c, d);

	//한 직선위에 없거나 두 선분이 겹치지 않는 경우를 우선 걸러낸다. 본문의 1번 관계인 경우이다.
	if (ccw(a, b, c) != 0 || b < c || d < a) return false;

	//두 선분이 확실히 겹친다면 교차점 하나를 찾는다.
	if (a < c) p = c;
	else p = a;
	return true;

}

bool Ccw::inBoundingRectangle(Vector3 p, Vector3 a, Vector3 b)
{
	if (b < a) swap(a, b);
	return p == a || p == b || (a < p && p < b);

}





bool Ccw::sementIntersects(Vector3 a, Vector3 b, Vector3 c, Vector3 d)
{
	double ab = ccw(a, b, c)*ccw(a, b, d);
	double cd = ccw(c, d, a)*ccw(c, d, b);
	//두 선분이 한 직선에 위에 있거나 끝점이 겹치는 경우
	if (ab == 0 && cd == 0) {
		if (b < a) swap(a, b);
		if (d < c) swap(c, d);
		return !(b < c || d < a);
	}
	return ab < 0 && cd < 0;

}
