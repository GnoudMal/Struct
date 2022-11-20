#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
	return (a / gcd(a, b) * b);
}


struct Phanso {
	long long tu, mau;
};

void Input(Phanso& s)
{
	cin >> s.tu >> s.mau;
}

void Rutgon(Phanso& s)
{
	ll l = gcd(s.tu, s.mau);
	s.tu /= l;
	s.mau /= l;
}

Phanso Tong(Phanso a, Phanso b)
{
	ll mc = lcm(a.mau, b.mau);
	a.tu = mc / a.mau * a.tu;
	b.tu = mc / b.mau * b.tu;
	a.tu += b.tu;
	a.mau = mc;
	Rutgon(a);
	return a;
}

void Output(Phanso s)
{
	cout << s.tu << "/" << s.mau << endl;
}

int main()
{
	Phanso p, q;
	Input(p); Input(q);
	Phanso t = Tong(p, q);
	Output(t);
	return 0;
}