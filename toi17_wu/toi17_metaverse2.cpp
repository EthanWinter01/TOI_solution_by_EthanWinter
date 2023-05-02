/*
CONTEST: 17th Thailand Olympiad in Informatics, 2021
HOST: Walailuk University, Nakhon Sri Thammarat
TASK: The Marauder's Map of Metaverse City (toi17_metaverse_2)
TASK_SOURCE:
    https://beta.programming.in.th/tasks/toi17_metaverse_2
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 02/05/2023
*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define MAX_NODE 20002
using namespace std;
int warp[4][MAX_NODE];
int dist[18][MAX_NODE];
int manhattanDistance(int l, int r){
    return abs(warp[2][l]-warp[0][r])+abs(warp[3][l]-warp[1][r]);
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,K,P;
    cin >> M >> N >> K >> P;
    warp[0][0]=warp[1][0]=warp[2][0]=warp[3][0] = 1;
    warp[0][K+1]=warp[2][K+1]=M;
    warp[1][K+1]=warp[3][K+1]=N;
    for (int i=0; i<=P; i++){
        for (int j=0; j<=K+1; j++){
            dist[i][j] = INT_MAX;
        }
    }
    for (int i=1; i<=K; ++i)
        cin >> warp[0][i] >> warp[1][i] >> warp[2][i] >> warp[3][i];
    for (int i=0; i<=K+1; ++i)
        dist[0][i] = manhattanDistance(0,i);
    for (int t=1; t<=P; ++t){
        for (int i=0; i<=K+1; ++i){
            for (int j=0; j<=K+1; ++j){
                dist[t][j] = min(dist[t][j],dist[t-1][i]+manhattanDistance(i,j));
            }
        }
    }
    int finalDist = INT_MAX;
    int finalTick = 0;
    for (int i=0; i<=P; i++){
        if (dist[i][K+1] < finalDist){
            finalDist = dist[i][K+1];
            finalTick = i;
        }
    }
    cout << finalDist << " " << finalTick;
    return 0;
}
