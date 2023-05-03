/*
CONTEST: 18th Thailand Olympiad in Informatics, 2022
HOST: Chaing Mai University, Chaing Mai
TASK: Shopping (toi18_shopping)
TASK_SOURCE:
    https://beta.programming.in.th/tasks/toi18_shopping
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 03/05/2023
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, shop;
    cin >> n >> m;
    vector<ll> loss(n,0);
    vector<ll> pts(n,0);
    cin >> shop;
    (shop<0)?loss[0]-=shop:pts[0]+=shop;
    for (int i=1; i<n; i++){
        cin >> shop;
        if (shop<0)
            loss[i] -= shop-loss[i-1];
        else
            loss[i] = loss[i-1];
        if (shop>=0)
            pts[i] += shop+pts[i-1];
        else
            pts[i] = pts[i-1];
    }
    while (m--){
        ll x,h;
        cin >> x >> h;
        ll lower = lower_bound(loss.begin()+x,loss.end(),h+(x==0?0:loss[x-1]))-loss.begin();
        if (lower == n)
            lower = n-1;
        ll skiploss =(x==0?0:pts[x-1]);
        cout << pts[lower]-skiploss<<"\n";
    }
    return 0;
}