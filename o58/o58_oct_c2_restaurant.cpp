/*
CONTEST: Olympics IPST in Computer, 2558, Camp 2
HOST: Institute for the Promotion of Teaching Science and Technology
TASK: Restaurant (o58_oct_c2_restaurant)
SOURCE:
    https://beta.programming.in.th/tasks/o58_oct_c2_restaurant
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 20/05/2023
*/

#include <bits/stdc++.h>
using namespace std;
struct NODES{
    int dis,curr,prev;
    bool operator<(const NODES& r)const{
        return dis > r.dis;
    }
};
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,T;
    cin >> N >> T;
    vector<vector<int>> dist(N+1,vector<int>(N+1));
    vector<bool> visited(N+1,false);
    vector<vector<int>> adj(N+1);
    for (int i=1; i<=N; ++i)
        for (int j=1; j<=N; ++j)
            cin >> dist[i][j];
    priority_queue<NODES> PQ;
    PQ.push({0,1,1});
    while (!PQ.empty()){
        auto [d,u,p] = PQ.top();
        PQ.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        if (u != p){
            adj[u].push_back(p);
            adj[p].push_back(u);
        }
        for (int v=1; v<=N; ++v)
            if (!visited[v])
                PQ.push({dist[u][v],v,u});
    }
    int restaurant;
    for (int i=1; i<=N; ++i)
        if (adj[i].size() >= 3)
            restaurant = i;
    cout << restaurant << "\n";
    if (T==2)
        cout << adj[restaurant].size() << "\n";
    return 0;
}