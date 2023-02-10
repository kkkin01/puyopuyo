#include"menu.h"
#include"DxLib.h"

void menu::Draw() {
    DrawFormatStringToHandle(100, 50, GetColor(255, 255, 255), Font01, "ééçÏÉQÅ[ÉÄ14(Ç’ÇÊÅj", 8);
    gpUpdateKey();
    if (Key[KEY_INPUT_DOWN] == 1) { 

        SelectNum = (SelectNum + 1) % 4; 

        for (int i = 0; i < 4; i++) {             
            if (i == SelectNum) {         
                Menu[i].x = 80; 
            }
            else {
                Menu[i].x = 100;
            }
        }
    }else if (Key[KEY_INPUT_UP] == 1) {

        SelectNum = (SelectNum + 3) % 4;

        for (int i = 0; i < 4; i++) {
            if (i == SelectNum) {
                Menu[i].x = 80;
            }
            else {
                Menu[i].x = 100;
            }
        }
    }
    for (int i = 0; i < 4; i++) { 
        DrawFormatString(Menu[i].x, Menu[i].y, GetColor(255, 255, 255), Menu[i].name);
    }

}
int menu::Update() {
    if (Key[KEY_INPUT_Z] == 1) {
        return SelectNum+1;
    }
    else {
        return 5;
    }

}
int menu::gpUpdateKey() {
    char tmpKey[256]; 
    GetHitKeyStateAll(tmpKey); 
    for (int i = 0; i < 256; i++) {
        if (tmpKey[i] != 0) { 
            Key[i]++;     
        }
        else {              
            Key[i] = 0;   
        }
    }
    return 0;
}
