/*
CONTEST: 17th Thailand Olympiad in Informatics, 2021
HOST: Walailuk University, Nakhon Sri Thammarat
TASK: Fermented Rice Noodle (toi17_noodle)
TASK_SOURCE:
    https://beta.programming.in.th/tasks/toi17_noodle
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 04/05/2023
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M,K;
    cin >> N >> M >> K;
    vector<ll> noodle(N);
    for (int i=0; i<N; i++)
        cin >> noodle[i];
    ll left = 0;
    ll right = (ll)1e18;
    while (left < right){
        ll mid = (left+right)/2;
        priority_queue<ll,vector<ll>,greater<ll>> PQ;
        ll sum = 0;
        int cnt = 0;
        for (int i=0; i<N; i++){
            sum += noodle[i];
            PQ.push({noodle[i]});
            while (PQ.size()>K){
                sum -= PQ.top();
                PQ.pop();
            }
            if (sum>=mid && PQ.size()==K){
                sum = 0;
                ++cnt;
                while (!PQ.empty())
                    PQ.pop();
            }
        }
        if (cnt < M)
            right = mid;
        else
            left = mid+1;
    }
    cout << left-1;
    return 0;
}