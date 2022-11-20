#include <bits/stdc++.h>
using namespace std;

struct Peason {
	string Name, Birth;
};

bool cmp(Peason a, Peason b)
{
	string s = a.Birth, t = b.Birth;
	int n1 = (s[0] - '0') * 10 + s[1] - '0', t1 = (s[3] - '0') * 10 + s[4] - '0', na1 = stoi(s.substr(6));
	int n2 = (t[0] - '0') * 10 + t[1] - '0', t2 = (t[3] - '0') * 10 + t[4] - '0', na2 = stoi(t.substr(6));
	if (na1 != na2)
	{
		return na1 > na2;
	}
	if (t1 != t2)
	{
		return t1 > t2;
	}
	return n1 > n2;
}

int main()
{
	int n = 2;
	Peason p[2];
	for (size_t i = 0; i < 2; i++)
	{
		cin >> p[i].Name >> p[i].Birth;
	}
	sort(p, p + n, cmp);
	cout << p[n - 1].Name << "\n" << p[0].Name << endl;
	return 0;
}