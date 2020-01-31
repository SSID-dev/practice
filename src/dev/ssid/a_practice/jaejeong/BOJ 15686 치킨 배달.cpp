#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 51
struct POS{
    int y, x;
};
POS house[101];
POS store[14];
int n, m;
int map[MAX][MAX];
int checkStore[14];
int houseTotalNum, storeTotalNum;
int totalNum = 9999;
void dfs(int cnt, int num){
    if(cnt == m){
        int sum = 0;
        for(int i = 0; i < houseTotalNum; i++){
            int minNum = 9999;
            for(int j = 0; j < storeTotalNum; j++){
                if(!checkStore[j]) continue;
                minNum = min(minNum, abs(store[j].y - house[i].y) + abs(store[j].x - house[i].x));
            }
            sum += minNum;
        }
        totalNum = min(totalNum, sum);
        return;
    }
    for(int i = num; i < storeTotalNum; i++){
        checkStore[i] = true;
        dfs(cnt + 1, i + 1);
        checkStore[i] = false;
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(map[i][j] == 1){
                house[houseTotalNum].y = i;
                house[houseTotalNum].x = j;
                houseTotalNum++;
            }else if(map[i][j] == 2){
                store[storeTotalNum].y = i;
                store[storeTotalNum].x = j;
                storeTotalNum++;
            }
        }
    }
    dfs(0, 0);
    cout << totalNum;
}