CODE CHAY TREN VISUAL STUDIO. 
HOAC CO THE DUNG FILE .EXE DE TEST
--------------------DANG NHAP------------------------
-Khi dang nhap vao he thong, he thong se tu dong hien ra man hinh cho tung loai user(admin, teacher, student).
--------------------ADMIN----------------------------
-Man hinh Admin gom 7 chuc nang:
+ Tim kiem user: Tim kiem user theo id.
  * Neu nhap dung id se xuat ra man hinh: Ten dang nhap, mat khau, loai user va thong tin ca nhan
+ Them user: Them teacher hoac student  
  * Yeu cau nhap loai user (teacher or student)
  * Sau do Nhap ma sinh vien/giang vien va thong tin can thiet
+ Xoa user giang vien:(bao gom chuc nang tim kiem giang vien theo ten)
  * Nhap ten giang vien muon xoa sau do se xuat ra man hinh nhung giang vien co ten tuong tu( Yeu cau phai nhap chu IN HOA)
  * Neu khong tim thay se duoc yeu cau nhap lai
  * Neu tim thay se xuat ra thong tin cua User giang vien(bao gom: id, ten,...)
  * Nhap ID cua giang vien muon xoa
+ Xoa user sinh vien: Tuong tu xoa user giang vien
+ Doi mat khau 
  * Nhap mat khau cu, neu nhap sai se yeu cau nhap lai
  * Nhap mat khau dung, se duoc yeu cau nhap mat khau moi
+ Dang xuat: Dan den man hinh dang nhap
+ Thoat: Thoat khoi chuong trinh
--------------------GIANG VIEN------------------------
-Man hinh gom 6 chuc nang:
+ Mo mon hoc: Nhap thong tin mon hoc muon mo. khi mo mon hoc thanh cong se tao ra mot file luu diem cua sinh vien.
+ Doi mat khau: 
  * Nhap mat khau cu, neu nhap sai se yeu cau nhap lai
  * Nhap mat khau dung, se duoc yeu cau nhap mat khau moi
+ Tong ket diem: 
  * Chuong trinh se doc file diem va tinh diem tong ket cua tung mon.
  * Moi giang vien day 1 mon hoc se co 1 file diem rieng:
	. Yeu cau nhap ID mon hoc va ID giang vien.
	. Neu dung thi moi thuc hien duoc chuc nang nay.
  * Tuy theo ty le giua cac diem thanh phan ma moi mon co diem khac nhau (ty le do giang vien nhap).
  * Sau khi tong ket diem:
	. Cap nhat them cot diem nay vao trong file diem.
	. Giang vien co the lua chon in ra diem tong ket hoac la khong.
+ Sua diem: 
  * Thuc hien sua diem tren tung file diem.
  * Yeu cau nhap ID mon hoc va ID giang vien, dung thi moi thuc hien tiep.
  * Doc file diem da tim duoc, thuc hien sua diem:
  	. Tim diem theo ma so sinh vien, neu sai co the nhap lai hoac thoat ve man hinh chinh.
  	. Co the tuy chon thay doi diem cac diem thanh phan:
	   - Yeu cau nhap diem ban dau, neu sai co the nhap lai hoac thoat.
	   - Nhap diem muon sua va cap nhat trong file diem cua mon hoc.
	   - Co the tiep tuc hoac thoat ve man hinh sua diem.
--------------------SinhVien----------------------------
-Man hình SinhVien gom 6 chuc nang:
+ Dang ki mon hoc: Dang ki theo id mon hoc va id giao vien
* Nhap id mon hoc
* Nhap id giao vien
* Neu sai bat nhap lai , neu dung xuat ra dang ki thanh cong
+ Huy  mon hoc: Huy theo id mon hoc va id giao vien
* Nhap id mon hoc
* Nhap id giao vien
* Neu sai bat nhap lai , neu dung xuat ra huy mon hoc thanh cong
+ Doi mat khau
* Nhap mat khau cu ,neu sai bat nhap lai
* Neu dung xuat ra doi mat khau thanh cong
+ Xem thong tin ca nhan:
* Xuat ra ho ten,ngay sinh ,que quan sinh vien
* Xuat ra cac mon hoc sinh vien da dang ki
+ Dang xuat
* Thoat tai khoan nay de login mot tai khoan khac
+ Thoat
* Ket thuc chuong trinh