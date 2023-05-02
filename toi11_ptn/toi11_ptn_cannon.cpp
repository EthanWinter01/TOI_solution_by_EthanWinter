/*
CONTEST: 11th Thailand Olympiad in Informatics, 2015
HOST: Prince Songkla University, Pattani Campus, Trang
TASK: Cannons at the Fort (toi11_cannon)
TASK_SOURCE:
    https://beta.programming.in.th/tasks/toi11_cannon
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 02/05/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,K,L;
    cin >> N >> M >> K >> L;
    vector<int> cannon(N);
    for (int i=0; i<N; i++)
        cin >> cannon[i];
    while (K--){
        vector<int> tray(M);
        for (int i=0; i<M; i++)
            cin >> tray[i];
        int ready = 0,curr = 0;
        for (int i=0; i<M; i++){
            int upper = upper_bound(cannon.begin()+curr,cannon.end(),tray[i]+L)-cannon.begin();
            int lower = lower_bound(cannon.begin()+curr,cannon.end(),tray[i]-L)-cannon.begin();
            if (curr >= N)
                break;
            ready += upper-lower;
            curr = upper;
        }
        cout << ready<<"\n";
    }
    return 0;
}
