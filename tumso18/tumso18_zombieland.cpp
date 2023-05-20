/*
CONTEST: 18th Triam Udom Mathematics and Science Olympiad, 2021
HOST: Triam Udom Suksa School
TASK: Zombie Land (tumso18_zombieland)
SOURCE: 
    https://beta.programming.in.th/tasks/tumso18_zombieland
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
SCHOOL: Phimanpittayasan School
WRITTEN ON: 13/05/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second 
#define ll long long 
#define pii pair<ll,int>
#define MAX 200001
using namespace std;
vector<vector<pii>> adj(MAX);
vector<vector<ll>> dist(3,vector<ll>(MAX,LLONG_MAX));
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,S,E;
    cin >> N >> M >> S >> E;
    for (int i=0; i<M; ++i){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    priority_queue<pii,vector<pii>,greater<pii>> PQ;
    dist[0][S] = 0;
    PQ.push({0,S});
    while (!PQ.empty()){
        auto [d,u] = PQ.top();
        PQ.pop();
        for (auto [w,v] : adj[u]){
            if (dist[0][u] + w < dist[0][v]){
                dist[0][v] = dist[0][u] + w;
                PQ.push({dist[0][v],v});
            }
        }
    }
    dist[1][E] = 0;
    PQ.push({0,E});
    while (!PQ.empty()){
        auto [d,u] = PQ.top();
        PQ.pop();
        for (auto [w,v] : adj[u]){
            if (dist[1][u] + w < dist[1][v]){
                dist[1][v] = dist[1][u] + w;
                PQ.push({dist[1][v],v});
            }
        }
    }
    for (int i=1; i<=N; ++i)
        if (dist[0][i] + dist[1][i] == dist[0][E]){
            dist[2][i] = 0;
            PQ.push({dist[2][i],i});
        }
    while (!PQ.empty()){
        auto [d,u] = PQ.top();
        PQ.pop();
        for (auto [w,v] : adj[u]){
            if (dist[2][u] + w < dist[2][v]){
                dist[2][v] = dist[2][u] + w;
                PQ.push({dist[2][v],v});
            }
        }
    }
    int Q;
    cin >> Q;
    while (Q--){
        int q;
        cin >> q;
        cout << dist[2][q] << "\n";
    }
    return 0;
}