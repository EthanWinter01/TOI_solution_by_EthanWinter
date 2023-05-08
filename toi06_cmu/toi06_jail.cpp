/*
CONTEST: 6th Thailand Olympiad in Informatics, 2010
HOST: Chaing Mai University, Chaing Mai
TASK: Jail
SOURCE:
    https://beta.programming.in.th/tasks/toi6_jail
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 18/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    queue<int> Q;
    for (int i=1; i<=n; i++)
        Q.push(i);
    int cnt = 0;
    while (!Q.empty()){
        cnt++;
        if (cnt == m){
            cout << Q.front() << " ";
            Q.pop();
            cnt = 0;
        } else {
            int temp = Q.front();
            Q.pop();
            Q.push(temp);
        }
    }
    return 0;
}
