#include <bits/stdc++.h>
using namespace std;

struct Info {
	string HoTen;
	string Birth;
	double p1;
	double p2;
	double p3;
};

void Input(Info &s)
{
	getline(cin, s.HoTen);
	cin >> s.Birth;
	cin >> s.p1 >> s.p2 >> s.p3;
}

void Output(Info s)
{
	cout << s.HoTen << " " << s.Birth << fixed << setprecision(1) << " " << (s.p1 + s.p2 + s.p3) << endl;
}

int main()
{
	Info I;
	Input(I);
	Output(I);
	return 0;
}