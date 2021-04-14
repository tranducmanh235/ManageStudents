#include "DangNhap.h"
#include "Admin.h"
#include "GiangVien.h"
#include "SinhVien.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;


DangNhap::DangNhap()
{
}
	
void DangNhap::ScreenLogin() {

}

void DangNhap::Login() {
	system("cls");
	string username, password;
	cout << "USER NAME: ";
	getline(cin, username);
	cout << "PASSWORD: ";
	getline(cin, password);
	fstream f1;
	fstream f;
	string s1, s2, s3,ss1,ss2,ss3;
	f1.open("user.csv", ios::in);
	int bool3 = 0;
	while (!f1.eof()) {
		getline(f1, s1, ',');
		getline(f1, s2, ',');
		getline(f1, s3);
		
		if (username == s1&&password == s2) {
			ss1 = s1;ss2 = s2;ss3 = s3;
			bool3 = 1;
			break;
		}
	}
	f1.close();
	
	while (bool3==0) {
		f1.open("user.csv", ios::in);
		cout << "Ban Nhap Sai Ten Dang Nhap Hoac Mat Khau! Moi Nhap lai." << endl;
		system("pause");
		system("cls");
		string username, password;
		cout << "USER NAME: ";
		getline(cin, username);
		cout << "PASSWORD: ";
		getline(cin, password);
		bool3 = 0;
		while (!f1.eof()) {
			getline(f1, s1, ',');
			getline(f1, s2, ',');
			getline(f1, s3);

			if (username == s1&&password == s2) {
				ss1 = s1;ss2 = s2;ss3 = s3;
				bool3 = 1;
				break;
			}
		}
		f1.close();
	}
	f.open("curuser.csv", ios::out);
	f << ss1 << "," << ss2 << "," << ss3;
	f.close();
	system("cls");
	//cout << ss1 << endl;
	if (ss3 == "teacher") {
		GiangVien gv;
		gv.ScreenGV();
	}
	if (ss3 == "admin") {
		Admin a;
		a.ScreenAdmin();
	}
	if (ss3 == "student") {
		SinhVien sv;
		sv.ScreenSV();
	}
}
DangNhap::~DangNhap()
{
}
