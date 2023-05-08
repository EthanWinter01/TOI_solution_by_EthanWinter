/*
CONTEST: 3rd POSN - Olympiad in Informatics, 2007
HOST: Khon Khaen University, Khon Khaen
TASK: Tiling (toi3_tiling & 1014)
SOURCE:
    https://beta.programming.in.th/tasks/toi3_tiling
    https://beta.programming.in.th/tasks/1014
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus (PTN)
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 13/04/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
#define MAX_SIZE 18
using namespace std;
int n;
vector<int> dir = {0,1,0,-1,0};
vector<vector<int>> tile(MAX_SIZE,vector<int>(MAX_SIZE));
vector<vector<bool>> visited(MAX_SIZE,vector<bool>(MAX_SIZE,false));
bool dfs(int startRow, int startCol){
    stack<pii> S;
    S.push({startRow,startCol});
    visited[startRow][startCol] = true;
    int dist = 1;
    bool travelVertical = false;
    bool travelHorizontal = false;
    while (!S.empty()){
        int row = S.top().f;
        int col = S.top().s;
        S.pop();
        for (int i=0; i<4; i++){
            int newRow = row+dir[i];
            int newCol = col+dir[i+1];
            if (newRow>=0 && newCol>=0 && newRow<n && newCol<n && !visited[newRow][newCol] && tile[newRow][newCol]==tile[row][col]){
                visited[newRow][newCol] = true;
                dist++;
                if (newRow!=row)
                    travelVertical = true;
                if (newCol!=col)
                    travelHorizontal = true;
                S.push({newRow,newCol});
            }
        }
    }
    if (dist==3 && travelHorizontal && travelVertical)
        return true;
    return false;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> tile[i][j];
    int answer = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (!visited[i][j] && tile[i][j]!=0){
                if (dfs(i,j))
                    answer++;
            }
        }
    }
    cout << answer;
    return 0;
}
