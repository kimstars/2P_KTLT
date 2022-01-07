#include"SinhVien.cpp"
#include<vector>


vector<SinhVien> themMoiHoSo(vector<SinhVien>, int &);
vector<SinhVien> suaHoSo(vector<SinhVien>, int );
vector<SinhVien> xoaHoSo(vector<SinhVien>, int &);

//==================================================

//ham them moi ho so (done)
vector<SinhVien> themMoiHoSo(vector<SinhVien> ds, int &n){
    clrscr(8);
    gotoXY(35,10); TextColor(6); cout << "NHAP SO LUONG SINH VIEN CAN THEM:	 "; 
	int k; cin >> k;
	if(k==0){
		return ds;
	}
    gotoXY(35,12); TextColor(6); cout << "NHAP DANH SACH SINH VIEN: ";
    SinhVien sv;
	for(int i=0;i<k;i++){
		gotoXY(32,14+6*i); TextColor(7); cout << i+1 << "> "<<endl;
		sv.Input(35,14+6*i+1); ds.push_back(sv);
	}
	n = n + k;
	clrscr(8);
	gotoXY(40,10); TextColor(2); cout << "Ban da them sinh vien thanh cong "<<endl;
    return ds;
	
}



// ham sua ho so sinh vien (done)
vector<SinhVien> suaHoSo(vector<SinhVien> ds, int n){
	clrscr(8);
	gotoXY(35, 10); TextColor(6); cout << "NHAP MA SINH VIEN CAN SUA : ";
	string msv; cin >> msv;
	int i;
	//ghi lai so thu tu cua sinh vien i trung ma sinh vien can sua
	for(i = 0; i < n; i++){
		if(ds[i].maSV == msv){
			break;
		}
	}
		
	//neu khong tim thay thi i==n
	if(i == n){
		clrscr(8);
		gotoXY(35,10); TextColor(4); cout << "Khong tim thay sinh vien can xoa!";
	}else{
		//neu tim thay thi bat dau sua thong tin
		gotoXY(35,12); TextColor(6); cout << "NHAP THONG TIN SINH VIEN";
		TextColor(7); ds[i].Input(35,14); //sua lai thong tin sv i
		clrscr(8);
		gotoXY(40,9); TextColor(2); cout << "Ban da sua sinh vien thanh cong! " <<endl;
	} 
	return ds;
}


// ham xoa ho so mot sinh vien (done)
vector<SinhVien> xoaHoSo(vector<SinhVien> ds, int &n){
	clrscr(8);
	gotoXY(35, 10); TextColor(6); cout << "NHAP VAO MA SINH VIEN CAN XOA : ";
	string msv; cin >> msv;
	int i;
	for(i = 0; i < n; i++){
		if(ds[i].maSV == msv){
			break;
		}	
	}
	if(i == n){
		clrscr(8);
		gotoXY(40,9); TextColor(4); cout << "Khong tim thay sinh vien can xoa!" << endl;
	}else{
		ds.erase( ds.begin() + i ); //xoa SV tai vi tri i
		n--;
		clrscr(8);
		gotoXY(40, 10); TextColor(2); cout << "Ban da xoa sinh vien thanh cong! " << endl;
	}
	return ds;
}