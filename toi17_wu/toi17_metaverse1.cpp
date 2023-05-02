/*
CONTEST: 17th Thailand Olympiad in Informatics, 2021
HOST: Walailuk University, Nakhon Sri Thammarat
TASK: The Marauder's Map of Metaverse City (toi17_metaverse_1)
TASK_SOURCE:
    https://beta.programming.in.th/tasks/toi17_metaverse_1
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 02/05/2023
*/

#include <bits/stdc++.h>
#define MAX_NODE 20002
#define pii pair<int,int>
using namespace std;
struct NODES{
    int dis, now, ticket;
    bool operator<(const NODES& r)const{
        return dis > r.dis;
    }
};
int adj[MAX_NODE][MAX_NODE];
int warp[MAX_NODE][4];
int visited[MAX_NODE][18];
vector<vector<int>> dist(MAX_NODE,vector<int>(18,INT_MAX));
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,K,P;
    cin >> M >> N >> K >> P;
    adj[0][0] = adj[K+1][K+1] = 0;
    adj[0][K+1] = adj[K+1][0] = M+N;
    for (int i=1; i<=K; i++){
        adj[i][i] = 0;
        cin >> warp[i][0] >> warp[i][1] >> warp[i][2] >> warp[i][3];
        adj[0][i] = warp[i][0]-1+warp[i][1]-1;
        adj[i][0] = warp[i][2]-1+warp[i][3]-1;
        adj[i][K+1] = abs(M-warp[i][2])+abs(N-warp[i][3]);
    }
    for (int i=1; i<=K; i++){
        for (int j=1; j<=K; j++){
            if (i==j)
                continue;
            adj[i][j] = abs(warp[i][2]-warp[j][0]) + abs(warp[i][3]-warp[j][1]);
        }
    }
    priority_queue<NODES> PQ;
    PQ.push({0,0,P});
    dist[0][P] = 0;
    int finalDist = INT_MAX;
    int finalTick = 0;
    while (!PQ.empty()){
        int curDist = PQ.top().dis;
        int curNode = PQ.top().now;
        int curTick = PQ.top().ticket;
        PQ.pop();
        if (visited[curNode][curTick])
            continue;
        visited[curNode][curTick] = true;
        for (int i=1; i<=K+1; i++){
            if (i<K+1){
                if (curTick-1>=0 && dist[curNode][curTick]+adj[curNode][i] < dist[i][curTick-1]){
                    dist[i][curTick-1] = dist[curNode][curTick]+adj[curNode][i];
                    PQ.push({dist[i][curTick-1], i, curTick-1});
                }
            } else {
                if (dist[curNode][curTick]+adj[curNode][i] < dist[i][curTick]){
                    dist[i][curTick] = dist[curNode][curTick]+adj[curNode][i];
                }
            }
        }
    }
    for (int i=0; i<18; i++){
        if (finalDist >= dist[K+1][i]){
            finalDist = dist[K+1][i];
            finalTick = i;
        }
    }
    cout << finalDist << " " << P-finalTick;
    return 0;
}