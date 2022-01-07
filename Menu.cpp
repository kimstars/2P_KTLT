#include"File.cpp"
#include"CapNhatHoSo.cpp"
#include"SapXep.cpp"
#include"TimKiem.cpp"
#include"ThongKe.cpp"


//======================================================================

string ds_Menu[] = { "Cap nhat ho so sinh vien. ",
				"In danh sach sinh vien. ",
				"Sap xep du lieu sinh vien. ",
				"Tim kiem sinh vien theo yeu cau. ",
				"Thong ke sinh vien. ",
				"Thoat." };
string ds_CapNhat[] = { "Them moi sinh vien.",
				"Sua doi thong tin sinh vien.",
				"Xoa sinh vien.",
				"Man hinh chinh." };
string ds_SapXep[] = { "Sap xep noi bot." ,
				"Sap xep chen." ,
				"Sap xep chon." ,
				"Sap xep nhanh." };
string ds_TimKiem[] = { "Tim kiem tuan tu." ,
				"Tim kiem nhi phan." ,
				"Man hinh chinh." };
string ds_Khoa[] = { "Theo ma lop." ,
				"Theo ma sinh vien." ,
				"Theo ten sinh vien." ,
				"Theo ngay sinh." ,
				"Theo diem trung binh." ,
				"Quay lai." };
string ds_ThongKe[]={"Thong ke theo lop.",
				"Thong ke theo ket qua hoc tap.",
				"Man hinh chinh."};
string ds_chon[]={"Co.","Khong."};

//=======================================================================


// bat su kien ban phim
KEY_PRESS key(int);

//menu chinh
void mainMenu();
//menu chung
int Menu(string, int);

//ham bao tri
void baotriHeThong(string );

//cap nhap ho so
void capNhatHoSo();
vector<SinhVien> themMoiHoSo(vector<SinhVien>, int &);
vector<SinhVien> suaHoSo(vector<SinhVien>, int );
vector<SinhVien> xoaHoSo(vector<SinhVien>, int &);

//in
void inDanhSach(vector<SinhVien>,int);

//sap xep
void sapXep();
void chonSapXep(int, int); // goi ham sao xep va khoa sap xep da chon
vector<SinhVien> sapXepNoiBot(vector<SinhVien>, int, int);
vector<SinhVien> sapXepChen(vector<SinhVien>, int , int );
vector<SinhVien> sapXepChon(vector<SinhVien>, int , int );
vector<SinhVien> sapXepNhanh(vector<SinhVien>,int, int , int );


//timkiem
void timKiem();
void timKiemNhiPhan();
void timKiemTuanTu();
void timKiemTT(vector<SinhVien>, int, int);
void timKiemNP(vector<SinhVien>, int,int);

//thong ke
void thongKe();
void thongKeTheoLop(vector<SinhVien> ds, int n);
void thongKeTheoKetQuaHocTap(vector<SinhVien> ds, int n);

//thoat
void thoat();

// vao ra file
void loading();
void IMAGE();
void WriteToFile(vector<SinhVien>, int);
vector<SinhVien> readFile(int&);


//=======================================================================

int n;
vector<SinhVien> ds = readFile(n);

//=======================================================================


// ham tao ra mot MENU lua chon ( done)
int Menu(string ds[], int n, int x)
{
	clrscr(x);
	int tt = 0; // bien chi ra dang o thao tac nao
	int *mau = new int[n];
	for (int i = 0; i < n; i++)
	{
		mau[i] = 7;
	}
	mau[tt] = 3; // hien dang o thao tac thu nhat
	int i;
	for ( i = 0; i < n; i++)
	{	
			gotoXY(35,12+2*i); TextColor(mau[i]); // ham doi mau chu cho chu chuan bi in ra man hinh
			cout << i + 1 << "> " << ds[i] << endl;
	}
	int chon; // 1 -> len //2 -> xuong
	int a;
	
	while (true)
	{
		//clrscr(x); // xoa man hinh tu dong x
		Nocursortype(); //an con tro chuot
		// in ra man hinh giao dien cua menu
		/*
		for ( i = 0; i < n; i++)
		{	
			gotoXY(35,12+2*i); TextColor(mau[i]); 
			cout << i + 1 << "> " << ds[i] << endl;
		}
		*/

		int ikey = getch();
		KEY_PRESS batphim = key(ikey);
		switch (batphim)
		{
		case UP:
		{
			chon = 1;
			if (tt == 0)
			{
				tt = n - 1;
			}
			else
			{
				tt--;
			}
			break;
		}
		case DOWN:
		{
			chon = 2;
			if (tt == n - 1)
			{
				tt = 0;
			}
			else
			{
				tt++;
			}
			break;
		}
		case ENTER:
		{
			return tt;
			break;
		}
		}

		if(chon == 1){
			if(tt == n - 1){
				a = 0;
			}else{
				a = tt + 1;
			}
		} else if ( chon == 2){
			if(tt == 0){
				a = n - 1;
			}else{
				a = tt - 1;
			}
		}
		
		// reset lai mau sau khi da chon lai thao tac khac de in ra
		for (int i = 0; i < n; i++)
		{
			mau[i] = 7;
		}
		mau[tt] = 3;

		gotoXY(35,12+2*(a));
		TextColor(mau[a]);
		cout << a + 1 << "> " << ds[a] << endl;
		gotoXY(35,12+2*tt);
		TextColor(mau[tt]);
		cout << tt + 1 << "> " << ds[tt] << endl;
		
	}
	
}


//=======================================================================


// ham bao tri he thong (done)
void baoTriHeThong(string hambaotri) {
	if (hambaotri == "SapXep" || hambaotri == "TimKiem" || hambaotri == "ThongKe" || hambaotri== "InDanhSach") {
		clrscr(8);
		gotoXY(35,12); TextColor(4); cout << "Chuc nang hien dang xay dung vui long quay lai sau." << endl;
		int c = getch();
		mainMenu();
	}
}


//=======================================================================


// ham menu chinh (done)
void mainMenu() {
	
	gotoXY(50, 3); TextColor(12); cout << "QUAN LI SINH VIEN";
	gotoXY(20, 5); TextColor(14); cout << "==============================================================================";
	gotoXY(25, 6); cout << "Hoc Vien Thuc Hien : LE THI PHUONG PHUONG" <<"	      Lop: CNTT2" << endl;
	gotoXY(20, 7); cout << "==============================================================================";
	switch (Menu(ds_Menu,6,8)){
		case 0: {
			capNhatHoSo();
			break;
		}
		case 1: {
			//baoTriHeThong("InDanhSach");
			inDanhSach(ds,n);
			break;
		}
		case 2: {
			//baoTriHeThong("SapXep");
			sapXep();
			break;
		}
		case 3: {
			//baoTriHeThong("TimKiem");
			timKiem();
			break;
		}
		case 4: {
			//baoTriHeThong("ThongKe");
			thongKe();
			break;
		}
		case 5:
		{
			thoat();
			break;
		}
	}
}

//=======================================================================


//_____________________CAP NHAT HO SO_____________________


//menu ham cap nhat ho so (done)
void capNhatHoSo()
{
	clrscr(8);
	gotoXY(40, 10); TextColor(6); cout << "CAP NHAT DANH SACH SINH VIEN";
	switch (Menu(ds_CapNhat,4,11)) {
		case 0: 
		{
			ds = themMoiHoSo(ds,n);
			int c = getch();
			mainMenu();
			break;
		}
		case 1:
		{
			ds = suaHoSo(ds,n);
			int c = getch();
			mainMenu();
			break;
		}
		case 2:
		{
			ds = xoaHoSo(ds,n);
			int c = getch();
			mainMenu();
			break;
		}	
		case 3:
		{
			clrscr(8);
			mainMenu();
			break;
		}
	}
	
}


//_____________________IN DANH SACH_____________________

//ham in danh sach (done)
void inDanhSach(vector<SinhVien> ds, int size){
    clrscr(8);
	gotoXY(50,10); TextColor(6); cout << "DANH SACH SINH VIEN" << endl;
    TextColor(7); khungDS(8,12,2,size);
    // in tat ca danh sach
	int i;
	for(int i=0;i<size;i++){
    	ds[i].Output(8,15+i*2,i+1);
	}
    int c = getch();
	mainMenu();
}


//_____________________SAP XEP_____________________


// menu ham sap xep (done)
void sapXep(){
    clrscr(8);
    int x,y;

	gotoXY(35, 10); TextColor(6); cout << "CHON THUAT TOAN SAP XEP:" <<endl;
    x = Menu(ds_SapXep,4,11);

    clrscr(8);
	gotoXY(35, 10); TextColor(6); cout << "CHON KIEU SAP XEP:" <<endl;
    y = Menu(ds_Khoa,6,11);
    if(y==5){
    	mainMenu();
    }

    chonSapXep(x,y);
    //kt =true; // da sap xep du lieu
    clrscr(8);
    gotoXY(48,10); TextColor(2); cout << "Da sap xep thanh cong!" << endl;
	int c = getch();
	mainMenu();
}

void chonSapXep( int i, int type){
	switch(i){
		case 0: 
		{
			ds = sapXepChen(ds,n,type);
			break;
		}
		case 1: 
		{
			ds = sapXepChen(ds,n,type);
			break;
		}
		case 2: 
		{
			ds = sapXepChon(ds,n,type);
			break;
		}
		case 3: 
		{
			ds = sapXepNhanh(ds,type,0,n-1);
			break;
		}
	}
}


//_____________________TIM KIEM_____________________


//menu tim kiem (done)
void timKiem(){
    clrscr(8);
	gotoXY(35, 10); TextColor(6); cout << "CHON THUAT TOAN TIM KIEM:" <<endl;
    switch (Menu(ds_TimKiem,3,11))
    {
    case 0:
        timKiemTuanTu();
        break;
    case 1:
        timKiemNhiPhan();
        break;
	case 2:
		clrscr(8);
		mainMenu();
		break;
    }
}


//menu tim kiem tuan tu (done)
void timKiemTuanTu(){
	clrscr(8);
	gotoXY(35, 10); TextColor(6); cout << "TIM KIEM TUAN TU" <<endl;
    switch (Menu(ds_Khoa,6,11))
    {
    	case 0:
		{
			timKiemTT(ds,n,0);
			int c = getch();
			mainMenu();
       		 break;
		}
        
    	case 1:
		{
        	timKiemTT(ds,n,1);
			int c = getch();
			mainMenu();
       		break;
		}
    	
		case 2:
		{
       		timKiemTT(ds,n,2);
			int c = getch();
			mainMenu();
       		break;
		}
		case 3:
		{
        	timKiemTT(ds,n,3);
			int c = getch();
			mainMenu();
        	break;
		}
		case 4:
        {	
			timKiemTT(ds,n,4);
			int c = getch();
			mainMenu();
       		break;
		}
		case 5:
        {	
			clrscr(8);
        	timKiem();
      	  	break;
		}
	}
}


//menu tim kiem nhi phan (done)
void timKiemNhiPhan(){
	clrscr(8);
	gotoXY(35, 10); TextColor(6); cout << "TIM KIEM NHI PHAN" <<endl;
    switch (Menu(ds_Khoa,6,11))
    {
    	case 0:
		{
			timKiemNP(ds,n,0);
			int c = getch();
			mainMenu();
        	break;
		}
    	case 1:
    	{ 
	    	timKiemNP(ds,n,1);
			int c = getch();
			mainMenu();
       	 	break;
		}
    	case 2:
		{
        	timKiemNP(ds,n,2);
			int c = getch();
			mainMenu();
       	 break;
		}
		case 3:
		{
       	 	timKiemNP(ds,n,3);
			int c = getch();
			mainMenu();
       		 break;
		}
		case 4:
		{
        	timKiemNP(ds,n,4);
			int c = getch();
			mainMenu();
       	 	break;
		}
		case 5:
		{
        	clrscr(8);
        	timKiem();
        	break;
		}
	}
}


//______________________THONG KE______________________


//menu ham thong ke
void thongKe(){
    clrscr(8);
    gotoXY(35,10); TextColor(6); cout << "BAO CAO SO LUONG SINH VIEN" << endl;
    switch (Menu(ds_ThongKe,3,11))
    {
        case 0:
        {
            thongKeTheoLop(ds,n);
			int c = getch();
			mainMenu();
            break;
        }
        case 1:
        {
            thongKeTheoKetQuaHocTap(ds,n);
			int c = getch();
			mainMenu();
            break;
        }
		case 2:
		{
			clrscr(8);
			mainMenu();
			break;
		}
    }
}


//______________________THOAT______________________

//ham thoat (done)
void thoat(){
    clrscr(8);
    gotoXY(38,10); TextColor(6); cout << "Ban co muon luu du lieu vao file khong ? " << endl;
    switch (Menu(ds_chon,2,11))
    {
		case 0:
		{
			// ghi du lieu vao file 
			WriteToFile(ds,n);
			clrscr(8);
			gotoXY(45,10); TextColor(2); cout << "Ghi file thanh cong." <<endl;
			int c = getch();
			break;
		}
		case 1:
			break;
	}
	
	system("cls");
	gotoXY(45,2);TextColor(8); cout << "Ban da thoat chuong trinh." << endl;
	gotoXY(45,4); cout << "Chuc ban mot ngay tot lanh." << endl;
	cout << endl;
	TextColor(7);
	
}






	



