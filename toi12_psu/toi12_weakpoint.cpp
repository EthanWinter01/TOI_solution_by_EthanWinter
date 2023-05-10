#include <bits/stdc++.h>
#define MAX_NODE 500001
using namespace std;
struct DB{
    int val,node;
    bool operator<(const DB &r)const{
        if (node == r.node)
            return node < r.node;
        return val > r.val;
    }
};
int N,M;
vector<vector<int>> adj(MAX_NODE);
vector<DB> memo(MAX_NODE);
vector<bool> visited(MAX_NODE,false);
int dfs(int u){
    visited[u] = true;
    bool cycle = false;
    int sum = 1;
    for (auto v : adj[u]){
        if (v == M)
            cycle = true;
        if (visited[v])
            continue;
        int d = dfs(v);
        if (!d)
            cycle = true;
        sum += d;
    }
    memo[u].val = sum;
    if (cycle)
        return 0;
    else
        return sum;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i=1; i<=N; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        memo[i].node = i;
    }
    dfs(M);
    sort(memo.begin()+1,memo.begin()+N);
    for (int i=1; i<=N; i++){
        if (memo[i].node != M){
            cout <<memo[i].node << "\n" << memo[i].val-1;
            break;
        }
    }
    return 0;
}
