#include <iostream>
#include <cstring>
using namespace std;
#define MAX 9
#define endl "\n"
struct POS{
    int y, x, n;
};
POS cctv[8];
int n, m;
int totalNum = 9999;
int map[MAX][MAX];
int cctvTotalNum;
bool cctvCheck[8];
void move(int y, int x, int dir){
    dir = (dir % 4);
    if(dir == 0){
        for(int i = x; i < m; i++){
            if(map[y][i] == 6) break;
            map[y][i] = 9;
        }
    }else if(dir == 1){
        for(int i = y; i >= 0; i--){
            if(map[i][x] == 6) break;
            map[i][x] = 9;
        }
    }else if(dir == 2){
        for(int i = x; i >= 0; i--){
            if(map[y][i] == 6) break;
            map[y][i] = 9;
        }
    }else if(dir == 3){
        for(int i = y; i < n; i++){
            if(map[i][x] == 6) break;
            map[i][x] = 9;
        }
    }
}
void dfs(int cnt, int num){
    if(cnt == cctvTotalNum){
        int sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(map[i][j] == 0){
                    sum++;
                }
            }
        }
        if(sum < totalNum){
            totalNum = sum;
        }
        return ;
    }
    for(int i = num; i < cctvTotalNum; i++){
        if(cctvCheck[i]) continue;
        cctvCheck[i] = true;
        int temp[MAX][MAX];
        memcpy(temp, map, sizeof(temp));
        if(cctv[i].n == 1){
            for(int dir = 0; dir < 4; dir++){
                move(cctv[i].y, cctv[i].x, dir);
                dfs(cnt + 1, i + 1);
                memcpy(map, temp, sizeof(map));
            }
        }else if(cctv[i].n == 2){
            for(int dir = 0; dir < 2; dir++){
                move(cctv[i].y, cctv[i].x, dir);
                move(cctv[i].y, cctv[i].x, dir + 2);
                dfs(cnt + 1, i + 1);
                memcpy(map, temp, sizeof(map));
            }
        }else if(cctv[i].n == 3){
            for(int dir = 0; dir < 4; dir++){
                move(cctv[i].y, cctv[i].x, dir);
                move(cctv[i].y, cctv[i].x, dir + 1);
                dfs(cnt + 1, i + 1);
                memcpy(map, temp, sizeof(map));
            }
        }else if(cctv[i].n == 4){
            for(int dir = 0; dir < 4; dir++){
                move(cctv[i].y, cctv[i].x, dir);
                move(cctv[i].y, cctv[i].x, dir + 1);
                move(cctv[i].y, cctv[i].x, dir + 2);
                dfs(cnt + 1, i + 1);
                memcpy(map, temp, sizeof(map));
            }
        }else if(cctv[i].n == 5){
            move(cctv[i].y, cctv[i].x, 0);
            move(cctv[i].y, cctv[i].x, 1);
            move(cctv[i].y, cctv[i].x, 2);
            move(cctv[i].y, cctv[i].x, 3);
            dfs(cnt + 1, i + 1);
            memcpy(map, temp, sizeof(map));
        }
        cctvCheck[i] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] >= 1 && map[i][j] <= 5){
                cctv[cctvTotalNum].y = i;
                cctv[cctvTotalNum].x = j;
                cctv[cctvTotalNum].n = map[i][j];
                cctvTotalNum++;
            }
        }
    }
    dfs(0, 0);
    cout << totalNum;
}