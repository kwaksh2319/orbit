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

	//�� �������� ���ų� �� ������ ��ġ�� �ʴ� ��츦 �켱 �ɷ�����. ������ 1�� ������ ����̴�.
	if (ccw(a, b, c) != 0 || b < c || d < a) return false;

	//�� ������ Ȯ���� ��ģ�ٸ� ������ �ϳ��� ã�´�.
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
	//�� ������ �� ������ ���� �ְų� ������ ��ġ�� ���
	if (ab == 0 && cd == 0) {
		if (b < a) swap(a, b);
		if (d < c) swap(c, d);
		return !(b < c || d < a);
	}
	return ab < 0 && cd < 0;

}
