#pragma once
#include "GiangVien.h"
#include "DangNhap.h"
#include "SinhVien.h"
#include "User.h"
#include<iomanip>
class Admin
{
public:
	Admin();

	
	void Add();
	void DeleteGV();
	void DeleteSV();
	void FindUser();
	void ScreenAdmin();
	void ListUser(string in);

	~Admin();
};

