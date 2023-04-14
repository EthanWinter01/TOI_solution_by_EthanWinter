/*
TASK: Candle Light Prayer (toi11_candle)
TASK_SOURCE:
    https://beta.programming.in.th/tasks/toi11_candle
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
WRITTEN ON: 12/04/2023
*/

#include <bits/stdc++.h>
#define f first 
#define s second 
#define pii pair<int,int>
#define MAX_SIZE 2001
using namespace std;
int M, N;
vector<int> dirX = {-1,0,1,1,1,0,-1,-1};
vector<int> dirY = {1,1,1,0,-1,-1,-1,0};
vector<vector<char>> grid(MAX_SIZE,vector<char>(MAX_SIZE));
vector<vector<bool>> visited(MAX_SIZE, vector<bool>(MAX_SIZE,false));
void dfs(int startRow, int startCol){
    stack<pii> S;
    S.push({startRow,startCol});
    visited[startRow][startCol] = true;
    while (!S.empty()){
        int row = S.top().f;
        int col = S.top().s;
        S.pop();
        for (int i=0; i<8; i++){
            int newRow = row+dirY[i];
            int newCol = col+dirX[i];
            if (newRow>=0 && newCol>=0 && newRow<M && newCol<N && !visited[newRow][newCol] && grid[newRow][newCol]=='1'){
                visited[newRow][newCol] = true;
                S.push({newRow,newCol});
            }
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;
    for (int i=0; i<M; i++)
        for (int j=0; j<N; j++)
            cin >> grid[i][j];
    int cnt = 0;
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            if (grid[i][j]=='1' && !visited[i][j]){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
