/*
CONTEST: 17th Thailand Olympiad in Informatics, 2021
HOST: Walailuk University, Nakhon Sri Thammarat
TASK: T-Junction (toi17_junction)
TASK_SOURCE:
    https://beta.programming.in.th/tasks/toi17_junction
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 04/05/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<long long,int>
#define ll long long
#define MAX_NODE 80001
using namespace std;
vector<vector<pii>> adj(MAX_NODE);
vector<ll> weight;
vector<bool> visited(MAX_NODE,false);
void dfs(long long u){
    visited[u] = true;
    for (auto v : adj[u]){
        if (!visited[v.s]){
            dfs(v.s);
            weight.push_back(v.f);
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    for (int i=0; i<=N; i++){
        if (adj[i].size()==1){
            dfs(i);
            break;
        }
    }
    ll left = 0;
    ll right = LLONG_MAX-1;
    while (left < right){
        ll mid = (left+right)/2;
        ll sum = 0;
        int cnt = 0;
        for (auto w : weight){
            sum += w;
            if (sum >= mid){
                sum = 0;
                cnt++;
            }
        }
        if (cnt >= 3)
            left = mid+1;
        else
            right = mid;
    }
    cout << left-1;
    return 0;
}