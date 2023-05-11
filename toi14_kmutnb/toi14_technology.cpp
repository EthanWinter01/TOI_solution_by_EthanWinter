/*
CONTEST: 14th Thailand Olympiad in Informatics, 2018
HOST: King Mongkut's University of Technology, North Bangkok, Bangkok
TASK: Technology (toi14_technology) 
SOURCE: 
    https://beta.programming.in.th/tasks/toi14_technology
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 05/05/2023
*/

#include <bits/stdc++.h>
#define MAX_LEVEL 10001
#define MAX_NODE 100001
using namespace std;
int N,K,T,L,P;
vector<vector<int>> level(MAX_LEVEL);
vector<vector<int>> adj(MAX_NODE);
vector<int> color(MAX_NODE);
bool dfs(int u){
    if (color[u] == 1)
        return true;
    if (color[u] == 2)
        return false;
    color[u] = 1;
    for (auto v : adj[u]){
        if (dfs(v))
            return true;
    }
    color[u] = 2;
    --T;
    return false;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K >> T;
    for (int i=1; i<=N; i++){
        cin >> L >> P;
        while (P--){
            int p;
            cin >> p;
            adj[i].push_back(p);
        }
        level[L].push_back(i);
    }
    int finish = 0;
    bool foundCycle = false;
    for (int i=1; i<=K; i++){
        for (auto j : level[i]){
            if (!color[j] && dfs(j))
                foundCycle = true;
        }
        if (foundCycle || T<0)
            break;
        finish = i;
    }
    cout << (finish==0?-1:finish);
    return 0;
}
