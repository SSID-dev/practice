#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 21
int n;
int map[MAX][MAX];
bool check[MAX];
int totalNum = 9999;
void dfs(int cnt, int num){
    if(cnt == n/2){
        vector<int> start, link;
        int startTotNum = 0, linkTotNum = 0;
        for(int i = 1; i <= n; i++){
            if(check[i]){
                start.push_back(i);
            }else{
                link.push_back(i);
            }
        }
        for(int i = 0; i < start.size(); i++){
            for(int j = 0; j < start.size(); j++){
                if(i == j) continue;
                startTotNum += map[start[i]][start[j]];
            }
        }
        for(int i = 0; i < link.size(); i++){
            for(int j = 0; j < link.size(); j++){
                if(i == j) continue;
                linkTotNum += map[link[i]][link[j]];
            }
        }
        int diff = abs(startTotNum - linkTotNum);
        if(diff < totalNum){
            totalNum = diff;
        }
        return ;
    }
    for(int i = num; i <= n; i++){
        if(check[i]) continue;
        check[i] = true;
        dfs(cnt + 1, i + 1);
        check[i] = false;
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }
    dfs(0, 1);
    cout << totalNum;
}