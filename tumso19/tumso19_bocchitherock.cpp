/*
CONTEST: 19th Triam Udom Mathematics and Science Olympiad, 2022
HOST: Triam Udom Suksa School
TASK: ぼっち・ざ・ろっく (tumso19_bocchitherock)
SOURCE: 
    https://beta.programming.in.th/tasks/tumso19_bocchitherock
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
SCHOOL: Phimanpittayasan School
WRITTEN ON: 12/05/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
#define MAX 100002
#define START 100001
using namespace std;
vector<vector<pii>> adj(MAX);
vector<int> dist(MAX,INT_MAX);
vector<bool> visited(MAX);
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,K;
    cin >> N >> M;
    for (int i=0; i<M; ++i){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    cin >> K;
    for (int i=0; i<K; ++i){
        int v,w;
        cin >> v >> w;
        adj[START].push_back({w,v});
    }
    priority_queue<pii,vector<pii>,greater<pii>> PQ;
    PQ.push({0,START});
    dist[START] = 0;
    while (!PQ.empty()){
        int u = PQ.top().s;
        int d = PQ.top().f;
        PQ.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        if (u==0)
           break;
        for (auto vw : adj[u]){
            int v = vw.s;
            int w = vw.f;
            if (visited[v])
                continue;
            if (dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
                PQ.push({dist[v],v});
            }
        }
    }
    cout << dist[0];
    return 0;
}