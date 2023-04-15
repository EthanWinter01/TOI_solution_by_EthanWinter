/*
TASK: Chromartie School (toi4_school & 1064)
SOURCE:
    https://beta.programming.in.th/tasks/toi4_school
    https://beta.programming.in.th/tasks/1064
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
WRITTEN ON: 15/04/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
#define MAX 65
using namespace std;
int W,L;
vector<int> dir = {0,1,0,-1,0};
vector<vector<char>> grid(MAX,vector<char>(MAX));
vector<vector<int>> dp(MAX,vector<int>(MAX,0));
vector<vector<pii>> vec(10);
void dfs(int r, int c, int realR,int realC,int len,vector<vector<bool>>&visited){
    queue<pii> Q;
    visited[r][c]=true;
    Q.push({r,c});
    while (!Q.empty()){
        int row = Q.front().f;
        int col = Q.front().s;
        Q.pop();
        for (int i=0; i<4; i++){
            int newRow = row+dir[i];
            int newCol = col+dir[i+1];
            if (newRow>=1&&newRow<=L&&newCol>=1&&newCol<=W
                &&!visited[newRow][newCol]&&grid[newRow][newCol]=='P'){
                visited[newRow][newCol]=true;
                Q.push({newRow,newCol});
            }
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> W >> L;
    for (int i=1; i<=L; i++){
        for (int j=1; j<=W; j++){
            cin >> grid[i][j];
            if (grid[i][j]=='S'||grid[i][j]=='P'){
                dp[i][j] = 1;
            }
        }
    }
    int landSize = 0;
    for (int i=1; i<=L; i++){
        for (int j=1; j<=W; j++){
            if (grid[i][j]=='S'||grid[i][j]=='P'){
                dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                landSize = max(landSize,dp[i][j]);
            }
            vec[dp[i][j]].push_back({i,j});
        }
    }
    int wellCount = INT_MAX;
    for (auto v : vec[landSize]){
        int cnt = 0;
        vector<vector<bool>> visited(MAX,vector<bool>(MAX,false));
        for (int i=v.f-landSize+1; i<=v.f; i++){
            for (int j= v.s-landSize+1; j<=v.s; j++){
                if (!visited[i][j]&&grid[i][j]=='P'){
                    cnt++;
                    dfs(i,j,v.f,v.s,landSize,visited);
                }
            }
        }
        wellCount = min(cnt,wellCount);
    }
    cout << landSize*landSize << " " << wellCount;
    return 0;
}
