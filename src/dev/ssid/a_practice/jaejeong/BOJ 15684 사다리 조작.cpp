#include <iostream>
using namespace std;
#define endl "\n"
int map[31][11];
int ans = 4;
int n, m, h;
bool check(){
    for(int i = 1; i <= n; i++){
        int start = i, end = i;
        for(int j = 1; j <= h; j++){
            if(map[j][end]){
                end++;
            }else if(map[j][end - 1]){
                end--;
            }
        }
        if(start != end) return false;
    }
    return true;
}

void dfs(int y, int cnt){
    if(cnt >= ans) return;
    if(check()){
        ans = cnt;
        return;
    }
    if(cnt == 3) return;
    for(int i = y; i <= h; i++){
        for(int j = 1; j < n; j++){
            if(map[i][j] || map[i][j + 1] || map[i][j - 1]) continue;
            map[i][j] = 9;
            dfs(i, cnt + 1);
            map[i][j] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> h;
    for(int i = 0, a, b; i < m; i++){
        cin >> a >> b;
        map[a][b] = 1;
    }
    dfs(1, 0);
    if(ans > 3) ans = -1;
    cout << ans;
}