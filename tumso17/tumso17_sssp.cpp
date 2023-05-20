/*
CONTEST: 17th Triam Udom Mathematics and Science Olympiad, 2020
HOST: Triam Udom Suksa School
TASK: วิถีที่สั้นที่สุดแบบแหล่งต้นทางเดียว (tumso17_sssp)
SOURCE:
    https://beta.programming.in.th/tasks/tumso17_sssp
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
SCHOOL: Phimanpittayasan School
WRITTEN ON: 12/05/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
#define MAX 100001
using namespace std;
vector<vector<pii>> adj(MAX);
vector<bool> visited(MAX,false);
vector<int> parent(MAX);
vector<int> dist(MAX,INT_MAX);
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,S,T;
    cin >> N >> M >> S >> T;
    for (int i=0; i<M; ++i){
        int u,v,w;
        cin >> u >> v >> w;
        w = log(w);
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    for (int i=0; i<N; ++i)
        parent[i] = i;
    priority_queue<pii,vector<pii>,greater<pii>> PQ;
    PQ.push({1,S});
    dist[S] = 1;
    while (!PQ.empty()){
        int u = PQ.top().s;
        int d = PQ.top().f;
        PQ.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        for (auto vw : adj[u]){
            int v = vw.s;
            int w = vw.f;
            if (visited[v])
                continue;
            if (dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
                parent[v] = u;
                PQ.push({dist[v],v});
            }
        }
    }
    stack<int> answer;
    int idx = T;
    while (parent[idx]!=idx){
        answer.push(idx);
        idx = parent[idx];
    }
    answer.push(idx);
    while (!answer.empty()){
        cout << answer.top() << " ";
        answer.pop();
    }
    return 0;
}
