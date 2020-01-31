#include <iostream>
#include <cstdio>
using namespace std;
int tob[5][9];
int k;
void spin(int num, int dir){
    if(dir == 1){ // 시계 방향
        for(int i = 8; i >= 2; i--){
            swap(tob[num][i], tob[num][i - 1]);
        }
    }else if(dir == -1){ // 반시계 방향  
        for(int i = 1; i <= 7; i++){
            swap(tob[num][i], tob[num][i + 1]);
        }
    }
}
void solution(int num, int dir){
    if(num == 1){
        if(tob[1][3] != tob[2][7]){
            if(tob[2][3] != tob[3][7]){
                if(tob[3][3] != tob[4][7]){
                    spin(4, dir*(-1));
                }
                spin(3, dir);
            }
            spin(2, dir*(-1));
        }
        spin(num, dir);
    }else if(num == 2){
        if(tob[2][3] != tob[3][7]){
            if(tob[3][3] != tob[4][7]){
                spin(4, dir);
            }
            spin(3, dir*(-1));
        }
        if(tob[2][7] != tob[1][3]){
            spin(1, dir*(-1));
        }
        spin(num, dir);
    }else if(num == 3){
        if(tob[3][7] != tob[2][3]){
            if(tob[2][7] != tob[1][3]){
                spin(1, dir);
            }
            spin(2, dir*(-1));
        }
        if(tob[3][3] != tob[4][7]){
            spin(4, dir*(-1));
        }
        spin(num, dir);
    }else if(num == 4){
        if(tob[4][7] != tob[3][3]){
            if(tob[3][7] != tob[2][3]){
                if(tob[2][7] != tob[1][3]){
                    spin (1, dir*(-1));
                }
                spin(2, dir);
            }
            spin(3, dir*(-1));
        }
        spin(num, dir);
    }
}
int main(){
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 8; j++){
            scanf("%1d", &tob[i][j]);
        }
    }
    scanf("%d", &k);
    while(k--){
        int tobNum, dir;
        scanf("%d %d", &tobNum, &dir);
        solution(tobNum, dir);
    }
    int sum = 0;
    if(tob[1][1] == 1) sum += 1;
    if(tob[2][1] == 1) sum += 2;
    if(tob[3][1] == 1) sum += 4;
    if(tob[4][1] == 1) sum += 8;
    printf("%d\n", sum);
}