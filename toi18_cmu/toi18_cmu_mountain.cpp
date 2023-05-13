/*
CONTEST: 18th Thailand Olympiad in Informatics, 2022
HOST: Chaing Mai University, Chaing Mai
TASK: Mountain (toi18_mountain)
TASK_SOURCE:
    https://beta.programming.in.th/tasks/toi18_mountain
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 13/05/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define pii pair<ll,ll>
#define MAX 501
using namespace std;
vector<vector<ll>> dist(MAX,vector<ll>(MAX,LLONG_MAX));
vector<pii> camp(MAX);
ll manhattanDistance(int a, int b){
    return abs(camp[a].f-camp[b].f)+abs(camp[a].s-camp[b].s);
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,x,y;
    cin >> n >> m;
    for (int i=1; i<=n; ++i)
        cin >> camp[i].f >> camp[i].s;
    for (int i=1; i<=n; ++i)
        dist[1][i] = manhattanDistance(1,i);
    for (int i=2; i<=n; ++i){
        for (int j=1; j<=n; ++j){
            dist[i][j] = dist[i-1][j];
            for (int k=1; k<=n; ++k){
                dist[i][j] = min(dist[i][j],max(dist[i-1][k],manhattanDistance(j,k)));
            }
        }
    }
    ll sum = 0;
    while (m--){
        ll supply;
        cin >> supply;
        ll left = 0;
        ll right = n;
        while (left < right){
            ll mid = (left+right)/2;
            if (dist[mid][n] <= supply)
                right = mid;
            else
                left = mid+1;
        }
        sum += left;
    }
    cout << sum;
    return 0;
}