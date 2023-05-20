/*
CONTEST: Olympics IPST in Computer, 2558, Camp 2
HOST: Institute for the Promotion of Teaching Science and Technology
TASK: Wormhole (o59_oct_c2_wormholes)
SOURCE:
    https://beta.programming.in.th/tasks/o59_mar_c2_wormholes
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 20/05/2023
*/

#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
struct POINT{
    int x,y;
    int operator+(const POINT& r)const{
        return abs(x-r.x)+abs(y-r.y);
    }
};
vector<vector<POINT>> wormhole(31,vector<POINT>(2));
vector<vector<int>> dist(31,vector<int>(31,INT_MAX));
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int K,M;
    cin >> K >> M;
    for (int i=0; i<K; ++i)
        cin >> wormhole[i][0].x >> wormhole[i][0].y >> wormhole[i][1].x >> wormhole[i][1].y;
    for (int i=0; i<K; ++i)
        for (int j=0; j<K; ++j)
            for (int holei=0; holei<2; ++holei)
                for (int holej=0; holej<2; ++holej)
                    dist[i][j] = min(dist[i][j],wormhole[i][holei]+wormhole[j][holej]);
    for (int k=0; k<K; ++k)
        for (int i=0; i<K; ++i)
            for (int j=0; j<K; ++j)
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
    while (M--){
        POINT a,b;
        cin >> a.x >> a.y >> b.x >> b.y;
        int answer = a+b;
        for (int i=0; i<K; ++i)
            for (int j=0; j<K; ++j)
                for (int holei=0; holei<2; ++holei)
                    for (int holej=0; holej<2; ++holej)
                        answer = min(answer,(wormhole[i][holei]+a)+dist[i][j]+(wormhole[j][holej]+b));
        cout << answer << "\n";
    }
    return 0;
}