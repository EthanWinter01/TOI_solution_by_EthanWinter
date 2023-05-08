/*
CONTEST: 10th Thailand Olympiad in Informatics, 2014
HOST: Ubon Ratchathani University, Ubon Ratchathani
TASK: Go to School (toi10_goschool)
SOURCE: 
    https://beta.programming.in.th/tasks/toi10_goschool
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 26/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,O;
    cin >> n >> m >> O;
    vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
    vector<vector<int>> dog(n+1,vector<int>(m+1,false));
    while (O--){
        int dogN, dogM;
        cin >> dogN >> dogM;
        dog[dogN][dogM] = true;
    }
    dp[1][1] = 1;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (!dog[i][j])
                dp[i][j] += dp[i-1][j]+dp[i][j-1];
        }
    }
    cout << dp[n][m];
    return 0;
}