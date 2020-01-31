#include <iostream>
using namespace std;
#define MAX 16
int n, totalNum;
int t[MAX], p[MAX];
void dfs(int day, int sum){
    if(day >= n + 1){
        if(totalNum < sum){
            totalNum = sum;
        }
        return;
    }
    if(day + t[day] <= n + 1){
        dfs(day + t[day], sum + p[day]);
    }
    dfs(day + 1, sum);
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t[i] >> p[i];
    }
    dfs(1, 0);
    cout << totalNum;
}