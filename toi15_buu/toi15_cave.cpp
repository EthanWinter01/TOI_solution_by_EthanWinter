/*
CONTEST: 15th Thailand Olympiad in Informatics, 2019
HOST: Burapha University, Chonburi
TASK: Cave (toi15_cave)
SOURCE:
    https://beta.programming.in.th/tasks/toi15_cave
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN: 07/05/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<long long,int>
#define ll long long
#define MAX_NODE 2001
using namespace std;
struct NODES {
    ll dis; int cnt,nod;
};
vector<vector<pii>> adj(MAX_NODE);
vector<vector<pii>> dist(MAX_NODE,vector<pii>(1,{LLONG_MAX,0}));
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,P,U,E,L,u,v;
    ll w;
    cin >> N >> P >> U >> E;
    for (int i=0; i<E; ++i){
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }
    queue<NODES> Q;
    Q.push({0,0,P});
    dist[P].push_back({0,0});
    while (!Q.empty()){
        ll distSoFar = Q.front().dis;
        int cntSoFar = Q.front().cnt;
        int currNode = Q.front().nod;
        Q.pop();
        for (auto nextOne : adj[currNode]){
            ll nextDist = nextOne.f;
            int nextNode = nextOne.s;
            if (distSoFar+nextDist < dist[nextNode].back().f){
                dist[nextNode].push_back({distSoFar+nextDist,cntSoFar+1});
                Q.push({distSoFar+nextDist,cntSoFar+1,nextNode});
            }
        }
    }
    cin >> L;
    while (L--){
        int h;
        cin >> h;
        ll answer = LLONG_MAX;
        for (auto it : dist[U]){
            if (it.s == 0)
                continue;
            answer = min(answer,it.f+((it.s-1)*h));
        }
        cout << answer << " ";
    }
    return 0;
}
