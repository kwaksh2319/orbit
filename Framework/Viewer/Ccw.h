#pragma once
class Ccw {
	

public:
	Ccw();
	~Ccw();
	double ccw(Vector3 a, Vector3 b);
	double cross(Vector3 a, Vector3 b);
	double ccw(Vector3 p,Vector3 a, Vector3 b);
	bool paralleSegments(Vector3 a, Vector3 b, Vector3 c, Vector3 d, Vector3& p);
	bool inBoundingRectangle(Vector3 p, Vector3 a, Vector3 b);

	bool sementIntersects(Vector3 a, Vector3 b, Vector3 c, Vector3 d);
	bool sementIntersects(Vector3 a, Vector3 b, Vector3 c, Vector3 d, Vector3& p);
	bool lineIntersection(Vector3 a, Vector3 b, Vector3 c, Vector3 d, Vector3& x);

private:



};
