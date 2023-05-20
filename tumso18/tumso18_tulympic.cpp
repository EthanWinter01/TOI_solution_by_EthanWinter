/*
CONTEST: 18th Triam Udom Mathematics and Science Olympiad, 2021
HOST: Triam Udom Suksa School
TASK: TU Lympics (tumso18_tulympic)
SOURCE: 
    https://beta.programming.in.th/tasks/tumso18_tulympic
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
SCHOOL: Phimanpittayasan School
WRITTEN ON: 23/03/2023
*/

#include <bits/stdc++.h>
#define f first 
#define s second 
#define ll long long
using namespace std;
int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N,M,X,T,sc,rank; 
    cin >> N >> M >> X >> T;
    ll score[N], mat[N][M];
    for (int i=0; i<N; i++)
        cin >> score[i];
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> mat[i][j];
    ll total[N] = {0};
    pair<ll,int> tn[N];
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            tn[j].f = mat[j][i];
            tn[j].s = j;
        }
        sort(tn, tn+N);
        for (int j=0; j<N; j++)
            total[tn[j].s] += score[j];
    }
    sc = total[X-1];
    sort(total, total+N);
    reverse(total, total+N);
    for (int i=0; i<N; i++)
        if (total[i] == sc)
            rank = i+1;
    if (T == 1)
        cout << rank;
    else if (T==2)
        cout << rank << " " << sc;
    return 0;
}