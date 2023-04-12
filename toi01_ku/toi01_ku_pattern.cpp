/*
TASK: Pattern (toi1_pattern)
TASK_SOURCE: https://beta.programming.in.th/tasks/toi1_pattern
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus (PTN)
WRITTEN ON: 12/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> silk(50001,vector<bool>(71,false));
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int maxRow = 1;
    cin >> N;
    for (int i=0; i<N; i++){
        int P,Q,R;
        cin >> P >> Q >> R;
        maxRow = max(P,maxRow);
        for (int j=0; j<R; j++){
            silk[P][Q+j] = 'x';
        }
    }
    for (int i=1; i<=maxRow; i++){
        for (int j=1; j<=70; j++)
            silk[i][j]?cout<<"x":cout<<"o";
        cout << "\n";
    }
    return 0;
}
