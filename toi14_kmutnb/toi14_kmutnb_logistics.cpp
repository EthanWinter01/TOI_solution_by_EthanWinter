/*
CONTEST: 14th Thailand Olympiad in Informatics, 2018
HOST: King Mongkut's University of Technology, North Bangkok, Bangkok
TASK: Technology (toi11_logistics) 
SOURCE: 
    https://beta.programming.in.th/tasks/toi14_logistics
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 19/04/2023
*/

#include <bits/stdc++.h>
#define MAX_NODE 101
#define MAX_FUEL 101
#define pii pair<int,int>
using namespace std;
struct NODES{
    int dis,now,gas,ticket;
    bool operator<(const NODES &r)const{
        return dis > r.dis;
    }
};
int price[MAX_NODE];
int pay[MAX_NODE][MAX_FUEL][2];
bool visited[MAX_NODE][MAX_FUEL][2];
vector<vector<pii>> adj(MAX_NODE);
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,S,D,F;
    cin >> N;
    for (int i=1; i<=N; ++i){
        for (int j=0; j<MAX_FUEL; j++){
            pay[i][j][0]=pay[i][j][1]=INT_MAX;
            visited[i][j][0]=visited[i][j][1]=false;
        }
        cin >> price[i];
    }
    cin >> S >> D >> F >> M;
    while (M--){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }
    int answer = 0;
    priority_queue<NODES> PQ;
    PQ.push({0,S,0,1});
    pay[S][0][1] = 0;
    while (!PQ.empty()){
        int curDist = PQ.top().dis;
        int curNode = PQ.top().now;
        int curGas = PQ.top().gas;
        int curTicket = PQ.top().ticket;
        PQ.pop();
        if (visited[curNode][curGas][curTicket])
            continue;
        visited[curNode][curGas][curTicket] = true;
        if (curGas<F){
            pay[curNode][curGas+1][curTicket] = pay[curNode][curGas][curTicket] + price[curNode];
            PQ.push({pay[curNode][curGas+1][curTicket],curNode,curGas+1,curTicket});
        }
        if (curTicket>0){
            pay[curNode][F][curTicket-1] = pay[curNode][curGas][curTicket];
            PQ.push({pay[curNode][F][curTicket-1],curNode,F,curTicket-1});
        }
        if (curNode == D && curGas==F){
            cout << curDist;
            return 0;
        }
        for (auto v : adj[curNode]){
            int nextDist = v.first;
            int nextNode = v.second;
            if (curGas < nextDist)
                continue;
            if (pay[curNode][curGas][curTicket]<pay[nextNode][curGas-nextDist][curTicket]){
                pay[nextNode][curGas-nextDist][curTicket] = pay[curNode][curGas][curTicket];
                PQ.push({pay[nextNode][curGas-nextDist][curTicket],nextNode,curGas-nextDist,curTicket});
            }
        }
    }
    return 0;
}