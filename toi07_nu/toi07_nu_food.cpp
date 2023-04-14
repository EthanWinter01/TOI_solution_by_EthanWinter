/*
TASK: Food (toi7_food & 0039)
SOURCE:
    https://beta.programming.in.th/tasks/toi7_food
    https://beta.programming.in.th/tasks/0039
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus (PTN)
WRITTEN: 13/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> menu(n);
    vector<bool> dontGoFirst(n,false);
    int d;
    for (int i=0; i<m; i++){
        cin >> d;
        dontGoFirst[d] = true;
    }
    for (int i=1; i<=n; i++)
        menu[i-1] = i;
    do {
        if (dontGoFirst[menu[0]])
            continue;
        for (auto it : menu)
            cout << it << " ";
        cout << "\n";
    } while (next_permutation(menu.begin(),menu.end()));
    return 0;
}
