/*
CONTEST: 17th Thailand Olympiad in Informatics, 2021
HOST: Walailuk University, Nakhon Sri Thammarat
TASK: The Wall: The Sequel (toi17_1221)
TASK_SOURCE:
    https://beta.programming.in.th/tasks/toi17_1221
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 06/05/2023
*/

#include <bits/stdc++.h>
#define ll long long
#define MAX_NODE 100001
using namespace std;
vector<ll> qs(MAX_NODE,0);
vector<ll> vec(MAX_NODE);
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,Q;
    cin >> N >> Q;
    for (int i=1; i<=N; i++){
        cin >> vec[i];
        qs[i] = qs[i-1]+vec[i]; 
    }
    while (Q--){
        int L,M,R;
        cin >> L >> M >> R;
        if (M == 1){
            cout << qs[R]-qs[L-1] << " ";
        } else {
            ll sum = 0;
            for (int i=L; i<=R; i+=M)
                sum += vec[i];
            cout << sum << " ";
        }
    }

    return 0;
}