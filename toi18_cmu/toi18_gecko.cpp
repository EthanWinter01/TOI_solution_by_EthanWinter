/*
CONTEST: 18th Thailand Olympiad in Informatics, 2022
HOST: Chaing Mai University, Chaing Mai
TASK: Gecko (toi18_gecko)
TASK_SOURCE:
    https://beta.programming.in.th/tasks/toi18_gecko
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 01/05/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
#define ll long long
#define INF 1e9
#define MAX_NODE 20001
using namespace std;
struct NODES{
    int dis,now,prv;
    bool operator<(const NODES& r)const{
        return dis > r.dis;
    }
};
vector<int> gecko;
vector<pii> stinkGecko;
map<pii,int> pathFreq;
vector<vector<pii>> adj(MAX_NODE);
vector<int> dist(MAX_NODE, INF);
vector<bool> visited(MAX_NODE, false);
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,K,P;
    cin >> N >> M >> K >> P;
    for (int i=0; i<K; i++){
        int g;
        cin >> g;
        gecko.push_back(g);
    }
    for (int i=0; i<M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    priority_queue<NODES> PQ;
    stack<pii> path;
    dist[P] = 0;
    PQ.push({dist[P], P, 0});
    int geckoCount = 0;
    while (!PQ.empty()){
        int p = PQ.top().prv;
        int u = PQ.top().now;
        int d = PQ.top().dis;
        PQ.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        for (int i=0; i<gecko.size(); i++){
            if (u==gecko[i]){
                stinkGecko.push_back({i,d});
                geckoCount++;
                break;
            }
        }
        if (!pathFreq.count({u,p}) && !pathFreq.count({p,u}) && dist[u]!=0){
            path.push({p,u});
            pathFreq.insert({{u,p},1});
            pathFreq.insert({{p,u},1});
        }
        if (geckoCount >= K)
            break;
        for (auto vw : adj[u]){
            int v = vw.f;
            int w = vw.s;
            if (!visited[v] && dist[u]+w<dist[v]){
                dist[v] = dist[u]+w;
                PQ.push({dist[v],v,u});
            }
        }
    }
    sort(stinkGecko.begin(),stinkGecko.end());
    for (auto g : stinkGecko)
        cout << g.s << " ";
    cout << "\n" << path.size() << "\n";
    while (!path.empty()){
        cout << path.top().f << " " << path.top().s<<"\n";
        path.pop();
    }
    return 0;
}

