#pragma once
#include "DxLib.h"
#include "player.h"
#include "puyo.h"
#include "stage.h"
#include <ctime>       
#include <cstdlib>    
player::player() {
    puyoX = initpuyoX;
    puyoR = initpuyoR;
    puyoC1 = 0;
    puyoC2 = 0;
    puyoY = initpuyoY;
    endGame = false;
}
void player::Move() {
    if (canMove = true) {
        if (key[KEY_INPUT_LEFT] ==1) {//左キー入力
            switch (puyoR) {
            case 0:
            case 1:
            case 2:
                if (S.stagecell[puyoX - 1][(int)((puyoY - S.displayy) / 16)] == 5) {
                    --puyoX;
                }
                break;
            case 3:
                if (S.stagecell[puyoX - 2][(int)((puyoY - S.displayy) / 16)] == 5) {
                    --puyoX;
                }
                break;
            }
        }
        else if (key[KEY_INPUT_RIGHT] ==1) {//右キー入力
            switch (puyoR) {
            case 0:
            case 2:
            case 3:
                if (S.stagecell[puyoX + 1][(int)((puyoY - S.displayy) / 16)] == 5) {
                    ++puyoX;
                }
                break;
            case 1:
                if (S.stagecell[puyoX + 2][(int)((puyoY - S.displayy) / 16)] == 5) {
                    ++puyoX;
                }
                break;
            }
        }
        if (key[KEY_INPUT_DOWN] > 1) {//下キー入力
            ++puyoY;
        }
    }

}
void player::Rotate() {
    if (canMove = true) {
        if (key[KEY_INPUT_X]==1) {//左キー入力
            switch (puyoR) {
            case 1:
            case 3:
                puyoR = (puyoR + 1) % 4;
                break;
            case 0:
                if (S.stagecell[puyoX + 1][(int)((puyoY - S.displayy) / 16)] != 5) {
                    --puyoX;
                    puyoR = (puyoR + 1) % 4;
                }
                else {
                    puyoR = (puyoR + 1) % 4;
                }
                break;
            case 2:
                if (S.stagecell[puyoX - 1][(int)((puyoY - S.displayy) / 16)] != 5) {
                    ++puyoX;
                    puyoR = (puyoR + 1) % 4;
                }
                else {
                    puyoR = (puyoR + 1) % 4;
                }
                break;
            }
        }else if (key[KEY_INPUT_Z] == 1) {//左キー入力
            switch (puyoR) {
            case 1:
            case 3:
                puyoR = (puyoR + 3) % 4;
                break;
            case 2:
                if (S.stagecell[puyoX + 1][(int)((puyoY - S.displayy) / 16)] != 5) {
                    --puyoX;
                    puyoR = (puyoR + 3) % 4;
                }
                else {
                    puyoR = (puyoR + 3) % 4;
                }
                break;
            case 0:
                if (S.stagecell[puyoX - 1][(int)((puyoY - S.displayy) / 16)] != 5) {
                    ++puyoX;
                    puyoR = (puyoR + 3) % 4;
                }
                else {
                    puyoR = (puyoR + 3) % 4;
                }
                break;
            }
        }


    }

}
void player::FallCheck() {
    bool fall = false;
    switch (puyoR) {
    case 0:
        if (puyoY + 16 > S.PlacePuyo(S.ceil[puyoX], S.displayy)) {
            fall = true;
        }
        break;
    case 1:
        if (puyoY + 16 > S.PlacePuyo(S.ceil[puyoX], S.displayy) || puyoY + 16 > S.PlacePuyo(S.ceil[puyoX+1], S.displayy)) {
            fall = true;
        }
        break;
    case 2:
        if (puyoY + 32 > S.PlacePuyo(S.ceil[puyoX], S.displayy)) {
            fall = true;
        }
        break;
    case 3:
        if (puyoY + 16 > S.PlacePuyo(S.ceil[puyoX], S.displayy) || puyoY + 16 > S.PlacePuyo(S.ceil[puyoX - 1], S.displayy)) {
            fall = true;
        }
        break;
    }
    if (fall==true) {
        canMove = false;
        SetPuyo();
        S.Combo();
        Genrerate();

   }


}
void player::DisplayRotate(int x, double y, int r,int c1,int c2) {
    switch (r) {
    case 0:
        DrawGraph(S.PlacePuyo(x, S.displayx), y, P.ImagePuyo[c1], TRUE);
        DrawGraph(S.PlacePuyo(x, S.displayx), y-16, P.ImagePuyo[c2], TRUE);
        break;
    case 1:
        DrawGraph(S.PlacePuyo(x, S.displayx), y, P.ImagePuyo[c1], TRUE);
        DrawGraph(S.PlacePuyo(x+1, S.displayx), y, P.ImagePuyo[c2], TRUE);
        break;
    case 2:
        DrawGraph(S.PlacePuyo(x, S.displayx), y, P.ImagePuyo[c1], TRUE);
        DrawGraph(S.PlacePuyo(x, S.displayx), y+16, P.ImagePuyo[c2], TRUE);
        break;
    case 3:
        DrawGraph(S.PlacePuyo(x, S.displayx), y, P.ImagePuyo[c1], TRUE);
        DrawGraph(S.PlacePuyo(x-1, S.displayx), y, P.ImagePuyo[c2], TRUE);
        break;
    }



}

void player::SetPuyo() {
    switch (puyoR) {
    case 0:
        S.stagecell[puyoX][--S.ceil[puyoX]] = puyoC1; 
        S.stagecell[puyoX][--S.ceil[puyoX]] = puyoC2; 
        break;
    case 1:
        S.stagecell[puyoX][--S.ceil[puyoX]] = puyoC1; 
        S.stagecell[puyoX+1][--S.ceil[puyoX+1]] = puyoC2; 
        break;
    case 2:
        S.stagecell[puyoX][--S.ceil[puyoX]] = puyoC2; 
        S.stagecell[puyoX][--S.ceil[puyoX]] = puyoC1;
        break;
    case 3:
        S.stagecell[puyoX][--S.ceil[puyoX]] = puyoC1; 
        S.stagecell[puyoX -1][--S.ceil[puyoX-1]] = puyoC2; 
        break;
    }
    S.AddScore();
}
void player::Genrerate() {
    srand(time(NULL));
    puyoX = initpuyoX;
    puyoY = initpuyoY;
    puyoR = initpuyoR;
    puyoC1 = P.tmp[0][0];
    puyoC2 = P.tmp[0][1];
    canMove = true;  //ぷよをセットして動かせるように

    for (int i = 1; i < 3; ++i) { //tmpをずらす
        for (int j = 0; j < 2; ++j) {
            P.tmp[i - 1][j] = P.tmp[i][j];
        }
    }
    for (int i = 0; i < 2; ++i) {//tmp[3][]に補充
        P.tmp[2][i] = rand() % 4;
    }
}
void player::UpdatateKey() {
    char tmpKey[256]; 
    GetHitKeyStateAll(tmpKey); 
    for (int i = 0; i < 256; i++) {
        if (tmpKey[i] != 0) { 
            key[i]++;    
        }
        else {              
            key[i] = 0;   
        }
    }
}
int player::FinishCheck() { //ゲームオーバー判定
    bool finish = false;
    if (S.stagecell[3][1] != 5) {
        endGame = true;
        return S.scorePoint; 
    }
    for (int i = 1; i <= 6; i++) {
        if (S.stagecell[i][0] != 5) {
            endGame = true;
            return S.scorePoint;
        }
    }
  
    return 0;
}
int player::FinishCheck(bool b) {//未使用 消してもいい
    if (b == true) {
        endGame = true;
        return S.scorePoint;
    }
    else {
        return 0;
    }
}
void player::PlayPuyo() {
    S.Display();
    UpdatateKey();
    if (endGame == false) {
        if (canMove == false) {
            Genrerate();
        }
        Move(); Rotate();
        puyoY += puyoS;
        DisplayRotate(puyoX, puyoY, puyoR, puyoC1, puyoC2);
        FallCheck();
        S.IntegrityCheck();
    }
    P.DisplayNextPuyo();

}
