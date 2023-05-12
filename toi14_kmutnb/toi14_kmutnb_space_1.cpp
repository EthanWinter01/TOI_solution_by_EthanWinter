/*
CONTEST: 14th Thailand Olympiad in Informatics, 2018
HOST: King Mongkut's University of Technology, North Bangkok, Bangkok
TASK: Space Deep Field Image (toi14_space_1) 
SOURCE: 
    https://beta.programming.in.th/tasks/toi14_space_1
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 12/05/2023
*/

#include <bits/stdc++.h>
#define MAX 10001
using namespace std;
int M,N;
pair<int,int> lcoor, rcoor, tcoor, bcoor;
vector<int> dir = {0,1,0,-1,0};
vector<vector<int>> grid(MAX,vector<int>(MAX));
vector<vector<bool>> visited(MAX,vector<bool>(MAX,false));
vector<int> answer(3,0);
int bfs(int r, int c){
    queue<pair<int,int>> Q;
    Q.push({r,c});
    visited[r][c] = true;
    lcoor = rcoor = tcoor = bcoor = {r,c};
    while (!Q.empty()){
        int row = Q.front().first;
        int col = Q.front().second;
        Q.pop();
        if (col < lcoor.second)
            lcoor = {row,col};
        if (col > rcoor.second)
            rcoor = {row,col};
        if (row < tcoor.first)
            tcoor = {row,col};
        if (row > bcoor.first)
            bcoor = {row,col};
        for (int i=0; i<4; ++i){
            int newRow = row+dir[i];
            int newCol = col+dir[i+1];
            if (newRow>=0 && newCol>=0 && newRow<M && newCol<N&& !visited[newRow][newCol] && grid[newRow][newCol]==1){
                Q.push({newRow,newCol});
                visited[newRow][newCol] = true;
            }
        }
    }
    if (tcoor.first==lcoor.first && tcoor.first==rcoor.first && tcoor.second==bcoor.second)
        ++answer[0];
    else if (rcoor.first==lcoor.first && bcoor.first>rcoor.first && tcoor.second==bcoor.second && tcoor.first!=lcoor.first && tcoor.first!=rcoor.first)
        ++answer[1];
    else
        ++answer[2];
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    char c;
    for (int i=0; i<M; ++i){
        for (int j=0; j<N; ++j){
            cin >> c;
            grid[i][j] = c-'0';
        }
    }
    for (int i=0; i<M; ++i)
        for (int j=0; j<N; ++j)
            if (grid[i][j]==1 && !visited[i][j])
                bfs(i,j);
    for (int i=0; i<3; ++i)
        cout << answer[i] << " ";
    return 0;
}