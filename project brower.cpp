#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <ctime>
#include <conio.h>
#define chieu_dai 171
#define chieu_rong 50
using namespace std;
string s;	// toan cuc // bien de tim kiem 
int soTab = 0;
int m = 1,n=1;
int m2 = 1; // newwindow
int n2 = 47;//newwindow
string history[50] = ""; // luu lich su tim kiem
string UaThich [50];//luu ua thich
int ut = 0; //so luong ua thich da luu
int k = 0;			// so luong lich su da luu < 50 
string thoiGian[50] = "";//Mang luu tgian 
int A[100];//chua gia tri cua thanh tab
int l = 0;// vi tri gia tri cua thanh tab
int i = 1;
int A1[100];//chua gia tri cua newwindow
int i1 = 1;
int l1 = 0;// vi tri gia tri cua newwindow
void SetScreenBufferSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD NewSize;
    NewSize.X = width;
    NewSize.Y = height;

    SetConsoleScreenBufferSize(hStdout, NewSize);
}
void resizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void TextColor(int x)
{
    HANDLE mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau,x);
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
string trichXuatTime()
{
	time_t now = time(0); 
	string dt = ctime(&now); 
    return dt; 
} 
struct Node 
{
	string data;
	int solieu;
	Node *next;
};
struct LStack
{
	Node *head;
};
struct LStack2
{
	Node *top;
};
struct dataOfTab
{
	LStack stack1;
	LStack2 stack2;
	int index;
	int index2;
};
dataOfTab Tab[20]; 
struct dataOfNewWindow
{
	dataOfTab Tab[20];	
	int soTab;
	int so_i;
	int so_l;
};
dataOfNewWindow NewW[20]; 
void khoiTao(LStack &l)
{
	l.head = NULL;
}
void khoiTaoStack2 (LStack2 &q)
{
	q.top = NULL;
}
Node *taoNodeMoi (string s, int a)
{
	Node *p = new Node;
	p -> next = NULL;
	p -> data = s;
	p -> solieu = a; 
	return p;
}
void push (LStack &l, string s,int a)
{
	Node *p = taoNodeMoi (s,a);
	if (l.head == NULL)
	{
		l.head = p;
	}
	else
	{
		p -> next = l.head;
		l.head = p;
	}
}
Node* pop (LStack &l)
{
	if (l.head == NULL)
		return NULL;
	else
	{
		Node *p = l.head;
		l.head = p -> next;
		p -> next = NULL;
		return p;
	}
}
void pushStack2 (LStack2 &q, Node *p)
{
	if (q.top == NULL)
	{
		q.top = p;
	}
	else
	{
		p -> next = q.top;
		q.top = p;
	}
}
Node* popStack2 (LStack2 &q)
{
	if (q.top == NULL)
		return NULL;
	else
	{
		Node *p = q.top;
		q.top = p -> next;
		p -> next = NULL;
		return p;
	}	
}
void chuanHoa(string &x)
{
    int n = x.length();
//Xoa space
    for(int i = 0 ; i < n ; i++)
	{
        if(x[i]==' ')
		{
            for(int j = i+1 ; i < n ; j++)
            {
            	x[j-1] = x[j]; 
			}
        }
        else break;
    }
//viet hoa -> viet thuong 
    for(int i = 0 ; i < n ; i++)
    {
    	if(x[i] >= 'A' && x[i] <= 'Z')
			x[i] += 32; 
	}
 
}
bool kiemTraChuoiCon(string x,string y)
{
	int m = x.length();
    int n = y.length();

    for (int i = 0; i <= n - m; i++) 
	{
        int j;
        for (j = 0; j < m; j++) 
		{
            if (y[i + j] != x[j])
			{
                break;
            }
        }
        if (j == m)
		{
            return true;
        }
    }
    return false;
}
void dungKhung()
{
	//tao goc trai khung tren
	cout << char (201);
	int x;
	//tao hang ngang khung tren
	for(int x=0;x<chieu_dai-1;x++)
		cout << char(205);
	// tao goc phai khung tren
	cout << char (187);
	// tao hai ben chieu doc
	for(x=0;x < chieu_rong -1 ;x++)
	{
		
		if (x == 3 || x == 5)
		{
			cout << char (204);
			for(int y=0;y<chieu_dai-1;y++)
			{
				if ((y == 12 &&  x == 3)|| (y == 130 && x == 3) || (y == 150 && x == 3))
					cout << char (203);
				else if ((y == 12 && x == 5) || (y == 130 && x == 5)|| (y == 150 && x == 5))
					cout << char (202);
				else
					cout << char(205);
			}
			cout << char(185);
		}
		else
		{
			gotoxy(0,x+1);
			cout << char(186);
			gotoxy(chieu_dai,x+1);
			cout <<char(186);
		}
		
	}

	// tao goc trai khung duoi
	cout << char(200);
	// tao thanh ngang khung duoi
	for(x=0;x<chieu_dai-1;x++)
		cout <<char(205);
	// tao goc phai khung duoi
	cout << char (188);
	gotoxy (3,5);
	cout << char (17);
	gotoxy (6,5);
	cout << char (16);
	gotoxy (9,5);
	cout << char (2);
	gotoxy(13,5);
	cout <<char(186); 
	// cong cu lua chon newwindow
	gotoxy (163,1);
	cout << char(5);	
	gotoxy (166,1);
	cout << char (4);
	gotoxy (129,5);
	cout << "*";
	gotoxy(131,5);
	cout <<char(186);  
	gotoxy(151,5);
	cout << char (186);
	int m = 50; 
	int n = 15;
	gotoxy (m,n++);                                                                          
    cout <<                  "   :@MMMMMMMMC                                    MM.          " << endl;                                    
    gotoxy (m,n++); 
	cout <<                  "  WMMi     .0:                                    MM           " << endl;                                   
    gotoxy (m,n++); 
	cout <<                  " $M9                 ..                    ..     MM     ..    "<< endl;                               
    gotoxy (m,n++); 
	cout <<                  ".MM      :......  iMMMMMMv   .CbI66n,   ,MMMMM$MU @M  .MMMMM$  "<<endl;                             
    gotoxy (m,n++); 
	cout <<                  ":MM     vMMMMMMM tMM.  .MMA :Z1    7b: 7MM.  .MM9 @M .MM   bMM,"<<endl;                           
    gotoxy (m,n++); 
	cout <<                  " MMv         ,M$ MM      MM XA      zS MM      Mz @M BMtYMM$;. " <<endl;                          
    gotoxy (m,n++); 
	cout <<                  "  MMA       :MM  MMi    iMM c6.     6C $M;    ;M2 @M CMMc      " << endl;                          
    gotoxy (m,n++); 
	cout <<                  "   9MMMWZQ@MM$    MMMZ6MMM   tZniiCb1   #M@Uz@MM2 MM  WM#CC@MM " << endl;                          
    gotoxy (m,n++); 
	cout <<                  "     ,2W#$Z;       ,E@@E:     .i7Y;.      CEQ,:Mb YS   .6#@Wv  "<<endl;                           
    gotoxy (m,n++); 
	cout <<                  "                                      ,MA    BM:               " << endl;                           
    gotoxy (m,n++); 
	cout <<                  "                                        ZMMMMMMi               "  << endl;                          
    gotoxy (m,n++); 
	cout <<                  "                                           :,.                 " << endl;
	//tao goc trai khung tren
	gotoxy (40,27);
	cout << char (201);
	//tao hang ngang khung tren
	for(int x=0;x<85-1;x++)
		cout << char(205);
	// tao goc phai khung tren
	cout << char (187);
	// tao hai ben chieu doc
	for(int x = 27;x < 30 -1 ;x++)
	{
		gotoxy(40,x+1);
		cout << char(186);
		gotoxy(125,x+1);
		cout <<char(186);
	}
	// tao goc trai khung duoi
	gotoxy(40,30);
	cout << char(200);
	// tao thanh ngang khung duoi
	for(int x=0;x<85-1;x++)
		cout <<char(205);
	// tao goc phai khung duoi
	cout << char (188);
	// phan newWidow
	gotoxy (0,chieu_rong - 4);
	cout << char (204);
	for (int x = 0; x < chieu_dai - 1; x++)
		cout << char (205);
	gotoxy(chieu_dai,chieu_rong - 4);
	cout << char(185);
	// phan thanh cong cu
	gotoxy (41,28);
	cout << "Search: ";
	gotoxy (15,5);
	cout << "Search URL: ";
	gotoxy (169,1);
	cout << "X" ;
	
	gotoxy(137,5);
	cout <<"HISTORY";  
	gotoxy(157,5);
	cout <<"BOOKMARK";
		
}
void dungKhungMoi()
{
	//tao goc trai khung tren
	cout << char (201);
	int x;
	//tao hang ngang khung tren
	for(int x=0;x<chieu_dai-1;x++)
		cout << char(205);
	// tao goc phai khung tren
	cout << char (187);
	// tao hai ben chieu doc
	for(x=0;x < chieu_rong -1 ;x++)
	{
		
		if (x == 3 || x == 5)
		{
			cout << char (204);
			for(int y=0;y<chieu_dai-1;y++)
			{
				if ((y == 12 &&  x == 3)|| (y == 130 && x == 3) || (y == 150 && x == 3))
					cout << char (203);
				else if ((y == 12 && x == 5) || (y == 130 && x == 5)||(y == 150 && x == 5))
					cout << char (202);
				else
					cout << char(205);
			}
			cout << char(185);
		}
		else
		{
			gotoxy(0,x+1);
			cout << char(186);
			gotoxy(chieu_dai,x+1);
			cout <<char(186);
		}	
	}
	// tao goc trai khung duoi
	cout << char(200);
	// tao thanh ngang khung duoi
	for(x=0;x<chieu_dai-1;x++)
		cout <<char(205);
	// tao goc phai khung duoi
	cout << char (188);
	gotoxy (3,5);
	cout << char (17);
	gotoxy (6,5);
	cout << char (16);
	gotoxy (9,5);
	cout << char (2);
	gotoxy(13,5);
	cout <<char(186); 
	gotoxy (166,1);
	cout << char (4);
	// cong cu lua chon newwindow
	gotoxy (163,1);
	cout << char(5);
	gotoxy (129,5);
	cout << "*";
	gotoxy(131,5);
	cout <<char(186);  
	gotoxy(151,5);
	cout << char (186);
	//tao goc trai khung tren
	gotoxy (40,8);
	cout << char (201);
	//tao hang ngang khung tren
	for(int x=0;x<85-1;x++)
		cout << char(205);
	// tao goc phai khung tren
	cout << char (187);
	// tao hai ben chieu doc
	for(int x = 8;x < 10 -1 ;x++)
	{
		gotoxy(40,x+1);
		cout << char(186);
		gotoxy(125,x+1);
		cout <<char(186);
	}
	// tao goc trai khung duoi
	gotoxy(40,10);
	cout << char(200);
	// tao thanh ngang khung duoi
	for(int x=0;x<85-1;x++)
		cout <<char(205);
	// tao goc phai khung duoi
	cout << char (188);
	gotoxy (0,chieu_rong - 4);
	cout << char (204);
	for (int x = 0; x < chieu_dai - 1; x++)
		cout << char (205);
	gotoxy(chieu_dai,chieu_rong - 4);
	cout << char(185);
	// phan thanh cong cu
	
	gotoxy (15,5);
	cout << "Search URL: ";
	gotoxy (169,1);
	cout << "X" ;
	gotoxy(137,5);
	cout <<"HISTORY";  
	gotoxy(157,5);
	cout <<"BOOKMARK";
	// khung cua select
	gotoxy (73,12);
	cout << char (201);
	for(int x=0;x<12;x++)
		cout << char(205);
	cout << char (187);
	for(int x = 12 ;x < 14 -1 ;x++)
	{
		gotoxy(73,x+1);
		cout << char(186);
		gotoxy(86,x+1);
		cout <<char(186);
	}
	gotoxy(73,14);
	cout << char(200);
	for(int x=0;x<12;x++)
		cout <<char(205);
	cout << char (188);
	gotoxy (77,13);
	cout << "SELECT";		
}
void dungKhungMoi1()
{
	//tao goc trai khung tren
	cout << char (201);
	int x;
	//tao hang ngang khung tren
	for(int x=0;x<chieu_dai-1;x++)
		cout << char(205);
	// tao goc phai khung tren
	cout << char (187);
	// tao hai ben chieu doc
	for(x=0;x < chieu_rong -1 ;x++)
	{
		
		if (x == 3 || x == 5)
		{
			cout << char (204);
			for(int y=0;y<chieu_dai-1;y++)
			{
				if ((y == 12 &&  x == 3)|| (y == 130 && x == 3) || (y == 150 && x == 3))
					cout << char (203);
				else if ((y == 12 && x == 5) || (y == 130 && x == 5)||(y == 150 && x == 5))
					cout << char (202);
				else
					cout << char(205);
			}
			cout << char(185);
		}
		else
		{
			gotoxy(0,x+1);
			cout << char(186);
			gotoxy(chieu_dai,x+1);
			cout <<char(186);
		}
		
	}

	// tao goc trai khung duoi
	cout << char(200);
	// tao thanh ngang khung duoi
	for(x=0;x<chieu_dai-1;x++)
		cout <<char(205);
	// tao goc phai khung duoi
	cout << char (188);
	// phan newWidow
	gotoxy (0,chieu_rong - 4);
	cout << char (204);
	for (int x = 0; x < chieu_dai - 1; x++)
		cout << char (205);
	gotoxy(chieu_dai,chieu_rong - 4);
	cout << char(185);
	// phan thanh cong cu
	
	gotoxy (3,5);
	cout << char (17);
	gotoxy (6,5);
	cout << char (16);
	gotoxy (9,5);
	cout << char (2);
	gotoxy(13,5);
	cout <<char(186); 
	gotoxy (166,1);
	cout << char (4);
	// cong cu lua chon newwindow
	gotoxy (163,1);
	cout << char(5);
	gotoxy (129,5);
	cout << "*";
	gotoxy(131,5);
	cout <<char(186);  
	gotoxy(151,5);
	cout << char (186);
	gotoxy (15,5);
	cout << "Search URL: ";
	gotoxy (169,1);
	cout << "X" ;
	gotoxy(137,5);
	cout <<"HISTORY";  
	gotoxy(157,5);
	cout <<"BOOKMARK";
}
void taoBangBookMark()
{
	gotoxy (151,7);
	cout << char (201);
	for(int x=0;x<18;x++)
		cout << char(205);
	cout << char (187);
	for(int x = 7 ;x < 16 ;x++)
	{
		gotoxy(151,x+1);
		cout << char(186);
		gotoxy(170,x+1);
		cout <<char(186);
	}
	gotoxy(151,16);
	cout << char(200);
	for(int x=0;x<18;x++)
		cout <<char(205);
	cout << char (188);
	gotoxy (152,9);
	for(int x=0;x<18;x++)
		cout <<char(205);
	gotoxy (158,8);
	cout <<"Select";
	int m = 10;			
	for (int i = 0; i <= ut; i++)
	{
		gotoxy(155,m);
		cout << UaThich[i] << endl;
		m++;
	}
}
void deleteNewWindow(int &l,int A[],int &b,int &a,int f,int &i) 
{
	//1.doi giao dien cua tab  
	int max_x = m2 - 7;
	int max_i = i-2;
	i = 1;
	m2 = 1;
	n2 = 47; 
	int t = A[b-2]; 
	//system("cls"); 
	//cout<<b;  
	while(m <= max_x && i <= max_i)
	{
		//dung khung de len tab da xoa
			gotoxy(m2, n2);
			cout << char(201);
			int x;
			for (x = 0; x < 5; x++)
				cout << char(205);
			cout << char(187);
			gotoxy(m2, n2 + 1);
			cout << char(186);
			for (x = 0; x < 5; x++)
			    cout << char(32);
			cout << char(186);
			gotoxy(m2, n2 + 2);
			cout << char(200);
			for (x = 0; x < 5; x++)
			    cout << char(205);
			cout << char(188);
			gotoxy(m2+2,n2+1);
		    cout <<"G";
		    	// tao dau cong them tab
 			gotoxy(m2 + 7, n2);
			cout << char(201);
			for (x = 0; x < 3; x++)
				cout << char(205);
			cout << char(187);
			gotoxy(m2 + 7, n2 + 1);
			cout << char(186);
			for (x = 0; x < 3; x++)
				cout << char(32);
			cout << char(186);
			gotoxy(m2+7, n2 + 2);
			cout << char(200);
			for (x = 0; x < 3; x++)
				cout << char(205);
			cout << char(188);
			gotoxy(m2+4,n2+1);
			cout << "x";
			
			gotoxy(m2+9,n2+1);
			cout << "+";
			m2 += 7;
			i++;
	}
			gotoxy(m2, n2);
			cout << " ";
			int x;
			for (x = 0; x < 5; x++)
				cout << " ";
			cout << " ";
			gotoxy(m2, n2 + 1);
			cout << " ";
			for (x = 0; x < 5; x++)
			    cout << " ";
			cout << " ";
			gotoxy(m2, n2 + 2);
			cout << " ";
			for (x = 0; x < 5; x++)
			    cout << " ";
			cout << " ";
			gotoxy(m2+2,n2+1);
		    cout <<" ";
		    	 //tao dau cong them tab
		    m2-=7;
		    gotoxy(m2 + 7, n2);
			cout << char(201);
			for (x = 0; x < 3; x++)
				cout << char(205);
			cout << char(187);
			gotoxy(m2 + 7, n2 + 1);
			cout << char(186);
			for (x = 0; x < 3; x++)
				cout << char(32);
			cout << char(186);
			gotoxy(m2+7, n2 + 2);
			cout << char(200);
			for (x = 0; x < 3; x++)
				cout << char(205);
			cout << char(188);
			gotoxy(m2+4,n2+1);
			cout << "x";
			
			gotoxy(m2+9,n2+1);
			cout << "+";
			i++;// loi cho nay
		// xoa khung dau + phia sau
		m2 += 7;
	    gotoxy(m2 + 7, n2);
		cout << " ";
		for (x = 0; x < 3; x++)
			cout << " ";
		cout << " ";
		gotoxy(m2 + 7, n2 + 1);
		cout << " ";
		for (x = 0; x < 3; x++)
			cout << " ";
		cout << " ";
		gotoxy(m2+7, n2 + 2);
		cout <<" ";
		for (x = 0; x < 3; x++)
			cout << " ";
		cout << " ";
//		gotoxy (m+4,n+1);
//		cout << " ";
		i--;
	// xoa giua 
	l = l - 2;// fix loi 
	A[l-1] = 0;
	// xoa cuoi bi loi
	if(max_i == i)
	{
		A[l-2] = i;
		A[l-1] = -1;
		A[l] = 0;
	}
//	2.doi data cua tab
	for(int j = b/2 ; j < max_i - 1;j++) 
	{
		Tab[j] = Tab[j+1]; 
	}
	a = 4;
	b = 0;
	gotoxy(0,20);
}
void deleteTab(int &l,int A[],int &b,int &a,int f,int &i) 
{
	//1.doi giao dien cua tab  
	int max_x = m - 12;
	int max_i = i-2;
	int k = i;//gioi han xoa
	// vi tri xoa
	i = 1;
	m = 1;
	n = 1; 
	int t = A[b-2];
	while(m <= max_x && i <= max_i)
	{
		//dung khung de len tab da xoa
		gotoxy(m, n);
		cout << char(201);
		int x;
		for (x = 0; x < 10; x++)
			cout << char(205);
		cout << char(187);
		gotoxy(m, n + 1);
			cout << char(186);
		for (x = 0; x < 10; x++)
		    cout << char(32);
		cout << char(186);
		gotoxy(m, n + 2);
		cout << char(200);
		for (x = 0; x < 10; x++)
		   cout << char(205);
		cout << char(188);
		gotoxy (m+2,n+1);
		cout << "Tab: "<<i;
		// tao dau cong them tab
	    gotoxy(m + 12, n);
		cout << char(201);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(187);
		gotoxy(m + 12, n + 1);
		cout << char(186);
		for (x = 0; x < 3; x++)
			cout << char(32);
		cout << char(186);
		gotoxy(m+12, n + 2);
		cout << char(200);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(188);
		gotoxy (m+9,n+1);
		cout << "x";
				
		gotoxy (m+14,n+1);
		cout << "+";
		i++;// loi cho nay
		m += 12;
	}
	// thay system cls
			//dung khung de len tab da xoa
		gotoxy(m, n);
		cout << " ";
		int x;
		for (x = 0; x < 10; x++)
			cout << " ";
		cout << " ";
		gotoxy(m, n + 1);
			cout << " ";
		for (x = 0; x < 10; x++)
		    cout << " ";
		cout << " ";
		gotoxy(m, n + 2);
		cout << " ";
		for (x = 0; x < 10; x++)
		   cout << " ";
		cout << " ";
		gotoxy (m+2,n+1);
		cout << "      ";
		// tao dau cong them tab
		m-=12;
	    gotoxy(m + 12, n);
		cout << char(201);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(187);
		gotoxy(m + 12, n + 1);
		cout << char(186);
		for (x = 0; x < 3; x++)
			cout << char(32);
		cout << char(186);
		gotoxy(m+12, n + 2);
		cout << char(200);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(188);
		gotoxy (m+9,n+1);
		cout << "x";
				
		gotoxy (m+14,n+1);
		cout << "+";
		i++;// loi cho nay
		// xoa khung dau + phia sau
		m += 12;
	    gotoxy(m + 12, n);
		cout << " ";
		for (x = 0; x < 3; x++)
			cout << " ";
		cout << " ";
		gotoxy(m + 12, n + 1);
		cout << " ";
		for (x = 0; x < 3; x++)
			cout << " ";
		cout << " ";
		gotoxy(m+12, n + 2);
		cout <<" ";
		for (x = 0; x < 3; x++)
			cout << " ";
		cout << " ";
		gotoxy (m+9,n+1);
		cout << " ";
		i--;
	// xoa giua 
	l = l - 2;// fix loi 
	A[l-1] = 0;
	// xoa cuoi bi loi
	if(max_i == i)
	{
		A[l-2] = i;
		A[l-1] = -1;
		A[l] = 0;
	}
//	2.doi data cua tab
		for(int j = t ; j < k;j++) 
		{
			Tab[j] = Tab[j+1]; 
		}
	
	a = 4;
	b = 0;
	gotoxy(0,20);
}
int khungTab()
{
	//dungKhung();
	bool c = true;
	char d;
	bool g = true;
	int m1 = 1;
	int n1 = 1;
	int k = 1;
	gotoxy(0,22);
	while (c)
	{
		gotoxy(0,20);
		if (g)
		{
			gotoxy(m, n);
			cout << char(201);
			int x;
			for (x = 0; x < 10; x++)
				cout << char(205);
			cout << char(187);
			gotoxy(m, n + 1);
			cout << char(186);
			for (x = 0; x < 10; x++)
			    cout << char(32);
			cout << char(186);
			gotoxy(m, n + 2);
			cout << char(200);
			for (x = 0; x < 10; x++)
			    cout << char(205);
			cout << char(188);
			gotoxy (m+2,n+1);
		    cout << "Tab: "<<i;
		    // tao dau cong them tab
		    gotoxy(m + 12, n);
			cout << char(201);
			for (x = 0; x < 3; x++)
				cout << char(205);
			cout << char(187);
			gotoxy(m + 12, n + 1);
			cout << char(186);
			for (x = 0; x < 3; x++)
				cout << char(32);
			cout << char(186);
			gotoxy(m+12, n + 2);
			cout << char(200);
			for (x = 0; x < 3; x++)
				cout << char(205);
			cout << char(188);
			gotoxy (m+9,n+1);
			cout << "x";
			
			gotoxy (m+14,n+1);
			cout << "+";
			m += 12;
			A[l] = i;
			l ++;
			A[l] = -1;
			l ++;
			A[l] = 0;
			l++;
			i++;
			//
			gotoxy(0,20);
		}
		if (i != 0)
		{
			bool e = true;
			int a = 4;
			int b = 0;
			int f = 2;
			while (e == true)
			{
				TextColor(7);
				d = getch();
				if (d == 80 ||d == 's'||d =='S'||d =='2')
				{
					if (b < l)
					{
						if (A[b] == -1)
						{
							TextColor(202);
							gotoxy (a-6,f);
							cout << "x";
							TextColor(7);
						}
						
						else if (A[b] == 0)
						{
							TextColor(202);
							gotoxy (a-13,f);
							cout << "+";
							TextColor(7);
						}
	
						else
						{
							if(A[b] == 1)
							{
								TextColor(202);
								gotoxy(a-1,f);
								cout <<"Tab: "<<  A[b] << endl;
							}
							else
							{
								TextColor(202);
								gotoxy(a-13,f);
								cout <<"Tab: "<<  A[b] << endl;
								a = a - 12;
							}
						
						}	
						if (a >= 5)
						{
							if(A[b-1] == -1)
							{
								if (A[b] == 2 || A[b] == 3 || A[b] == 4 || A[b] == 5||A[b] == 6 || A[b] == 7 || A[b] == 8 || A[b] == 9||A[b]==10 || A[b]== 11 || A[b] == 12)
								{
									TextColor(7);
									gotoxy(a - 6,f);
									cout <<"x" << endl;
								}
								else
								{
									TextColor(7);
									gotoxy(a - 18,f);
									cout <<"x" << endl;
								}
								
								
							}
							else
							{
								TextColor(7);
								gotoxy(a - 13,f);
								cout <<"Tab: "<< A[b - 1] << endl;
							}
							
						}
						a = a + 12;
						b++;
					}
				}			
				else if (d == 72 || d == 'w'||d == 'W'||d == '8')
				{
					
					a = a - 12;
					b --;
					if (a >= 0 && b > 0)
					{
						if (A[b] == -1)
						{
							TextColor(7);
							gotoxy(a-6,f);
							cout << "x";
						}
						else if (A[b] == 0)
						{
							TextColor(7);
							gotoxy(a-13,f);
							cout << "+";
						}
						else
						{
							if(A[b] == 2| A[b] == 3 || A[b] == 4 || A[b] == 5||A[b] == 6 || A[b] == 7 || A[b] == 8 || A[b] == 9||A[b]==10 || A[b]== 11 || A[b] == 12)
							{
								TextColor(7);
								gotoxy(a-1,f);
								cout <<"Tab: "<<  A[b] << endl;
								a = a + 12;
							}
							else
							{
								TextColor(7);
								gotoxy(a-13,f);
								cout <<"Tab: "<<  A[b] << endl;
								a = a + 12;
							}
						}
						if(A[b-1] == -1)
						{
							TextColor(202);
							gotoxy(a - 18,f);
							cout <<"x" << endl;
						}
						else
						{
							TextColor(202);
							gotoxy(a - 13,f);
							cout <<"Tab: " << A[b-1] << endl;
						}
					}
					else
					{
						a = a + 12;
						b ++;
					}
					
				}
				else if (d == 13 ||d =='e'||a=='E' ||d =='5')
				{
					if (A[b-1] == 0)
					{
						e = false;
						g = true;
						l = l - 1;
					}
					else if(A[b-1] == -1)
					{
						deleteTab(l,A,b,a,f,i);
						if(i == 1);			
						{
							///// deleteNewWindow(l1,A1,b,a,f,i1);	
							// xoay lai tiep tuc lua chon new Window				
						}
					}
					else
					{
						gotoxy (0,20);
						return A[b-1];
						g = false;
						e = false;
					}		
						
				}
			}
		}
		else 
			c = false;
	}
} 
void khungTabMoi()
{
	//dungKhungMoi();
	bool c = true;
	char d;
	bool g = true;
	int m1 = 1;
	int n1 = 1;
	int k = 1;
	int j = 0;
	gotoxy(0,20);
	while (m1 <= m - 12)
	{
		gotoxy(m1, n1);
		cout << char(201);
		int x;
		for (x = 0; x < 10; x++)
			cout << char(205);
		cout << char(187);
		gotoxy(m1, n1 + 1);
		cout << char(186);
		for (x = 0; x < 10; x++)
			cout << char(32);
		cout << char(186);
		gotoxy(m1, n1 + 2);
		cout << char(200);
		for (x = 0; x < 10; x++)
			cout << char(205);
		cout << char(188);
		gotoxy (m1+2,n1+1);
		cout << "Tab: "<<k;
		// tao dau cong them tab
		gotoxy(m1 + 12, n1);
		cout << char(201);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(187);
		gotoxy(m1 + 12, n1 + 1);
		cout << char(186);
		for (x = 0; x < 3; x++)
			cout << char(32);
		cout << char(186);
		gotoxy(m1+12, n1 + 2);
		cout << char(200);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(188);
		gotoxy (m1+9,n1+1);
		cout << "x";	
		gotoxy (m1+14,n1+1);
		cout << "+";
		m1 += 12;
		k++;
		//
		gotoxy(0,20);
	}
}
void khungTabMoi2()
{
	//dungKhung();
	bool c = true;
	char d;
	bool g = true;
	int m1 = 1;
	int n1 = 1;
	int k = 1;
	int j = 0;
	gotoxy(0,20);
	while (m1 <= m - 12)
	{
		gotoxy(m1, n1);
		cout << char(201);
		int x;
		for (x = 0; x < 10; x++)
			cout << char(205);
		cout << char(187);
		gotoxy(m1, n1 + 1);
		cout << char(186);
		for (x = 0; x < 10; x++)
			cout << char(32);
		cout << char(186);
		gotoxy(m1, n1 + 2);
		cout << char(200);
		for (x = 0; x < 10; x++)
			cout << char(205);
		cout << char(188);
		gotoxy (m1+2,n1+1);
		cout << "Tab: "<<k;
		// tao dau cong them tab
		gotoxy(m1 + 12, n1);
		cout << char(201);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(187);
		gotoxy(m1 + 12, n1 + 1);
		cout << char(186);
		for (x = 0; x < 3; x++)
			cout << char(32);
		cout << char(186);
		gotoxy(m1+12, n1 + 2);
		cout << char(200);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(188);
		gotoxy (m1+9,n1+1);
		cout << "x";	
		gotoxy (m1+14,n1+1);
		cout << "+";
		m1 += 12;
		k++;
		//
		gotoxy(0,20);
	}
}
int khungTabMoi3()
{
	bool c = true;
	char d;
	bool g = false;
	int m1 = 1;
	int n1 = 1;
	int k = 1;
	int j = 0;
	while (m1 <= m - 12)
	{
		gotoxy(m1, n1);
		cout << char(201);
		int x;
		for (x = 0; x < 10; x++)
			cout << char(205);
		cout << char(187);
		gotoxy(m1, n1 + 1);
		cout << char(186);
		for (x = 0; x < 10; x++)
			cout << char(32);
		cout << char(186);
		gotoxy(m1, n1 + 2);
		cout << char(200);
		for (x = 0; x < 10; x++)
			cout << char(205);
		cout << char(188);
		gotoxy (m1+2,n1+1);
		cout << "Tab: "<<k;
		// tao dau cong them tab
		gotoxy(m1 + 12, n1);
		cout << char(201);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(187);
		gotoxy(m1 + 12, n1 + 1);
		cout << char(186);
		for (x = 0; x < 3; x++)
			cout << char(32);
		cout << char(186);
		gotoxy(m1+12, n1 + 2);
		cout << char(200);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(188);
		gotoxy (m1+9,n1+1);
		cout << "x";	
		gotoxy (m1+14,n1+1);
		cout << "+";
		m1 += 12;
		k++;
		//
		g = false;
		gotoxy(0,20);
	}
	while (c)
	{
		gotoxy(0,20);
		if (g)
		{
			gotoxy(m, n);
			cout << char(201);
			int x;
			for (x = 0; x < 10; x++)
				cout << char(205);
			cout << char(187);
			gotoxy(m, n + 1);
			cout << char(186);
			for (x = 0; x < 10; x++)
			    cout << char(32);
			cout << char(186);
			gotoxy(m, n + 2);
			cout << char(200);
			for (x = 0; x < 10; x++)
			    cout << char(205);
			cout << char(188);
			gotoxy (m+2,n+1);
		    cout << "Tab: "<<i;
		    // tao dau cong them tab
		    gotoxy(m + 12, n);
			cout << char(201);
			for (x = 0; x < 3; x++)
				cout << char(205);
			cout << char(187);
			gotoxy(m + 12, n + 1);
			cout << char(186);
			for (x = 0; x < 3; x++)
				cout << char(32);
			cout << char(186);
			gotoxy(m+12, n + 2);
			cout << char(200);
			for (x = 0; x < 3; x++)
				cout << char(205);
			cout << char(188);
			gotoxy (m+9,n+1);
			cout << "x";
			
			gotoxy (m+14,n+1);
			cout << "+";
			m += 12;
			A[l] = i;
			l ++;
			A[l] = -1;
			l ++;
			A[l] = 0;
			l++;
			i++;
			//
			gotoxy(0,20);
		}
		if (i != 0)
		{
			bool e = true;
			int a = 4;
			int b = 0;
			int f = 2;
			while (e)
			{
				TextColor(7);
				d = getch();
				if (d == 80 ||d == 's'||d =='S'||d =='2')
				{
					
					if (b < l)
					{
						if (A[b] == -1)
						{
							TextColor(202);
							gotoxy (a-6,f);
							cout << "x";
							TextColor(7);
						}
						
						else if (A[b] == 0)
						{
							TextColor(202);
							gotoxy (a-13,f);
							cout << "+";
							TextColor(7);
						}
	
						else
						{
							if(A[b] == 1)
							{
								TextColor(202);
								gotoxy(a-1,f);
								cout <<"Tab: "<<  A[b] << endl;
							}
							else
							{
								TextColor(202);
								gotoxy(a-13,f);
								cout <<"Tab: "<<  A[b] << endl;
								a = a - 12;
							}
						
						}	
						if (a >= 5)
						{
							if(A[b-1] == -1)
							{
								if (A[b] == 2 || A[b] == 3 || A[b] == 4 || A[b] == 5||A[b] == 6 || A[b] == 7 || A[b] == 8 || A[b] == 9||A[b]==10 || A[b]== 11 || A[b] == 12)
								{
									TextColor(7);
									gotoxy(a - 6,f);
									cout <<"x" << endl;
								}
								else
								{
									TextColor(7);
									gotoxy(a - 18,f);
									cout <<"x" << endl;
								}
								
								
							}
							else
							{
								TextColor(7);
								gotoxy(a - 13,f);
								cout <<"Tab: "<< A[b - 1] << endl;
							}
							
						}
						a = a + 12;
						b++;
					}
					
				}			
				else if (d == 72 || d == 'w'||d == 'W'||d == '8')
				{
					
					a = a - 12;
					b --;
					if (a >= 0 && b > 0)
					{
						if (A[b] == -1)
						{
							TextColor(7);
							gotoxy(a-6,f);
							cout << "x";
						}
						else if (A[b] == 0)
						{
							TextColor(7);
							gotoxy(a-13,f);
							cout << "+";
						}
						else
						{
							if(A[b] == 2| A[b] == 3 || A[b] == 4 || A[b] == 5||A[b] == 6 || A[b] == 7 || A[b] == 8 || A[b] == 9||A[b]==10 || A[b]== 11 || A[b] == 12)
							{
								TextColor(7);
								gotoxy(a-1,f);
								cout <<"Tab: "<<  A[b] << endl;
								a = a + 12;
							}
							else
							{
								TextColor(7);
								gotoxy(a-13,f);
								cout <<"Tab: "<<  A[b] << endl;
								a = a + 12;
							}
						}
						if(A[b-1] == -1)
						{
							TextColor(202);
							gotoxy(a - 18,f);
							cout <<"x" << endl;
						}
						else
						{
							TextColor(202);
							gotoxy(a - 13,f);
							cout <<"Tab: " << A[b-1] << endl;
						}
					}
					else
					{
						a = a + 12;
						b ++;
					}
					
				}
				else if (d == 13 ||d =='e'||a=='E' ||d =='5')
				{
					if (A[b-1] == 0)
					{
						e = false;
						g = true;
						l = l - 1;		
					}
					else if(A[b-1] == -1)
					{
						deleteTab(l,A,b,a,f,i);
						if(i == 1)
						{
		/////					deleteNewWindow(l,A1,b,a,f,i);
								// xoay lai tiep tuc lua chon new Window
						}		
					}
					else
					{
						return  A[b-1];
						g = false;
						e = false;
						c = false;
					}		
						
				}
			}
		}
		else 
			c = false;
	}
} 
void khungTabMoi1()
{
	//dungKhungMoi1();
	bool c = true;
	char d;
	bool g = true;
	int m1 = 1;
	int n1 = 1;
	int k = 1;
	gotoxy(0,20);
	while (m1 <= m - 12)
	{
		gotoxy(m1, n1);
		cout << char(201);
		int x;
		for (x = 0; x < 10; x++)
			cout << char(205);
		cout << char(187);
		gotoxy(m1, n1 + 1);
		cout << char(186);
		for (x = 0; x < 10; x++)
			cout << char(32);
		cout << char(186);
		gotoxy(m1, n1 + 2);
		cout << char(200);
		for (x = 0; x < 10; x++)
			cout << char(205);
		cout << char(188);
		gotoxy (m1+2,n1+1);
		cout << "Tab: "<<k;
		// tao dau cong them tab
		gotoxy(m1 + 12, n1);
		cout << char(201);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(187);
		gotoxy(m1 + 12, n1 + 1);
		cout << char(186);
		for (x = 0; x < 3; x++)
			cout << char(32);
		cout << char(186);
		gotoxy(m1+12, n1 + 2);
		cout << char(200);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(188);
		gotoxy (m1+9,n1+1);
		cout << "x";	
		gotoxy (m1+14,n1+1);
		cout << "+";
		m1 += 12;
		k++;
		//
		gotoxy(0,20);
	}
}  
int khungNewWindow()
{
	dungKhung();
	bool c = true;
	char d;
	bool g = true;
	gotoxy(0,20);
	while (c)
	{
		gotoxy(0,20);
		if (g)
		{
			gotoxy(m2, n2);
			cout << char(201);
			int x;
			for (x = 0; x < 5; x++)
				cout << char(205);
			cout << char(187);
			gotoxy(m2, n2 + 1);
			cout << char(186);
			for (x = 0; x < 5; x++)
			    cout << char(32);
			cout << char(186);
			gotoxy(m2, n2 + 2);
			cout << char(200);
			for (x = 0; x < 5; x++)
			    cout << char(205);
			cout << char(188);
			gotoxy(m2+2,n2+1);
		    cout <<"G";
		    	// tao dau cong them tab
		    gotoxy(m2 + 7, n2);
			cout << char(201);
			for (x = 0; x < 3; x++)
				cout << char(205);
			cout << char(187);
			gotoxy(m2 + 7, n2 + 1);
			cout << char(186);
			for (x = 0; x < 3; x++)
				cout << char(32);
			cout << char(186);
			gotoxy(m2+7, n2 + 2);
			cout << char(200);
			for (x = 0; x < 3; x++)
				cout << char(205);
			cout << char(188);
			gotoxy(m2+4,n2+1);
			cout << "x";
			
			gotoxy(m2+9,n2+1);
			cout << "+";
			m2 += 7;
			A1[l1] = i1;
			l1 ++;
			A1[l1] = -1;
			l1 ++;
			A1[l1] = 0;
			l1++;
			i1++;
		}
		if (i1 != 0)
		{
			bool e = true;
			int a = 4;
			int b = 0;
			int f = 48;
			while (e)
			{
				TextColor(7);
				d = getch();
				if (d == 80 ||d == 's'||d =='S'||d =='2')
				{
					if (b < l1)
					{
						if (A1[b] == -1)
						{
							TextColor(202);
							gotoxy(a-6,f);
							cout << "x";
							TextColor(7);
						}
						
						else if (A1[b] == 0)
						{
							TextColor(202);
							gotoxy(a-8,f);
							cout << "+";
							TextColor(7);
						}
	
						else
						{
							if(A1[b] == 1)
							{
								TextColor(202);
								gotoxy(a-1,f);
								cout <<"G" << endl;
							}
							else
							{
								TextColor(202);
								gotoxy(a - 8,f);
								cout <<"G" << endl;
								a = a - 7;
							}
						}
						if (a >= 5)
						{
							if(A1[b-1] == -1)
							{
								if (A1[b] == 2 || A1[b] == 3 || A1[b] == 4 || A1[b] == 5||A1[b] == 6 || A1[b] == 7 || A1[b] == 8 || A1[b] == 9||A1[b]==10 || A1[b]== 11 || A1[b] == 12)
								{
									TextColor(7);
									gotoxy(a - 6,f);
									cout <<"x" << endl;
								}
								else
								{
									TextColor(7);
									gotoxy(a - 13,f);
									cout <<"x" << endl;
								}	
							}
							else
							{
								TextColor(7);
								gotoxy(a - 8,f);
								cout <<"G" << endl;
							}
							
						}
						a = a + 7;
						b++;
					}		
				}			
				else if (d == 72 || d == 'w'||d == 'W'||d == '8')
				{
					
					a = a - 7;
					b --;
					if(a >= 0 && b > 0)
					{
						if (A1[b] == -1)
						{
							TextColor(7);
							gotoxy(a-6,f);
							cout << "x";
						}
						else if (A1[b] == 0)
						{
							TextColor(7);
							gotoxy(a-13+5,f);
							cout << "+";
						}
						else
						{
							if(A1[b] == 2|| A1[b] == 3 || A1[b] == 4 || A1[b] == 5||A1[b] == 6 || A1[b] == 7 || A1[b] == 8 || A1[b] == 9||A1[b]==10 || A1[b]== 11 || A1[b] == 12)
							{
								TextColor(7);
								gotoxy(a-1,f);
								cout <<"G" << endl;
								a = a + 7;
							}
							else
							{
								TextColor(7);
								gotoxy(a-13,f);
								cout <<"G" << endl;
								a = a + 7;
							}
						}
						if(A1[b-1] == -1)
						{
							TextColor(202);
							gotoxy(a - 13,f);
							cout <<"x" << endl;
						}
						else
						{
							TextColor(202);
							gotoxy(a - 8,f);
							cout <<"G" << endl;
						}
					
					}
					else
					{
						a = a + 7;
						b ++;
					}	
				}
				else if (d == 13 ||d =='e'||a=='E' ||d =='5')
				{
					if (A1[b-1] == 0)
					{
						e = false;
						g = true;
						l1 = l1 - 1;
					}
					else if(A1[b-1] == -1)
					{
						deleteNewWindow(l1,A1,b,a,f,i1);
						if(i1 == 1)
						{
							system("cls");
							cout<<"da thoat trinh duyet ";	
						}
					}
					else
					{
						gotoxy(0,20);
						return A1[b-1];
						g = false;
						e = false;
					}	
				}
			}
		}
		else 
			c = false;
	}
}
void khungNewWindowMoi()
{
	dungKhungMoi();
	bool c = true;
	char d;
	int m1 = 1;
	int n1 = 47;
	int k = 1;
	bool g = true;
	gotoxy(0,20);
	while (m1 <= m2 - 7)
	{
		
		gotoxy(m1, n1);
		cout << char(201);
		int x;
		for (x = 0; x < 5; x++)
			cout << char(205);
		cout << char(187);
		gotoxy(m1, n1 + 1);
		cout << char(186);
		for (x = 0; x < 5; x++)
			cout << char(32);
		cout << char(186);
		gotoxy(m1, n1 + 2);
		cout << char(200);
		for (x = 0; x < 5; x++)
			cout << char(205);
		cout << char(188);
		gotoxy(m1+2,n1+1);
		cout <<"G";
		// tao dau cong them tab
		gotoxy(m1 + 7, n1);
		cout << char(201);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(187);
		gotoxy(m1 + 7, n1 + 1);
		cout << char(186);
		for (x = 0; x < 3; x++)
			cout << char(32);
		cout << char(186);
		gotoxy(m1+7, n1 + 2);
		cout << char(200);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(188);
		gotoxy(m1+4,n1+1);
		cout << "x";	
		gotoxy(m1+9,n1+1);
		cout << "+";
		m1 += 7;
		k++;
	}
}
void khungNewWindowMoi1()
{
	dungKhungMoi1();
	bool c = true;
	char d;
	int m1 = 1;
	int n1 = 47;
	int k = 1;
	bool g = true;
	gotoxy(0,20);
	while (m1 <= m2 - 7)
	{
		gotoxy(m1, n1);
		cout << char(201);
		int x;
		for (x = 0; x < 5; x++)
			cout << char(205);
		cout << char(187);
		gotoxy(m1, n1 + 1);
		cout << char(186);
		for (x = 0; x < 5; x++)
			cout << char(32);
		cout << char(186);
		gotoxy(m1, n1 + 2);
		cout << char(200);
		for (x = 0; x < 5; x++)
			cout << char(205);
		cout << char(188);
		gotoxy(m1+2,n1+1);
		cout <<"G";
		// tao dau cong them tab
		gotoxy(m1 + 7, n1);
		cout << char(201);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(187);
		gotoxy(m1 + 7, n1 + 1);
		cout << char(186);
		for (x = 0; x < 3; x++)
			cout << char(32);
		cout << char(186);
		gotoxy(m1+7, n1 + 2);
		cout << char(200);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(188);
		gotoxy(m1+4,n1+1);
		cout << "x";	
		gotoxy(m1+9,n1+1);
		cout << "+";
		m1 += 7;
		k++;
	}	
}
void khungNewWindowMoi2()
{
	dungKhung();
	bool c = true;
	char d;
	int m1 = 1;
	int n1 = 47;
	int k = 1;
	bool g = true;
	gotoxy(0,20);
	while (m1 <= m2 - 7)
	{
		gotoxy(m1, n1);
		cout << char(201);
		int x;
		for (x = 0; x < 5; x++)
			cout << char(205);
		cout << char(187);
		gotoxy(m1, n1 + 1);
		cout << char(186);
		for (x = 0; x < 5; x++)
			cout << char(32);
		cout << char(186);
		gotoxy(m1, n1 + 2);
		cout << char(200);
		for (x = 0; x < 5; x++)
			cout << char(205);
		cout << char(188);
		gotoxy(m1+2,n1+1);
		cout <<"G";
		// tao dau cong them tab
		gotoxy(m1 + 7, n1);
		cout << char(201);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(187);
		gotoxy(m1 + 7, n1 + 1);
		cout << char(186);
		for (x = 0; x < 3; x++)
			cout << char(32);
		cout << char(186);
		gotoxy(m1+7, n1 + 2);
		cout << char(200);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(188);
		gotoxy(m1+4,n1+1);
		cout << "x";	
		gotoxy(m1+9,n1+1);
		cout << "+";
		m1 += 7;
		k++;
	}	
}
int khungNewWindowMoi3()
{
	bool c = true;
	char d;
	int m1 = 1;
	int n1 = 47;
	int k = 1;
	bool g = true;
	gotoxy(0,20);
	while (m1 <= m2 - 7)
	{
		gotoxy(m1, n1);
		cout << char(201);
		int x;
		for (x = 0; x < 5; x++)
			cout << char(205);
		cout << char(187);
		gotoxy(m1, n1 + 1);
		cout << char(186);
		for (x = 0; x < 5; x++)
			cout << char(32);
		cout << char(186);
		gotoxy(m1, n1 + 2);
		cout << char(200);
		for (x = 0; x < 5; x++)
			cout << char(205);
		cout << char(188);
		gotoxy(m1+2,n1+1);
		cout <<"G";
		// tao dau cong them tab
		gotoxy(m1 + 7, n1);
		cout << char(201);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(187);
		gotoxy(m1 + 7, n1 + 1);
		cout << char(186);
		for (x = 0; x < 3; x++)
			cout << char(32);
		cout << char(186);
		gotoxy(m1+7, n1 + 2);
		cout << char(200);
		for (x = 0; x < 3; x++)
			cout << char(205);
		cout << char(188);
		gotoxy(m1+4,n1+1);
		cout << "x";	
		gotoxy(m1+9,n1+1);
		cout << "+";
		m1 += 7;
		k++;
		g = false;
	}
	while (c)
	{
		gotoxy(0,20);
		if (g)
		{
			gotoxy(m2, n2);
			cout << char(201);
			int x;
			for (x = 0; x < 5; x++)
				cout << char(205);
			cout << char(187);
			gotoxy(m2, n2 + 1);
			cout << char(186);
			for (x = 0; x < 5; x++)
			    cout << char(32);
			cout << char(186);
			gotoxy(m2, n2 + 2);
			cout << char(200);
			for (x = 0; x < 5; x++)
			    cout << char(205);
			cout << char(188);
			gotoxy(m2+2,n2+1);
		    cout <<"G";
		    	// tao dau cong them tab
		    gotoxy(m2 + 7, n2);
			cout << char(201);
			for (x = 0; x < 3; x++)
				cout << char(205);
			cout << char(187);
			gotoxy(m2 + 7, n2 + 1);
			cout << char(186);
			for (x = 0; x < 3; x++)
				cout << char(32);
			cout << char(186);
			gotoxy(m2+7, n2 + 2);
			cout << char(200);
			for (x = 0; x < 3; x++)
				cout << char(205);
			cout << char(188);
			gotoxy(m2+4,n2+1);
			cout << "x";
			
			gotoxy(m2+9,n2+1);
			cout << "+";
			m2 += 7;
			A1[l1] = i1;
			l1 ++;
			A1[l1] = -1;
			l1 ++;
			A1[l1] = 0;
			l1++;
			i1++;
		}
		if (i1 != 0)
		{
			bool e = true;
			int a = 4;
			int b = 0;
			int f = 48;
			while (e)
			{
				TextColor(7);
				d = getch();
				if (d == 80 ||d == 's'||d =='S'||d =='2')
				{
					if (b < l1)
					{
						if (A1[b] == -1)
						{
							TextColor(202);
							gotoxy(a-6,f);
							cout << "x";
							TextColor(7);
						}
						
						else if (A1[b] == 0)
						{
							TextColor(202);
							gotoxy(a-8,f);
							cout << "+";
							TextColor(7);
						}
	
						else
						{
							if(A1[b] == 1)
							{
								TextColor(202);
								gotoxy(a-1,f);
								cout <<"G" << endl;
							}
							else
							{
								TextColor(202);
								gotoxy(a - 8,f);
								cout <<"G" << endl;
								a = a - 7;
							}
							
						
						}	
						if (a >= 5)
						{
							if(A1[b-1] == -1)
							{
								if (A1[b] == 2 || A1[b] == 3 || A1[b] == 4 || A1[b] == 5||A1[b] == 6 || A1[b] == 7 || A1[b] == 8 || A1[b] == 9||A1[b]==10 || A1[b]== 11 || A1[b] == 12)
								{
									TextColor(7);
									gotoxy(a - 6,f);
									cout <<"x" << endl;
								}
								else
								{
									TextColor(7);
									gotoxy(a - 13,f);
									cout <<"x" << endl;
								}	
							}
							else
							{
								TextColor(7);
								gotoxy(a - 8,f);
								cout <<"G" << endl;
							}
							
						}
					}
					
					a = a + 7;
					b++;
				}			
				else if (d == 72 || d == 'w'||d == 'W'||d == '8')
				{
					
					a = a - 7;
					b --;
					if (a >= 0 && b > 0)
					{
						if (A1[b] == -1)
						{
							TextColor(7);
							gotoxy(a-6,f);
							cout << "x";
						}
						else if (A1[b] == 0)
						{
							TextColor(7);
							gotoxy(a-13+5,f);
							cout << "+";
						}
						else
						{
							if(A1[b] == 2|| A1[b] == 3 || A1[b] == 4 || A1[b] == 5||A1[b] == 6 || A1[b] == 7 || A1[b] == 8 || A1[b] == 9||A1[b]==10 || A1[b]== 11 || A1[b] == 12)
							{
								TextColor(7);
								gotoxy(a-1,f);
								cout <<"G" << endl;
								a = a + 7;
							}
							else
							{
								TextColor(7);
								gotoxy(a-13,f);
								cout <<"G" << endl;
								a = a + 7;
							}
						}
						if(A1[b-1] == -1)
						{
							TextColor(202);
							gotoxy(a - 13,f);
							cout <<"x" << endl;
						}
						else
						{
							TextColor(202);
							gotoxy(a - 8,f);
							cout <<"G" << endl;
						}
					}
					else
					{
						a = a + 7;
						b ++;
					}		
				}
				else if (d == 13 ||d =='e'||a=='E' ||d =='5')
				{
					if (A1[b-1] == 0)
					{
						e = false;
						g = true;
						l1 = l1 - 1;
					}
					else if(A1[b-1] == -1)
					{
						deleteNewWindow(l1,A1,b,a,f,i1);
						if(i1 == 1)
							cout<<"da thoat trinh duyet ";	
					}
					else
					{
						gotoxy(0,20);
						return A1[b-1];
						g = false;
						e = false;
					}	
				}
			}
		}
		else 
			c = false;
	}	
}
void saveHistory(string s)
{
	history[k] = s;
	thoiGian[k] = trichXuatTime();
	k++;
	history[k] = "back";
}
void xuatLichSu(string str[50])
{
	int m = 16; 
	if (k == 0)
	{
		gotoxy (68,16);
		cout << "Chua co lich su tim kiem!!!";
	}
	for(int i = 0 ; i < k ; i++)
	{
		gotoxy(45,m);
		cout<<str[i];
		gotoxy(80,m);
		cout<<thoiGian[i];
		m++;
	}	
}
void xuatUaThich(string str[50])
{
	int m = 34; 
	for(int i = 0 ; i < k ; i++)
	{
		gotoxy(50,15);
		cout<<str[i];
	}	
}
void thongTinTimKiem(string s)
{
	int j = 0;
	ifstream fileInput("database.txt");
	if (fileInput.fail())
	{
		cout <<"Loi File!"<< endl;
		return; 
	}
	else
	{
		int m = 15;
		string n;
		while (!fileInput.eof())
		{
			getline(fileInput,n);
			string ss = s;
			string nn = n;
			chuanHoa(ss);
			chuanHoa(nn);
			bool check = kiemTraChuoiCon(ss,nn);
			if(check == true)
			{
				gotoxy(74,m++);
				cout<<n<<endl; 
				j++;
			}
		}
		if (j == 0)
		{
			gotoxy(66,15);
			cout << "Khong co ket qua tim kiem!!!" << endl;
		}
		saveHistory(s);
	}
}
void thongTinTimKiem1(string s, string A[], int &i)
{
	ifstream fileInput("database.txt");
	if (fileInput.fail())
	{
		cout <<"Loi File!"<< endl;
		return; 
	}
	else
	{
		string n;
		while (!fileInput.eof())
		{
			getline(fileInput,n);
			string ss = s;
			string nn = n;
			chuanHoa(ss);
			chuanHoa(nn);
			bool check = kiemTraChuoiCon(ss,nn);
			if(check == true)
			{ 
				A[i]= n;
				i++;
			}
			A[i] = "back";
		}
	}
}

struct trangchu
{
	void taoGiaoDien (string &s, int a)
	{
		if (a == 1)
		{
			system("cls");
			khungNewWindowMoi2();
			khungTabMoi2();
			//nhap so lieu
			gotoxy (50,28);
			cin >> s;
//			//tim kiem
			gotoxy (1,7);
			for (int j = 0; j < 170; j++)
			{
				cout << char(22);
				Sleep(3);
			}
			system("cls");
			khungNewWindowMoi();
			khungTabMoi();
			gotoxy(42,9);
			cout<<"Search: "<<s<<endl;
			thongTinTimKiem(s);
			// dua con tro den cuoi
			gotoxy(0,42);
		}
		else if (a == 2)
		{
			gotoxy (27,5);
			cin >> s;
			gotoxy (1,7);
			for (int j = 0; j < 170; j++)
			{
				cout << char(22);
				Sleep(3);
			}
			system("cls");
			khungNewWindowMoi();
			khungTabMoi();
			gotoxy(42,9);
			cout<<"Search: "<<s<<endl;
			thongTinTimKiem(s);
			gotoxy(0,42);
		}
		else if (a == 5)
		{
			gotoxy (50,9);
			cin >> s;
			gotoxy (1,7);
			for (int j = 0; j < 170; j++)
			{
				cout << char(22);
				Sleep(3);
			}
			system("cls");
			khungNewWindowMoi();
			khungTabMoi();
			gotoxy(42,9);
			cout<<"Search: "<<s<<endl;
			thongTinTimKiem(s);
			gotoxy(0,42);
		}
		else if (a == 8)
		{
			system("cls");
			khungNewWindowMoi();
			khungTabMoi();
			gotoxy(42,9);
			cout<<"Search: "<<s<<endl;
			thongTinTimKiem(s);
			// dua con tro den cuoi
			gotoxy(0,42);
		}
		else if(a == 6)
		{
			system("cls");
			khungNewWindowMoi();
			khungTabMoi();
			gotoxy(42,9);
			cout<<"Search: "<<endl;
			gotoxy(42,11);
			cout<<"Lich su tim kiem la : "<<endl;
			xuatLichSu(history);
			gotoxy(0,42);
		}
	}
};
void docFile(string file)
{
	string t = file;
	file +=".txt" ;
	ifstream fileInput(file.c_str());
	if (fileInput.fail())
	{
		//cout <<"file "<<file<<" khong tim thay du lieu"<<endl;
		trangchu().taoGiaoDien(t,8);
		return; 
	}
	else
	{
		string data;
    	while (getline(fileInput, data)) 
		{
        	cout<<char (186)<< data<<endl;
    	}
    	fileInput.close();
    	gotoxy(0,42);
	}
    
}
void docFileMoi(string file, int &z)
{
	string t = file;
	file +=".txt" ;
	ifstream fileInput(file.c_str());
	if (fileInput.fail())
	{
		trangchu().taoGiaoDien(t,8);
		z = 8;
		return; 
	}
	else
	{
		system("cls");
		khungNewWindowMoi1();
		khungTabMoi1();
		gotoxy (44,7);
		string data;
    	while (getline(fileInput, data)) 
		{
        	cout<<char (186)<< data<<endl;
    	}
    	fileInput.close();
    	z = 12;
    	gotoxy(0,42);
	}
    
}
void feature(int &b, LStack &l3, LStack2 &q, int &k1)
{
	
	int b1 = b;
	gotoxy(0,42);
	bool c = true;//dung trong vong lap lon de thuc hien nhap nut
	if (b == 0)
	{
		s = ' ';
		push(l3,s,0);
		gotoxy(40,38);
	}
	while (c)
	{	
		int chon = 0;
    	int toado = 15;
	    do{
	        char a = getch();
	        if(a == 80 ||a == 's'||a=='S'||a=='2') 
				chon = 1;
	        else if(a == 72 || a == 'w'||a=='W'||a=='8') 
				chon = 2;
			else if(a == 13 ||a =='e'||a=='e' ||a=='5') 
				chon = 3;
	        else 
				chon = 0;
	        if(chon == 1 && toado < 27) 
				toado++;
	        else if(chon == 2 && toado >15) 
				toado--;
	        if(toado == 15)
	        {
	        	if (b1 == 0)
	        	{
	        		TextColor(202);
		            gotoxy(41, 28); 
					cout << "Search";		
				}
				else if (b1 != 12)
				{
					TextColor(202);
	            	gotoxy(42, 9); 
					cout << "Search";
					TextColor(7);
				}
	            TextColor(7);
			    gotoxy(3, 5); 
				cout << char (17);
			    gotoxy(6, 5); 
				cout << char (16);
				gotoxy(15,5);
				cout <<"Search URL: ";
			    gotoxy (169,1);
				cout << "X" ;
				gotoxy(137,5);
				cout <<"HISTORY";  
				gotoxy(157,5);
				cout <<"BOOKMARK";
				gotoxy (129,5);
				cout << "*";
				gotoxy (166,1);
				cout << char (4);
				gotoxy (9,5);
				cout << char (2);
				gotoxy (163,1);
				cout << char(5);
				TextColor(7);
	        }
	        if(toado == 16)
	        {
	        	if (b1 == 0)
	        	{
	        		TextColor(7);
	            	gotoxy(41, 28); 
					cout << "Search";
				}
				else if (b1 != 12)
				{
					TextColor(7);
	            	gotoxy(42, 9); 
					cout << "Search";
					gotoxy (77,13);
					cout << "SELECT";
				}
	            TextColor(202);
	            gotoxy(3, 5); 
				cout << char (17);
	            TextColor(7);
	            gotoxy(6, 5); 
				cout << char (16);
				gotoxy(15,5);
				cout <<"Search URL: ";
				gotoxy (169,1);
				cout << "X" ;
				gotoxy(137,5);
				cout <<"HISTORY";  
				gotoxy(157,5);
				cout <<"BOOKMARK";
				gotoxy (129,5);
				cout << "*";
				gotoxy (166,1);
				cout << char (4);
				gotoxy (9,5);
				cout << char (2);
				gotoxy (163,1);
				cout << char(5);
	            TextColor(7);
	        }
	        if(toado == 17)
	        {
	        	if (b1 == 0)
	        	{
	        		TextColor(7);
	            	gotoxy(41, 28); 
					cout << "Search";
				}
				else if (b1 != 12)
				{
					TextColor(7);
	            	gotoxy(42, 9); 
					cout << "Search";
					gotoxy (77,13);
					cout << "SELECT";
				}
	            gotoxy(3, 5); 
				cout << char (17);
	            TextColor(202);
	            gotoxy(6, 5); 
				cout << char (16);
				TextColor(7);
				gotoxy(15,5);
				cout <<"Search URL: ";
				gotoxy (169,1);
				cout << "X" ;
				gotoxy(137,5);
				cout <<"HISTORY";  
				gotoxy(157,5);
				cout <<"BOOKMARK";
				gotoxy (129,5);
				cout << "*";
				gotoxy (166,1);
				cout << char (4);
				gotoxy (9,5);
				cout << char (2);
				gotoxy (163,1);
				cout << char(5);
	            TextColor(7);
	        }
	        if (toado == 18)
	        {
	        	if (b1 == 0)
	        	{
	        		TextColor(7);
	            	gotoxy(41, 28); 
					cout << "Search";
				}
				else if (b1 != 12)
				{
					TextColor(7);
	            	gotoxy(42, 9); 
					cout << "Search";
					gotoxy (77,13);
					cout << "SELECT";
				}
	            gotoxy(3, 5); 
				cout << char (17);
	            TextColor(7);
	            gotoxy(6, 5); 
				cout << char (16);
				TextColor(202);
				gotoxy(15,5);
				cout <<"Search URL: ";
	            TextColor(7);
	            gotoxy (169,1);
				cout << "X" ;
				gotoxy(137,5);
				cout <<"HISTORY";  
				gotoxy(157,5);
				cout <<"BOOKMARK";
				gotoxy (129,5);
				cout << "*";
				gotoxy (166,1);
				cout << char (4);
				gotoxy (9,5);
				cout << char (2);
				gotoxy (163,1);
				cout << char(5);
				TextColor(7);
			}
			if (toado == 19)
			{
				if (b1 == 0)
	        	{
	        		TextColor(7);
	            	gotoxy(41, 28); 
					cout << "Search";
				}
				else if (b1 != 12)
				{
					TextColor(7);
	            	gotoxy(42, 9); 
					cout << "Search";
					gotoxy (77,13);
					cout << "SELECT";
				}
	            gotoxy(3, 5); 
				cout << char (17);
	            TextColor(7);
	            gotoxy(6, 5); 
				cout << char (16);
				gotoxy(15,5);
				cout <<"Search URL: ";
	            TextColor(202);
	            gotoxy (169,1);
				cout << "X" ;
				TextColor(7);
				gotoxy(137,5);
				cout <<"HISTORY";  
				gotoxy(157,5);
				cout <<"BOOKMARK";
				gotoxy (129,5);
				cout << "*";
				gotoxy (166,1);
				cout << char (4);
				gotoxy (9,5);
				cout << char (2);
				gotoxy (163,1);
				cout << char(5);
				TextColor(7);
			}
			if (toado == 20)
			{
				if (b1 == 0)
	        	{
	        		TextColor(7);
	            	gotoxy(41, 28); 
					cout << "Search";
				}
				else if (b1 != 12)
				{
					TextColor(7);
	            	gotoxy(42, 9); 
					cout << "Search";
					gotoxy (77,13);
					cout << "SELECT";
				}
	            gotoxy(3, 5); 
				cout << char (17);
	            TextColor(7);
	            gotoxy(6, 5); 
				cout << char (16);
				gotoxy(15,5);
				cout <<"Search URL: ";
	            gotoxy (169,1);
				cout << "X" ;
				TextColor(202);
				gotoxy(137,5);
				cout <<"HISTORY";  
				TextColor(7);
				gotoxy(157,5);
				cout <<"BOOKMARK";
				gotoxy (129,5);
				cout << "*";
				gotoxy (166,1);
				cout << char (4);
				gotoxy (9,5);
				cout << char (2);
				gotoxy (163,1);
				cout << char(5);
				TextColor(7);
			}
			if (toado == 21)
			{
				if (b1 == 0)
	        	{
	        		TextColor(7);
	            	gotoxy(41, 28); 
					cout << "Search";
				}
				else if (b1 != 12)
				{
					TextColor(7);
	            	gotoxy(42, 9); 
					cout << "Search";
					gotoxy (77,13);
					cout << "SELECT";
				}
	            gotoxy(3, 5); 
				cout << char (17);
	            TextColor(7);
	            gotoxy(6, 5); 
				cout << char (16);
				gotoxy(15,5);
				cout <<"Search URL: ";
	            gotoxy (169,1);
				cout << "X" ;
				gotoxy(137,5);
				cout <<"HISTORY";  
				TextColor(202);
				gotoxy(157,5);
				cout <<"BOOKMARK";
				TextColor(7);
				gotoxy (129,5);
				cout << "*";
				gotoxy (166,1);
				cout << char (4);
				gotoxy (9,5);
				cout << char (2);
				gotoxy (163,1);
				cout << char(5);
			}
			if (toado == 22)
			{
				if (b1 == 0)
	        	{
	        		TextColor(7);
	            	gotoxy(41, 28); 
					cout << "Search";
				}
				else if (b1 != 12)
				{
					TextColor(7);
	            	gotoxy(42, 9); 
					cout << "Search";
					TextColor(202);
					gotoxy (77,13);
					cout << "SELECT";
					TextColor(7);
				}
	            gotoxy(3, 5); 
				cout << char (17);
	            TextColor(7);
	            gotoxy(6, 5); 
				cout << char (16);
				gotoxy(15,5);
				cout <<"Search URL: ";
	            gotoxy (169,1);
				cout << "X" ;
				gotoxy(137,5);
				cout <<"HISTORY";  
				gotoxy(157,5);
				cout <<"BOOKMARK";
				gotoxy (129,5);
				cout << "*";
				gotoxy (166,1);
				cout << char (4);
				gotoxy (9,5);
				cout << char (2);
				gotoxy (163,1);
				cout << char(5);
				TextColor(7);
			}
			if (toado == 23)
			{
				if (b1 == 0)
	        	{
	        		TextColor(7);
	            	gotoxy(41, 28); 
					cout << "Search";
				}
				else if (b1 != 12)
				{
					TextColor(7);
	            	gotoxy(42, 9); 
					cout << "Search";
					gotoxy (77,13);
					cout << "SELECT";
				}
	            gotoxy(3, 5); 
				cout << char (17);
	            TextColor(7);
	            gotoxy(6, 5); 
				cout << char (16);
				gotoxy(15,5);
				cout <<"Search URL: ";
	            gotoxy (169,1);
				cout << "X" ;
				gotoxy(137,5);
				cout <<"HISTORY";  
				gotoxy(157,5);
				cout <<"BOOKMARK";
				TextColor(202);
				gotoxy (129,5);
				cout << "*";
				TextColor(7);
				gotoxy (166,1);
				cout << char (4);
				gotoxy (9,5);
				cout << char (2);
				gotoxy (163,1);
				cout << char(5);
			}
			if (toado == 24)
			{
				if (b1 == 0)
	        	{
	        		TextColor(7);
	            	gotoxy(41, 28); 
					cout << "Search";
				}
				else if (b1 != 12)
				{
					TextColor(7);
	            	gotoxy(42, 9); 
					cout << "Search";
					gotoxy (77,13);
					cout << "SELECT";
				}
	            gotoxy(3, 5); 
				cout << char (17);
	            TextColor(7);
	            gotoxy(6, 5); 
				cout << char (16);
				gotoxy(15,5);
				cout <<"Search URL: ";
	            gotoxy (169,1);
				cout << "X" ;
				gotoxy(137,5);
				cout <<"HISTORY";  
				gotoxy(157,5);
				cout <<"BOOKMARK";
				gotoxy (129,5);
				cout << "*";
				TextColor(202);
				gotoxy (166,1);
				cout << char (4);
				TextColor(7);
				gotoxy (9,5);
				cout << char (2);
				gotoxy (163,1);
				cout << char(5);
			}
			if (toado == 25)
			{
				if (b1 == 0)
	        	{
	        		TextColor(7);
	            	gotoxy(41, 28); 
					cout << "Search";
				}
				else if (b1 != 12)
				{
					TextColor(7);
	            	gotoxy(42, 9); 
					cout << "Search";
					gotoxy (77,13);
					cout << "SELECT";
				}
	            gotoxy(3, 5); 
				cout << char (17);
	            TextColor(7);
	            gotoxy(6, 5); 
				cout << char (16);
				gotoxy(15,5);
				cout <<"Search URL: ";
	            gotoxy (169,1);
				cout << "X" ;
				gotoxy(137,5);
				cout <<"HISTORY";  
				gotoxy(157,5);
				cout <<"BOOKMARK";
				gotoxy (129,5);
				cout << "*";
				gotoxy (166,1);
				cout << char (4);
				TextColor(202);
				gotoxy (9,5);
				cout << char (2);
				TextColor(7);
				gotoxy (163,1);
				cout << char(5);
			}
			if (toado == 26)
			{
				if (b1 == 0)
	        	{
	        		TextColor(7);
	            	gotoxy(41, 28); 
					cout << "Search";
				}
				else if (b1 != 12)
				{
					TextColor(7);
	            	gotoxy(42, 9); 
					cout << "Search";
					gotoxy (77,13);
					cout << "SELECT";
				}
	            gotoxy(3, 5); 
				cout << char (17);
	            TextColor(7);
	            gotoxy(6, 5); 
				cout << char (16);
				gotoxy(15,5);
				cout <<"Search URL: ";
	            gotoxy (169,1);
				cout << "X" ;
				gotoxy(137,5);
				cout <<"HISTORY";  
				gotoxy(157,5);
				cout <<"BOOKMARK";
				gotoxy (129,5);
				cout << "*";
				gotoxy (166,1);
				cout << char (4);
				gotoxy (9,5);
				cout << char (2);
				TextColor(202);
				gotoxy (163,1);
				cout << char(5);
				TextColor(7);
			}
	    }while(chon != 3);
	    int d;
	    if(toado == 15 && b1 == 0) 
			d = '1';
		else if (toado == 16)
			d = '4';
		else if (toado == 17)
			d = '3';
		else if (toado == 18)
			d = '2';
		else if (toado == 15)
			d = '5';
		else if (toado == 19)
			d = '0';
		else if (toado == 20)
			d = '6';
		else if (toado == 21)
			d = '9';
		else if (toado == 22)
			d = '7';
		else if (toado == 23)
			d = '8';
		else if (toado == 24)
		{
			d = 'A';
		}
		else if (toado == 25)
		{
			d = 'B';
		}
		else if (toado == 26)
		{
			d = 'C';
		}
			
//		cout << "Nhap thao tac can thuc hien(so): ";
		 // bo qua dau enter
		int a = d - '0';// nhap cac nut dang so (tranh truong hop nhap chu)
		if (a > 9)
			a = a - 7;
		// tao mot trinh duyet moi
		if (a == 1)// trang tim kiem
		{
			trangchu().taoGiaoDien(s,a);
			b = a;
			// luu vao stack 2 gia tri
			// gia tri thu hai = b de luu trang tim kiem
			push(l3,s,b);
			b1 = 8;
		}
		else if (a == 2)// serch URL
		{
			trangchu().taoGiaoDien(s,a);
			b = a;
			push(l3,s,b);
			b1 = 8;
					
		}
		else if (a == 5)// serch trong tim kiem
		{
			trangchu().taoGiaoDien(s,a);
			b = a;
			push(l3,s,b);
			b1 = 8;
		}
//		// dung de next trang
		else if (a == 3)
		{
			if (q.top == NULL)
			{
				gotoxy (6,7);
				cout << "khong co trang de next" << endl;
			}
				
			else
			{
				Node *k = NULL;
				// xoa Node dau trong Stack2 de luu node xoa vao Stack cu
				k = popStack2 (q);
				string h = k -> data;
				int t = k -> solieu;
				push (l3,h,t);
				// khoi tao khung cho tung truong hop
				if (l3.head -> solieu == 6)// giao dien cua history
				{
					trangchu().taoGiaoDien(l3.head->data,6);
					b1 = 8;
				}
				else if (l3.head -> solieu == 7)// giao dien cua trang web////
				{
					string name = l3.head -> data;
					string t = name;
					int z;
					docFileMoi(name,z);
					b1 = z;
				}
				else if (l3.head -> solieu == 0)//giao dien trang chu
				{
					system("cls");
					khungNewWindowMoi2();
					khungTabMoi2();
					b1 = 0;////
				}
				else
				{
					trangchu().taoGiaoDien(h,8);//giao dien cua trang tim kiem
					b1 = 8;
				}	
			}		
		}
		else if (a == 4)// dung de back
		{	
			if (l3.head -> next == NULL)
			{
				gotoxy (6,7);
				cout << "khong co trang de back!!!!" << endl;
			}
			else
			{
				Node *p = new Node();
				p = pop(l3);
				// luu nhung cai trong stack khi xoa voa stack moi
				pushStack2(q,p);
				gotoxy(0,42);
			 	if (l3.head -> solieu == 1)// quay lai trang timkiem
				{
					trangchu().taoGiaoDien(l3.head -> data,8);
					b1 = 8;
				}
				else if (l3.head -> solieu == 0)// quay lai trang chu
				{
					//trangchu().taoGiaoDien(s,1);
					system("cls");
					khungNewWindowMoi2();
					khungTabMoi2();
					b1 = 0;
				}
				else if (l3.head -> solieu == 6)//quay lai trang history
				{
					trangchu().taoGiaoDien(l3.head->data,6);
					b1 = 8;
				}
				else if (l3.head -> solieu == 7)// giao dien cua trang web
				{
					int z;
					string name = l3.head -> data;
					docFileMoi(name,z);
					b1 = z;
				}
				else
				{
					trangchu().taoGiaoDien(l3.head -> data,8);
					b1 = 8;
				}
					
			}	
		}
		
		else if (a == 0)// thuc hien viec thoat trinh duyet
		{
			c = false;
		}
		else if(a == 6)// tao history
		{
				
				trangchu().taoGiaoDien(l3.head->data,6);// hien thi history
				b = a;
				push(l3,s,b);
				b1 = 8;
		}
		else if (a == 7)
		{
				int i = 16;// toa do vi tri cac thanh phan lua chon
				int j = 0;
				int m = 15;// toa do vi tri cac thanh phan lua chon
				int n = 0;
				bool e = true;
				int isoLuong = 0;
				if (l3.head -> solieu == 6)
				{
					trangchu().taoGiaoDien(l3.head->data,6);
				}
				string A[100];
				if (l3.head -> solieu != 6)
				{
					thongTinTimKiem1(l3.head -> data,A,isoLuong);	
				}
				while (e)
				{
					TextColor(7);
					d = getch();
					if (d == 80 ||d == 's'||d =='S'||d =='2')
					{
						if (l3.head -> solieu == 6)
						{
							if (j <= k)
							{
								TextColor(202);
								gotoxy(45,i);
								cout << history[j] << endl;
								if (i >= 17)
								{
									TextColor(7);
									gotoxy(45,i-1);
									cout << history[j-1] << endl;
								}
								i++;
								j++;
							}
							
						}
						else
						{
							if (n <= isoLuong)
							{
								TextColor(202);
								gotoxy(74,m);
								cout << A[n] << endl;
								if (m >= 16)
								{
									TextColor(7);
									gotoxy(74,m-1);
									cout << A[n-1] << endl;
								}
								m++;
								n++;
							}
							
						}			
					}
					else if (d == 72 || d == 'w'||d == 'W'||d == '8')
					{
						if (i > 16 || m > 15)
						{
							if (l3.head -> solieu == 6)
							{
								TextColor(7);
								i--;
								j--;
								if (i > 16)
								{
									gotoxy(45,i);
									cout << history[j] << endl;
									TextColor(202);
									gotoxy(45,i-1);
									cout << history[j-1] << endl;
								}
								
							}
							else 
							{
								TextColor(7);
								m--;
								n--;
								if (m > 15)
								{
									gotoxy(74,m);
									cout << A[n] << endl;
									TextColor(202);
									gotoxy(74,m-1);
									cout << A[n-1] << endl;
								}
								
							}	
						}
					}
					else if (d == 13 ||d =='e'||a=='E' ||d =='5')
					{
						if (l3.head -> solieu == 6)
						{
							string name = history[j-1];
							if (name == "back")
							{
								trangchu().taoGiaoDien(s,6);
								e = false;
							}
							else
							{
								push (l3,name,8);
								int z;
								docFileMoi(name,z);
								b1 = z;// truong hop select
								e = false;
							}
							
						}
						else
						{
							system("cls");
							khungNewWindowMoi1();
							khungTabMoi1();
							gotoxy (44,7);
							string name = A[n-1];
							if (name == "back")
							{
								trangchu().taoGiaoDien(s,8);
								e = false;
							}
							else
							{
								saveHistory(name);
								push (l3,name,7);
								b = 7;
								int z;
								docFileMoi(name,z);
								b1 = z; // truong hop Select
								e = false;
							}	
							
						}
						
					}
				}
		}
		else if (a == 8)// trang yeu thich
		{
			UaThich[ut] = l3.head -> data;
			ut++;
			UaThich[ut] = "back";		
			gotoxy(0,42);
		}
		else if (a == 9)
		{
			if (ut == 0)
			{
				taoBangBookMark();
				gotoxy (154,10);
				cout << "chua co du lieu";
			}
			else
			{
				taoBangBookMark();
				int m = 10;
				int n = 0;
				bool e = true;
				if (l3.head -> solieu == 6)
				{
					trangchu().taoGiaoDien(l3.head->data,6);
					taoBangBookMark();
				}				
				while (e)
				{
					TextColor(7);
					d = getch();
					if (d == 'a')
					{
						if (l3.head -> solieu == 6)
							trangchu().taoGiaoDien(l3.head -> data,6);
						else
							trangchu().taoGiaoDien(l3.head -> data,8);
						e = false;
					}
					else if (d == 80 ||d == 's'||d =='S'||d =='2')
					{
						if (n <= ut)
						{
							TextColor(202);
							gotoxy(155,m);
							cout << UaThich[n] << endl;
							if (m >= 11)
							{
								TextColor(7);
								gotoxy(155,m-1);
								cout << UaThich[n-1] << endl;
							}
							m++;
							n++;	
						}
								
					}
					else if (d == 72 || d == 'w'||d == 'W'||d == '8')
					{
						if (m > 10)
						{
							TextColor(7);
							m--;
							n--;
							if (m > 10)
							{
								gotoxy(155,m);
								cout << UaThich[n] << endl;
								TextColor(202);
								gotoxy(155,m-1);
								cout << UaThich[n-1] << endl;	
							}
							
						}
						
					}
					else if (d == 13 ||d =='e'||a=='E' ||d =='5')
					{
						string name = UaThich[n-1];
						string g = UaThich[n-2];
						int z;
						if (name == "back")
						{
							docFileMoi(l3.head -> data,z);
							e = false;
						}
						else
						{
							push (l3,name,8);
							docFileMoi(name,z);
							b1 = z;
							e = false;
						}
							
					}
				}
			}	
			    
		}
		else if (a == 10)
		{
			int i2 = khungTabMoi3();
			if (NewW[k1].Tab[i2].stack2.top != NULL || NewW[k1].Tab[i2].stack1.head != NULL)
			{
				NewW[k1].soTab = m;
				NewW[k1].so_i = i2;
				NewW[k1].so_l = l;
				if (NewW[k1].Tab[i2].index == 0)
				{
					system("cls");
					khungNewWindowMoi2();
					khungTabMoi2();
					NewW[k1].Tab[i2].index = 0;
					feature(NewW[k1].Tab[i2].index,NewW[k1].Tab[i2].stack1,NewW[k1].Tab[i2].stack2,k1);	
				}
				else if (NewW[k1].Tab[i2].stack1.head ->  solieu == 6)
				{
					trangchu().taoGiaoDien(NewW[k1].Tab[i2].stack1.head->data,6);
					NewW[k1].Tab[i2].index = 8;
					feature(NewW[k1].Tab[i2].index,NewW[k1].Tab[i2].stack1,NewW[k1].Tab[i2].stack2,k1);
				}
				else
				{
					int z;
					docFileMoi(NewW[k1].Tab[i2].stack1.head -> data,z);
					b1 = z;
					NewW[k1].Tab[i2].index = b1;
					feature(NewW[k1].Tab[i2].index,NewW[k1].Tab[i2].stack1,NewW[k1].Tab[i2].stack2,k1);
				}
				
			}
			else 
			{
				system("cls");
				khungNewWindowMoi2();
				khungTabMoi2();		
				NewW[k1].Tab[i2].index = 0;
				NewW[k1].soTab = m;
				NewW[k1].so_i = i2;
				NewW[k1].so_l = l;
				feature(NewW[k1].Tab[i2].index,NewW[k1].Tab[i2].stack1,NewW[k1].Tab[i2].stack2,k1);	
			}
		}
		else if (a == 11)
		{
			system("cls");
			khungNewWindowMoi2();
			khungTabMoi2();
			b = 0;
			string w;
			w = ' ';
			push (l3,w,b);
		}
		else if (a == 12)
		{
			k1 = khungNewWindowMoi3();
			if (NewW[k1].soTab == 0)
			{
				system("cls");
				khungNewWindowMoi2();
				m = 1;
				i = 1;
				l = 0;
				NewW[k1].soTab = m; 
				NewW[k1].so_i = i;
				NewW[k1].so_l = l;	
//				cout << "NewW[k1].soTab: " << NewW[k1].soTab << endl;
//				cout  << "NewW[k1].so_i: " << NewW[k1].so_i << endl;
//				cout << "NewW[k1].so_l: "<< NewW[k1].so_l << endl;
				khungTab();
				b = 0;
				feature(b,NewW[k1].Tab[NewW[k1].so_i].stack1,NewW[k1].Tab[NewW[k1].so_i].stack2,k1);	
			}
			else
			{
				system("cls");
				m = NewW[k1].soTab;
				i = NewW[k1].so_i;
				l = NewW[k1].so_l;
				khungNewWindowMoi1();
				khungTabMoi1();
				gotoxy (44,7);
				docFile(NewW[k1].Tab[i].stack1.head -> data);
				i++;
				feature(NewW[k1].Tab[i].index,NewW[k1].Tab[i].stack1,NewW[k1].Tab[i].stack2,k1);
			}
		}
		else
		{
			cout <<"chua cai dat nen dung co nhan lung tung" <<  endl;
		}
	}
	if (c == false)
	{
		system("cls");
		cout << "ban da thoat khoi trinh duyet";
	}
}

int main ()
{
	resizeConsole(1920,920);
	int b = 0;// luu vao vi tri cac nut bam de in ra cac khung phu hop
	int k1 = khungNewWindow();
	int i3 = khungTab ();
	cout << "k1: " << k1 << endl;
	cout << "i3: " << i3 << endl;
	NewW[k1].Tab[i3].index = 0;
	NewW[k1].Tab[i3].index2 = b;
	NewW[k1].Tab[i3].stack1.head = NULL;
	NewW[k1].Tab[i3].stack2.top = NULL;
	NewW[k1].soTab = m;
	NewW[k1].so_i = i3;
	NewW[k1].so_l = l;
	feature(NewW[k1].Tab[i3].index,NewW[k1].Tab[i3].stack1,NewW[k1].Tab[i3].stack2,k1);	
    //cout << Tab[i].stack1.head -> data;
	return 0;
}
