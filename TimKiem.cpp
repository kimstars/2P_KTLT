#include "SapXep.cpp"
#include <vector>

int SIZE_BANG[7] = {0, 6, 22, 40, 74, 92, 104};

struct Node
{
	SinhVien data;
	Node *next;
};

struct TreeNode
{
	SinhVien data;
	TreeNode *left, *right;
};

//===================================================

void timKiemTT(vector<SinhVien>, int, int);
void timKiemNP(vector<SinhVien>, int, int);

//==================================================

void khongTimThay();
void rawTextDemo(int x, int y, int size[], string data[]);
void rawTextColor(int x, int y, int size[], string data, int vt, string key, int type);
void rawSV_mau(int x, int y, int size[], SinhVien data, int vt, int loai, string key);
bool checkSinhVien(SinhVien data, int type, string s);
void printSearch(vector<SinhVien> ds2, int count, int type, string s);
void printSearch(Node *t, int count, int type, string s);
string low2(string); // chuyen string thanh chu thuong nhung k lam thay doi string do

//==================================================

Node *newNode(SinhVien sv);
TreeNode *newTreeNode(SinhVien sv);
void add(SinhVien sv, Node *t);
TreeNode *Insert(TreeNode *t, SinhVien data, int type);
int Search(SinhVien sv, string s, int type);
SinhVien SearchTree(TreeNode *root, TreeNode *dsNP, string s, int type);

//=================TIM KIEM TUAN TU==================

// ham tim kiem tuan tu theo type (done)
void timKiemTT(vector<SinhVien> ds, int n, int type)
{
	clrscr(8);
	TextColor(6);
	gotoXY(30, 10);
	cout << "Nhap tu khoa can tim: ";
	string s;
	int dem = 0;
	if (type == 2)
	{
		fflush(stdin);
		getline(cin, s);
	}
	else
	{
		cin >> s;
	}

	vector<SinhVien> ds2;
	for (int i = 0; i < n; i++)
	{
		if (checkSinhVien(ds[i], type, s) == 1)
		{
			ds2.push_back(ds[i]);
			++dem;
		}
	}

	if (dem == 0)
	{
		khongTimThay();
	}
	else
	{
		printSearch(ds2, dem, type, s);
	}
}

//==================TIM KIEM NHI PHAN=================

// ham tim kiem nhi phan theo type

void timKiemNP(vector<SinhVien> ds, int n, int type)
{
	clrscr(8);
	TextColor(6);
	gotoXY(30, 10);
	cout << "Nhap tu khoa can tim: ";
	string keyword;
	if (type == 2)
	{
		fflush(stdin);
		getline(cin, keyword);
	}
	else
	{
		cin >> keyword;
	}
	cout << keyword;
	//Cần xử lý keyword tìm kiếm với ngày sinh
	//Cách xử lý của tao là tạo một đối tượng mới chỉ 
	//có thuộc tính cần so sánh
	//rồi so sánh để tìm đối tượng đó

	TreeNode *svtemp;
	switch(type){
		case 0: {
			SinhVien a(keyword,"","","",0);
			svtemp = newTreeNode(a);
			break;
		}
		case 1:{ 
			SinhVien a("",keyword,"","",0);
			svtemp = newTreeNode(a);
			break;
		}
		case 2:{ //tim theo ten
			SinhVien a("","",keyword,"",0);
			svtemp = newTreeNode(a);
			break;
		}
		case 3:{ // tim theo ngay sinh (xu ly ngay sinh)
			SinhVien a("","","",keyword,0);
			svtemp = newTreeNode(a);
			break;
		}
		case 4 :{ // tim theo diemtb (can xu ly tiep)
			SinhVien a(keyword,"","","",0);
			svtemp = newTreeNode(a);
			break;
		}
		default:
			break;
	}

	ds = sapXepNhanh(ds, type, 0, n);
	int count = 0;
	TreeNode *root;
	TreeNode *temp = root;
	for(int i = 0; i < ds.size(); i++){
		temp = Insert(temp,ds[i],type);
	}

	SinhVien k;
	k = SearchTree(root, svtemp, keyword, type);
	// root : tree ban đầu , svtemp là đối tượng chứa thuộc tính cần so sánh, s : key word

	cout << k;

	if (count == 0)
	{
		// khongTimThay();
	}
	else
	{
		// printSearch(dsNP, count, type, s);
	}
}

//====================CAC HAM HO TRO TIM KIEM===============

// ham hien thi khi khong tim thay theo yeu cau
void khongTimThay()
{
	clrscr(8);
	gotoXY(35, 10);
	TextColor(4);
	cout << "Khong tim thay sinh vien theo yeu cau!";
}

// ham in chu o giua khung
void rawTextDemo(int x, int y, int size[], string data[])
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	for (int i = 0; i < 6; i++)
	{
		int length = (size[i + 1] - size[i] + 1);
		gotoXY(x + size[i] + length / 2 - data[i].length() / 2, y + 1);
		cout << data[i];
	}
}

// ham in mau chu tim kiem
void rawTextColor(int x, int y, int size[], string data, int vt, string key, int type)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 96);

	low(key);
	int length = (size[vt + 1] - size[vt] + 1);
	int X = x + size[vt] + length / 2 - data.length() / 2;
	int Y = y + 1;
	size_t found = (low2(data)).find(key);

	while (found != string::npos)
	{
		string KQ = data.substr(found, key.length());
		gotoXY(X + found, Y);
		cout << KQ;
		found = (data).find(key, found + 1);
	}
	SetConsoleTextAttribute(hConsole, 15);
}

// in mau cho string tim thay trong sinh vien sd vector
void rawSV_mau(int x, int y, int size[], SinhVien data, int vt, int loai, string key)
{

	low(key);
	string bang[6];
	bang[0] = coverIntToString(vt + 1, 3);
	bang[1] = data.maLop;
	bang[2] = data.maSV;
	bang[3] = data.hoTen;
	bang[4] = data.ngaySinh;
	bang[5] = floatToString(data.diemTB);
	rawTextDemo(x, y, size, bang);
	rawTextColor(x, y, size, bang[loai + 1], loai + 1, key, loai);
	// y += vt*2;
}

// kiem tra sinh vien co tim thay du lieu string s can tim hay khong
bool checkSinhVien(SinhVien data, int type, string s)
{
	low(s);
	switch (type)
	{
	case 0:
	{
		// ma lop
		low(data.maLop);
		size_t found = data.maLop.find(s);
		if (found == string::npos)
			return 0;
		return 1;
		break;
	}
	case 1:
	{
		// ma sinh vien
		low(data.maSV);
		size_t found = data.maSV.find(s);
		if (found == string::npos)
			return 0;
		return 1;
		break;
	}
	case 2:
	{
		// hoten
		low(data.hoTen);
		size_t found = data.hoTen.find(s);
		if (found == string::npos)
			return 0;
		return 1;
		break;
	}
	case 3:
	{
		// ngay sinh
		size_t found = data.ngaySinh.find(s);
		if (found == string::npos)
			return 0;
		return 1;
		break;
	}
	case 4:
	{
		string x = floatToString(data.diemTB);
		size_t found = x.find(s);
		if (found == string::npos)
			return 0;
		return 1;
		break;
	}
	}
}

// in ds tim kiem sd vector
void printSearch(vector<SinhVien> ds2, int count, int type, string s)
{
	clrscr(8);
	gotoXY(45, 10);
	TextColor(6);
	cout << "DANH SACH SINH VIEN TIM KIEM";
	TextColor(7);
	khungDS(8, 12, 2, count);

	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);

	for (int i = 0; i < count; i++)
	{
		rawSV_mau(8, 14 + i * 2, SIZE_BANG, ds2[i], i, type, s);
	}
}

// in ds tim kiem sd cau truc cay nhi phan
void printSearch(Node *t, int count, int type, string s)
{
	if (t == NULL)
	{
		khongTimThay();
		return;
	}
	clrscr(8);
	gotoXY(45, 10);
	TextColor(6);
	cout << "DANH SACH SINH VIEN TIM KIEM";
	TextColor(7);
	khungDS(8, 12, 2, count);

	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);

	Node *temp = t;
	if (temp != NULL)
	{
		for (int i = 0; i < count; i++)
		{
			rawSV_mau(8, 14 + i * 2, SIZE_BANG, temp->data, i, type, s);
			temp = temp->next;
		}
	}
}

// ham chuyen cac chu cai thanh in thuong, tra ve string
string low2(string x)
{
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] >= 'A' && x[i] <= 'Z')
			x[i] = x[i] + 32;
	}
	return x;
}

//------------------SU DUNG STRUCT TIM KIEM NHI PHAN--------------------

Node *newNode(SinhVien sv)
{
	Node *temp = new Node();
	temp->data = sv;
	temp->next = NULL;
	return temp;
}

TreeNode *newTreeNode(SinhVien sv)
{
	TreeNode *temp = new TreeNode();
	temp->data = sv;
	temp->left = temp->right = NULL;
	return temp;
}

// them sv vao list node t
void add(SinhVien sv, Node *t)
{
	Node *p = new Node;
	p->data = sv;
	p->next = NULL;
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		t->next = p;
	}
}

// them data vao cay
//  nho hon them vao trai
//  lon hon hoac bang them vao phai
TreeNode *Insert(TreeNode *t, SinhVien data, int type)
{

	if (t == NULL)
		return newTreeNode(data); // neu tree rong ra ve node moi

	if (soSanh(t->data, data, type) == -1)
		t->left = Insert(t->left, data, type);
	else
	{
		t->right = Insert(t->right, data, type);
	}
	return t;
}

int Search(SinhVien sv, string s, int type)
{
	int check = checkSinhVien(sv, type, s);
	switch (type)
	{
	case 0:
	{
		// ma lop
		if (check == 1)
		{
			return 10;
		}
		low(sv.maLop);
		return soSanhChuoi(sv.maLop, s);
		break;
	}
	case 1:
	{
		// ma sinh vien
		if (check == 1)
		{
			return 10;
		}
		low(sv.maSV);
		return soSanhChuoi(sv.maSV, s);
		break;
	}
	case 2:
	{
		// hoten
		if (check == 1)
		{
			return 10;
		}
		low(sv.hoTen);
		return soSanhTen(sv.hoTen, s);
		break;
	}
	case 3:
	{
		// ngay sinh
		if (check == 1)
		{
			return 10;
		}
		return soSanhNgaySinh(sv.ngaySinh, s);
		break;
	}
	case 4:
	{
		if (check == 1)
		{
			return 10;
		}
		return soSanhChuoi(floatToString(sv.diemTB), s);
		break;
	}
	}
}


int LeftOf(TreeNode *value, TreeNode *root, int type)
{
	return soSanh(root->data, value->data,type) == -1;
}

int RightOf(TreeNode *value, TreeNode *root, int type)
{
	return soSanh(root->data, value->data,type) != -1;
}

// search cay nhi phan tim kiem
SinhVien SearchTree(TreeNode *root,TreeNode *value,  string s, int type)
{
	if (root == NULL)
		return root->data;
	// Node *temp = newNode(root->data);
	// int ss = Search(temp->data, s, type);
	// if (ss == 10)
	// {
	// 	add(root->data,dsNP);
	// 	++count;
	// }
	// if (ss == -1){
	// 	return SearchTree(root->left,dsNP, s, type, count);
	// }else if (ss == 1){
	// 	return SearchTree(root->right,dsNP,s, type, count);
	// }

	if (soSanh(root->data, value->data,type) == 0)
	{
		return root->data;
	}
	else if (LeftOf(value, root, type))
	{
		return SearchTree(root->left, value ,s, type);
	}
	else if (RightOf(value, root, type))
	{
		return SearchTree(root->right, value , s,type);
	}
}
