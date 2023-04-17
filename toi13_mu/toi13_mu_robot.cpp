/*
CONTEST: 13th Thailand Olympiad in Informatics, 2017
HOST: Mahidol Wittayanusorn & Mahidol University, Nakhon Pathom
TASK: Robot (toi13_robot)
SOURCE:
    https://beta.programming.in.th/tasks/toi13_robot
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 16/04/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
#define MAX 2001
using namespace std;
int N,M;
vector<int> dir = {0,1,0,-1,0};
vector<vector<char>> grid(MAX,vector<char>(MAX));
vector<vector<int>> dist(MAX,vector<int>(MAX,0));
queue<pii> Q;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> grid[i][j];
            if (grid[i][j]=='W')
                dist[i][j] = -1;
            if (grid[i][j]=='X'){
                Q.push({i,j});
                dist[i][j] = 1;
            }
        }
    }
    int objCount = 0;
    int totalDist = 0;
    int distCounter = 0;
    while (!Q.empty()){
        int sz = Q.size();
        while (sz--){
            int row = Q.front().f;
            int col = Q.front().s;
            Q.pop();
            if (grid[row][col] == 'A'){
                objCount++;
                totalDist += dist[row][col];
            }
            for (int i=0; i<4; i++){
                int newRow = row+dir[i];
                int newCol = col+dir[i+1];
                if (newRow>=0 && newRow<N && newCol>=0 && newCol<M && dist[newRow][newCol]==0){
                    dist[newRow][newCol] = distCounter+1;
                    Q.push({newRow,newCol});
                }
            }
        }
        distCounter++;
    }
    cout << objCount << " " << totalDist*2;
    return 0;
}