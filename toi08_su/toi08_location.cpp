/*
CONTEST: 8th Thailand Olympiad in Informatics, 2012
HOST: Silapakorn University, Bangkok
TASK: Location (toi8_fighter & 1158)
SOURCE:
    https://beta.programming.in.th/tasks/toi8_location
    https://beta.programming.in.th/tasks/1158
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 16/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M,N,K;
    cin >> M >> N >> K;
    vector<vector<int>> grid(M+1,vector<int>(N+1,0));
    for (int i=1; i<=M; i++)
        for (int j=1; j<=N; j++){
            cin >> grid[i][j];
            grid[i][j] += grid[i][j-1]+grid[i-1][j]-grid[i-1][j-1];
        }
    int answer = 0;
    for (int i=K; i<=M; i++)
        for (int j=K; j<=N; j++)
            answer = max(answer,grid[i][j]-grid[i-K][j]-grid[i][j-K]+grid[i-K][j-K]);
    cout << answer;
    return 0;
}
