#include <bits/stdc++.h>
using namespace std;

struct Sinhvien {
	string maSv;
	string Hoten, Lop, ns;
	double gpa;
};

void nhap(Sinhvien& s)
{
	getline(cin, s.Hoten);
	cin >> s.Lop;
	cin >> s.ns;
	cin >> s.gpa;
	s.Lop = "NAOSSHN091";
	if (s.ns[1] == '/')
	{
		s.ns = '0' + s.ns;
	}
	if (s.ns[4] == '/')
	{
		s.ns.insert(3, "0");
	}
}

void xuat(Sinhvien s)
{
	cout << s.Hoten << " " <<  s.Lop << " " << s.ns << fixed << setprecision(2) << " " << s.gpa << endl;
}

int main()
{
	Sinhvien s;
	nhap(s);
	xuat(s);
	return 0;
}