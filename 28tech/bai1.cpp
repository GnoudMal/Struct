#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

struct Phanso
{
	long long tu ,mau;
};

void Input(Phanso &s)
{
	cin >> s.tu >> s.mau;
}

void rutgon(Phanso& s)
{
	long long l = gcd(s.tu, s.mau);
	s.tu /= l;
	s.mau /= l;
}

void Output(Phanso s)
{
	cout << s.tu << '/' << s.mau << endl;
}

int main()
{
	struct Phanso s;
	Input(s);
	rutgon(s);
	Output(s);
	return 0;
}