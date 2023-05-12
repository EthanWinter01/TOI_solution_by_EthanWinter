/*
CONTEST: 11th Thailand Olympiad in Informatics, 2015
HOST: Prince Songkla University, Pattani Campus, Trang
TASK: Labor at the Dock (toi11_labor)
TASK_SOURCE:
    https://beta.programming.in.th/tasks/toi11_labor
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 14/04/2023
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m,n;
    cin >> m >> n;
    vector<ll> labor(m);
    for (int i=0; i<m; i++)
        cin >> labor[i];
    ll left = 0, right = LLONG_MAX-1;
    while (left < right){
        ll mid = left+(right-left)/2;
        ll cnt = 0;
        for (auto l : labor){
            cnt += mid/l;
            if (cnt >= n)
                break;
        }
        if (cnt >= n)
            right = mid;
        else 
            left = mid+1;
    }
    cout << left;
    return 0;
}
