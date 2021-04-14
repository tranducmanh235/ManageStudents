#include "Admin.h"

#include <iostream>
#include <string>

Admin::Admin() {
	
	
}

void Admin::ListUser(string in) {
	
	
	sinhvien sv;
	giangvien gv;

		fstream fstudent, fteacher;

		
		int bool1 = 0;
		string a;
		cin.ignore();
		do {
			fstudent.open("student.csv", ios::in);
			cout << "Nhap ten User muon tim kiem: ";

			getline(cin, a);
			if (in == "student") {
				cout << setw(8) << left << "ID" << setw(25) << left << "Ho va Ten" << setw(15) << left << "||Ngay Sinh" << setw(30) << left << "||Dia chi" << endl;
				cout << "---------------------------------------------------------------------------------------------------------" << endl;
				while (!fstudent.eof()) {
					getline(fstudent, sv.ID_sv, ',');
					getline(fstudent, sv.FullName_sv, ',');
					getline(fstudent, sv.BirthDay_sv, ',');
					getline(fstudent, sv.Address_sv);
					size_t found = sv.FullName_sv.find(a);
					if (sv.ID_sv == "") break;
					if (found != string::npos) {
						bool1 = 1;
						cout << setw(8) << left << sv.ID_sv << left << "||" << setw(23) << sv.FullName_sv  << left << setw(13) << "||" << sv.BirthDay_sv   << left << "||" << setw(28) << sv.Address_sv << endl;
					}
				}
				if (bool1 == 0) cout << "RECORD NOT FOUND!" << endl;
				fstudent.close();
			}
			if (in == "teacher") {
				fteacher.open("teacher.csv", ios::in);
				cout << setw(8) << left << "ID" << setw(25) << left << "||Ho va Ten" << setw(15) << left << "||Ngay Sinh" << setw(20) << left << "||So Dien Thoai" << setw(30) << left << "||Dia chi" << endl;
				cout << "----------------------------------------------------------------------------------------------------------" << endl;
				while (!fteacher.eof()) {
					getline(fteacher, gv.ID_GV, ',');
					getline(fteacher, gv.FullName, ',');
					getline(fteacher, gv.BirthDay, ',');
					getline(fteacher, gv.phoneNumber, ',');
					getline(fteacher, gv.Address);
					size_t found = gv.FullName.find(a);
					if (found != string::npos) {
						bool1 = 1;
						cout << setw(8) << left << gv.ID_GV << left << "||" << setw(23) << gv.FullName << left << "||" << setw(13) << gv.BirthDay << left << "||" << setw(18) << gv.phoneNumber << left << "||" << setw(28) << gv.Address << endl;
					}

				}
				if (bool1 == 0) cout << "RECORD NOT FOUND!" << endl;
				fteacher.close();
			}
		} while (bool1 == 0);
	/*string vanBan("Mot doan van ban dai 3 trang co chu Thanh o day va mot chu Thanh nua o day");
	string chuoi("Thanh");

	size_t found = vanBan.find(chuoi);
	if (found != string::npos)
		std::cout << "Chu " << chuoi << " dau tien nam o: " << found << '\n';

	found = vanBan.rfind(chuoi);
	if (found != string::npos)
		cout << "Chu " << chuoi << " cuoi cung nam o: " << found << '\n';*/
	system("pause");
	
}

void Admin::Add(){
	string in, admin, temp;
	giangvien gv;
	user u;
	
	cout << "Ban muon them giang vien hay sinh vien ( teacher or student ) : ";
	cin >> in;
	while (in != "teacher"&&in != "student") {
		cout << "Khong Hop Le! Moi nhap lai !" << endl;
		cout << "Ban muon them giang vien hay sinh vien (teacher or student): ";
		cin >> in;
	}
	fstream f1, f2;
	fstream t1, t2;
	f2.open("user.csv", ios::in);
	t1.open("teacheruser.csv", ios::out);
	t2.open("studentuser.csv", ios::out);
	while (!f2.eof()) {
		getline(f2, u.acc, ',');
		getline(f2, u.pass, ',');
		getline(f2, u.type);
		if (u.acc == "") break;
		if (u.type == "teacher"||u.type=="admin") {
			t1 << u.acc << "," << u.pass << "," << u.type << endl;
		}
		if (u.type == "student") {
			t2 << u.acc << "," << u.pass << "," << u.type << endl;
		}
	}
	t1.close();
	t2.close();
	f2.close();
	if (in == "teacher") {
		f2.open("user.csv", ios::in);
		cout << "Nhap Ma Giang Vien: ";
		cin >> gv.ID_GV;
		while (!f2.eof()) {
			getline(f2, u.acc, ',');
			getline(f2, temp);
			while (gv.ID_GV == u.acc) {
				cout << "Ma Giang Vien da ton tai! Moi Nhap lai: ";
				cin >> gv.ID_GV;
			}
		}
		f2.close();
		cout << "Nhap Ho va Ten Gian Vien: ";
		cin.ignore();
		getline(cin, gv.FullName);
		cout << "Nhap ngay sinh cua Gian vien: ";
		getline(cin, gv.BirthDay);
		cout << "Nhap So Dien Thoai Giang Vien: ";
		getline(cin, gv.phoneNumber);
		cout << "Nhap Dia chi cua Giang Vien: ";
		getline(cin, gv.Address);
		f1.open("teacher.csv", ios::app);
		f1 << gv.ID_GV << "," << gv.FullName << "," << gv.BirthDay << "," << gv.phoneNumber << "," << gv.Address << endl;
		t1.open("teacheruser.csv", ios::app);
		t1 << gv.ID_GV << "," << gv.ID_GV << ",teacher" << endl;

	}
	f1.close();
	sinhvien sv;
	if (in == "student") {
		f2.open("user.csv", ios::in);
		cout << "Nhap Ma Sinh Vien: ";
		cin >> sv.ID_sv;
		while (!f2.eof()) {
			getline(f2, u.acc, ',');
			getline(f2, temp);
			while (sv.ID_sv == u.acc) {
				cout << "Ma Sinh Vien da ton tai! Moi Nhap lai: ";
				cin >> sv.ID_sv;
			}
		}
		f2.close();
		cout << "Ho va Ten cua Sinh Vien: ";
		cin.ignore();
		getline(cin, sv.FullName_sv);
		cout << "Nhap ngay sinh cua Sinh Vien: ";
		getline(cin, sv.BirthDay_sv);
		cout << "Nhap dia chi cua Sinh Vien: ";
		getline(cin, sv.Address_sv);
		f1.open("student.csv", ios::app);
		f1 << sv.ID_sv << "," << sv.FullName_sv << "," << sv.BirthDay_sv << "," << sv.Address_sv << endl;
		t2.open("studentuser.csv", ios::app);
		t2 << sv.ID_sv << "," << sv.ID_sv << ",student" << endl;
	}

	f1.close();
	t1.close();
	t2.close();
	f1.open("temp.csv", ios::out);
	t1.open("teacheruser.csv", ios::in);
	t2.open("studentuser.csv", ios::in);
	while (!t1.eof()) {
		getline(t1, u.acc, ',');
		getline(t1, u.pass, ',');
		getline(t1, u.type);
		if (u.acc == "") break;
		f1 << u.acc << "," << u.pass << "," << u.type << endl;
	}
	while (!t2.eof()) {
		getline(t2, u.acc, ',');
		getline(t2, u.pass, ',');
		getline(t2, u.type);
		if (u.acc == "") break;
		f1 << u.acc << "," << u.pass << "," << u.type << endl;
	}
	cout << "Them Thanh Cong !" << endl;
	system("pause");
	system("cls");
	f1.close();
	t1.close();
	t2.close();
	remove("user.csv");
	rename("temp.csv", "user.csv");
	remove("teacheruser.csv"); 
	remove("studentuser.csv");
}

void Admin::FindUser() {
	string s1,t,tem;
	cout << "Nhap Ten Dang Nhap cua User: ";
	cin >> s1;
	fstream f1;
	int bool1 = 0;
	while (bool1 == 0) {
		f1.open("user.csv", ios::in);
		while (!f1.eof()) {
			getline(f1, t, ',');
			getline(f1, tem);
			if (t == s1) bool1 = 1;
		}
		f1.close();
		if (bool1 == 0) {
			cout << "Ten Dang Nhap cua user khong ton tai! Moi Nhap lai: ";
			cin >> s1;
		}
	}
	f1.close();
	f1.open("user.csv", ios::in);
	string ss1, ss2, ss3, temp;
	while (!f1.eof()) {
		getline(f1, ss1, ',');
		getline(f1, ss2,',');
		getline(f1, ss3);
		if (s1 == ss1) {
			cout << "Thong Tin cua user." << endl;
			cout << "Ten Dang Nhap: " << ss1 << endl;
			cout << "Mat Khau: " << ss2 << endl;
			cout << "Loai user: " << ss3 << endl;
			break;
		}
	}
	f1.close();
	fstream f2;
	giangvien gv;
	sinhvien sv;
	if (ss3 == "teacher") {
		f2.open("teacher.csv", ios::in);
		while (!f2.eof()) {
			getline(f2, gv.ID_GV, ',');
			getline(f2, gv.FullName, ',');
			getline(f2, gv.BirthDay, ',');
			getline(f2, gv.phoneNumber, ',');
			getline(f2, gv.Address);
			if (gv.ID_GV == s1) {
				cout << setw(25) << left << "Ho va Ten" << setw(15) << left << "Ngay Sinh" << setw(15) << left << "So Dien Thoai" << setw(30) << left << "Dia chi" << endl;
				cout << setw(25) << left << gv.FullName << setw(15) << left << gv.BirthDay << setw(15) << left << gv.phoneNumber << setw(30) << left << gv.Address << endl;
				f2.close();
				break;
			}
		}
	}
	if (ss3 == "student") {
		f2.open("student.csv", ios::in);
		while (!f2.eof()) {
			getline(f2, sv.ID_sv, ',');
			getline(f2, sv.FullName_sv, ',');
			getline(f2, sv.BirthDay_sv, ',');
			getline(f2, sv.Address_sv);
			if (sv.ID_sv == s1) {
				cout << setw(25) << left << "Ho va Ten" << setw(15) << left << "Ngay Sinh" << setw(30) << left << "Dia chi" << endl;
				cout << setw(25) << left << sv.FullName_sv << setw(15) << left << left << sv.BirthDay_sv << setw(30) << left << left << sv.Address_sv << endl;
				f2.close();
				break;
			}
		}
	}
}

void Admin::DeleteGV() {
	ListUser("teacher");
	fstream f1, f2;
	giangvien gv;
	string msgv;
	string ms, t;
	cout << "Nhap ma giang vien ban muon xoa: ";
	cin >> msgv;
	int bool1 = 0;
	while (bool1 == 0) {
		f1.open("teacher.csv", ios::in);
		while (!f1.eof()) {
			getline(f1, ms, ',');
			getline(f1, t);
			if (ms == msgv) bool1 = 1;
		}
		f1.close();
		if (bool1 == 0) {
			cout << "Ten Dang Nhap cua user khong ton tai! Moi Nhap lai: ";
			cin >> msgv;
		}
	}
	f1.close();
	f1.open("teacher.csv", ios::in);
	f2.open("tempteacher.csv", ios::out);
	while (!f1.eof()) {
		getline(f1, gv.ID_GV, ',');
		getline(f1, gv.FullName, ',');
		getline(f1, gv.BirthDay, ',');
		getline(f1, gv.phoneNumber, ',');
		getline(f1, gv.Address);
		if (gv.ID_GV == "") break;
		if (gv.ID_GV == msgv) continue;
		else f2 << gv.ID_GV << "," << gv.FullName << "," << gv.BirthDay << "," << gv.phoneNumber << "," << gv.Address << endl;
	}
	fstream fo, fi;
	string msg, mkg, tg;
	fo.open("user.csv", ios::in);
	fi.open("tuser.csv", ios::out);
	while (!fo.eof()) {
		getline(fo, msg, ',');
		getline(fo, mkg, ',');
		getline(fo, tg);
		if (msg == "") break;
		if (msg == msgv) continue;
		else fi << msg << "," << mkg << "," << tg << endl;
	}
	fo.close();
	fi.close();

	cout << "Xoa Giang Vien Thanh Cong" << endl;

	f1.close();
	f2.close();
	remove("teacher.csv");
	rename("tempteacher.csv", "teacher.csv");
	remove("user.csv");
	rename("tuser.csv", "user.csv");
	system("pause");
}

void Admin::DeleteSV() {
	ListUser("student");
	fstream f1, f2;
	sinhvien sv;
	string mssv;
	string ms, t;
	cout << "Nhap ma sinh vien ban muon xoa: ";
	cin >> mssv;
	int bool1 = 0;
	while (bool1 == 0) {
		f1.open("student.csv", ios::in);
		while (!f1.eof()) {
			getline(f1, ms, ',');
			getline(f1, t);
			if (ms == mssv) bool1 = 1;
		}
		f1.close();
		if (bool1 == 0) {
			cout << "Ten Dang Nhap cua user khong ton tai! Moi Nhap lai: ";
			cin >> mssv;
		}
	}
	f1.close();
	f1.open("teacher.csv", ios::in);
	f2.open("tempteacher.csv", ios::out);
	while (!f1.eof()) {
		getline(f1, sv.ID_sv, ',');
		getline(f1, sv.FullName_sv, ',');
		getline(f1, sv.BirthDay_sv, ',');
		getline(f1, sv.Address_sv);
		if (sv.ID_sv == "") break;
		if (sv.ID_sv == mssv) continue;
		else f2 << sv.ID_sv << "," << sv.FullName_sv<< "," << sv.Address_sv <<  "," << sv.Address_sv<< endl;
	}
	fstream fo, fi;
	string mss, mks, ts;
	fo.open("user.csv", ios::in);
	fi.open("tuser.csv", ios::app);
	while (!fo.eof()) {
		getline(fo, mss, ',');
		getline(fo, mks, ',');
		getline(fo, ts);
		if (mss == "") break;
		if (mss == mssv) continue;
		else fi << mss << "," << mks << "," << ts << endl;

	}
	fo.close();
	fi.close();
	


	cout << "Xoa Sinh Vien Thanh Cong" << endl;
	
	f1.close();
	f2.close();
	remove("teacher.csv");
	rename("tempteacher.csv", "teacher.csv");
	remove("user.csv");
	rename("tuser.csv", "user.csv");
	system("pause");
}

void Admin::ScreenAdmin() {
	//system("cls");
	cout << "\n\n\n";
	cout << "\n  \t\t         ษออออออออออออออออออออออออออป";
	cout << "\n  \t\t         บ ---- WELCOME ADMIN! ---- บ";
	cout << "\n  \t\t         ศออออออออออออออออออออออออออผ\n\n\n";

	cout << "\n \t  ษอออออออออออออออออออออออป      ษอออออออออออออออออออออออป"
		<< "\n \t  บ 1. Tim kiem user      บ      บ 2. Them user          บ"
		<< "\n \t  ศอออออออออออออออออออออออผ      ศอออออออออออออออออออออออผ"
		<< "\n \t  ษอออออออออออออออออออออออป      ษอออออออออออออออออออออออป"
		<< "\n \t  บ 3. Xoa user Sinh vien บ      บ 4. Xoa user Giang Vienบ"
		<< "\n \t  ศอออออออออออออออออออออออผ      ศอออออออออออออออออออออออผ"
		<< "\n \t  ษอออออออออออออออออออออออป      ษอออออออออออออออออออออออป"
		<< "\n \t  บ 5. Doi mat khau       บ      บ 6. Dang xuat          บ"
		<< "\n \t  ศอออออออออออออออออออออออผ      ศอออออออออออออออออออออออผ"
		<< "\n \t  ษอออออออออออออออออออออออป"
		<< "\n \t  บ 7. Thoat              บ"
		<< "\n \t  ศอออออออออออออออออออออออผ\n\n" << endl;
	/*cout << "WELCOM ADMIN! " << endl;
	cout << "1. Tim kiem user." << endl;
	cout << "2. Them user." << endl;
	cout << "3. Xoa user Sinh Vien." << endl;
	cout << "4. Xoa user Giang Vien." << endl;
	cout << "5. Doi Mat Khau." << endl;
	cout << "6. Dang Xuat." << endl;
	cout << "7. Thoat." << endl;*/
	cout << "\n\nNhap lua chon: ";
	int chon;
	cin >> chon;
	GiangVien g;
	DangNhap d;
	switch (chon)
	{
	case 1:FindUser();
		system("pause");
		ScreenAdmin();
		break;
	case 2: Add();
		ScreenAdmin();
		break;
	case 3: DeleteSV();
		ScreenAdmin();
		break;
	case 4: DeleteGV();
		ScreenAdmin();
		break;
	case 5: g.changePass();
		ScreenAdmin();
		break;
	case 6:cin.ignore();
		rm;
		d.Login();
	/*case 9:ListUser();
		ScreenAdmin();
		break;*/
		
	case 7:
		rm;
		break;
		
	default:
		cout << "Lua chon khung dung! Moi Nhap lai." << endl;
		system("pause");
		ScreenAdmin();
	}
}

Admin::~Admin() {

}
