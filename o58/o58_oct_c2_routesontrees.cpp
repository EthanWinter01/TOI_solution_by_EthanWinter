/*
CONTEST: Olympics IPST in Computer, 2558, Camp 2
HOST: Institute for the Promotion of Teaching Science and Technology
TASK: Routes on Trees (o58_oct_c2_routesontrees)
SOURCE:
    https://beta.programming.in.th/tasks/o58_oct_c2_routesontrees
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 19/05/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
#define MAX_NODE 100001
using namespace std;
vector<vector<pii>> adj(MAX_NODE);
vector<vector<int>> dist(MAX_NODE,vector<int>(6,INT_MAX));
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,K,U,V,H;
    cin >> N >> M >> K;
    for (int i=0; i<M; ++i){
        cin >> U >> V >> H;
        if (H > -100)
            H = max(H,0);
        adj[U].push_back({H,V});
    }
    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> PQ;
    PQ.push({0,{0,1}});
    dist[1][0] = 0;
    while (!PQ.empty()){
        int d = PQ.top().f;
        int c = PQ.top().s.f;
        int u = PQ.top().s.s;
        PQ.pop();
        if (u == N){
            cout << d;
            return 0;
        }
        for (auto [w,v] : adj[u]){
            if (w >= 0){
                if (d + w < dist[v][c]){
                    dist[v][c] = d+w;
                    PQ.push({dist[v][c],{c,v}});
                }
            } else if (c < K){
                if (dist[v][c+1] > d){
                    dist[v][c+1] = d;
                    PQ.push({dist[v][c+1],{c+1,v}});
                }
            }
        }
    }
    cout << -1;
    return 0;
}