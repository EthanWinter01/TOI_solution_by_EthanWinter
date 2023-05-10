/*
CONTEST: 12th Thailand Olympiad in Informatics, 2016
HOST: Prince Songkla University, Hat Yai Campus
TASK: Barrier (toi12_barrier)
SOURCE:
    https://beta.programming.in.th/tasks/toi12_barrier
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanphittayasan School
WRITTEN ON: 09/05/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,w;
    cin >> n >> w;
    int value=0, len=INT_MAX, sum=0;
    deque<pair<int,int>> DQ;
    for (int i=1; i<=n; ++i){
        int v;
        cin >> v;
        sum += v;
        while (!DQ.empty() && i-DQ.front().second > w)
            DQ.pop_front();
        while (!DQ.empty() && DQ.back().first > sum)
            DQ.pop_back();
        DQ.push_back({sum,i});
        if (sum-DQ.front().first > value){
            value = sum-DQ.front().first;
            len = i-DQ.front().second;
        } else if (sum-DQ.front().first == value){
            len = min(len,i-DQ.front().second);
        }
    }
    cout << value << "\n" << (len==INT_MAX?0:len);
    return 0;
}
