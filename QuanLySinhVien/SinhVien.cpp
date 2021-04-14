#include "SinhVien.h"
#include<string>
#include<iomanip>
#include<locale>

using namespace std;

#define max 1000

SinhVien::SinhVien() {
}

void SinhVien::changePass() {
	cout << "Nhap Mat Khau cu: ";
	string str1, str2, pass, temp, user, type;
	cin >> str1;
	ifstream f;
	f.open("curuser.csv", ios::out);
	if (f.fail()) {
		cout << "Failed to open this file! " << endl;
		system("pause");
		return;
	}
	else {
		getline(f, user, ',');
		getline(f, pass, ',');
		getline(f, type);
	}
	while (pass != str1) {
		cout << "Mat khau khong dung, Moi nhap lai mat khau: ";
		cin >> str1;
	}
	if (pass == str1) {
		cout << "Nhap Mat khau moi: ";
		cin >> str1;
		cout << "Doi Mat Khau Thanh Cong ! " << endl;
	}
	f.close();
	ifstream f1;
	string s1, s2, s3, stam;

	f1.open("user.csv", ios::out);
	fstream ftam;
	ftam.open("usertam.csv", ios::app);
	int i = 0;
	while (!f1.eof()) {
		getline(f1, stam);
		i++;
	}
	f1.close();
	f1.open("user.csv", ios::out);

	int k = 0;
	while (!f1.eof()) {
		getline(f1, s1, ',');
		getline(f1, s2, ',');
		getline(f1, s3);
		if (s1 == "") break;
		if (k != i - 1) {
			if (s1 == user) {
				ftam << user << "," << str1 << "," << type << endl;
				k++;
			}
			else {
				ftam << s1 << "," << s2 << "," << s3 << endl;
				k++;
			}
		}
		else {
			if (s1 == user) {
				ftam << user << "," << str1 << "," << type;
				k++;
			}
			else {
				ftam << s1 << "," << s2 << "," << s3;
				k++;
			}
		}
	}

	f1.close();
	ftam.close();
	remove("user.csv");
	rename("usertam.csv", "user.csv");
}

void SinhVien::ListObject() {
	fstream fobj;
	int bool1 = 0;
	monhoc mh;
	string a;
	cin.ignore();
	do {
		fobj.open("course.csv", ios::in);
		cout << "Nhap ten mon hoc muon tim kiem: ";
		getline(cin, a);
		cout << setw(12) << left << "ID mon hoc" << setw(12) << left << "ID giao vien" << setw(30) << left << "Ten mon hoc" << setw(10) << left << "So luong" << setw(8) << left << "Slot" << setw(8) << left << "Hoc ky" << endl;
		cout << "---------------------------------------------------------------------------------------------------------" << endl;
		while (!fobj.eof()) {
			getline(fobj, mh.ID, ',');
			getline(fobj, mh.IDGV, ',');
			getline(fobj, mh.NameOBJ, ',');
			getline(fobj, mh.numberS, ',');
			getline(fobj, mh.SLOT, ',');
			getline(fobj, mh.HocKy);
			size_t found = mh.NameOBJ.find(a);
			if (mh.ID == "") break;
			if (found != string::npos) {
				bool1 = 1;
				cout << setw(12) << left << mh.ID << left << setw(12) << mh.IDGV << left << setw(30) << mh.NameOBJ << left << setw(10) << mh.numberS << left << setw(8) << mh.SLOT << left << setw(8) << mh.HocKy << endl;
			}
		}
		if (bool1 == 0)
			cout << "RECORD NOT FOUND!" << endl;
		fobj.close();
	} while (bool1 == 0);
}
void SinhVien::CourseRegistration() {
	ListObject();
	string IdMonHoc, IdGiaoVien, line;
	string Course_ID, Teacher_ID, Name, n_student, slot,hk;
	int i = 0, k = 0;
	int count = 0;
	ifstream fileLogin;
	fileLogin.open("curuser.csv");
	string TenDangNhap;
	cin.ignore();
	getline(fileLogin, TenDangNhap, ',');

	
	dm:
		cout << "moi ban nhap id mon hoc: ";
		getline(cin, IdMonHoc);
		cout << "moi ban nhap id giao vien: ";
		getline(cin, IdGiaoVien);
		
		fstream openF;
		openF.open("course.csv", ios::in);
		while (getline(openF, line))
		{
			i++;
		}
		openF.close();
		
		fstream a;
		a.open("course.csv", ios::in);
		while (!a.eof())
		{
			getline(a, Course_ID, ',');
			getline(a, Teacher_ID, ',');
			getline(a, Name, ',');
			getline(a, n_student, ',');
			getline(a, slot,',');
			getline(a, hk);
			if (IdMonHoc != Course_ID||IdGiaoVien != Teacher_ID) {
				count++;
			}
		}
		//cout << i << "  " << count << endl;
		//system("pause");
		a.close();
		if (count-1 == i) {
			cout << "ban da nhap sai ,moi nhap lai" << endl;
			i = 0;
			count = 0;
			goto dm;
		}
	
///nhập sai nhập lại

	fstream f;
	f.open("course.csv", ios::in);
	fstream ftam;
	ftam.open("coursetam.csv", ios::app);
	while (!f.eof())
	{
		getline(f, Course_ID, ',');
		getline(f, Teacher_ID, ',');
		getline(f, Name, ',');
		getline(f, n_student, ',');
		getline(f, slot,',');
		getline(f, hk);
		if (IdMonHoc == Course_ID&&IdGiaoVien == Teacher_ID) {
			int ConvertN_student = stoi(n_student);
			int ConvertSlot = stoi(slot);
			if (ConvertN_student < ConvertSlot) ConvertN_student += 1;
			if (k != i - 1 && k<i) {
				ftam << IdMonHoc << "," << IdGiaoVien << "," << Name << "," << ConvertN_student << "," << slot<<","<<hk << endl;
				k++;
				
			}
			else
			{
				if (k < i) {
					ftam << IdMonHoc << "," << IdGiaoVien << "," << Name << "," << ConvertN_student << "," << slot << "," << hk<<endl;
					k++;
				}
			}
			string file = IdMonHoc + "_" + IdGiaoVien + "_" + hk + ".csv";
			fstream ffile;
			ffile.open(file, ios::app);
			ffile << TenDangNhap << ",";
			ffile.close();
			cout << "dang ki thanh cong!!" << endl;
			system("pause");
			fstream fObj;
			fObj.open("object.csv", ios::app);
		
			fObj << IdMonHoc << "," << TenDangNhap << "," << Teacher_ID << "," << "-1" << "," << hk << endl;
			fObj.close();
			fileLogin.close();
		}
		else
		{
			if (k != i - 1 && k<i) {
				ftam << Course_ID << "," << Teacher_ID << "," << Name << "," << n_student << "," << slot << "," << hk << endl;
				k++;

			}
			else
			{
				if (k < i) {
					ftam << Course_ID << "," << Teacher_ID << "," << Name << "," << n_student << "," << slot << "," << hk<<endl;
					k++;
				}
			}
		}
	}
	f.close();
	ftam.close();
	remove("course.csv");
	rename("coursetam.csv", "course.csv");
}


void SinhVien::viewPersonalInformation() {
	string idhs, hoten, ngaysinh, quequan;
	string h;
	ifstream a, b;
	a.open("curuser.csv");
	getline(a, h, ',');
	a.close();
	b.open("student.csv");
	while (!b.eof())
	{
		getline(b, idhs, ',');
		getline(b, hoten, ',');
		getline(b, ngaysinh, ',');
		getline(b, quequan);
		if (idhs == h) {
			cout << setw(12) << left << "ID SV" << setw(20) << left << "Ho Ten" << setw(15) << left << "Ngay Sinh" << setw(30) << left << "Que Quan" << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			cout << setw(12) << left << idhs << setw(20) << left << hoten << setw(15) << left << ngaysinh << setw(30) << left << quequan << endl;
		}
	}
	
	b.close();
	////////////////////////
	ifstream ifS;
	ifS.open("object.csv");
	ifstream ifU;
	ifU.open("curuser.csv");
	string id;
	getline(ifU, id, ',');
	string Course_id, Student_id, Teacher_id, Score, semeter_id;
	string *bienTam1, *bienTam2;
	bienTam1 = new string[10];
	bienTam2 = new string[10];
	int dem1 = 0;
	while (!ifS.eof())
	{
		getline(ifS, Course_id, ',');
		getline(ifS, Student_id, ',');
		getline(ifS, Teacher_id, ',');
		getline(ifS, Score, ',');
		getline(ifS, semeter_id);
		if (Student_id == id) {
			bienTam1[dem1] = Course_id;
			bienTam2[dem1] = Teacher_id;
			dem1++;
		}
	}
	string Course_ID, Teacher_ID, Name, n_student, slot;
	cout << "cac mon ban da dang ki: " << endl;
	int dem = 0;
	ifstream ifC;
	ifC.open("course.csv");
	while (!ifC.eof())
	{
		getline(ifC, Course_ID, ',');
		getline(ifC, Teacher_ID, ',');
		getline(ifC, Name, ',');
		getline(ifC, n_student, ',');
		getline(ifC, slot);
		for (int i = 0; i < 8; i++) {
			if (bienTam1[i] == Course_ID&&bienTam2[i] == Teacher_ID) {
				cout << Name << endl;
				dem++;
			}
		}
	}
	if (dem == 0) {
		cout << "ban chua dang ki mon nao" << endl;
	}
	ifS.close();
	ifU.close();
	ifC.close();
	system("pause");
}

void SinhVien::DropCouse() {
	SinhVien sv;
	fstream f;
	fstream ftam;
	bool b = false;
	string idMonHoc, idGiaoVien;
	string idHocSinh;
	ifstream fCuruser;
	cin.ignore();
	lai:
	
	cout << "moi nhap id mon hoc: ";
	
	getline(cin, idMonHoc);
	//cin.ignore(100, '\n');
	cout << "moi nhap id giao vien: ";
	getline(cin, idGiaoVien);
	//cout << idMonHoc << idGiaoVien << endl;
	
	f.open("object.csv", ios::in);

	ftam.open("objTemp.csv", ios::app);
	
	fCuruser.open("curuser.csv", ios::in);
	getline(fCuruser, idHocSinh, ',');
	fCuruser.close();
	string Course_id, Teacher_id, Score, semeter_id;
	while (!f.eof())
	{

		getline(f, Course_id, ',');
		getline(f, sv.ID_sv, ',');
		getline(f, Teacher_id, ',');
		getline(f, Score, ',');
		getline(f, semeter_id);
		if (Course_id == "") break;
		if (Course_id == idMonHoc && idHocSinh == sv.ID_sv && Teacher_id == idGiaoVien) {
			b = true;
			continue;
		}
		
		ftam << Course_id << "," << sv.ID_sv << "," << Teacher_id << "," << Score << "," << semeter_id << endl;
	}
	f.close();
	ftam.close();
	
	remove("object.csv");
	rename("objTemp.csv", "object.csv");
	if(b==true)
	cout << "xoa mon hoc thanh cong" << endl;
	else
	{
		cout << "ban da nhap sai hoac mon hoc ban chua dang ki ,moi nhap lai!" << endl;
		goto lai;
	}
	system("pause");

}

void SinhVien::ScreenSV() {
	//system("cls");
	//Giao dien sinh vien
	cout << "\n\n\n";
	cout << "\n  \t\t      ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»";
	cout << "\n  \t\t      º --- WELCOME STUDENT! --- º";
	cout << "\n  \t\t      ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼\n\n\n";

	cout << "\n \t  ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»      ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"
		<< "\n \t  º 1. Dang ky mon hoc       º      º 2. Huy mon hoc           º"
		<< "\n \t  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼      ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼"
		<< "\n \t  ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»      ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"
		<< "\n \t  º 3. Doi mat khau          º      º 4. Dang xuat             º"
		<< "\n \t  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼      ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼"
		<< "\n \t  ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»      ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»"
		<< "\n \t  º 5. Xem thong tin ca nhan º      º 6. Thoat                 º"
		<< "\n \t  ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼      ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼\n\n" << endl;

	int chon;
	DangNhap d;
	cout << "Nhap Lua chon: ";
	//cin.ignore();
	cin >> chon;
	switch (chon)
	{
	case 1:
		CourseRegistration();
		ScreenSV();
		break;
	case 2:
		DropCouse();
		ScreenSV();
		break;
	case 3:changePass();
		ScreenSV();
		break;
	case 4:cin.ignore();
		rm;
		d.Login();
	case 5: viewPersonalInformation();
		ScreenSV();
		break;
	case 6:	rm;
		break;

	default:
		cout << "Lua chon khong dung!" << endl;
		system("pause");
		cin.ignore();
		ScreenSV();
	}
}

SinhVien::~SinhVien() {

}
