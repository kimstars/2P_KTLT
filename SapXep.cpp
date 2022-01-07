#pragma once
#include"SinhVien.cpp"
#include<vector>
#include<stdlib.h>
#include<sstream>


vector<SinhVien> sapXepNoiBot(vector<SinhVien>, int, int);
vector<SinhVien> sapXepChen(vector<SinhVien>, int , int );
vector<SinhVien> sapXepChon(vector<SinhVien>, int , int );
vector<SinhVien> sapXepNhanh(vector<SinhVien>,int, int , int );

//=================================================================
void swapSV(SinhVien&, SinhVien& );
void low(string& );
int soSanhChuoi(string, string);
int soSanhTen(string , string );
int soSanhNgaySinh(string , string );
int soSanh(SinhVien ,SinhVien ,int);
int soSanh(string , SinhVien , int);
string floatToString(float);

//====================CAC THUAT TOAN SAP XEP========================


// ham sap xep noi bot BUBBLE SORT (done)
vector<SinhVien> sapXepNoiBot(vector<SinhVien> ds, int n, int type){
	for (int i = 0; i < ds.size(); i++){
		for (int j = 0; j < ds.size() - i - 1; j++) {
			if (soSanh(ds[j],ds[j+1],type) == 1)
			{
				swapSV(ds[j],ds[j+1]);
			}
		}
    }
    return ds;
}


//ham sap xep chen INSERTION SORT (done)
vector<SinhVien> sapXepChen(vector<SinhVien> ds, int n, int type){
	int index;
	SinhVien sv;
	for (int i = 1; i < ds.size(); i++) {
		index = i - 1;
		sv = ds[i];
		while (index >= 0 && soSanh(ds[index],sv,type)==1) {// ds[index]>sv
				ds[index + 1] = ds[index];
				index--;
		}
		ds[index + 1] = sv;
	}
    return ds;
}


//ham sap chep chon SELECTION SORT (done)
vector<SinhVien> sapXepChon(vector<SinhVien> ds, int n, int type){
	int min;
	for (int i = 0; i < ds.size(); i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (soSanh(ds[min],ds[j],type) == 1)
				min = j;
		}
		if (min != i)
			swapSV(ds[i], ds[min]);
	}
    return ds;
}
	

    

// ham sap xep nhanh QUICK SORT (done)
vector<SinhVien> sapXepNhanh(vector<SinhVien> ds,int type, int l, int r){
	if(type==2){
		//ds = sapXepChon(ds,r+1,type);
		//note: em xin loi thay. em khong sap xep nhanh theo ten duoc :(((((
		//em chua fix duoc loi nay
	}else{
    	SinhVien p=ds[(l+r)/2];
    	int i=l,j=r;
    	while(i<j){
       		while(soSanh(p,ds[i],type)==1){ //ds[i] < p
            	i++;
        	}
        	while(soSanh(ds[j],p,type)==1){ // ds[j]>p
            	j--;
        	}
        	if(i<=j){
            	swapSV(ds[i],ds[j]);
            	i++;
            	j--;
        	}
    	}
    	if(i<r){
        	ds = sapXepNhanh(ds,type,i,r);
    	}
    	if(j>l){
        	ds = sapXepNhanh(ds,type,l,j);
    	}
	}
    return ds;
}
//=================CAC HAM BO TRO CHO SAP XEP=====================


// doi cho 2 doi tuong sinh vien
void swapSV(SinhVien& a1, SinhVien& a2)
{
	SinhVien temp = a1;
	a1 = a2;
	a2 = temp;
}

//chuyen chu hoa ve chu thuong
void low(string& x)
{
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] >= 'A' && x[i] <= 'Z')
			x[i] = x[i] + 32;
	}
}

//so sanh 2 chuoi, tra ve 0 neu bang nhau, -1 neu nho hon, 1 neu lon hon
int soSanhChuoi(string s1, string s2) {
	int ss1 = s1 > s2;
    int ss2 = s1 < s2;
    int ss3 = (s1 == s2);
	if(ss1 == 1){
		return 1;
	}else if(ss2 == 1){
		return -1;
	}else if(ss3 == 1){
		return 0;
	}
}


 //so sanh ten
int soSanhTen(string x1, string x2) {
	
	low(x1); low(x2);
	int size1 = x1.length() - 1, size2 = x2.length() - 1;
	int vt1, vt2; // luu vi tri bat dau cua ten

	//lay vi tri bat dau cua ten
	for(int i=size1 ;i>=0 ;i--){
		if(x1[i] == ' '){
			vt1 = i + 1; 
			break;
		}
	}
	for(int i=size2 ;i>=0 ;i--){
		if(x2[i] == ' '){
			vt2 = i + 1; 
			break;
		}
	}

	// gan ten vao 2 bien string
	string n1, n2;
	char a1[20], a2[20];
	int j = 0;
	for(int i = vt1; i<= size1 ; i++){
		a1[j] = x1[i];
		j++;
	}
	j = 0;
	for(int i = vt2; i<= size2 ; i++){
		a2[j] = x2[i];
		j++;
	}
	n1 = string(a1);
	n2 = string(a2);

	//so sanh 2 ten
	return soSanhChuoi(n1,n2);
}


//so sanh ngay sinh
int soSanhNgaySinh(string x, string y){
	string day_x, day_y, month_x, month_y, year_x, year_y;
	day_x += x[0];
	day_x += x[1];
	month_x += x[3];
	month_x += x[4];
	year_x += x[6];
	year_x += x[7];
	year_x += x[8];
	year_x += x[9];
	
	day_y += y[0];
	day_y += y[1];
	month_y += y[3];
	month_y += y[4];
	year_y += y[6];
	year_y += y[7];
	year_y += y[8];
	year_y += y[9];


	int ngay_x, ngay_y, thang_x, thang_y, nam_x, nam_y;
	ngay_x = atoi(day_x.c_str()); // ham atoi chuyen string thanh int
	thang_x = atoi(month_x.c_str());
	nam_x = atoi(year_x.c_str());
	
	ngay_y = atoi(day_y.c_str()); // ham atoi chuyen string thanh int
	thang_y = atoi(month_y.c_str());
	nam_y = atoi(year_y.c_str());
	
	if(nam_x > nam_y){
		return 1;
	}else if(nam_x == nam_y) {
		if(thang_x > thang_y){
			return 1;
		}else if( thang_x == thang_y) {
			if(ngay_x > ngay_y){
				return 1;
			}else {
				if(ngay_x < ngay_y){
					return -1;
				}else{
					//ngay_x = ngay_y
					return 0;
				}
			}
		}else{
			if(thang_x < thang_y){
				return -1;
			}else{
				//thang_x = thang_y
				return 0;
			}
		}
	}else{
		if(nam_x < nam_y){
			return -1;
		}else{
			return 0;
	    }
	}
}


int soSanh(SinhVien x ,SinhVien y,int type){
	int key;
	// cout << "kietcheck";
	switch (type)
	{
		case 0: key = soSanhChuoi(x.maLop,y.maLop); break;
		case 1: key = soSanhChuoi(x.maSV, y.maSV); break;
		case 2: key = soSanhTen(x.hoTen,y.hoTen); break;
		case 3: key = soSanhNgaySinh(x.ngaySinh,y.ngaySinh); break;
		case 4: key = soSanhChuoi(floatToString(x.diemTB),floatToString(y.diemTB)); break;
	}
	// cout << key;
	return key;
}

int soSanh(string s, SinhVien x, int type){
	int key;
	low(s);
	switch (type)
	{	
		case 0: key = soSanhChuoi(s, x.maLop); break; 
		case 1: key = soSanhChuoi(s, x.maSV); break;
		case 2: key = soSanhTen(s,x.hoTen); break;
		case 3: key = soSanhNgaySinh(s,x.ngaySinh); break;
		case 4:	key = soSanhChuoi(s, floatToString(x.diemTB)); break;
	} 
	return key;
}



//chuyen tu float sang string
string floatToString(float num)
{
	ostringstream buff;
	buff <<  fixed << setprecision(2) << num;
	return buff.str();
}	

