#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()
#define fi first
#define se second

bool check(string s)
{
	if (s.size() < 2)
	{
		return false;
	}
	string t = s;
	reverse(all(s));
	return s == t;
}

bool cmp(pair<string, int> a, pair<string, int> b)
{
	return(a.fi.size() != b.fi.size() ? a.fi.size() > b.fi.size() : a > b);
}

int main()
{
	map <string, int> mp;
	string s;
	while (cin >> s)
	{
		if (check(s))
		{
			mp[s]++;
		}
	}
	vector<pair<string, int>> v;
	for (auto it : mp)
	{
		v.push_back(it);
	}
	sort(all(v), cmp);
	for (auto it : v)
	{
		cout << it.fi << " " << it.se << endl;
	}
	return 0;
}
// chua chay duoc do visual studio can phai nhap du gia tri voi chay
