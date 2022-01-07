#include<fstream>
#include<cstdio>
#include<vector>
#include"SinhVien.cpp"


void loading(){
	char a= 177, b =219;
	Nocursortype();
	gotoXY(53,10); cout << "loading..";
	gotoXY(45,12);
	for(int i=0;i<26;i++){
		cout << a;
	}
	cout << "\r";
	gotoXY(45,12);
	for(int i=0; i < 26; i++){
		cout << b;
		Sleep(100);
	}
	system("cls");
}

void IMAGE(){
	cout << endl;
	fstream newFile;
	newFile.open("image.txt", ios::in);
	if(newFile.is_open()){
		string tp;
		while(getline(newFile,tp)){
			cout << tp <<endl;
			Sleep(20);
		}
		newFile.close();
	}
	cout << "\n\n";
	cout << "\t\t\t\t\tNhan phim ENTER de bat dau...";
	cin.ignore();
	system("cls");
	// loading();
	system("cls");
}




//============================FILE==================================


// ghi vector Sinh Vien vao file (done)
void WriteToFile(vector<SinhVien> ds, int n){
	ofstream fileOut;
	fileOut.open("Bai5_out.txt" , ios::out);
	if (!fileOut.is_open()){
		cout<< "Cannot open file." << endl;
		return;	
	}
	fileOut << "			DANH SACH SINH VIEN" << endl;
	for(int i=0;i<n;i++){
		fileOut << endl;
		fileOut << i + 1 << "> " << endl;
		fileOut << "Ma lop: " << ds[i].maLop << endl;
    	fileOut << "Ma sinh vien: " << ds[i].maSV << endl;
    	fileOut << "Ho va ten: " << ds[i].hoTen << endl; 
    	fileOut << "Ngay sinh: " << ds[i].ngaySinh << endl;
    	fileOut << "Diem trung binh tich luy: " << ds[i].diemTB << endl;
    	fileOut << endl;
	}
	fileOut.close();
}


// doc du lieu tu file (done)
vector<SinhVien> readFile(int&n){
	int count=0;
	vector<SinhVien> ds2;
	
	ifstream fileIn;
	fileIn.open( "Bai5_in.txt", ios::in );
	if(!fileIn.is_open()){
		cout << "Cannot open file." << endl;
		return ds2;	 
	}	
	
	SinhVien sv;
	while(!fileIn.eof()){
		string maLop;
        string maSV;
        string hoTen;
        string ngaySinh;
        double diemTB;

		getline(fileIn,hoTen);
		fileIn >> maLop;
		fileIn >> maSV;
		fileIn >> ngaySinh;
		fileIn >> diemTB;

		sv.hoTen = hoTen;
		sv.maLop = maLop;
		sv.maSV = maSV;
		sv.ngaySinh = ngaySinh;
		sv.diemTB = diemTB;
		fileIn.get();
		ds2.push_back(sv);
		count++;
	}		
	n = count;	
	fileIn.close();
	return ds2;
}




