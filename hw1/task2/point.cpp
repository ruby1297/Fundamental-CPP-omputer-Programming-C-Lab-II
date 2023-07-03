#include<cmath>
class Point{
private:
	double X;
	double Y;
public:
	Point() {};
	Point(double x, double y) :X(x), Y(y) {};

	void setX(double x) {
		X = x;
	}
	double getX() {
		return X;
	}

	void setY(double y) {
		Y = y;
	}

	double getY() {
		return Y;
	}

	void setPoint(double x, double y) {
		(X, Y) = (x, y);
	}

	double distance(double x, double y) {
		return sqrt(pow((x - X), 2) + pow((y - Y), 2));
	}

	double distance(Point another) {
		return sqrt(pow((another.X - X), 2) + pow((another.Y - Y), 2));
	}
};