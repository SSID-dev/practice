#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int map[21][21];
int tmap[21][21];
int sum[5];
int answer = 10000000;
void set(int x, int y, int d1, int d2){
    memset(tmap, 0, sizeof(tmap));
    memset(sum, 0, sizeof(sum));
    for(int i = 0; i <= d1; i++){
        tmap[x + i][y - i] = 5;
        tmap[x + d2 + i][y + d2 - i] = 5;
    }
    for(int i = 0; i <= d2; i++){
        tmap[x + i][y + i] = 5;
        tmap[x + d1 + i][y - d1 + i] = 5;
    }
    for(int i = 0; i < d2; i++){
        int t = 1;
        while(tmap[x + i + t][y + i] != 5){
            tmap[x + i + t][y + i] = 5; t++;
        }
    }
    for(int i = 0; i < d1; i++){
        int t = 1;
        while(tmap[x + i + t][y - i] != 5){
            tmap[x + i + t][y - i] = 5; t++;
        }
    }
    for(int xx = 1; xx <= n; xx++){
        for(int yy = 1; yy <= n; yy++){
            if(tmap[yy][xx] == 5) sum[4] = sum[4] + map[yy][xx];
            else{
                if(yy >= 1 && yy < x + d1 && xx >= 1 && xx <= y){
                    sum[0] = sum[0] + map[yy][xx]; tmap[yy][xx] = 1;
                }
                else if(yy >= 1 && yy <= x + d2 && xx > y && xx <= n){
                    sum[1] = sum[1] + map[yy][xx]; tmap[yy][xx] = 2;
                }
                else if(yy >= x + d1 && yy <= n && xx >= 1 && xx < y - d1 + d2){
                    sum[2] = sum[2] + map[yy][xx]; tmap[yy][xx] = 3;
                }
                else if(yy > x + d2 && yy <= n && xx >= y - d1 + d2 && xx <= n){
                    sum[3] = sum[3] + map[yy][xx]; tmap[yy][xx] = 4;
                }
            }
        }
    }
    sort(sum, sum + 5);
    answer = min(answer, sum[4] - sum[0]);
}
void div(){
    for(int x = 1; x <= n; x++){
        for(int y = 1; y <= n; y++){
            for(int d1 = 1; d1 <= n; d1++){
                if(x + d1 > n || y - d1 <= 0) continue;
                for(int d2 = 1; d2 <= n; d2++){
                    if(x + d1 + d2 > n || y - d1 + d2 > n || x + d2 + d1 > n || y + d2 - d1 <= 0) continue;
                    set(x, y, d1, d2);
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }
    div();
    cout << answer;
    return 0;
}