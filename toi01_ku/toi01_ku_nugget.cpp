/*
TASK: Nugget Number (toi1_nugget & 1003)
TASK_SOURCE: https://beta.programming.in.th/tasks/toi1_nugget
             https://beta.programming.in.th/tasks/1003
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus (PTN)
WRITTEN ON: 11/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> mcNugget(121, false);
    mcNugget[6] = true;
    mcNugget[9] = true;
    mcNugget[20] = true;
    bool check = false;
    for (int i=1; i<=N; i++){
        if (mcNugget[i]){
            cout << i << "\n";
            mcNugget[i+6] = true;
            mcNugget[i+9] = true;
            mcNugget[i+20] = true;
            check = true;
        }
    }
    if (!check)
        cout << "no";
    return 0;
}
