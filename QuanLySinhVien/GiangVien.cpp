#include "GiangVien.h"
#include "DangNhap.h"

GiangVien::GiangVien() {

}

bool GiangVien::checkmh(Monhoc a) {
	/*ifstream f;
	f.open("course.csv", ios::out);
	if (f.fail())
	cout << "Failed to open this file!" << endl;
	return -1;
	string str;
	Monhoc mh;
	string temp;
	while (!f.eof) {
	getline(f, str);
	stringstream ss;
	ss<> mh.ID_MonHoc;ss >> temp;ss >> mh.Giangvien;ss >> temp;ss >> mh.Ten_MonHoc;ss >> temp;ss >> mh.slot;ss >> temp;ss >> mh.slot;
	}
	if (a.ID_MonHoc==mh.ID_MonHoc) return true;
	else return false;*/
	return 0;
}

void GiangVien::MoMonHoc() {
	string kh_ID, gv_ID, temp, IDcur, hk;
	fstream fcou;
	fstream fcur;
	fcur.open("curuser.csv", ios::in);
	getline(fcur, IDcur, ',');

	cout << "Nhap Thong Tin Mon Hoc:" << endl;
	Monhoc mh;
	cout << "Nhap ma mon hoc: ";
	cin >> mh.ID_MonHoc;
	cout << "Nhap ma Giang vien: ";
	cin >> mh.ID_Giangvien;
	while (mh.ID_Giangvien != IDcur) {
		cout << "Nhap Sai Ma! Moi nhap lai:" << endl;
		cin >> mh.ID_Giangvien;
	}
	cout << "Nhap Ten mon hoc: ";

	cin.ignore();
	getline(cin, mh.Ten_MonHoc);
	cout << "Nhap So luong Sinh vien: ";
	cin >> mh.slot;
	cout << "Nhap hoc ki muon mo: ";
	cin >> mh.hocki;

	int hocki;
	fcou.open("course.csv", ios::in);
	if (fcou.fail()) {
		cout << "Failed to open this file! " << endl;
		system("pause");
		return;
	}
	int max_cou = 0;
	while (!fcou.eof()) {
		getline(fcou, temp, ',');
		getline(fcou, gv_ID, ',');
		getline(fcou, temp, ',');
		getline(fcou, temp, ',');
		getline(fcou, temp, ',');
		getline(fcou, hk);
		hocki = atoi(hk.c_str());
		if (gv_ID == IDcur&&hocki == mh.hocki) {
			max_cou++;
		}
	}
	if (max_cou < 5) {
		fstream f;
		f.open("course.csv", ios::app);
		if (f.fail())
			cout << "Failed to open this file course.csv!" << endl;
		else {
			f << mh.ID_MonHoc << "," << mh.ID_Giangvien << "," << mh.Ten_MonHoc << "," << mh.SLSV << "," << mh.slot << "," << mh.hocki << endl;
			cout << "Mo Mon hoc thanh cong!" << endl;
			string file = mh.ID_MonHoc + "_" + mh.ID_Giangvien + "_" + hk + ".csv";
			fstream ffile;
			ffile.open(file, ios::app);
			ffile << "Id_SV,Midterm,Lab,Ass,Finalterm" << endl;
			ffile.close();
			system("pause");
		}
		f.close();
	}
	else {
		cout << "Ban chi mo duoc toi da 5 mon hoc trong hoc ki!" << endl;
		system("pause");
	}
	//
	//	else cout << "Ban chi duoc phep mo 5 mon hoc trong hoc ki nay! " << endl;
	fcou.close();
	fcur.close();
}
void GiangVien::changePass() {
	cout << "Nhap Mat Khau cu: ";
	string str1, str2, pass, temp, user, type;
	cin >> str1;
	fstream f;
	f.open("curuser.csv", ios::in);
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
	fstream f1;
	string s1, s2, s3, stam;
	f1.open("user.csv", ios::in);
	fstream ftam;
	ftam.open("usertam.csv", ios::app);
	int i = 0;
	while (!f1.eof()) {
		getline(f1, stam);
		i++;
	}
	f1.close();
	f1.open("user.csv", ios::in);

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
	system("pause");
}

void GiangVien::TongKetDiem() {
	Monhoc mh[max];
	string str;

	system("cls");

	cout << "\n \t      ษอออออออออออออออออออออออออออออออออออป"
		<< "\n \t      บ --------- Tong ket diem --------- บ"
		<< "\n \t      ศอออออออออออออออออออออออออออออออออออผ\n\n" << endl;

	//Moi mon hoc co 1 file diem rieng

	string vv, hk;
	int e = 0;
	fstream ifile;
	ifile.open("course.csv", ios::in);
	getline(ifile, vv);
	while (!ifile.eof()) {
		getline(ifile, mh[e].ID_MonHoc, ',');
		getline(ifile, mh[e].ID_Giangvien, ',');
		getline(ifile, mh[e].Ten_MonHoc, ',');
		getline(ifile, vv, ','); mh[e].SLSV = atoi(vv.c_str());
		getline(ifile, vv, ','); mh[e].slot = atoi(vv.c_str());
		getline(ifile, vv); hk = vv; mh[e].hocki = atoi(vv.c_str());
		if (mh[e].ID_MonHoc == "") break;
		mh[e].NameFile = mh[e].ID_MonHoc + "_" + mh[e].ID_Giangvien + "_" + hk + ".csv";

		e++;
	}
	ifile.close();

	int i = 0;
	string idmh, idgv; 	cout << "Nhap ID mon hoc: "; cin >> idmh;
	cout << "\nNhap ID giang vien: "; cin >> idgv;
	for (int j = 0; j < e; j++) {
		if (idmh == mh[j].ID_MonHoc && idgv == mh[j].ID_Giangvien) { //Tim thay mon hoc can tong ket
			cout << "\n\n";

			fstream f;
			f.open(mh[j].NameFile, ios::in);
			if (f.fail()) {
				cout << "Failed to open " << mh[j].NameFile << "!" << endl;
				system("pause");
				return;
			}

			double x, y, z, t;
			cout << "Nhap phan tram diem cua: " << endl;
			do {
				cout << "Diem giua ky: "; cin >> x;
				cout << "Diem lab: "; cin >> y;
				cout << "Diem ass: "; cin >> z;
				cout << "Diem cuoi ky: "; cin >> t;

				if (x + y + z + t != 1.0) {
					cout << "Nhap sai, moi ban nhap lai!";
				}
			} while (x + y + z + t != 1.0);

			int l = 0;
			getline(f, str);
			while (!f.eof()) {
				getline(f, mh[l].diem.id_sv, ','); //cout << mh[i].diem.id_sv << endl;
				getline(f, str, ','); mh[l].diem.midterm = atof(str.c_str()); //cout << mh[i].diem.midterm << endl;
				getline(f, str, ','); mh[l].diem.lab = atof(str.c_str());// cout << mh[i].diem.lab << endl;
				getline(f, str, ','); mh[l].diem.ass = atof(str.c_str());// cout << mh[i].diem.ass << endl;
				getline(f, str); mh[l].diem.finalterm = atof(str.c_str());// cout << mh[i].diem.finalterm << endl;

				mh[l].diem.Score = mh[l].diem.midterm*x + mh[l].diem.lab*y + mh[l].diem.ass*z + mh[l].diem.finalterm*t;

				l++;
			}
			f.close();

			//--------------Day vao file moi, roi doi ten thanh file cu----------------//

			fstream file;
			file.open("tamthoi.csv", ios::out);

			file << "Id_sv,Midterm,Lab,Ass,Finalterm,Score" << endl;
			for (int t = 0; t < l; t++) {
				if (mh[t].diem.id_sv == "") break;
				file << mh[t].diem.id_sv << ","
					<< mh[t].diem.midterm << ","
					<< mh[t].diem.lab << ","
					<< mh[t].diem.ass << ","
					<< mh[t].diem.finalterm << ","
					<< mh[t].diem.Score << endl;
			}

			cout << "\n\n\t--Tong ket diem thanh cong!--\t" << endl;
			int cc;
			cout << "\n\nBan co muon xem diem tong ket?" << endl
				<< "1. Co" << endl
				<< "2. Khong" << endl
				<< "\nNhap lua chon: "; cin >> cc;
			if (cc == 1) {
				cout << "ID_SV     DiemTB" << endl
					<< "-----     ------" << endl;
				for (int t = 0; t < l; t++) {
					if (mh[t].diem.id_sv == "") break;
					cout << setw(12) << left << mh[t].diem.id_sv << setw(6) << left << mh[t].diem.Score << endl;
				}
			}
			system("pause");

			file.close();

			remove(mh[j].NameFile.c_str());
			rename("tamthoi.csv", mh[j].NameFile.c_str());
			i++;	//Bien dem de xac dinh xem co tim thay ten file hay khong!
			break;
		}
	}
	if (i == 0) {
		cout << "Khong tim thay file diem nay!" << endl;
	}
}

void GiangVien::SuaDiem() {
	Monhoc mh[max];

	string vv, hk, str;
	int e = 0;
	fstream ifile;
	ifile.open("course.csv", ios::in);
	getline(ifile, vv);
	while (!ifile.eof()) {
		getline(ifile, mh[e].ID_MonHoc, ',');
		getline(ifile, mh[e].ID_Giangvien, ',');
		getline(ifile, mh[e].Ten_MonHoc, ',');
		getline(ifile, vv, ','); mh[e].SLSV = atoi(vv.c_str());
		getline(ifile, vv, ','); mh[e].slot = atoi(vv.c_str());
		getline(ifile, vv); hk = vv; mh[e].hocki = atoi(vv.c_str());
		if (mh[e].ID_MonHoc == "") break;
		mh[e].NameFile = mh[e].ID_MonHoc + "_" + mh[e].ID_Giangvien + "_" + hk + ".csv";

		e++;	//Doc so luong file diem - chinh la so luong mon hoc
	}
	ifile.close();

	int i = 0; //Bien xac dinh co thay mon hoc hay khong!
	string idmh, idgv; cout << "\nNhap ID mon hoc: "; cin >> idmh;
	cout << "\nNhap ID giang vien: "; cin >> idgv;
	for (int t = 0; t < e; t++) {//t la bien de tim vi tri mon hoc
		if (idmh == mh[t].ID_MonHoc && idgv == mh[t].ID_Giangvien) {//Tim thay mon hoc, tien hanh sua diem
			fstream f;
			f.open(mh[t].NameFile);
			if (f.fail()) {
				cout << "Failed to open " << mh[t].NameFile << endl;
				system("pause");
				return;
			}
			int l = 0;
			getline(f, str);
			while (!f.eof()) {
				getline(f, mh[l].diem.id_sv, ','); //cout << mh[i].diem.id_sv << endl;
				getline(f, str, ','); mh[l].diem.midterm = atof(str.c_str());
				getline(f, str, ','); mh[l].diem.lab = atof(str.c_str());
				getline(f, str, ','); mh[l].diem.ass = atof(str.c_str());
				getline(f, str); mh[l].diem.finalterm = atof(str.c_str());
				if (mh[t].diem.id_sv == "") break;

				l++;	//Bien xac dinh so luong sinh vien trong file diem
			}
			f.close();

			string mssv;

			int choice;
			do {
				int k = 0;  //Bien de xac dinh co tim thay sinh vien hay khong
				system("cls");

				cout << "\n \t      ษอออออออออออออออออออออออออออออออออออป"
					<< "\n \t      บ ------------ Sua diem ----------- บ"
					<< "\n \t      ศอออออออออออออออออออออออออออออออออออผ\n\n" << endl;
				cout << "\nNhap mssv: "; cin >> mssv;
				for (int j = 0; j < l; j++) {
					if (mh[j].diem.id_sv == mssv) {
						//Tien hanh sua doi
						system("cls");
						cout << "\n \t\t  ษออออออออออออออออออออออออออออออออออออออออออออออป"
							<< "\n \t\t  บ ---------- Danh sach cac loai diem --------- บ"
							<< "\n \t\t  ศออออออออออออออออออออออออออออออออออออออออออออออผ\n\n" << endl;
						cout << "\n\n \t\t  ษอออออออออออออออออออป "
							<< "\n \t\t  บ 1. Diem giua ky   บ"
							<< "\n \t\t  ศอออออออออออออออออออผ"
							<< "\n \t\t  ษอออออออออออออออออออป"
							<< "\n \t\t  บ 2. Dem lab        บ"
							<< "\n \t\t  ศอออออออออออออออออออผ"
							<< "\n \t\t  ษอออออออออออออออออออป"
							<< "\n \t\t  บ 3. Diem ass       บ"
							<< "\n \t\t  ศอออออออออออออออออออผ"
							<< "\n \t\t  ษอออออออออออออออออออป"
							<< "\n \t\t  บ 4. Dem cuoi ky    บ"
							<< "\n \t\t  ศอออออออออออออออออออผ\n\n" << endl;
						cout << "\nMoi ban nhap lua chon: "; cin >> choice;

						double diemBD, diemSua;
						int choice1;
						switch (choice) {
						case 1: {
							system("cls");

							cout << "\n \t      ษอออออออออออออออออออออออออออออออออออป"
								<< "\n \t      บ -------- Doi diem giua ky ------- บ"
								<< "\n \t      ศอออออออออออออออออออออออออออออออออออผ\n\n" << endl;

							int choice1;
							do {
								system("cls");
								cout << " \t      ษอออออออออออออออออออออออออออออออออออป"
									<< "\n \t      บ -------- Doi diem giua ky ------- บ"
									<< "\n \t      ศอออออออออออออออออออออออออออออออออออผ\n\n" << endl;
								cout << "\n\n\nNhap diem giua ky hien tai: "; cin >> diemBD;
								if (diemBD == mh[j].diem.midterm) {
									//Dung
									do {
										cout << "\nNhap diem muon sua: "; cin >> diemSua; ////////////
										if (diemSua < 0 || diemSua > 10) {
											cout << " \t      ษออออออออออออออออออออออออออออออออออออออออออออออป"
												<< "\n \t      บ -------- Nhap sai, moi ban nhap lai! ------- บ"
												<< "\n \t      ศออออออออออออออออออออออออออออออออออออออออออออออผ\n\n" << endl;
										}
									} while (diemSua < 0 && diemSua > 10);

									fstream file;
									file.open("tamthoi.csv", ios::out);

									file << "ID_sv,Midterm,Lab,Ass,Finalterm" << endl;
									for (int m = 0; m < l; m++) {
										if (mh[m].diem.id_sv == "") break;
										if (m == j) {
											mh[m].diem.midterm = diemSua;
										}
										file << mh[m].diem.id_sv << "," << mh[m].diem.midterm << "," << mh[m].diem.lab << "," << mh[m].diem.ass << "," << mh[m].diem.finalterm << endl;
									}
									file.close();

									remove(mh[t].NameFile.c_str());
									rename("tamthoi.csv", mh[t].NameFile.c_str());

									cout << "\nThay doi thanh cong!" << endl;
									system("pause"); break;
								}
								else {
									system("cls");
									cout << " \t      ษอออออออออออออออออออออออออออออออออออป"
										<< "\n \t      บ -------- Doi diem giua ky ------- บ"
										<< "\n \t      ศอออออออออออออออออออออออออออออออออออผ\n\n\n\n" << endl;
									cout << "\n \t\t  ษออออออออออออออออออออออป"
										<< "\n \t\t  บ ----- Nhap sai! ---- บ"
										<< "\n \t\t  ศออออออออออออออออออออออผ\n" << endl;

									cout << "\n \t  ษอออออออออออออออป      ษอออออออออออออออป"
										<< "\n \t  บ 1. Nhap lai   บ      บ 0. Thoat      บ"
										<< "\n \t  ศอออออออออออออออผ      ศอออออออออออออออผ" << endl;

									cout << "\n\nNhap lua chon: ";
									cin >> choice1;
								}
							} while (choice1 != 0);

							break;
						}
						case 2: {
							system("cls");

							cout << "\n \t      ษอออออออออออออออออออออออออออออออออออป"
								<< "\n \t      บ ---------- Doi diem lab --------- บ"
								<< "\n \t      ศอออออออออออออออออออออออออออออออออออผ\n\n" << endl;

							do {
								cout << "Nhap diem lab hien tai: "; cin >> diemBD;
								if (diemBD == mh[j].diem.lab) {
									//Tien hanh sua
									cout << "Nhap diem muon sua: "; cin >> diemSua;

									fstream file;
									file.open("tamthoi.csv", ios::out);

									file << "ID_sv,Midterm,Lab,Ass,Finalterm" << endl;
									for (int m = 0; m < l; m++) {
										if (mh[m].diem.id_sv == "") break;
										if (m == j) {
											mh[m].diem.lab = diemSua;
										}
										file << mh[m].diem.id_sv << "," << mh[m].diem.midterm << "," << mh[m].diem.lab << "," << mh[m].diem.ass << "," << mh[m].diem.finalterm << endl;
									}
									file.close();

									remove(mh[t].NameFile.c_str());
									rename("tamthoi.csv", mh[t].NameFile.c_str());

									cout << "\nThay doi thanh cong!" << endl;
									system("pause"); break;
								}
								else {
									system("cls");
									cout << "\n \t\t  ษออออออออออออออออออออออออออป"
										<< "\n \t\t  บ ------- Nhap sai! ------ บ"
										<< "\n \t\t  ศออออออออออออออออออออออออออผ\n\n\n" << endl;

									cout << "\n \t  ษอออออออออออออออป      ษอออออออออออออออป"
										<< "\n \t  บ 1. Nhap lai   บ      บ 0. Thoat      บ"
										<< "\n \t  ศอออออออออออออออผ      ศอออออออออออออออผ" << endl;

									cout << "\n\nNhap lua chon: ";
									cin >> choice1;
								}
							} while (choice1 != 0);
							break;
						}
						case 3: {
							system("cls");

							cout << "\n \t      ษอออออออออออออออออออออออออออออออออออป"
								<< "\n \t      บ ---------- Doi diem ass --------- บ"
								<< "\n \t      ศอออออออออออออออออออออออออออออออออออผ\n\n" << endl;

							do {
								cout << "Nhap diem ass hien tai: "; cin >> diemBD;
								if (diemBD == mh[j].diem.ass) {
									//Tien hanh sua doi
									cout << "Nhap diem muon sua: "; cin >> diemSua;

									fstream file;
									file.open("tamthoi.csv", ios::out);

									file << "ID_sv,Midterm,Lab,Ass,Finalterm" << endl;
									for (int m = 0; m < l; m++) {
										if (mh[m].diem.id_sv == "") break;
										if (m == j) {
											mh[m].diem.ass = diemSua;
										}
										file << mh[m].diem.id_sv << "," << mh[m].diem.midterm << "," << mh[m].diem.lab << "," << mh[m].diem.ass << "," << mh[m].diem.finalterm << endl;
									}
									file.close();

									remove(mh[t].NameFile.c_str());
									rename("tamthoi.csv", mh[t].NameFile.c_str());

									cout << "\nThay doi thanh cong!" << endl;
									system("pause"); break;
								}
								else {
									system("cls");
									cout << "\n \t\t  ษออออออออออออออออออออออออออป"
										<< "\n \t\t  บ ------- Nhap sai! ------ บ"
										<< "\n \t\t  ศออออออออออออออออออออออออออผ\n\n\n" << endl;

									cout << "\n \t  ษอออออออออออออออป      ษอออออออออออออออป"
										<< "\n \t  บ 1. Nhap lai   บ      บ 0. Thoat      บ"
										<< "\n \t  ศอออออออออออออออผ      ศอออออออออออออออผ" << endl;

									cout << "\n\nNhap lua chon: ";
									cin >> choice1;
								}
							} while (choice1 != 0);
							break;
						}
						case 4: {
							system("cls");

							cout << "\n \t      ษอออออออออออออออออออออออออออออออออออป"
								<< "\n \t      บ -------- Doi diem cuoi ky ------- บ"
								<< "\n \t      ศอออออออออออออออออออออออออออออออออออผ\n\n" << endl;

							do {
								cout << "Nhap diem cuoi ky hien tai: "; cin >> diemBD;
								if (diemBD == mh[j].diem.finalterm) {
									//Tien hanh sua
									cout << "Nhap diem muon sua: "; cin >> diemSua;

									fstream file;
									file.open("tamthoi.csv", ios::out);

									file << "ID_sv,Midterm,Lab,Ass,Finalterm" << endl;
									for (int m = 0; m < l; m++) {
										if (mh[m].diem.id_sv == "") break;
										if (m == j) {
											mh[m].diem.finalterm = diemSua;
										}
										file << mh[m].diem.id_sv << "," << mh[m].diem.midterm << "," << mh[m].diem.lab << "," << mh[m].diem.ass << "," << mh[m].diem.finalterm << endl;
									}
									file.close();

									remove(mh[t].NameFile.c_str());
									rename("tamthoi.csv", mh[t].NameFile.c_str());

									cout << "\nThay doi thanh cong!" << endl;
									system("pause"); break;
								}
								else {
									system("cls");
									cout << "\n \t\t  ษออออออออออออออออออออออออออป"
										<< "\n \t\t  บ ------- Nhap sai! ------ บ"
										<< "\n \t\t  ศออออออออออออออออออออออออออผ\n\n\n" << endl;

									cout << "\n \t  ษอออออออออออออออป      ษอออออออออออออออป"
										<< "\n \t  บ 1. Nhap lai   บ      บ 0. Thoat      บ"
										<< "\n \t  ศอออออออออออออออผ      ศอออออออออออออออผ" << endl;

									cout << "\n\nNhap lua chon: ";
									cin >> choice1;
								}
							} while (choice1 != 0);
							break;
						}
						}
						system("cls");
						cout << " \t  ษอออออออออออออออออออออออออออออออออออออออออออออออออออป"
							<< "\n \t  บ --- Ban con muon tiep tuc chuc nang sua diem? --- บ"
							<< "\n \t  ศอออออออออออออออออออออออออออออออออออออออออออออออออออผ\n\n\n" << endl;
						cout << "\n \t\t  ษอออออออออออออออป      ษอออออออออออออออป"
							<< "\n \t\t  บ 1. Tiep tuc   บ      บ 0. Thoat      บ"
							<< "\n \t\t  ศอออออออออออออออผ      ศอออออออออออออออผ" << endl;

						cout << "\n\nNhap lua chon: ";
						cin >> choice;
						k++;
					}
				}
				if (k == 0) {
					system("cls");
					cout << "\n\n\n \t\t    ษออออออออออออออออออออออออออออออออออป"
						<< "\n \t\t    บ --- Khong tim thay sinh vien --- บ"
						<< "\n \t\t    ศออออออออออออออออออออออออออออออออออผ\n\n\n\n" << endl;
					cout << "\n\n \t\t  ษอออออออออออออออป      ษอออออออออออออออป"
						<< "\n \t\t  บ 1. Nhap lai   บ      บ 0. Thoat      บ"
						<< "\n \t\t  ศอออออออออออออออผ      ศอออออออออออออออผ" << endl;
					cout << "\n\nNhap lua chon: ";
					cin >> choice;
				}
			} while (choice != 0);
			i++;
			break;
		}
	}
	if (i == 0) {
		cout << "Khong tim thay mon hoc!" << endl;
	}
	system("pause");
}

void GiangVien::ScreenGV() {
	system("cls");
	//Giao dien giang vien
	cout << "\n\n\n";
	cout << "\n  \t\t    ษออออออออออออออออออออออออออป";
	cout << "\n  \t\t    บ --- WELCOME TEACHER! --- บ";
	cout << "\n  \t\t    ศออออออออออออออออออออออออออผ\n\n\n";

	cout << "\n \t  ษอออออออออออออออออออป      ษอออออออออออออออออออป"
		<< "\n \t  บ 1. Mo mon hoc     บ      บ 2. Tong ket diem  บ"
		<< "\n \t  ศอออออออออออออออออออผ      ศอออออออออออออออออออผ"
		<< "\n \t  ษอออออออออออออออออออป      ษอออออออออออออออออออป"
		<< "\n \t  บ 3. Sua diem       บ      บ 4. Doi mat khau   บ"
		<< "\n \t  ศอออออออออออออออออออผ      ศอออออออออออออออออออผ"
		<< "\n \t  ษอออออออออออออออออออป      ษอออออออออออออออออออป"
		<< "\n \t  บ 5. Dang xuat      บ      บ 6. Thoat          บ"
		<< "\n \t  ศอออออออออออออออออออผ      ศอออออออออออออออออออผ\n\n" << endl;
	int chon;
	DangNhap d;
	cout << "Nhap Lua chon: ";
	cin >> chon;
	switch (chon)
	{
	case 1:
		MoMonHoc();
		ScreenGV();
		break;
	case 2:
		TongKetDiem();
		ScreenGV();
		break;
	case 3:SuaDiem();
		ScreenGV();
		break;
	case 4:changePass();
		ScreenGV();
		break;
	case 5:cin.ignore();
		rm;
		d.Login();
	case 6:	rm;
		break;

	default:
		cout << "Lua chon khong dung!" << endl;
		system("pause");
		ScreenGV();
	}
}
GiangVien::~GiangVien() {

}