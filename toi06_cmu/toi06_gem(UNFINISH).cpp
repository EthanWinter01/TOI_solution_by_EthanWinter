/*
CONTEST: 6th Thailand Olympiad in Informatics, 2010
HOST: Chaing Mai University, Chaing Mai
TASK: Gem (toi6_gem)
SOURCE:
    https://beta.programming.in.th/tasks/toi6_gem
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 11/05/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
using namespace std;
int tarjan(int u,int &idx,vector<vector<int>>& adj,vector<int>&disc,vector<int>&low,vector<int>&scc,vector<bool>&inpath,stack<int>&path){
    disc[u] = low[u] = ++idx;
    path.push(u);
    inpath[u] = true;
    for (auto v : adj[u]){
        if (!disc[v]){
            tarjan(v,idx,adj,disc,low,scc,inpath,path);
            low[u] = min(low[u],low[v]);
        } else if (inpath[v]){
            low[u] = min(low[u],low[v]);
        }
    }
    if (low[u] == disc[u]){
        int t;
        do {
            t = path.top();
            path.pop();
            inpath[t] = false;
            scc[t] = u;
        } while (t!=u);
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 5;
    while (t--){
        int n,m;
        cin >> n >> m;
        vector<pii> gem(n);
        for (int i=0; i<n; ++i)
            cin >> gem[i].f >> gem[i].s;
        vector<int> opp(m+1);
        for (int i=0; i<m/2; ++i){
            int a,b;
            cin >> a >> b;
            opp[a] = b;
            opp[b] = a;
        }
        vector<vector<int>> adj(m+1);
        for (auto [u,v] : gem){
            adj[opp[u]].push_back(v);
            adj[opp[v]].push_back(u);
        }
        vector<int> disc(m+1),low(m+1),scc(m+1);
        vector<bool> inpath(m+1);
        stack<int> path;
        int idx = 0;
        for (int i=1; i<=m; ++i)
            if (!disc[i])
                tarjan(i,idx,adj,disc,low,scc,inpath,path);
        bool able = true;
        for (int i=1; i<=m; ++i)
            if (scc[i]==scc[opp[i]])
                able = false;
        cout <<(able?"Y":"N");
    }
}
