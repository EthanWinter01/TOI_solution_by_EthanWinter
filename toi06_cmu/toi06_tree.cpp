/*
CONTEST: 6th Thailand Olympiad in Informatics, 2010
HOST: Chaing Mai University, Chaing Mai
TASK Tree
SOURCE:
    https://beta.programming.in.th/tasks/toi6_tree
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 18/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 5;
    vector<pair<int,int>> node1,node2;
    while (T--){
        int n,u,v;
        cin >> n;
        for (int i=0; i<n-1; i++){
            cin >> u >> v;
            node1.push_back({min(u,v),max(u,v)});
        }
        for (int i=0; i<n-1; i++){
            cin >> u >> v;
            node2.push_back({min(u,v),max(u,v)});
        }
        sort(node1.begin(),node1.end());
        sort(node2.begin(),node2.end());
        (node1==node2)?cout<<"Y":cout<<"N";
        node1.clear();
        node2.clear();
    }
    return 0;
}
