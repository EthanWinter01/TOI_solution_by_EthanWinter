// UNFINISH : 90/100

/*
CONTEST: 3rd POSN - Olympiad in Informatics, 2007
HOST: Khon Khaen University, Khon Khaen
TASK: Block Game (toi3_block & 1011)
SOURCE:
    https://beta.programming.in.th/tasks/toi3_block
    https://beta.programming.in.th/tasks/1011
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus (PTN)
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: XX/XX/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
using namespace std;
int m,n,l,score=0;
vector<int> dir = {0,1,0,-1,0};
vector<vector<char>> grid(5,vector<char>(5));
bool isCheated(int r, int c, char op){
    int k = 0;
    (op == 'L')? k-- : k++;
    if (grid[r][c]=='#' || grid[r][c]=='-' || grid[r][c+k]!='-')
        return true;
    return false;
}
void dropCheck(){
    for (int j=0; j<n; j++){
        for (int i=m-1; i>0; i--){
            if (grid[i][j] == '-' && (grid[i-1][j]!='#'&&grid[i-1][j]!='-')){
                swap(grid[i][j],grid[i-1][j]);
                i=m-1;
            }
        }
    }
}
void dfs(int r, int c, char check){
    stack<pii> S;
    vector<vector<bool>> visited(5,vector<bool>(5,false));
    S.push({r,c});
    visited[r][c] = true;
    bool scoring = false;
    while (!S.empty()){
        int row = S.top().f;
        int col = S.top().s;
        S.pop();
        for (int i=0; i<4; i++){
            int newRow = row+dir[i];
            int newCol = col+dir[i+1];
            if (newRow>=0 && newCol>=0 && newRow<m && newCol<n && !visited[newRow][newCol] && grid[newRow][newCol]==check){
                scoring = true;
                visited[newRow][newCol] = true;
                S.push({newRow,newCol});
            }
        }
    }
    if (scoring){
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (visited[i][j]){
                    grid[i][j] = '-';
                    score += 5;
                }
            }
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> grid[i][j];
    cin >> l;
    while (l--){
        int r,c;
        char op;
        cin >> r >> c >> op;
        if (isCheated(r,c,op)){
            score -= 5;
            continue;
        }
        if (op == 'L')
            swap(grid[r][c],grid[r][c-1]);
        else
            swap(grid[r][c],grid[r][c+1]);
        dropCheck();
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                if (grid[i][j]!='#' && grid[i][j]!='-')
                    dfs(i,j,grid[i][j]);
        dropCheck();
    }
    cout << score << "\n";
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
