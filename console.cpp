

#ifndef _console_header
#define _console_header


#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

#define default_ColorCode		7


#define key_Up		1072
#define key_Down	1080
#define key_Left	1075
#define key_Right	1077
#define key_none	-1

const char gocTT = 218; //goc trai tren
const char gocTD = 192; //goc trai duoi
const char gocPT = 191; //goc phai tren
const char gocPD = 217; //gc phai duoi
const char gachNgang = 196;
const char gachDoc = 179;
const char gachGT = 194; //giua tren
const char gachGD = 193; // giua duoi
const char gachGiuaTrong = 197;
const char gachGiuaTrai = 195;
const char gachGiuaPhai = 180;

enum KEY_PRESS
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	ESC,
	ENTER,
};


//--------------------------------------------------------
#include<iostream>
#include <windows.h>
#include<conio.h>
#include<iomanip>
using namespace std;

//-------------------------Screen-------------------------
void Cursortype();

// ham an con tro chuot
void Nocursortype( );

//ham xoa man hinh
void clrscr(int x);

//screen: goto [x,y]
void gotoXY (int column, int line);

//screen: get [x]
int whereX();

//screen: get [y]
int whereY();

//ham doi mau chu
void TextColor (int color);

//ham doi mau chu va nen chu
#define on ,
void Text(int color on int p_color);

//ham bat su kien ban phim
KEY_PRESS key(int );

//ham ve khung in danh sach 
void khungDS(int x, int y, int a, int row); // x,y la toa do bat dau, a la do rong cua mot o, row la so hang can in

//ham ve khung in thong ke
void khungTK (int x, int y, int a, int row, int type); 

// ve duong ke doc, duong ke ngang 
void MakeLine(int x, int y, int style, int length);

//chu chay
void chuChay();

//end----------------------Screen----------------------end




//-------------------------Screen-------------------------
void Cursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
// ham an con tro chuot
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
} 

//ham xoa man hinh
void clrscr(int x)
{
	HANDLE hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD count;
	DWORD cellCount;
	COORD homeCoords = { 0, x }; // xoa tu dong x

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(hStdOut, (TCHAR)' ', cellCount, homeCoords, &count)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}



//screen: goto [x,y]
void gotoXY (int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


//screen: get [x]
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}


//screen: get [y]
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}

// ham doi mau chu
void TextColor (int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}

void Text(int text_color = 7 on int paper_color = 0)
{
	int color_total = (text_color + (paper_color * 16));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_total);
}

// ham bat su kien ban phim (done)
KEY_PRESS key(int ikey)
{
	if (ikey == 224)
	{
		char c = getch();
		if (c == 72)
			return UP;
		if (c == 80)
			return DOWN;
		if (c == 75)
			return LEFT;
		if (c == 77)
			return RIGHT;
	}
	else if (ikey == 13)
	{
		return ENTER;
	}
	else if (ikey == 27)
	{
		return ESC;
	}
}

//ham in khung ds
void khungDS(int x, int y, int a, int row) {
	TextColor(14);
	gotoXY(x + 2, y + a/2); cout << "STT";
	gotoXY(x + 10, y + a/2); cout << "Ma Lop";
	gotoXY(x + 26, y + a/2); cout << "Ma Sinh Vien";
	gotoXY(x + 53, y + a/2); cout << "Ho Ten";
	gotoXY(x + 79, y + a/2); cout << "Ngay Sinh";
	gotoXY(x + 97, y + a/2); cout << "Diem";
	
	TextColor(10);
	gotoXY(x, y); cout << gocTT;
	gotoXY(x + 6, y); cout << gachGT;
	gotoXY(x + 22, y); cout << gachGT;
	gotoXY(x + 40, y); cout << gachGT;
	gotoXY(x + 74, y); cout << gachGT;
	gotoXY(x + 92, y); cout << gachGT;
	gotoXY(x + 104, y); cout << gocPT;

	gotoXY(x, y + a + row *a); cout << gocTD;
	gotoXY(x + 6, y + a + row *a); cout << gachGD;
	gotoXY(x + 22, y + a + row *a); cout << gachGD;
	gotoXY(x + 40, y + a+ row *a); cout << gachGD;
	gotoXY(x + 74, y + a+ row *a); cout << gachGD;
	gotoXY(x + 92, y + a+ row *a); cout << gachGD;
	gotoXY(x + 104, y + a+ row *a); cout << gocPD;
		
	for (int i = 0; i <= row; i++) {
		if(i!=0){
			gotoXY(x, y + i *a); cout << gachGiuaTrai;
			gotoXY(x + 6, y + i *a); cout << gachGiuaTrong;
			gotoXY(x + 22, y + i *a); cout << gachGiuaTrong;
			gotoXY(x + 40, y + i *a); cout << gachGiuaTrong;
			gotoXY(x + 74, y + i *a); cout << gachGiuaTrong;
			gotoXY(x + 92, y + i *a); cout << gachGiuaTrong;
			gotoXY(x + 104, y + i *a); cout << gachGiuaPhai;
		}
		for (int j = 0; j <= 104; j++) {
			if (j != 0 && j != 6 && j != 22 && j != 40 && j != 74 && j != 92 && j != 104) {
				gotoXY(x + j, y+i *a );
				cout << gachNgang;
				gotoXY(x + j, y + a +i*a );
				cout << gachNgang;
			}
			else {
				for(int k=1;k<a;k++){
					gotoXY(x + j, y + k +i*a);
					cout << gachDoc;
				}
			}
		}
	}
}

//ham in khung thong ke
void khungTK (int x, int y, int a, int row, int type) {
	//type = 1 => thong ke theo lop
	
	if(type==1){
		TextColor(14);
		gotoXY(x + 2, y + a/2); cout << "Ma Lop";
		gotoXY(x + 26, y + a/2); cout << "Ten Lop";
		gotoXY(x + 57, y + a/2); cout << "So SV";

		TextColor(10);
		gotoXY(x, y); cout << gocTT;
		gotoXY(x + 10, y); cout << gachGT;
		gotoXY(x + 50, y); cout << gachGT;
		gotoXY(x + 70, y); cout << gocPT;

		gotoXY(x, y + a + row *a); cout << gocTD;
		gotoXY(x + 10, y + a + row *a); cout << gachGD;
		gotoXY(x + 50, y + a + row *a); cout << gachGD;
		gotoXY(x + 70, y + a+ row *a); cout << gocPD;
		
		for (int i = 0; i <= row; i++) {
			if(i!=0){
				gotoXY(x, y + i *a); cout << gachGiuaTrai;
				gotoXY(x + 10, y + i *a); cout << gachGiuaTrong;
				gotoXY(x + 50, y + i *a); cout << gachGiuaTrong;
				gotoXY(x + 70, y + i *a); cout << gachGiuaPhai;
			}
			for (int j = 0; j <= 70; j++) {
				if (j != 0 && j != 10 && j != 50 && j != 70 ) {
					gotoXY(x + j, y+i *a );
					cout << gachNgang;
					gotoXY(x + j, y + a +i*a );
					cout << gachNgang;
				}
				else {
					for(int k=1;k<a;k++){
						gotoXY(x + j, y + k +i*a);
						cout << gachDoc;
					}
				}
			}
		}
	}

	//type = 2 => thong ke theo ket qua hoc tap
	if(type==2){
		TextColor(14);
		gotoXY(x + 4, y + a/2); cout << "	";
		gotoXY(x + 18, y + a/2); cout << "Xuat Sac";
		gotoXY(x + 34, y + a/2); cout << "Gioi";
		gotoXY(x + 48, y + a/2); cout << "Kha";
		gotoXY(x + 59, y + a/2); cout << "Trung Binh";
		gotoXY(x + 75, y + a/2); cout << "Yeu";
	
		TextColor(10);
		gotoXY(x, y); cout << gocTT;
		gotoXY(x + 15, y); cout << gachGT;
		gotoXY(x + 29, y); cout << gachGT;
		gotoXY(x + 43, y); cout << gachGT;
		gotoXY(x + 57, y); cout << gachGT;
		gotoXY(x + 71, y); cout << gachGT;
		gotoXY(x + 85, y); cout << gocPT;

		gotoXY(x, y + a + row *a); cout << gocTD;
		gotoXY(x + 15, y + a + row *a); cout << gachGD;
		gotoXY(x + 29, y + a + row *a); cout << gachGD;
		gotoXY(x + 43, y + a+ row *a); cout << gachGD;
		gotoXY(x + 57, y + a+ row *a); cout << gachGD;
		gotoXY(x + 71, y + a+ row *a); cout << gachGD;
		gotoXY(x + 85, y + a+ row *a); cout << gocPD;
		
		for (int i = 0; i <= row; i++) {
			if(i!=0){
				gotoXY(x, y + i *a); cout << gachGiuaTrai;
				gotoXY(x + 15, y + i *a); cout << gachGiuaTrong;
				gotoXY(x + 29, y + i *a); cout << gachGiuaTrong;
				gotoXY(x + 43, y + i *a); cout << gachGiuaTrong;
				gotoXY(x + 57, y + i *a); cout << gachGiuaTrong;
				gotoXY(x + 71, y + i *a); cout << gachGiuaTrong;
				gotoXY(x + 85, y + i *a); cout << gachGiuaPhai;
			}
			for (int j = 0; j <= 85; j++) {
				if (j != 0 && j != 15 && j != 29 && j != 43 && j != 57 && j != 71 && j != 85) {
					gotoXY(x + j, y+i *a );
					cout << gachNgang;
					gotoXY(x + j, y + a +i*a );
					cout << gachNgang;
				}
				else {
					for(int k=1;k<a;k++){
						gotoXY(x + j, y + k +i*a);
						cout << gachDoc;
					}
				}
			}
		}
	}
}

// ve duong ke doc, duong ke ngang 
void MakeLine(int x, int y, int style, int length)
{
	if (style == 1)
	{
		for (int i = x; i <= x + length; i++)
		{
			gotoXY(i, y);
			cout << gachNgang;
		}
	}
	if (style == 2)
	{
		for (int i = y; i <= y + length; i++)
		{
			gotoXY(x, i);
			cout << gachDoc;
		}
	}
}



//chu chay
void chuChay(){

	char a[300] = "  San pham duoc hoan thanh vao ngay 27/11/2021. Moi chi tiet xin lien he Facebook : https://www.facebook.com/ltpp.6420.9328. Xin cam on !!  ";
	char b[300], c[100];
	strcpy(b,a);
	strcat(a,b);
	for(int i=0; i< strlen(a); i++){
		strncpy(c, a + i, 100);
		c[100] = 0;
		Sleep(100);
		gotoXY(10,15); cout << c;
		//if( i == strlen(b)) i = 0;
	}
	system("cls");
}

#endif
