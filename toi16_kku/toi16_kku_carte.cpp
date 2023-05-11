/*
CONTEST: 16th Thailand Olympaid in Informatics, 2020
HOST: Khon Khaen University, Khon Khaen
TASK: toi16_carte
SOURCE: 
    https://beta.programming.in.th/tasks/toi16_carte
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 11/05/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int R,K,maxFood=0;
    cin >> R >> K;
    vector<vector<int>> dp(401,vector<int>(401,0));
    while (R--){
        int N;
        cin >> N;
        vector<int> food(N);
        for (int i=0; i<N; ++i){
            cin >> food[i];
            dp[i][i] = 1;
        }
        for (int sz=1; sz<N; ++sz){
            for (int be=0; be+sz<=N; ++be){
                int en = be+sz;
                dp[be][en] = INT_MAX;
                for (int k=be; k<en; ++k){
                    dp[be][en] = min(dp[be][en],dp[be][k]+dp[k+1][en]);
                }
                if (food[be] == food[en]){
                    --dp[be][en];
                }
            }
        }
        maxFood = max(maxFood,dp[0][N-1]);
        for (int i=0; i<=N; ++i)
            for (int j=0; j<=N; ++j)
                dp[i][j] = 0;
    }
    cout << maxFood;
    return 0;
}