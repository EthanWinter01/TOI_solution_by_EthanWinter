/*
CONTEST: 11th Thailand Olympiad in Informatics, 2015
HOST: Prince Songkla University, Pattani Campus, Trang
TASK: Sacred Place (toi11_place)
TASK_SOURCE:
    https://beta.programming.in.th/tasks/toi11_place
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 12/04/2023
*/

#include <bits/stdc++.h>
#define MAX_NODE 200001
#define ll long long
using namespace std;
int N,M;
struct Edges{
    int u,v;
    ll w;
    bool operator<(const Edges& r)const{
        return w < r.w;
    }
};
vector<int> parent(MAX_NODE);
int findParent(int u){
    if (u == parent[u])
        return u;
    return parent[u] = findParent(parent[u]);
}
priority_queue<Edges> PQ;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i=1; i<=N; i++)
        parent[i] = i;
    for (int i=0; i<M; i++){
        int s,d; ll l;
        cin >> s >> d >> l;
        PQ.push({s,d,l});
    }
    ll sum = 0;
    int cnt = 0;
    while (!PQ.empty() && cnt<N-1){
        Edges e = PQ.top();
        PQ.pop();
        int pu = findParent(e.u);
        int pv = findParent(e.v);
        if (pu == pv)
            continue;
        parent[pu] = pv;
        sum += e.w;
        cnt++;
    }
    cout << sum-N+1;
    return 0;
}