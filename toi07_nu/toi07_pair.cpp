/*
CONTEST: 7th Thailand Olympiad in Informatics, 2011
HOST: Naresuan University, Phitsanulok
TASK: Food (toi7_pair & 1109)
SOURCE:
    https://beta.programming.in.th/tasks/toi7_pair
    https://beta.programming.in.th/tasks/1109
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus (PTN)
SCHOOL: Phimanpittayasan School, Satun
WRITTEN: 20/05/2023
*/

#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
ll n, ans;
vector<pll> vec;
void mergeSort(int left, int right){
    if (left == right)
        return;
    int mid = (left+right)/2;
    mergeSort(left, mid);
    mergeSort(mid+1, right);
    int idxl = left;
    int idxr = mid+1;
    vector<pll> temp;
    ll dp[mid+1];
    dp[mid] = vec[mid].first;
    for(int i = mid-1; i >= left; i--)
        dp[i] = vec[i].first + dp[i+1];
    while(idxl <= mid and idxr <= right){
        if (vec[idxl].second <= vec[idxr].second){
            temp.push_back(vec[idxl++]);
        } else {
            ans += (mid-idxl+1) * vec[idxr].first + dp[idxl];
            temp.push_back(vec[idxr++]);
        }
    }
    while (idxl <= mid)
        temp.push_back(vec[idxl++]);
    while (idxr <= right)
        temp.push_back(vec[idxr++]);
    for (int i = left; i <= right; i++)
        vec[i] = temp[i-left];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }
    sort(vec.begin(), vec.end());
    mergeSort(0, n-1);
    cout << ans;
}
