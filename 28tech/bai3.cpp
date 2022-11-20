#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
	double x, y;
};

void Input(Point& p)
{
	cin >> p.x >> p.y;
}

double distance(Point a, Point b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}



int main()
{
	Point A,B;
	int t; cin >> t;
	while (t--)
	{
		Input(A); Input(B);
		cout << fixed << setprecision(4) << distance(A, B) << endl;
	}
	return 0;
}