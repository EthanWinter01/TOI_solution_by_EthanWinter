/*
TASK: Space (toi7_sewer & 1161)
SOURCE:
    https://beta.programming.in.th/tasks/toi7_sewer
    https://beta.programming.in.th/tasks/1161
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus (PTN)
WRITTEN: 14/04/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
#define MAX 101
using namespace std;
int a, b;
vector<vector<vector<pii>>> adj(MAX,vector<vector<pii>>(MAX));
vector<vector<int>> dist(MAX,vector<int>(MAX,-1));
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    for (int i=1; i<=a; i++){
        for (int j=1; j<=b; j++){
            char c;
            cin >> c;
            if (c=='B' || c=='D'){
                adj[i][j].push_back({i+1,j});
                adj[i+1][j].push_back({i,j});
            }
            if (c=='B' || c=='R'){
                adj[i][j].push_back({i,j+1});
                adj[i][j+1].push_back({i,j});
            }
        }
    }
    queue<pii> Q;
    Q.push({1,1});
    dist[1][1] = 1;
    while (!Q.empty()){
        int row = Q.front().f;
        int col = Q.front().s;
        Q.pop();
        for (auto nextNode : adj[row][col]){
            int newRow = nextNode.f;
            int newCol = nextNode.s;
            int newDist = dist[row][col]+1;
            if (dist[newRow][newCol]!=-1 && dist[newRow][newCol]!=newDist)
                continue;
            if (newDist == dist[newRow][newCol]){
                cout<<newDist<<"\n"<<newRow<<" "<<newCol<<"\n";
                return 0;
            }
            dist[newRow][newCol] = newDist;
            Q.push({newRow,newCol});
        }
    }
    return 0;
}
