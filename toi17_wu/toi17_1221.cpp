/*
CONTEST: 17th Thailand Olympiad in Informatics, 2021
HOST: Walailuk University, Nakhon Sri Thammarat
TASK: 1221 (toi17_1221)
TASK_SOURCE:
    https://beta.programming.in.th/tasks/toi17_1221
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 06/05/2023
*/

#include <bits/stdc++.h>
#define ll long long
#define MAX_NODE 501
using namespace std;
vector<ll> items(MAX_NODE);
vector<vector<ll>> grid(MAX_NODE,vector<ll>(MAX_NODE));
vector<vector<int>> cnt(MAX_NODE,vector<int>(MAX_NODE));
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,Q;
    cin >> N >> M >> Q;
    for (int i=0; i<N; ++i)
        cin >> items[i]; 
    for (int i=0; i<N; ++i){
        for (int j=0; j<N; ++j){
            grid[i][j] = items[i]+items[j];
            cnt[i][j] = 2;
        }
    }
    for (int i=0; i<M; ++i){
        int a,b; ll c;
        cin >> a >> b >> c;
        --a; --b;
        grid[a][b] = grid[b][a] = c;
    }
    for (int k=0; k<N; ++k){
        for (int i=0; i<N; ++i){
            for (int j=0; j<N; ++j){
                ll dist = grid[i][k]+grid[k][j];
                int unit = cnt[i][j]+cnt[k][j];
                if (dist < grid[i][j]){
                    grid[i][j] = dist;
                    cnt[i][j] = cnt[i][k]+cnt[k][j];
                }
                if (dist == grid[i][k])
                    cnt[i][j] = min(cnt[i][j],unit);
            }
        }
    }
    while (Q--){
        int a,b;
        cin >> a >> b;
        --a; --b;
        cout << grid[a][b] << " " << cnt[a][b] << "\n";
    }
    return 0;
}