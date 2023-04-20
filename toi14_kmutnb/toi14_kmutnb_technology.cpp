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
WRITTEN ON: 19/04/2023
*/

#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
vector<vector<int>> level(MAX);
vector<vector<int>> graph(MAX);
vector<int> color(MAX);
int cnt = 0;
bool dfs(int currNode){
    if (color[currNode]==1)
        return true;
    if (color[currNode]==2)
        return false;
    color[currNode] = 1;
    cnt++;
    for (auto it : graph[currNode]){
        if (dfs(it))
            return true;
    }
    color[currNode] = 2;
    return false; 
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K,T;
    cin >> N >> K >> T;
    for (int i=1; i<=N; i++){
        int L,P,p;
        cin >> L >> P;
        level[L].push_back(i);
        while (P--){
            cin >> p;
            graph[i].push_back(p);
        }
    }
    bool foundCycle = false;
    int techLevel = 0;
    for (int i=1; i<=K; i++){
        for (auto l : level[i]){
            if (!color[l]){
                if (dfs(l))
                    foundCycle = true;
            }
        }
        if (foundCycle || cnt>T)
            break;
        techLevel = i;
    }
    cout<<(techLevel==0? -1: techLevel);
    return 0;
}