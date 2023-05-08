/*
CONTEST: 15th Thailand Olympiad in Informatics, 2019
HOST: Burapha University, Chonburi
TASK: Archery (toi15_archery)
SOURCE:
    https://beta.programming.in.th/tasks/toi15_archery
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN: 06/05/2023
*/

#include <bits/stdc++.h>
#define MAX 500001
#define ll long long
using namespace std;
vector<pair<ll,ll>> height(MAX);
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    ll minHeight = LLONG_MAX;
    for (int i=0; i<N; ++i){
        cin >> height[i].second;
        minHeight = min(minHeight,height[i].second);
    }
    for (int i=0; i<N; ++i)
        cin >> height[i].first;
    sort(height.begin(),height.begin()+N);
    ll sum = 0;
    for (int i=0; i<N; ++i)
        sum += height[i].first - height[0].first;
    ll pos = height[0].first;
    ll mov = sum;
    for (int i=1; i<N; ++i){
        if (height[i].first > minHeight)
            break;
        sum -= (height[i].first - height[i-1].first) * (N-1);
        sum += (height[i-1].second - height[i].first + height[i-1].first);
        if (sum < mov){
            pos = height[i].first;
            mov = sum;
        }
    }
    cout << pos << " " << mov;
    return 0;
}
