/*
CONTEST: 6th Thailand Olympiad in Informatics, 2010
HOST: Chaing Mai University, Chaing Mai
TASK: Schedule
SOURCE:
    https://beta.programming.in.th/tasks/toi6_schedule
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 18/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
struct SIGNAL{
    int sorter,status,index;
    bool operator<(const SIGNAL& r)const{
        if (r.sorter==sorter)
            return status < r.status;
        return sorter < r.sorter;
    }
};
vector<SIGNAL> vec;
vector<bool> visited(500001,false);
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k,u,v;
    cin >> n >> k >> m;
    for (int i=1; i<=n; i++){
        cin >> u >> v;
        vec.push_back({u,1,i});
        vec.push_back({v+1,-1,i});
    }    
    sort(vec.begin(),vec.end());
    int cnt = 0;
    for (auto it : vec){
        int stat = it.status;
        int index = it.index;
        if (stat==1 && cnt<k){
            visited[index] = true;
            cnt++;
        } else if (stat==-1){
            if (visited[index])
                cnt--;
        }
    }
    while (m--){
        int x;
        cin >> x;
        cout << (visited[x]?"Y":"N") << " ";
    }
    return 0;
}