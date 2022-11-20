#include <bits/stdc++.h>
#include <Windows.h>
#include <iomanip>
using namespace std;
#define ll long long 

double π = 3.14159265359;
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
	return (a / gcd(a, b)) * b;
}
size_t res = 0;

void Press()
{
	system("pause");
}

void Menu() {
	cout << "===========================MENU===========================" << endl;
	cout << "1. Nhap thong tin sinh vien" << endl;
	cout << "2. Hien thi danh sach sinh vien" << endl;
	cout << "3. Tim kiem sinh vien" << endl;
	cout << "4. Xoa Sinh Vien khoi danh sach" << endl;
	cout << "5. Liet ke cac sinh vien co GPA cao nhat\n";
	cout << "6. Liet ke cac sinh vien co GPA >= 2.5\n";
	cout << "7. Sap xep danh sach sinh vien theo ten\n";
	cout << "8. Sap xep sinh vien theo lop theo thu tu Alphabet\n";
	cout << "9. Sap xep sinh vien theo lop theo diem GPA giam dan\n";
	cout << "0. Thoat Menu \n";
	cout << "==========================================================" << endl;
}

void Tieude()
{
	cout << "\t\t";
	cout << "+" << setfill('-') << setw(7) << "-" << setfill(' ');
	cout << "+" << setfill('-') << setw(20) << "-" << setfill(' ');
	cout << "+" << setfill('-') << setw(10) << "-" << setfill(' ');
	cout << "+" << setfill('-') << setw(15) << "-" << setfill(' ');
	cout << "+" << setfill('-') << setw(5) << "-" << setfill(' ') << "+" << endl;

	cout << "\t\t" << "|";
	cout << setw(5) << "MSV " << setw(3) << "|" << " Full Name " << setw(10) << "|" << " Class " << setw(4) << "|" << " Birth " << setw(9) << "|" << " GPA " << "|" << endl;
	cout << "\t\t";
	cout << "+" << setfill('-') << setw(7) << "-" << setfill(' ');
	cout << "+" << setfill('-') << setw(20) << "-" << setfill(' ');
	cout << "+" << setfill('-') << setw(10) << "-" << setfill(' ');
	cout << "+" << setfill('-') << setw(15) << "-" << setfill(' ');
	cout << "+" << setfill('-') << setw(5) << "-" << setfill(' ') << "+" << endl;
}
struct Sinhvien {
	string msv, Fname, Class, Birth;
	double gpa{};

	void Output1()
	{
		/*cout << "-----------------------" << endl;
		cout << "Student Code: " << msv << endl;
		cout << "Full Name: " << Fname << endl;
		cout << "Class: " << Class << endl;
		cout << "Date Of Birth: " << Birth << endl;
		cout << "GPA: " << fixed << setprecision(2) << gpa << endl;
		cout << "-----------------------" << endl;*/

	}
	void Output()
	{
		cout << "\t\t" << "|" << setw(4) << msv << setw(4) << "|" << Fname
			<< "|" << Class << setw(7) << "|" << Birth << setw(6) << "|"
			<< fixed << setprecision(2) << gpa << setw(2) << "|" << endl;
	}
	void Input()
	{
		cout << "Nhap msv: "; cin >> msv;
		cout << "Nhap Ho Va Ten: ";
		cin.ignore();
		getline(cin, Fname);
		if (Fname.size() < 20)
		{
			res = 22 - Fname.size();
			while (res != 0 && Fname.size() < 20)
			{
				Fname = Fname + " ";
				--res;
			}
		}
		cout << "Nhap Lop: "; cin >> Class;
		cout << "Nhap Ngay Thang Nam sinh: "; cin >> Birth;
		if (Birth[1] == '/')
		{
			Birth.insert(0, "0");
		}

		if (Birth[4] == '/')
		{
			Birth.insert(3, "0");
		}
		cout << "Nhap vao Gpa: "; cin >> gpa;
		cout << endl;
	}
};

void load_file(Sinhvien a[], int& n)
{
	//B1 : Khai bao bien:

	ifstream filein;

	//B2 : Mo file:
	filein.open("resour.txt", ios_base::in);

	//B3 : Doc file:

	int sl;
	filein >> sl;
	filein.ignore();


	for (int i = 0; i < sl; i++)
	{
		Sinhvien ds;
		getline(filein, ds.msv);
		getline(filein, ds.Fname);
		if (ds.Fname.size() < 20)
		{
			res = 22 - ds.Fname.size();
			while (res != 0 && ds.Fname.size() < 20)
			{
				ds.Fname = ds.Fname + " ";
				--res;
			}
		}
		getline(filein, ds.Class);
		getline(filein, ds.Birth);
		if (ds.Birth[1] == '/')
		{
			ds.Birth.insert(0, "0");
		}
		if (ds.Birth[4] == '/')
		{
			ds.Birth.insert(3, "0");
		}

		filein >> ds.gpa;
		filein.ignore();

		a[n++] = ds;
	}
	//B4 : Dong file:
	filein.close();
}

void XoaSv(Sinhvien a[], int& n)
{
	int res = 0;
	string Dele;
	cout << "Nhap vao ma cua sinh vien can xoa khoi danh sach: ";
	cin >> Dele;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i].msv == Dele)
		{
			res++;
			for (size_t j = i; j < n; j++)
			{
				a[j] = a[j + 1];
			}
		}
	}
	if (res == 0)
	{
		cout << "Khong Tim thay ma sinh vien!" << endl;
	}
	else n--;
}

void List(Sinhvien a[], int n)
{
	Tieude();
	for (size_t i = 0; i < n; i++)
	{
		a[i].Output();
		Sleep(100);
	}
	cout << "\t\t";
	cout << "+" << setfill('-') << setw(7) << "-" << setfill(' ');
	cout << "+" << setfill('-') << setw(20) << "-" << setfill(' ');
	cout << "+" << setfill('-') << setw(10) << "-" << setfill(' ');
	cout << "+" << setfill('-') << setw(15) << "-" << setfill(' ');
	cout << "+" << setfill('-') << setw(5) << "-" << setfill(' ') << "+" << endl;
}

void SearchID(Sinhvien a[], int n)
{
	string msv;
	cout << "Nhap vao ma sinh vien can tim: "; cin >> msv;
	bool check = false;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i].msv.find(msv) != string::npos)
		{
			a[i].Output();
			check = true;
		}
	}
	if (!check)
	{
		cout << "ID Not Found!" << endl;
	}
}

void SearchName(Sinhvien a[], int n)
{
	bool check = false;
	string name;
	cout << "Nhap vao ten cua sinh vien can kiem tra: "; cin >> name;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i].Fname.find(name) != string::npos)
		{
			a[i].Output();
			check = true;
		}
	}
	if (!check)
	{
		cout << "Khong tim thay ten sinh vien!" << endl;
	}
}

void SearchClass(Sinhvien a[], int n)
{
	string Cla;
	cout << "Nhap vao lop can tim: "; cin >> Cla;
	bool check = false;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i].Class.find(Cla) != string::npos)
		{
			a[i].Output();
			check = true;
		}
	}
	if (!check)
	{
		cout << "Khong tim thay lop!" << endl;
	}
}

vector<string> Chuanhoa(string name)
{
	stringstream ss(name); vector <string> v;
	string token;
	while (ss >> token)
	{
		v.push_back(token);
	}
	return v;
}



bool cmp1(Sinhvien a, Sinhvien b)
{
	return a.gpa > b.gpa;
}

bool cmp2(Sinhvien a, Sinhvien b)
{
	vector<string> v1 = Chuanhoa(a.Fname), v2 = Chuanhoa(b.Fname);
	if (v1.back() != v2.back())
	{
		return v1.back() < v2.back();
	}
	size_t len1 = v1.size(), len2 = v2.size();
	for (size_t i = 0; i < min(len1, len2); i++)
	{
		if (v1[i] != v2[i])
		{
			return v1[i] < v2[i];
		}
	}
	return len1 < len2;
}

bool cmp3(Sinhvien a, Sinhvien b)
{
	if (a.Class != b.Class)
	{
		return a.Class < b.Class;
	}
	vector<string> v1 = Chuanhoa(a.Fname), v2 = Chuanhoa(b.Fname);
	if (v1.back() != v2.back())
	{
		return v1.back() < v2.back();
	}
	size_t len1 = v1.size(), len2 = v2.size();
	for (size_t i = 0; i < min(len1, len2); i++)
	{
		if (v1[i] != v2[i])
		{
			return v1[i] < v2[i];
		}
	}
	return len1 < len2;
}

bool cmp4(Sinhvien a, Sinhvien b)
{
	if (a.Class != b.Class)
	{
		return a.Class < b.Class;
	}
	return a.gpa > b.gpa;
}

void LkGpa1(Sinhvien a[], int n)
{
	double Top = a[0].gpa;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i].gpa > Top)
		{
			Top = a[i].gpa;
		}
	}
	cout << "Danh sach cac sinh vien co GPA cao nhat la: " << endl;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i].gpa == Top)
		{
			a[i].Output();
		}
	}
}

void LkGpa2(Sinhvien a[], int n)
{
	vector<Sinhvien> v;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i].gpa >= 2.5)
		{
			v.push_back(a[i]);
		}
	}
	cout << "Danh sach sinh vien co Gpa >= 2.5: " << endl;
	sort(v.begin(), v.end(), cmp1);
	for (auto x : v)
	{
		x.Output();
	}
}


void sxName(Sinhvien a[], int n)
{
	sort(a, a + n, cmp2);
}

void sxLop(Sinhvien a[], int n)
{
	sort(a, a + n, cmp3);
}

void sxGpa(Sinhvien a[], int n)
{
	sort(a, a + n, cmp4);
}

int main()
{
	int n = 0;
	char confirm;
	Sinhvien s[20];
	load_file(s, n);
	Menu();
	do
	{
		cout << "Select: ";
		int Select; cin >> Select;
		/*if (Select == 1)
		{
			s[n].Input();
			++n;
		}
		else if (Select == 2)
		{
			List(s, n);
		}
		else if (Select == 3)
		{
			SearchID(s, n);
		}
		else if (Select == 4)
		{
			XoaSv(s, n);
		}
		else if (Select == 5)
		{
			LkGpa1(s, n);
		}
		else if (Select == 6)
		{
			LkGpa2(s, n);
		}
		else if (Select == 7)
		{
			sxName(s, n);
		}
		else if (Select == 8)
		{
			sxLop(s, n);
		}
		else if (Select == 9)
		{
			sxGpa(s, n);
		}
		else if (Select == 0)
		{
			break;
		}*/

		switch (Select)
		{
		case 1:
			s[n].Input();
			n++;
			Press();
			break;
		case 2:
			List(s, n);
			Press();
			break;
		case 3:
			cout << "\t ->1. Tim Kiem theo ID " << endl;
			cout << "\t ->2. Tim Kiem theo Ten " << endl;
			cout << "\t ->3. Tim Kiem theo Class " << endl;
			cout << "chon Option ban muon tim kiem: ";
			int pick; cin >> pick;
			if (pick == 1)
			{
				SearchID(s, n);
			}
			else if (pick == 2)
			{
				SearchName(s, n);
			}
			else if (pick == 3)
			{
				SearchClass(s, n);
			}
			Press();
			break;
		case 4:
			XoaSv(s, n);
			Press();
			break;
		case 5:
			LkGpa1(s, n);
			Press();
			break;
		case 6:
			LkGpa2(s, n);
			Press();
			break;
		case 7:
			sxName(s, n);
			Press();
			break;
		case 8:
			sxLop(s, n);
			Press();
			break;
		case 9:
			sxGpa(s, n);
			Press();
			break;

		default:
			cout << "Ban da nhap sai key lua chon!" << endl;
			Press();
			break;
		}
		cout << "Ban co muon tiep tuc lua chon khong? (y/n)" << endl;
		cin >> confirm;
		if (confirm == 'n')
			cout << "Da Dong Menu!" << endl;
	} while (confirm == 'y' || confirm == 'Y');
	return 0;
}