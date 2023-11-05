void man_hinh_hien_thi(){
	SetColor(12);
	bool bien = true;
	int i = 1;
		// kiem tra cham bien
		// X bien trai : 5, X bien phai : 96
		// Y tren : 1, Y duoi : 30
	gotoXY(15, 1);
	for(int i = 15 ; i < 45 ; i++){
		gotoXY(i, y);
		cout << "=";
	}
	gotoXY(15, 7);
	for(int i = 15 ; i < 45 ; i++){
		gotoXY(i, y);
		cout << "=";
	}
while(bien){
		cout << endl << endl << endl;
		gotoXY(40 - 15, 3);
		SetColor(12);
		cout << "Lai la game Snack san moi :PP";
		cout << endl << endl << endl;
		gotoXY(50 - 15, 6);
		SetColor(11);
		cout << "Play (1)";
		cout << endl << endl;
		gotoXY(50 - 15, 9);
		cout << "Exit (2)" << endl;
		gotoXY(28, 11),
		cout << "---- >  " ; int ki_tu; cin >> ki_tu;
		while(ki_tu != 1 && ki_tu != 2){
			cout << "Ko hop le vui long nhap lai : ";
			cin >> ki_tu;
		}
		if(ki_tu == 1){
			system("cls");
			gotoXY(50, 15);
			SetColor(11);
			cout << "LOADING ";
			for(int i = 1 ; i <= 100 ; i++){
				Sleep(100);
				gotoXY(59, 15);
				cout << i << "%" ;
			}
			system("cls");
		}else
		{
			if(ki_tu == 2){
				system("cls");
		    	gotoXY(50 - 15, 10);
		    	SetColor(11);
		    	cout << "Bai :))";
		    	kt = false;
			}
		}
		bien = false;
	}
}
