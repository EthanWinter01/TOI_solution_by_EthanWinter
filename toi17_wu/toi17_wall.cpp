/*
CONTEST: 17th Thailand Olympiad in Informatics, 2021
HOST: Walailuk University, Nakhon Sri Thammarat
TASK: The Wall (toi17_wall)
TASK_SOURCE:
    https://beta.programming.in.th/tasks/toi17_wall
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 04/05/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
#define MAX_SIZE 1001
using namespace std;
int R,C;
vector<vector<char>> grid(MAX_SIZE,vector<char>(MAX_SIZE));
vector<vector<bool>> water(MAX_SIZE,vector<bool>(MAX_SIZE,false));
vector<vector<bool>> visited(MAX_SIZE,vector<bool>(MAX_SIZE,false));
vector<int> dir = {0,1,0,-1,0};
queue<pii> start;
void flood(){
    queue<pii> Q;
    water[1][1] = true;
    Q.push({1,1});
    while (!Q.empty()){
        int row = Q.front().f;
        int col = Q.front().s;
        Q.pop();
        for (int i=0; i<4; i++){
            int newRow = row+dir[i];
            int newCol = col+dir[i+1];
            if (newRow>0 && newCol>0 && newRow<=R && newCol<=C && grid[newRow][newCol]=='.' && !water[newRow][newCol]){
                Q.push({newRow,newCol});
                water[newRow][newCol] = true;
            }
        }
    }
}
int wallCount(int r, int c){
    int wall = 0;
    queue<pii> Q;
    Q.push({r,c});
    visited[r][c] = true;
    while (!Q.empty()){
        int row = Q.front().f;
        int col = Q.front().s;
        Q.pop();
        for (int i=0; i<4; i++){
            int newRow = row+dir[i];
            int newCol = col+dir[i+1];
            if (newRow>0 && newCol>0 && newRow<=R && newCol<=C && water[newRow][newCol])
                ++wall;
            if (newRow>0 && newCol>0 && newRow<=R && newCol<=C && grid[newRow][newCol]=='X' && !visited[newRow][newCol]){
                visited[newRow][newCol] = true;
                Q.push({newRow,newCol});
            }
        }
    }
    return wall;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;
    for (int i=1; i<=R; i++){
        for (int j=1; j<=C; j++){
            cin >> grid[i][j];
            if (grid[i][j]=='X')
                start.push({i,j});
        }
    }
    flood();
    int answer = 0;
    while (!start.empty()){
        int r = start.front().f;
        int c = start.front().s;
        start.pop();
        if (visited[r][c])
            continue;
        answer = max(answer,wallCount(r,c));
    }
    cout << answer;
    return 0;
}
