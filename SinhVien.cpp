#pragma once
#include<string>
#include<algorithm> //for transform
#include<iomanip> //for setprecision
#include"console.cpp"


int checkDay(string&);
void chuanHoaTen(string&); //chuan hoa ten chi can in luc out nen k can in ngay luc nhap
void chuanHoaNgay(int, int, string&); //x,y de in ra dung vi tri luc nhap!!
void ktDiem(int, int, float&); //x,y toa do, float diemTB
string coverIntToString(int x, int srt);

//==========================================================

class SinhVien{     
    public:
        string maLop;
        string maSV;
        string hoTen;
        string ngaySinh;
        float diemTB;
        SinhVien();
        SinhVien(string, string , string , string , float);
        
        void Input(int ,int); //x,y
        void Output(int ,int ,int); //x,y,i
        
        bool operator == (SinhVien);
        friend ostream& operator << (ostream& , SinhVien& );
        //friend istream& operator >> (istream& , SinhVien& );
        
		
        
};


SinhVien::SinhVien(){
    this->maLop = "0";
    this->maSV = "0";
    this->hoTen = "Khong";
    this->ngaySinh = "00/00/0000";
    this->diemTB = 0.0;
}


SinhVien::SinhVien(string maLop, string maSV, string hoTen, string ngaySinh, float diemTB){
    this->maLop = maLop;
    this->maSV = maSV;
    this->hoTen = hoTen;
    this->ngaySinh = ngaySinh;
    this->diemTB = diemTB;
}


void SinhVien::Input(int x,int y){
    TextColor(7);
    gotoXY(x,y); cout << "   Ma lop: "; gotoXY(x+22,y); cin >> this->maLop;
    gotoXY(x,y+1); cout << "   Ma sinh vien: "; gotoXY(x+22,y+1); cin >> this->maSV;
    gotoXY(x,y+2); cout << "   Ho va ten: " ; gotoXY(x+22,y+2); fflush(stdin); getline(cin,this->hoTen); chuanHoaTen(this->hoTen);
    gotoXY(x,y+3); cout << "   Ngay sinh: "; gotoXY(x+22,y+3); cout << "dd/mm/yyyy"; 
	gotoXY(x+22,y+3); cin >> this->ngaySinh; chuanHoaNgay(x+22,y+3,this->ngaySinh);
	gotoXY(x,y+4); cout << "   Diem TB tich luy: "; gotoXY(x+22,y+4); cin >> this->diemTB; ktDiem(x+22,y+4,this->diemTB);
}


void SinhVien::Output(int x, int y, int i){
	TextColor(7);
	gotoXY(x+2,y); cout << coverIntToString(i, 3);
	gotoXY(x+10,y); cout << this->maLop ;
    gotoXY(x+26,y); cout << this->maSV ;
    gotoXY(x+45,y); chuanHoaTen(this->hoTen); cout << this->hoTen ; 
    gotoXY(x+79,y); cout << this->ngaySinh ;
    gotoXY(x+97,y); cout << this->diemTB; 
}


bool SinhVien::operator == (SinhVien sv) {
	if ((maLop == sv.maLop) && (maSV == sv.maSV) && (hoTen == sv.hoTen) && (ngaySinh == sv.ngaySinh) && (diemTB == sv.diemTB))
		return true;
	return false;
} 


ostream& operator << (ostream& out, SinhVien& sv ) {
	out << "Ma lop: " << sv.maLop << endl;
    out << "Ma sinh vien: " << sv.maSV << endl;
    out << "Ho va ten: " << sv.hoTen << endl; 
    out << "Ngay sinh: " << sv.ngaySinh << endl;
    out << "Diem trung binh tich luy: " << sv.diemTB << endl;
	return out;
}
/*
ostream& operator >> (ostream& in, SinhVien& sv ) {
	in >> sv.maLop;
	in >> sv.maSV;
	getline( in , sv.hoTen );
	in >> sv.ngaySinh;
	in >> sv.diemTB;
	return in;
}

*/
//======================================================

 void chuanHoaTen(string &s){
    //chuyen thanh chu thuong het
	std::transform(s.begin(), s.end(),s.begin(), ::tolower);
	
	//bo dau cach thua dau xau;
    int i=0;
    while(s[i]==' ' && i<s.length()){
		i++;
    }
    s= s.substr(i); //copy tu vi tri i cua xau hoTen vao hoTen
    
    
    //bo dau cach thua o giua xau
    i=0;
    while(i<s.length()-1){
        if (s[i]==' ' && s[i+1]==' '){
        	string s1 = s.substr(i+1);
        	s.replace(i,s.length()-i,s1);
        }
        else{
            i++;
        }
    }
    
    //bo dau cach thua o cuoi xau
    while(s[s.length()]==' ')
        s[s.length()]='\0';

	//Viet hoa cac tu dau
    if (s[0] != 32)
        {
            if (s[0] >96 && s[0]< 123)
                {
                	s[0] -= 32;
                }
        }
	for (i = 1; i < s.length(); i++)
    {
        if (s[i] == 32){
            if (s[i + 1]> 96 && s[i + 1] < 123){
                s[i + 1] -= 32;
            }
    	}
    }
}


// ham chuan hoa ngay thang nam
void chuanHoaNgay(int x, int y, string &s){	
	int check = checkDay(s); 
    while(check == 1 || check == 4 || check == 5 || check == 6 || check == 7){
    	gotoXY(x,y);
    	TextColor(4);
		cout << "Error!Again!";
		int ikey = getch();
		KEY_PRESS batphim = key(ikey);
		switch (batphim)
		{
			case ENTER:
			{
				TextColor(7);
				gotoXY(x,y); cout << "			";
				gotoXY(x,y); cout << "dd/mm/yyyy"; 
				int ikey = getch();
				KEY_PRESS batphim = key(ikey);
				switch (batphim)
				{
					default:
						gotoXY(x,y); cin >> s;
    					check = checkDay(s);
						break;
				}
				break;
			}
		}	
	} 
	
	while(check != 8){
		if(check == 2){
			//d/m/yyyy or d/mm/yyyy
			s.insert(0, "0"); //them "0" vao vi tri 0
			check = checkDay(s);
		}else if(check==3){
			// dd/m/yyyy
			s.insert(3,"0"); //them "0" vao vi tri 3
			check = checkDay(s);
		}	
	}

	TextColor(7); gotoXY(x,y); cout << s; //in lai ngay thang dung dinh dang
}


//ktra ngay 
int checkDay(string &s) {
	
	//1: loi sai dinh dang dd/mm/yyyy
	//2: loi thieu 0 trong dd
	//3: loi thieu 0 trong mm
	//4: loi sai cau truc date
	//5: loi sai ngay trong thang 2 cua nam nhuan
	//6: loi sai ngay trong thang 2 cua nam khong nhuan
	//7: loi sai ngay trong thang
	//8: dung

	if ((s.length() > 10) || (s.length() <8)) return 1; //khac dinh dang dd/mm/yyyy
	if (s[2] != '/') return 2; 
	if (s[5] != '/') return 3;

	string day, month, year;

	day += s[0];
	day += s[1];

	month += s[3];
	month += s[4];

	year += s[6];
	year += s[7];
	year += s[8];
	year += s[9];

	int ngay, thang, nam;

	ngay = atoi(day.c_str()); // ham atoi chuyen string thanh int
	thang = atoi(month.c_str());
	nam = atoi(year.c_str());

	if (ngay <= 0 || ngay > 31 || thang < 1 || thang > 12 || nam < 1900 || nam > 2020) return 4;
	if ((thang == 2) && ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0) && (ngay > 29)) return 5;
	else if ((thang == 2) && !(nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0) && (ngay > 28)) return 6;
	if ((thang == 4 || thang == 6 || thang == 9 || thang == 11) && (ngay > 30)) return 7;
	return 8;

}


//kiem tra nhap diem TB
void ktDiem(int x, int y, float &a){
	bool flag= true;
	while(flag){
		if((a>=0) && (a<=10)){
			flag = false;
		}else{
			gotoXY(x,y);TextColor(4); cout << "Error!Again!";
			int ikey = getch();
			KEY_PRESS batphim = key(ikey);
			switch (batphim)
			{
				case ENTER:
				{
					gotoXY(x,y); TextColor(7); cout << "		";
					gotoXY(x,y); cin >> a;
					break;
				}
			}
		}
	}
	gotoXY(x,y); cout << "		";
	std::cout << std::setprecision(3);
	gotoXY(x,y); cout << a;
}


//chuyen tu int sang string
string coverIntToString(int x, int srt) // x la so can chuyen  , srt la do dai xau can co
{
	string ans = ""; // khoi tao kq la rong
	while(x)  // tach tuong so ra
	{
		ans = char(x%10+'0') + ans; // chuyen thanh char ep vao ans
		x/=10;
	}
	while(ans.length() < srt) ans = "0" + ans; // neu ma day so chua du srt ky ty thi them so 0 vao dau
	ans = ans.substr(0, srt); // neu thua thi lay dung srt ky tu
	return ans;
}





















