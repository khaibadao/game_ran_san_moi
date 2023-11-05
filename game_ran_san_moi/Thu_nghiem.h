void Tao_qua(int $Xqua, $Yqua){
	Xqua = 6 + rand() % (95 - 6 + 1);
	Yqua = 3 + rand() % (29 - 3 + 1);
    // x = 5 ---> x = 96
    // y = 2 ---> y = 30
    gotoXY(Xqua,Yqua);
}
bool ran_cham_duoi(int Toa_do_y, int Toa_do_y){
	for(int i = 1 ; i < chieu_dai_ran ; i++){
		if(Toa_do_x[0] == Toa_do_x[i] || Toa_do_y[0] == Toa_do_y[i]){
			return false;
		}
	}
	return true;
}
