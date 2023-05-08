/*
CONTEST: 12th Thailand Olympiad in Informatics, 2016
HOST: Prince Songkla University, Hat Yai Campus
TASK: Cablecar (toi12_cablecar)
SOURCE:
    https://beta.programming.in.th/tasks/toi12_cablecar
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanphittayasan School
WRITTEN ON: 08/05/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
using namespace std;
int manhattanDistance(int& x1,int& x2,int& y1,int& y2){
    return abs(x1-x2)+abs(y1-y2);
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<pii> coor(n);
    vector<int> dist(n,INT_MAX);
    for (int i=0; i<n; ++i)
        cin >> coor[i].f >> coor[i].s;
    for (int i=0; i<n-1; ++i){
        int idx;
        int minDist = INT_MAX;
        for (int j=i+1; j<n; ++j){
            int d = manhattanDistance(coor[i].f,coor[j].f,coor[i].s,coor[j].s);
            dist[j] = min(dist[j],d);
            if (minDist > dist[j]){
                minDist = dist[j];
                idx = j;
            }
        }
        swap(coor[idx],coor[i+1]);
        swap(dist[idx],dist[i+1]);
    }
    sort(dist.begin(),dist.end());
    long long answer = 0;
    for (int i=0; i<n-k; i++)
        answer += dist[i];
    cout << answer;
    return 0;
}
