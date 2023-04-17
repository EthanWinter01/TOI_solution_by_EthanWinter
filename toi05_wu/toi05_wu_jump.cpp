/*
CONTEST: 5th POSN - Olympiad in Informatics, 2008
HOST: Walailuk University, Nakhon Sri Thammarat
TASK: Jump (toi5_jump)
SOURCE:
    https://beta.programming.in.th/tasks/toi5_jump
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 17/03/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K;
    cin >> N >> K;
    queue<pair<int,int>> Q;
    int answer = 0;
    for (int i=0; i<N; i++){
        int x;
        cin >> x;
        while (!Q.empty() && x-Q.front().first>K)
            Q.pop();
        Q.push({x,i});
        answer = max(answer,i-Q.front().second);
    }
    cout << answer;
    return 0;
}