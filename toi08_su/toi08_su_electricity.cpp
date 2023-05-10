/*
CONTEST: 8th Thailand Olympiad in Informatics, 2012
HOST: Silapakorn University, Bangkok
TASK: Electricity (toi8_electricity & 1157)
SOURCE:
    https://beta.programming.in.th/tasks/toi8_electricity
    https://beta.programming.in.th/tasks/1157
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 10/05/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,k;
    cin >> N >> k;
    deque<pair<int,int>> DQ;
    for (int i=1; i<=N; ++i){
        int p;
        cin >> p;
        if (i == 1){
            DQ.push_back({p,1});
            continue;
        }
        if (i == N){
            cout << DQ.front().first+p;
            return 0;
        }
        int temp = DQ.front().first+p;
        while (!DQ.empty() && i-DQ.front().second >= k)
            DQ.pop_front();
        while (!DQ.empty() && DQ.back().first > temp)
            DQ.pop_back();
        DQ.push_back({temp,i});
    }
}
