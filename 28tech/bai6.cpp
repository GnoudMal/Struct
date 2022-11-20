#include <bits/stdc++.h>
using namespace std;

struct Sinhvien {
	string Code, Fname, Gender, Address, TaxCode, ContractDate, Birth;
};

void Input(Sinhvien& s)
{
	cin.ignore();
	getline(cin, s.Fname);

	cin >> s.Gender >> s.Birth;

	if (s.Birth[1] == '/')
	{
		s.Birth.insert(0, "0");
	}

	if (s.Birth[4] == '/')
	{
		s.Birth.insert(3, "0");
	}
	cin.ignore();
	getline(cin, s.Address);

	cin >> s.TaxCode >> s.ContractDate; ;

	if (s.ContractDate[1] == '/')
	{
		s.ContractDate.insert(0, "0");
	}

	if (s.ContractDate[4] == '/')
	{
		s.ContractDate.insert(3, "0");
	}
}

void Output(Sinhvien a[], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		string s = to_string(i + 1);
		while (s.size() < 5)
		{
			s = "0" + s;
		}
		cout << "----------------------" << endl;
		cout << s << " ";
		cout << a[i].Fname << " " << a[i].Address << " " << a[i].Birth << " " << a[i].Gender << " " << a[i].TaxCode << " " << a[i].ContractDate << endl;
	}
}

int main()
{
	Sinhvien  s[10];
	int n; cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		Input(s[i]);
		Output(s,n);
	}
	return 0;
}