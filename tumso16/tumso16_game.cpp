/*
CONTEST: 16th Triam Udom Mathematics and Science Olympiad, 2019
HOST: Triam Udom Suksa School
TASK: เกมหยิบของ (tumso16_game)
SOURCE:
    https://beta.programming.in.th/tasks/tumso16_game
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
SCHOOL: Phimanpittayasan School
WRITTEN ON: 20/05/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin >> a >> b >> c;
    vector<int> p(4);
    vector<int> dp(1000001);
    p[0] = 1;
    p[1] = a;
    p[2] = b;
    p[3] = c;
    dp[1] = 1;
    for (int i=1; i<=1000000; ++i)
        for (int j=0; j<4; ++j)
            if (i-p[j]>=0 && dp[i-p[j]]==0)
                dp[i] = 1;
    int Q;
    cin >> Q;
    while (Q--){
        int n;
        cin >> n;
        cout << (dp[n]==0?"lang":"gorn") << "\n";
    }
    return 0;
}