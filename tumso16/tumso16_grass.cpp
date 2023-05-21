/*
CONTEST: 16th Triam Udom Mathematics and Science Olympiad, 2019
HOST: Triam Udom Suksa School
TASK: ปลูกหญ้า (tumso16_grass)
SOURCE:
    https://beta.programming.in.th/tasks/tumso16_grass
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
SCHOOL: Phimanpittayasan School
WRITTEN ON: 21/05/2023
*/

#include <bits/stdc++.h>
#define MAX 100
using namespace std;
int M,N;
vector<vector<bool>> grid(MAX,vector<bool>(MAX,false));
vector<int> dirR = {-1,-1,-1,0,1,1,1,0};
vector<int> dirC = {-1,0,1,1,1,0,-1,-1};
void dfs(int r, int c){
    stack<pair<int,int>> S;
    S.push({r,c});
    while (!S.empty()){
        auto [row,col] = S.top();
        S.pop();
        for (int i=0; i<8; ++i){
            int newRow = row+dirR[i];
            int newCol = col+dirC[i];
            if (newRow>=0 && newCol>=0 && newRow<M && newCol<N && !grid[newRow][newCol]){
                grid[newRow][newCol] = true;
                S.push({newRow,newCol});
            }
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;
    for (int i=0; i<M; ++i){
        for (int j=0; j<N; ++j){
            char g;
            cin >> g;
            if (g == '#')
                grid[i][j] = true;
        } 
    }
    int answer = 0;
    for (int i=0; i<M; ++i)
        for (int j=0; j<N; ++j)
            if (!grid[i][j]){
                dfs(i,j);
                ++answer;
            }
    cout << answer;
    return 0;
}
