/*
CONTEST: 12th Thailand Olympiad in Informatics, 2016
HOST: Prince Songkla University, Hat Yai Campus
TASK: Cablecar (toi12_cablecar)
SOURCE:
    https://beta.programming.in.th/tasks/toi12_cablecar
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanphittayasan School
WRITTEN ON: 06/05/2023
*/

#include<bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
#define MAX_NODE 2501
using namespace std;
vector<vector<pii>> adj(MAX_NODE);
vector<int> cap(MAX_NODE,INT_MAX);
vector<bool> visited(MAX_NODE,false);
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin >> N >> M;
    for (int i=0; i<M; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[v].push_back({w,u});
        adj[u].push_back({w,v});
    }
    int S,D,P;
    cin >> S >> D >> P;
    priority_queue<pii,vector<pii>,greater<pii>> PQ;
    PQ.push({0,S});
    cap[S] = 0;
    while (!PQ.empty()){
        int d = PQ.top().f;
        int u = PQ.top().s;
        PQ.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        if (u == D){
            cout << cap[D];
            return 0;
        }
        for (auto nextNode : adj[u]){
            int w = nextNode.f;
            int v = nextNode.s;
            if (visited[v])
                continue;
            int passenger = ceil((float)P/(w-1));
            passenger = max(passenger,d);
            if (passenger < cap[v]){
                cap[v] = passenger;
                PQ.push({cap[v],v});
            }
        }
    }
    return 0;
}
