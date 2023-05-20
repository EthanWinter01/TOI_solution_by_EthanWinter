/*
CONTEST: 5th POSN - Olympiad in Informatics, 2008
HOST: Walailuk University, Nakhon Sri Thammarat
TASK: Happy Land (toi5_land)
SOURCE:
    https://beta.programming.in.th/tasks/toi5_land
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 19/05/2023
*/

#include <bits/stdc++.h>
using namespace std;
int N,M;
double result = 1e10;
vector<vector<double>> grid(3,vector<double>(3));
vector<vector<bool>> visited(3,vector<bool>(3));
vector<int> dr = {1,1,1,0,-1,-1,-1,0};
vector<int> dc = {-1,0,1,1,1,0,-1,-1};
void buyFunction(int r,int c,int k){
    double temp = grid[r][c]/10*k;
    for (int i=0; i<8; ++i){
        int newRow = r+dr[i];
        int newCol = c+dc[i];
        if (newRow>=0 && newCol>=0 && newRow<N && newCol<M)
            grid[newRow][newCol] += temp;
    }
}
void search(int count,double sum){
    if (count == N*M){
        result = min(result,sum);
        return;
    }
    for (int i=0; i<N; ++i){
        for (int j=0; j<M; ++j){
            if (!visited[i][j]){
                visited[i][j] = true;
                buyFunction(i,j,1);
                search(count+1,sum+grid[i][j]);
                buyFunction(i,j,-1);
                visited[i][j] = false;
            }
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i=0; i<N; ++i)
        for (int j=0; j<M; ++j)
            cin >> grid[i][j];
    search(0,0);
    printf("%.2f",result);
    return 0;
}
