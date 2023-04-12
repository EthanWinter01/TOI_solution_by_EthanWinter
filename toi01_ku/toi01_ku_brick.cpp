/*
CONTEST: 1st POSN - Olympiad in Informatics, 2005
HOST: Kasetsart University, Bangkok
TASK: Brick (toi1_brick & 1001)
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 11/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin >> N >> M;
    vector<vector<char>> grid(N,vector<char>(M));
    vector<int> block(M,N);
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> grid[i][j];
            if (grid[i][j]=='O'){
                block[j] = min(i,block[j]);
            }
        }
    }
    vector<int> drop(M);
    for (int i=0; i<M; i++){
        cin >> drop[i];
        for (int j=block[i]-1; j>=0&&drop[i]!=0; j--){
            grid[j][i] = '#';
            drop[i]--;
        }
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cout << grid[i][j];
        }
        cout << "\n";
    }
    return 0;
}