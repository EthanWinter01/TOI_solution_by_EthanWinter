/*
CONTEST: 4th POSN - Olympiad in Informatics, 2008
HOST: Suranaree University of Technology, Nakhonratchasrima
TASK: Chromartie Mountain (toi4_mountain & 1060)
SOURCE:
    https://beta.programming.in.th/tasks/toi4_mountain
    https://beta.programming.in.th/tasks/1060
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 15/04/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
using namespace std;
int N,H,S,maxH=0,maxS=0;
vector<pii> vec;
vector<vector<char>> grid(11,vector<char>(101,'.'));
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> S >> H;
        maxH = max(maxH,H);
        maxS = max(maxS,S+(H*2)-1);
        vec.push_back({S,H});
    }
    for (auto v : vec){
        int s = v.f;
        int h = v.s;
        for (int j=0; j<h; j++){
            if (grid[maxH-j][j+s]=='\\')
                grid[maxH-j][j+s]='v';
            else
                grid[maxH-j][j+s]='/';
        }
        int temp = maxH-h+1;
        for (int j=0; j<h; j++){
            if (grid[temp+j][j+s+h]=='/')
                grid[temp+j][j+s+h]='v';
            else
                grid[temp+j][j+s+h]='\\';
        }
    }
    for (int j=0; j<=maxS; j++){
        bool silhouette = false;
        for (int i=0; i<=maxH; i++){
            if (silhouette)
                grid[i][j] = 'X';
            if (grid[i][j]=='/'||grid[i][j]=='\\'||grid[i][j]=='v')
                silhouette = true;
        }
    }
    for (int i=1; i<=maxH; i++){
        for (int j=1; j<=maxS; j++)
            cout << grid[i][j];
        cout << "\n";
    }
    return 0;
}