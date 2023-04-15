/*
CONTEST: 4th POSN - Olympiad in Informatics, 2008
HOST: Suranaree University of Technology, Nakhonratchasrima
TASK: Temperature is Rising (toi4_temp & 1060)
SOURCE:
    https://beta.programming.in.th/tasks/toi4_temp
    https://beta.programming.in.th/tasks/1061
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 15/04/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x,y;
    cin >> n >> x >> y;
    vector<vector<int>> grid(n+1,vector<int>(n+1));
    vector<vector<bool>> visited(n+1, vector<bool>(n+1,false));
    vector<int> dir = {0,1,0,-1,0};
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> grid[i][j];
        }
    }
    queue<pii> Q;
    Q.push({y,x});
    visited[y][x] = true;
    int answer = grid[y][x];
    while (!Q.empty()){
        int row = Q.front().f;
        int col = Q.front().s;
        Q.pop();
        for (int i=0; i<4; i++){
            int newRow = row+dir[i];
            int newCol = col+dir[i+1];
            if (newRow>0 && newCol>0 && newRow<=n && newCol<=n && grid[newRow][newCol]>grid[row][col] && grid[newRow][newCol]!=100 && !visited[newRow][newCol]){
                answer = max(answer,grid[newRow][newCol]);
                visited[newRow][newCol] = true;
                Q.push({newRow,newCol});
            }
        }
    }
    cout << answer;
    return 0;
}