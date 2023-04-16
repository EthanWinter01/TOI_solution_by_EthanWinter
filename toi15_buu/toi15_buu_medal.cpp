/*
CONTEST: 15th Thailand Olympiad in Informatics, 2019
HOST: Burapha University, Chonburi
TASK: Medal (toi15_medal)
SOURCE:
    https://beta.programming.in.th/tasks/toi15_medal
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN: 15/04/2023
*/

#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;
vector<int> h;
vector<int> t;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    h.resize(n);
    t.resize(n);
    for (int i=0; i<n; i++)
        cin >> h[i];
    for (int i=0; i<n; i++)
        cin >> t[i];
    sort(h.begin(),h.end());
    sort(t.begin(),t.end(),greater<int>());
    int maxsum=INT_MIN,minsum=INT_MAX;
    for (int i=0; i<n; i++){
        maxsum = max(maxsum,h[i]+t[i]);
        minsum = min(minsum,h[i]+t[i]);
    }
    cout << maxsum-minsum;
    return 0;
}