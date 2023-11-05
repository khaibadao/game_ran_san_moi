#include <iostream>
#include "mylib.h"
#include "Ve_tuong.h"
//#include "Thu_nghiem.h"
#define MAX 100
using namespace std;

// bien toan cuc
int chieu_dai_ran = 2;
bool game_continue = true;
bool kt2 = true;
int Toa_do_x[MAX], Toa_do_y[MAX];
int Xqua, Yqua;
bool Nguoc_tro_lai = true;
int your_point = 0;
int mau_qua = 7, mau_qua_cu = mau_qua;
int toc_do = 0;
int che_do_tro_choi = 0;

// cac ham 

int random_qua(){ // ham random qua :))
	return 1 + rand() % (15 - 1 + 1);
}
void khoi_tao_ran(int Toa_do_x[], int Toa_do_y[]){ // ham khoi tao ran
	int x = 30, y = 16;
	for(int i = 0 ; i < chieu_dai_ran ; i++){
		Toa_do_x[i] = x;
		Toa_do_y[i] = y;
		x--;
	}
}

void tao_hinh_ran(int Toa_do_x[], int Toa_do_y[]){ // ham tao hinh ran
	for(int i = 0 ; i < chieu_dai_ran ; i++){
		gotoXY(Toa_do_x[i], Toa_do_y[i]);
		if(i == 0){
			cout << "0";
		}else
		{
			cout << "o";
		}
	}
}

void them(int mang[], int x){ // them du lieu moi
	for(int i = chieu_dai_ran; i > 0 ; i--){
		mang[i] = mang[i - 1];
	}
	mang[0] = x;
    chieu_dai_ran++;
}

void xoa(int mang[], int vi_tri){ // xoa du lieu cu
	for(int i = vi_tri ; i < chieu_dai_ran ; i++){
		mang[i] = mang[i + 1];
	}
    chieu_dai_ran--;
}

void man_hinh_hien_thi(){ // khung hien thi dau tien 
	int i = 1;
		// kiem tra cham bien
		// X bien trai : 5, X bien phai : 96
		// Y tren : 1, Y duoi : 30
		
	for(int i = 18 ; i < 62 ; i++){
		gotoXY(i, 1);
		SetColor(9);
		cout << "*";
	}
	for(int i = 18 ; i < 62 ; i++){
		gotoXY(i, 19);
		SetColor(9);
		cout << "*";
	}
	for(int i = 1 ; i <= 19 ; i++){
		gotoXY(18, i);
		cout << "*";
	}
	for(int i = 1 ; i <= 19 ; i++){
		gotoXY(62, i);
		cout << "*";
	}
	SetColor(12);
	gotoXY(35, 2);
	cout << "XIN CHAO !!";
	gotoXY(22, 4);
	cout << "GAME RAN SAN MOI :))";
	gotoXY(22, 6);
	cout << "CAC NUT DUY CHUYEN : "; SetColor(10); cout << "W"; SetColor(11); cout << " : Di Len";
	gotoXY(22, 7);
	cout << "                     "; SetColor(15); cout << "S"; SetColor(11); cout << " : Di Xuong";
	gotoXY(22, 8);
	cout << "                     "; SetColor(13); cout << "A"; SetColor(11) ; cout << " : Qua Trai";
	gotoXY(22, 9);
    cout << "                     "; SetColor(14); cout << "D"; SetColor(11); cout << " : Qua Phai";
    gotoXY(22, 11);
    SetColor(12);
    cout << "Quy Luat:"; SetColor(11); cout << "+ Khi ran cham vao tuong thi";
	gotoXY(22, 12);
	cout << "tro choi se ket thuc !!! ";
	gotoXY(31, 14);
	cout << "+ Khi ran cham vao duoi hoac";
    gotoXY(22, 15);
	cout << "vao than tro choi se ket thuc !!!";
    gotoXY(22, 17);
    SetColor(12);
    cout << "Chuc ban choi vui ve :))";
}

void che_do() // che do cua game 
{
	int i = 1;
	int x = 14, y = 23;
	int xcu = x, ycu = y;
	int check = 1;
	bool kt = true;
	while(kt == true){ 
		while(check == 0){
			SetColor(i);
			i++;
			if(i > 15){
				i = 1;
			}
			gotoXY(xcu, ycu);
			cout << " ";
			gotoXY(x, y);
			cout << "ooo0";
			gotoXY(53, y);
			cout << "$";
			xcu = x, ycu = y;
			Sleep(120);
			x++;
			if(x == 51){
		    	break;
     	    }
		}
		if(x == 51 && y == 23){
			che_do_tro_choi = 1;
			break;
		}else if(x == 51 && y == 25){
			che_do_tro_choi = 2;
			break;
		}else if(x == 51 && y == 27)
		{
//			system("cls");
//			SetColor(15);
//			gotoXY(23, 10);
//			cout << "Bai :))";
			kt2 = false;
			break;
		}
		if(i > 15){
			i = 1;
		}
		i++;
		SetColor(i);
		gotoXY(xcu, ycu);
		cout << "    ";
		gotoXY(53, ycu);
		cout << " ";
		gotoXY(x, y);
		cout << "ooo0";
		gotoXY(53, y);
		cout << "$";
		xcu = x; ycu = y;
		Sleep(100);
		
		gotoXY(27, 23);
		SetColor(14);
		cout << "Nomal  -- > Space !!!   " ;
		gotoXY(27, 25);
		cout << "Across -- > Space !!!  ";
		gotoXY(27, 27);
		SetColor(14);
		cout << "EXIT  -- > Space !!!   " ;
		
		gotoXY(20 - 6, 27 - 6);
		SetColor(12);
		cout << "  (Dung W va D de dich chuyen va phim Space de chon)";
		
		if(_kbhit()){
			char ki_tu = _getch();
			if(ki_tu == 'w' && y > 23){
				y -= 2;
			}else if(ki_tu =='s' && y < 27){
				y += 2;
			}else if(ki_tu == ' '){
				check = 0;
			}
		}
	}
	
	// Phan toc do
	if(kt2 == true){
		gotoXY(14, 23);
		cout << "                                                                    ";
		gotoXY(14, 25);
		cout << "                                                                    ";
		gotoXY(14, 27);
		cout << "                                                                    ";
		// vi tri cua x(cua con ran) : 14, y (cua con ran) : 23;
		// vi tri cua De : x(27), y(23)
		// vi tri $ la x = 51, y = 23 || y = 25
		
	    i = 1;
	    x = 14, y = 23;
	    check = 1;
	    xcu = x; ycu = y;
		while(true){
			while(check == 0){
				SetColor(i);
				i++;
				if(i > 15){
					i = 1;
				}
				gotoXY(xcu, ycu);
				cout << " ";
				gotoXY(x, y);
				cout << "ooo0";
				gotoXY(53, y);
				cout << "$";
				xcu = x, ycu = y;
				Sleep(120);
				x++;
				if(x == 51){
			    	break;
	     	    }
			}
			if(x == 51 && y == 23){
				toc_do = 100;
				system("cls");
				SetColor(14);
				gotoXY(45 - 7, 15);
	    		cout << "LOADING ";
				for(int i = 1 ; i <= 100; i++){
					gotoXY(54 - 7 , 15);
					Sleep(40);
					cout << i << "%";
				}
				system("cls");
				break;
			}else if(x == 51 &&  y == 25){
				toc_do = 40;
				system("cls");
				SetColor(14);
				gotoXY(45 - 7, 15);
	    		cout << "LOADING ";
				for(int i = 1 ; i <= 100; i++){
					gotoXY(54 - 7 , 15);
					Sleep(50);
					cout << i << "%";
				}
				system("cls");
				break;
			}
			if(i > 15){
				i = 1;
			}
			
			SetColor(i);
			gotoXY(xcu, ycu);
			cout << "    ";
			gotoXY(53, ycu);
			cout << " ";
			gotoXY(x, y);
			cout << "ooo0";
			gotoXY(53, y);
			cout << "$";
			xcu = x, ycu = y;
			
			gotoXY(27, 23); //  de
			SetColor(14);
			cout << "EASY ---> SPACE !!!";
			
			gotoXY(27, 25);  //  kho 
			SetColor(11);
			cout << "HARD ---> SPACE !!!";
			
			if(_kbhit()){
				char ki_tu = getch();
				if(ki_tu == 'w' && y > 23){
					y -= 2;
				}else if(ki_tu == 's' && y == 23){
					y += 2;
				}else if(ki_tu == ' '){
					check = 0;
				}
			}
			i++;
			Sleep(100);
		}
	}
	
}

int ran_cham_duoi(int Toa_do_x[], int Toa_do_y[]){ // ham kiem tra ran cham duoi ---> end chuong trinh
	for(int i = 1 ; i < chieu_dai_ran ; i++){
		if(Toa_do_x[0] == Toa_do_x[i] && Toa_do_y[0] == Toa_do_y[i]){
			return 0;
		}
	}
	return 1;
}

int Qua_on_ran(int Xqua, int Yqua, int toa_do_x[], int toa_do_y[]){ // kiem tra qua co trung voi ran khi sinh hay khong
	for(int i = 0 ; i < chieu_dai_ran ; i++){
		if((Xqua == toa_do_x[i]) &&(Yqua == toa_do_y[i])){
			return 0;
		}
	}
	return 1;
}

int Check_ran_an_qua(int Xqua, int Yqua, int x0, int y0){ // ham kiem tra ran an qua hay chua
	if(Xqua == x0 && Yqua == y0){
		mau_qua_cu = mau_qua;
		return 1;
	}else
	{
		return 0;
	}
}

void Tao_qua(int &Xqua,int &Yqua, int toa_do_x[], int toa_do_y[]){ // ham khoi tao qua
//	Xqua = 6 + rand() % (95 - 6 + 1);
//	Yqua = 3 + rand() % (29 - 3 + 1);
//    // x = 5 ---> x = 96
//    // y = 2 ---> y = 30
    do
    {
    	Xqua = 6 + rand() % (95 - 6 + 1);
     	Yqua = 6 + rand() % (32 - 6 + 1);
	}
    while(Qua_on_ran(Xqua, Yqua, toa_do_x, toa_do_y) != 1);
    gotoXY(Xqua, Yqua);
    mau_qua = random_qua();
	SetColor(mau_qua);
    cout << "$";
}

void Xu_ly_ran(int toa_do_x[], int toa_do_y[] , int x, int y, int &Xqua, int &Yqua){ // ham xu ly ran
	them(toa_do_x, x);
	them(toa_do_y, y);
	if(Check_ran_an_qua(Xqua, Yqua, toa_do_x[0], toa_do_y[0]) == 0){
		xoa(toa_do_x, chieu_dai_ran - 1);
    	xoa(toa_do_y, chieu_dai_ran - 1);
	}else
	{
		Tao_qua(Xqua, Yqua, toa_do_x, toa_do_y);
		your_point += 10;
	}
	SetColor(mau_qua_cu);
	tao_hinh_ran(toa_do_x, toa_do_y);
}

void Xoa_ki_tu_cu(int toa_do_x[], int toa_do_y[]){ // ham xoa ki tu
	for(int i = 0 ; i < chieu_dai_ran ; i++){
		gotoXY(toa_do_x[i], toa_do_y[i]);
		cout << " ";
	}
}

// che_do_tro_choi = 1 : con ran cham tuong se die
// che_do_tro_choi = 2 : con ran di xuyen tuong

void con_ran_di_xuyen_tuong() // che do ran di xuyen tuong 
{
	
}

int main()
{
	char ki_tu_check = 'o';
	unsigned int x = 12, y = 6;	
    unsigned int xcu = x, ycu = y;
	unsigned int check = 2;
	while(Nguoc_tro_lai){
		man_hinh_hien_thi();
	    che_do();
		if(kt2 == false){
        	system("cls");
        	SetColor(11);
        	gotoXY(23, 10);
        	cout << "Hay nhin len goc tren ben phai man hinh :))";
        	gotoXY(27, 12);
        	SetColor(11);
            cout << "Thay dau "; 
			SetColor(4);
			cout << 'X';
			SetColor(11);
			cout << " khum :))";
        	int mau = 1;
        	while(true){
        		if(mau > 15){
        			mau = 1;
				}
				SetColor(mau);
				mau++;
				gotoXY(0, 14);
				Sleep(200);
				cout << "                               Bye :))";
				
			}
//			char ki_tu = getch();
    	}else
    	{
    		if(che_do_tro_choi == 1){
			   	srand(time(NULL));
		        ve_tuong_tren();
		    	Ve_tuong_phai();
		    	ve_tuong_duoi();
		    	ve_tuong_trai();
		    	SetColor(7);
		    	khoi_tao_ran(Toa_do_x, Toa_do_y);
		     	Tao_qua(Xqua, Yqua, Toa_do_x, Toa_do_y);
				while(game_continue){
					Xoa_ki_tu_cu(Toa_do_x, Toa_do_y);
					if(check == 0){
						y++;
					}else if(check == 1){
						y--;
					}
					// di qua trai qua phai
					if(check == 2){
						x++;
					}else if(check == 3){
						x--;
					}
					
					// nhap ki tu va xu ly nhap ki tu
					if(_kbhit()){
						char ki_tu = _getch();
						if(ki_tu == 'w' && ki_tu_check != 's'){
							check = 1;
							ki_tu_check = ki_tu;
						}else if(ki_tu ==  's' && ki_tu_check != 'w'){
							check = 0;
							ki_tu_check = ki_tu;
						}else if(ki_tu == 'a' && ki_tu_check != 'd'){
							check = 3;
							ki_tu_check = ki_tu;
						}else if(ki_tu == 'd' && ki_tu_check != 'a'){
							check = 2;
							ki_tu_check = ki_tu;
						}
					}
						
					// kiem tra cham bien
					// X bien trai : 5, X bien phai : 96
					// Y tren : 1, Y duoi : 30
					
					if(y == 4){
						game_continue = false;
					}else if(y == 34){
						game_continue = false;
					}else if(x == 5){
						game_continue = false;
					}else if(x == 96){
				    	game_continue = false;
					}else if(ran_cham_duoi(Toa_do_x, Toa_do_y) == 0){
						game_continue = false;
					}
			//		game_continue = ran_cham_duoi(Toa_do_x, Toa_do_y);
					Xu_ly_ran(Toa_do_x, Toa_do_y, x, y, Xqua, Yqua);
					gotoXY(1, 2);
					SetColor(14);
					cout << "Point : " << your_point;
					Sleep(toc_do);
				}
			}else if(che_do_tro_choi == 2)
			{
				srand(time(NULL));
		        ve_tuong_tren();
		    	Ve_tuong_phai();
		    	ve_tuong_duoi();
		    	ve_tuong_trai();
		    	SetColor(7);
		    	khoi_tao_ran(Toa_do_x, Toa_do_y);
		     	Tao_qua(Xqua, Yqua, Toa_do_x, Toa_do_y);
				while(game_continue){
					Xoa_ki_tu_cu(Toa_do_x, Toa_do_y);
					if(check == 0){
						y++;
					}else if(check == 1){
						y--;
					}
					// di qua trai qua phai
					if(check == 2){
						x++;
					}else if(check == 3){
						x--;
					}
					
					// nhap ki tu va xu ly nhap ki tu
					if(_kbhit()){
						char ki_tu = _getch();
						if(ki_tu == 'w' && ki_tu_check != 's'){
							check = 1;
							ki_tu_check = ki_tu;
						}else if(ki_tu ==  's' && ki_tu_check != 'w'){
							check = 0;
							ki_tu_check = ki_tu;
						}else if(ki_tu == 'a' && ki_tu_check != 'd'){
							check = 3;
							ki_tu_check = ki_tu;
						}else if(ki_tu == 'd' && ki_tu_check != 'a'){
							check = 2;
							ki_tu_check = ki_tu;
						}
					}
						
					// kiem tra cham bien
					// X bien trai : 5, X bien phai : 96
					// Y tren : 1, Y duoi : 30
					
					if(y == 4){
						y = 33;
					}else if(y == 34){
						y = 5;
					}else if(x == 5){
						x = 95;
					}else if(x == 96){
				    	x = 6;
					}else if(ran_cham_duoi(Toa_do_x, Toa_do_y) == 0){
						game_continue = false;
					}
			//		game_continue = ran_cham_duoi(Toa_do_x, Toa_do_y);
					Xu_ly_ran(Toa_do_x, Toa_do_y, x, y, Xqua, Yqua);
					gotoXY(1, 2);
					SetColor(14);
					cout << "Point : " << your_point;
					Sleep(toc_do);
				}
			}
		}
		system("cls");
		gotoXY(15, 10);
		SetColor(11);
		cout << "Ban da thua :)) ";
		gotoXY(15, 12);
		cout << "Diem cua ban la : "; SetColor(12); cout << your_point << " diem";
		gotoXY(15, 14);
		SetColor(11);
		cout << "Ta se quay lai man hinh chinh sau : ";
		for(int i = 7; i >= 0 ; i--){
			gotoXY(53, 14);
			cout << i << "s            ";
			Sleep(700);
		}
		your_point = 0;
		game_continue = true;
		kt2 = true;
		x = 20 - 10; y = 5;
		chieu_dai_ran = 2;
		check = 2;
		system("cls");
	}
	return 0;
}   
