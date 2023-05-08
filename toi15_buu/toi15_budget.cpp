/*
CONTEST: 15th Thailand Olympiad in Informatics, 2019
HOST: Burapha University, Chonburi
TASK: Budget (toi15_budget)
SOURCE:
    https://beta.programming.in.th/tasks/toi15_budget
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN: 06/05/2023
*/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define MAX_NODE 3001
using namespace std;
struct EDGES{
    int u,v;
    ll w;
    bool operator<(const EDGES &r)const{
        return w > r.w;
    }
};
vector<int> parent(MAX_NODE);
int findParent(int u){
    if (u == parent[u])
        return u;
    return parent[u] = findParent(parent[u]);
}
priority_queue<EDGES> PQ;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int B,E,P,cnt = 0;
    cin >> B >> E;
    for (int i=0; i<B; ++i)
        parent[i] = i;
    for (int i=0; i<E; ++i){
        int S,T,R; ll L;
        cin >> S >> T >> L >> R;
        PQ.push({S,T,L});
        if (R == 1){
            int ps = findParent(S);
            int pt = findParent(T);
            if (ps == pt)
                continue;
            parent[ps] = pt;
            cnt++;
        } else {
            PQ.push({S,T,L});
        }
    }
    cin >> P;
    vector<pii> pack;
    while (P--){
        int C,D;
        cin >> C >> D;
        pack.push_back({D,C});
    }
    sort(pack.begin(),pack.end());
    ll payment = 0;
    while (!PQ.empty() && cnt<B-1){
        EDGES e = PQ.top();
        PQ.pop();
        int pu = findParent(e.u);
        int pv = findParent(e.v);
        if (pu == pv)
            continue;
        parent[pu] = pv;
        for (auto p : pack){
            if (p.second >= e.w){
                payment += p.first;
                break;
            }
        }
        cnt++;
    }
    cout << payment;
    return 0;
}
