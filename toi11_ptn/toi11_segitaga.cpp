/*
CONTEST: 11th Thailand Olympiad in Informatics, 2015
HOST: Prince Songkla University, Pattani Campus, Trang
TASK: Segi Tiga Operation (toi11_segitiga)
TASK_SOURCE:
    https://beta.programming.in.th/tasks/toi11_segitiga
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 10/05/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 20;
    while (t--){
        int n;
        string str;
        cin >> n >> str;
        bool dp[3][n][n];
        for (int i=0; i<3; ++i)
            for (int j=0; j<n; ++j)
                for (int k=0; k<n; ++k)
                    dp[i][j][k] = false;
        for (int i=0; i<n; ++i)
            dp[str[i]-'0'][i][i]=true;
        for (int sz=2; sz<=n; ++sz){
            for (int be=0; be+sz<=n; ++be){
                int en = be+sz-1;
                for (int k=be; k<en; ++k){
                    dp[2][be][en] = dp[2][be][en]|(dp[0][be][k]&dp[0][k+1][en]);
                    dp[1][be][en] = dp[1][be][en]|(dp[0][be][k]&dp[1][k+1][en]);
                    dp[0][be][en] = dp[0][be][en]|(dp[0][be][k]&dp[2][k+1][en]);
                    dp[2][be][en] = dp[2][be][en]|(dp[1][be][k]&dp[0][k+1][en]);
                    dp[1][be][en] = dp[1][be][en]|(dp[1][be][k]&dp[1][k+1][en]);
                    dp[1][be][en] = dp[1][be][en]|(dp[1][be][k]&dp[2][k+1][en]);
                    dp[1][be][en] = dp[1][be][en]|(dp[2][be][k]&dp[0][k+1][en]);
                    dp[2][be][en] = dp[2][be][en]|(dp[2][be][k]&dp[1][k+1][en]);
                    dp[1][be][en] = dp[1][be][en]|(dp[2][be][k]&dp[2][k+1][en]);
                }
            }
        }
        cout << (dp[0][0][n-1]?"yes\n":"no\n");
    }
    return 0;
}
