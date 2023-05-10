/*
CONTEST: 13th Thailand Olympiad in Informatics, 2017
HOST: Mahidol Wittayanusorn & Mahidol University, Nakhon Pathom
TASK: Timer Switch (toi13_timerswitch)
SOURCE:
    https://beta.programming.in.th/tasks/toi13_timerswitch
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 10/05/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
#define MAX 10001
using namespace std;
vector<vector<pii>> adj(MAX);
vector<int> dist(MAX,INT_MAX);
vector<int> distR(MAX,INT_MAX);
vector<bool> visited(MAX,false);
vector<bool> visitedR(MAX,false);
struct NODES{
    int dis,cur,cos;
    bool operator<(const NODES &r)const{
        return dis > r.dis;
    }
};
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,X,Y,Z;
    cin >> N >> M >> X >> Y >> Z;
    for (int i=0; i<M; ++i){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    bool succeed = false;
    priority_queue<NODES> PQ;
    PQ.push({0,X,Z});
    dist[X] = 0;
    while (!PQ.empty()){
        int u = PQ.top().cur;
        int d = PQ.top().dis;
        int c = PQ.top().cos;
        PQ.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        if (u==Y){
            cout<<u<<" "<<dist[u]<<" "<<0;
            succeed = true;
            return 0;
        }
        for (auto vw : adj[u]){
            int v = vw.s;
            int w = vw.f;
            if (visited[v])
                continue;
            if (dist[u]+w<dist[v] && c-w>=0){
                dist[v] = dist[u]+w;
                PQ.push({dist[v],v,c-w});
            }
        }
    }
    if (!succeed){
        priority_queue<pii,vector<pii>,greater<pii>> PQR;
        PQR.push({0,Y});
        distR[Y] = 0;
        while (!PQR.empty()){
            int d = PQR.top().f;
            int u = PQR.top().s;
            PQR.pop();
            if (visited[u]){
                cout<<u<<" "<<dist[u]<<" "<<d;
                return 0;
            }
            if (visitedR[u])
                continue;
            visitedR[u] = true;
            for (auto vw : adj[u]){
                int v = vw.s;
                int w = vw.f;
                if (visitedR[v])
                    continue;
                if (distR[u]+w<distR[v]){
                    distR[v] = distR[u]+w;
                    PQR.push({distR[v],v});
                }
            }
        }
    }
    return 0;
}