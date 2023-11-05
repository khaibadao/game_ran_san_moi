#include "mylib.h"
using namespace std;
void ve_tuong_tren(){
	int x = 5, y = 4;
	while(x <= 96){
		SetColor(11);
		gotoXY(x, y);
		cout << "=";
		Sleep(10);
		x++;
	}
}
void Ve_tuong_phai(){
	int x = 96, y = 5;
	SetColor(12);
	while(y <= 34){
		gotoXY(x, y);
		cout << "<";
		Sleep(50);
		y++;
	}
}
void ve_tuong_duoi(){
	int x = 96, y = 34;
	SetColor(11);
	while(x >= 5){
		gotoXY(x, y);
		cout << "=";
		Sleep(10);
		x--;
	}
}
void ve_tuong_trai(){
	int x = 5;
	SetColor(12);
	for(int i = 33 ; i >= 5 ; i--){
		gotoXY(x, i);
		cout << ">";
		Sleep(50);
	}
}

