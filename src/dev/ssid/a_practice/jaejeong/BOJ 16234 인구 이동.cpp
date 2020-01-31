#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#define MAX 50
using namespace std;
int n, l, r;
int totalday;
int map[MAX][MAX];
int check[MAX][MAX];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
bool diff(int y, int x, int yy, int xx){
    return (l <= abs(map[y][x] - map[yy][xx]) && abs(map[y][x] - map[yy][xx]) <= r);
}
void bfs(int valY, int valX){
    queue<pair<int, int>> q, nq;
    q.push(make_pair(valY, valX));
    nq.push(make_pair(valY, valX));
    check[valY][valX] = true;
    int sum = 0;
    int cnt = 0;
    while (!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        sum += map[y][x];
        cnt++;
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (check[ny][nx]) continue;
            if (diff(y, x, ny, nx)){
                check[ny][nx] = 1;
                q.push(make_pair(ny, nx));
                nq.push(make_pair(ny, nx));
            }
        }
    }
    int num = sum / cnt;
    while (nq.empty() == 0){
        int y = nq.front().first;
        int x = nq.front().second;
        nq.pop();
        map[y][x] = num;
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    while (1){
        bool sw = false;
        memset(check, false, sizeof(check));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                for(int k = 0; k < 4; k++){
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                    if(check[i][j] == 0 && diff(i, j, ny, nx)){
                        bfs(i, j);
                        sw = true;
                    }
                }
            }
        }
        if (!sw) break;
        totalday++;
    }
    cout << totalday;
}