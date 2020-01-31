#include <iostream>
#include <algorithm>
using namespace std;
const int dy[] = {0, 1, 1};
const int dx[] = {1, 1, 0};
int n, l, totalNum;
int map[17][17];
bool check(int y, int x){ return (map[y-1][x] == 0 && map[y][x - 1] == 0); }
void dfs(int headY, int tailY, int headX, int tailX){
    if(headY == n && headX == n){
        totalNum++;
        return;
    }
    for(int i = 0; i < 3; i++){
        if(headY - tailY == 0 && headX - tailX == 1 && i == 2) continue;
        else if(headY - tailY == 1 && headX - tailX == 0 && i == 0) continue;
        int ny = headY + dy[i];
        int nx = headX + dx[i];
        if(i == 1 && !check(ny, nx)) continue;
        if(ny < 1 || ny > n || nx < 1 || nx > n || map[ny][nx] == 1) continue;
        dfs(ny, headY, nx, headX);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }
    dfs(1, 1, 2, 1);
    cout << totalNum;
}