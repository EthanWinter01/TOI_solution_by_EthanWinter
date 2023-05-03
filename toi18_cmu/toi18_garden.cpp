/*
CONTEST: 18th Thailand Olympiad in Informatics, 2022
HOST: Chaing Mai University, Chaing Mai
TASK: Botanical Garden (toi18_garden)
TASK_SOURCE:
    https://beta.programming.in.th/tasks/toi18_garden
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 03/05/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,Q;
    cin >> N >> Q;
    vector<int> tree(N);
    vector<pair<int,int>> answer(N);
    for (int i=0; i<N; i++)
        cin >> tree[i];
    vector<int> temp;
    for (int i=0; i<N; i++){
        int lower = lower_bound(temp.begin(),temp.end(),tree[i])-temp.begin();
        answer[i].first = lower;
        if (lower==temp.size()){
            temp.push_back(tree[i]);
        } else if (temp[0] > tree[i]){
            temp[0] = tree[i];
        } else if (temp[lower] > tree[i]){
            temp[lower] = tree[i];
        }
    }
    temp.clear();
    for (int i=N-1; i>0; i--){
        int lower = lower_bound(temp.begin(),temp.end(),tree[i])-temp.begin();
        answer[i].second = lower;
        if (lower==temp.size()){
            temp.push_back(tree[i]);
        } else if (temp[0] > tree[i]){
            temp[0] = tree[i];
        } else if (temp[lower] > tree[i]){
            temp[lower] = tree[i];
        }
    }
    while (Q--){
        int x;
        cin >> x;
        cout<<min(answer[x].first, answer[x].second)<<"\n";
    }
    return 0;
}