#include <iostream>
using namespace std;
#define MAX 20
#define endl "\n"
const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};
int n, m, x, y, k;
int map[MAX][MAX];
int dice[6] = {0, 0, 0, 0, 0, 0};
struct POS{
    int y, x;
};
POS dicePos;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> x >> y >> k;
    dicePos.y = x; dicePos.x = y;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    int cmd;
    int ny = 0, nx = 0;
    while(k--){
        cin >> cmd;
        if(cmd == 1){ // 동
            ny = dy[cmd - 1] + dicePos.y; nx = dx[cmd - 1] + dicePos.x;
        }else if(cmd == 2){ // 서
            ny = dy[cmd - 1] + dicePos.y; nx = dx[cmd - 1] + dicePos.x;
        }else if(cmd == 3){ // 북
            ny = dy[cmd - 1] + dicePos.y; nx = dx[cmd - 1] + dicePos.x;
        }else if(cmd == 4){ // 남
            ny = dy[cmd - 1] + dicePos.y; nx = dx[cmd - 1] + dicePos.x;
        }
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        dicePos.y = ny; dicePos.x = nx;
        if(cmd == 1){ // 동
            int temp = dice[5]; dice[5] = dice[2]; dice[2] = dice[0]; dice[0] = dice[3];
            dice[3] = temp;
        }else if(cmd == 2){ // 서
            int temp = dice[5]; dice[5] = dice[3]; dice[3] = dice[0]; dice[0] = dice[2];
            dice[2] = temp;
        }else if(cmd == 3){ // 북
            int temp = dice[5]; dice[5] = dice[1]; dice[1] = dice[0]; dice[0] = dice[4];
            dice[4] = temp;
        }else if(cmd == 4){ // 남
            int temp = dice[5]; dice[5] = dice[4]; dice[4] = dice[0]; dice[0] = dice[1];
            dice[1] = temp;
        }
        if(map[ny][nx] == 0){
            map[ny][nx] = dice[5];
        }else{
            dice[5] = map[ny][nx];
            map[ny][nx] = 0;
        }
        cout << dice[0] << "\n";
    }
}