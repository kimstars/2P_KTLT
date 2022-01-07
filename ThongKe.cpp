#include"SinhVien.cpp"
#include<vector>

string ds_MaLop[]= {"CNTT1","CNTT2","BDATTT","ANHTTT","PTDL"};
string ds_TenLop[] = { "Cong Nghe Thong Tin 1",
					"Cong Nghe Thong Tin 2",
					"Bao Dam An Toan Thong Tin",
					"An Ninh He Thong Thong Tin",
					"Phan Tich Du Lieu"}; 

//============================================

struct thongketheolop
{
	string maLop;
	string tenLop;
	int soSV;
};


struct thongketheokq
{
	string maLop;
	int xuatsac;		//1
	int gioi; 			//2
	int kha;			//3
	int trungbinh;		//4
	int yeu;			//5
	int tong;
};


//==================================================

thongketheolop lop[5];
thongketheokq KQ[5];
//=================================================

void thongKeSinhVienLop(vector<SinhVien> ds, int n);
void thongKeSinhVienKQ(vector<SinhVien> ds, int n);
void thongKeTheoLop(vector<SinhVien> ds, int n);
void thongKeTheoKetQuaHocTap(vector<SinhVien> ds, int n);
void drawKQ(vector<SinhVien> ds);
void drawLOP(vector<SinhVien> ds, int &tong);
void BieuDoKQ(vector<SinhVien> ds);
void BieuDoLOP(vector<SinhVien> ds);
void drawchart(int count, int size, int x);
void drawchart2(int stt, int x);
//==================================================

//ham thong ke so sinh vien moi lop
void thongKeSinhVienLop(vector<SinhVien> ds, int n){
	for(int j=0;j<5;j++){	
		for(int i=0;i<n;i++){
			if(lop[j].maLop == ds[i].maLop ){
				lop[j].soSV++;
			}
		}
	}
}


//ham thong ke so luong sinh vien theo moi ket qua hoc tap cua tung lop
void thongKeSinhVienKQ(vector<SinhVien> ds, int n){
	for(int j=0;j<5;j++){
		for(int i=0;i<n;i++){
			if(KQ[j].maLop == ds[i].maLop){
				if(ds[i].diemTB >= 9.0) KQ[j].xuatsac++;
				if(ds[i].diemTB >= 8.0 && ds[i].diemTB < 9.0) KQ[j].gioi++;
				if(ds[i].diemTB >= 6.5 && ds[i].diemTB < 8.0) KQ[j].kha++;
				if(ds[i].diemTB >= 5.0 && ds[i].diemTB < 6.5) KQ[j].trungbinh++;
				if(ds[i].diemTB < 5.0) KQ[j].yeu++;
				
				KQ[j].tong++;
			}
		}
	}
}



//ham in thong ke theo lop (done)
void thongKeTheoLop(vector<SinhVien> ds, int n){
	clrscr(8);
	gotoXY(38,10); TextColor(6); cout << "DANH SACH THONG KE SINH VIEN THEO LOP" << endl;
    TextColor(7); khungTK(23,12,2,5,1);
	for(int i=0;i<5;i++){
		lop[i].maLop = ds_MaLop[i];
		lop[i].tenLop = ds_TenLop[i];
	}
	thongKeSinhVienLop(ds,n); //nhap du lieu vao cac struct 
    //in thong tin theo bang
	TextColor(7);
	for(int i=0;i<5;i++){
		gotoXY(25,15+2*i); cout << lop[i].maLop ;
		gotoXY(38,15+2*i); cout << lop[i].tenLop;
		gotoXY(81,15+2*i); cout << lop[i].soSV;
	}
	//in thong tin theo bieu do
	BieuDoLOP(ds);
}


//ham in thong ke theo ket qua hoc tap (done)
void thongKeTheoKetQuaHocTap(vector<SinhVien> ds, int n){
    clrscr(8);
	gotoXY(33,10); TextColor(6); cout << "DANH SACH THONG KE SINH VIEN THEO KET QUA HOC TAP" << endl;
    TextColor(7); khungTK(17,12,2,5,2);
	for(int i=0;i<5;i++){
		KQ[i].maLop = ds_MaLop[i];
	}
	thongKeSinhVienKQ(ds,n);
    //in thong tin theo bang
	TextColor(7);
	for(int i=0;i<5;i++){
		gotoXY(21,15+2*i); cout << KQ[i].maLop ;
		gotoXY(37,15+2*i); cout << KQ[i].xuatsac;
		gotoXY(51,15+2*i); cout << KQ[i].gioi;
		gotoXY(65,15+2*i); cout << KQ[i].kha;
		gotoXY(79,15+2*i); cout << KQ[i].trungbinh;
		gotoXY(93,15+2*i); cout << KQ[i].yeu;
	}
	//in thong tin theo bieu do
	BieuDoKQ(ds);
}
//==================================================

//VE COT THONG KE LOP
void drawLOP(vector<SinhVien> ds, int &tong)
{
	for (int i = 0; i < 5; i++)
	{
		gotoXY(18 + 17 * i, 60);
		cout << lop[i].maLop;
	}
	drawchart(lop[0].soSV, ds.size(), 19);
	drawchart(lop[1].soSV, ds.size(), 36);
	drawchart(lop[2].soSV, ds.size(), 53);
	drawchart(lop[3].soSV, ds.size(), 70);
	drawchart(lop[4].soSV, ds.size(), 87);

	tong = lop[0].soSV + lop[1].soSV + lop[2].soSV + lop[3].soSV + lop[4].soSV;
}

//VE COT THONG KE KQHT
void drawKQ(vector<SinhVien> ds)
{
	for (int i = 0; i < 5; i++)
	{
		gotoXY(18 + 17 * i, 60);
		cout << KQ[i].maLop;
	}
	
	int i;
	for(i=0;i<5;i++) drawchart2(i, 19 + 17 * i);
}


void BieuDoLOP(vector<SinhVien> ds)
{
	Text(3 on 0);
	gotoXY(5, 30); cout << "DAI DOI 155-TIEU DOAN 1";
	gotoXY(50, 30); cout << "TONG SO SINH VIEN: ";
	for (int i = 0; i <= 5; i++) {
		gotoXY(8, 58 - 5 * i);
		cout << 20 * i;
	}
	Text(15 on 0);
	MakeLine(15, 32, 2, 27);
	MakeLine(15, 59, 1, 100);
	int tong = 0;
	drawLOP(ds, tong);
	Text(10 on 0); gotoXY(78,30); cout << tong;
}


//THONG KE DANG BIEU DO
void BieuDoKQ(vector<SinhVien> ds)
{
	Text(9 on 0);
	for (int i = 0; i <= 5; i++) {
		gotoXY(8, 58 - 5 * i);
		cout << 20 * i;
	}
	MakeLine(15, 32, 2, 27);
	MakeLine(15, 59, 1, 100);
	drawKQ(ds);
}

//ve cot thong ke
void drawchart(int count, int size, int x) {
	float length = count * 25 / size ;
	static int i = 1;
	i++;
	if(i == 15) i = 1;
	Text(9 on i);
	for (int i = 1; i <= length; i++) {
		gotoXY(x, 59 - i);
		Sleep(15);
		if (count >= 10) {
			cout << "    ";
			continue;
		}
		cout << "   ";
	}
	Text(12 on 0);
	gotoXY(x - 1, 58 - length);
	cout << setprecision(4) << (float)count * 100 / size << "%";
	gotoXY(x + 1, 59 - length / 2); Text(0 on i); cout << count;
	Text(0 on 0);
}

//ve cot thong ke
void drawchart2(int stt, int x) {
	int count;

	// hs xuat sac
	count = KQ[stt].xuatsac;
	float length1 = count * 25 / lop[stt].soSV ;
	Text(0 on 10);
	for (int i = 1 ; i <= length1; i++) {
		gotoXY(x, 59 - i);
		Sleep(15);
		if (count >= 10) {
			cout << "    ";
			continue;
		}
		cout << "   ";
	}
	Text(0 on 10); gotoXY(x + 1, 59 - length1/2);
	if(count != 0) cout << count;

	//hs gioi
	count = KQ[stt].gioi;
	float length2 = count * 25 / lop[stt].soSV ;
	Text(0 on 11);
	for (int i = length1 + 1 ; i <= (length1 + length2); i++) {
		gotoXY(x, 59 - i);
		Sleep(15);
		if (count >= 10) {
			cout << "    ";
			continue;
		}
		cout << "   ";
	}
	Text(0 on 11); gotoXY(x + 1, 59 - length1 - length2/2);
	if(count != 0) cout << count;


	//hs kha
	count = KQ[stt].kha;
	float length3 =count * 25 / lop[stt].soSV ;
	Text(0 on 12);
	for (int i = (length1 + length2) + 1; i <= (length1 + length2 + length3); i++) {
		gotoXY(x, 59 - i);
		Sleep(15);
		if (count >= 10) {
			cout << "    ";
			continue;
		}
		cout << "   ";
	}
	Text(0 on 12);gotoXY(x +1, 59 - length1 - length2 - (length3/2));
	if(count != 0) cout << count;

	//hs trung binh
	count = KQ[stt].trungbinh;
	float length4 = count * 25 / lop[stt].soSV ;
	Text(0 on 13);
	for (int i = (length1 + length2 + length3) + 1; i <= (length1 + length2 + length3 + length4); i++) {
		gotoXY(x, 59 - i);
		Sleep(15);
		if (count >= 10) {
			cout << "    ";
			continue;
		}
		cout << "   ";
	}
	Text(0 on 13);gotoXY(x + 1, 59 -length1 - length2 - length3 - (length4/2));
	if(count != 0) cout << count;

	//hs yeu
	count = KQ[stt].yeu;
	float length5 = count * 25 / lop[stt].soSV ;
	Text(0 on 14);
	for (int i = (length1 + length2 + length3 + length4) + 1; i <= (length1 + length2 + length3 + length4 + length5); i++) {
		gotoXY(x, 59 - i);
		Sleep(15);
		if (count >= 10) {
			cout << "    ";
			continue;
		}
		cout << "   ";
	}
	Text(0 on 14); gotoXY(x + 1, 59 - length1 - length2 - length3 - length4 - (length5/2));
	if(count != 0) cout << count;


}

