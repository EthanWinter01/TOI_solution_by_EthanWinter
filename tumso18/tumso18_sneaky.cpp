/*
CONTEST: Triam Udom, Mathematics and Science Olympiad, 2021
HOST: Triam Udom Suksa School
TASK: เนียนให้ผ่าน (tumso18_sneaky)
SOURCE:
    https://beta.programming.in.th/tasks/tumso18_sneaky
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
WRITTEN ON: 13/05/2023
*/

#include <bits/stdc++.h>
#define MAX 100001
#define ll long long
using namespace std;
vector<ll> arr(MAX,0);
vector<ll> dp(MAX,0);
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    m /= 2;
    for (int i=1; i<=n; ++i){
        cin >> arr[i];
        arr[i] += arr[i-1]-m;
    }
    int idx = 0;
    ll sz = 0;
    for (int i=1; i<=n; ++i){
        if (arr[i] <= 0)
            continue;
        idx = lower_bound(dp.begin(),dp.begin()+sz,arr[i])-dp.begin();
        if (idx == sz)
            ++sz;
        dp[idx] = arr[i];
    }
    cout << idx+1;
    return 0;
}
