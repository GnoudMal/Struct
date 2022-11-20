#include <bits/stdc++.h>
using namespace std;

 double pi = 3.14159265359;

struct Point {
	double a, b;

	double distance(Point s)
	{
		return sqrt(pow(a - s.a, 2) + pow(b - s.b, 2));
	}
};

void Solve(Point x,Point y,Point z)
{
	double x1 = x.distance(y), x2 = x.distance(z), x3 = y.distance(z);
	if (x1 <= 0 || x2 <= 0 || x3 <= 0 || x1 + x2 <= x3 || x2 + x3 <= x1 || x1 + x3 <= x2)
	{
		cout << "INVALID! " << " " << endl;
	}
	double p = (x1 + x2 + x3) / 2;
	double S = sqrt(p * (p - x1) * (p - x2) * (p - x3));
	double R = x1 * x2 * x3 / (4 * S);
	cout << fixed << setprecision(4) << pi * R * R << endl;
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		Point x, y, z;
		cin >> x.a >> x.b >> y.a >> y.b >> z.a >> z.b;
		Solve(x, y, z);
	}
	return 0;
}