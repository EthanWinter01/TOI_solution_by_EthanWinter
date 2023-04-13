/*
TASK: Skyline (toi2_skyline & 1008)
SOURCE:
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
WRITTEN ON: 12/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,L,H,R;
    cin >> N;
    vector<int> skyline(3001,0);
    for (int i=0; i<N; i++){
        cin >> L >> H >> R;
        for (int j=L; j<R; j++){
            skyline[j] = max(skyline[j],H);
        }
    }
    int current = 0;
    for (int i=1; i<=3000; i++){
        if (skyline[i]!=current){
            cout << i << " " << skyline[i] << " ";
            current = skyline[i];
        }
    }
    return 0;
}
