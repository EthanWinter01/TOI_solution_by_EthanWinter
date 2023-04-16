/*
TASK: Fortress (toi10_fortress)
SOURCE: 
    https://beta.programming.in.th/tasks/toi10_fortress
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
WRITTEN ON: 16/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Q = 20;
    long long m,n;
    while (Q--){
        cin >> m >> n;
        if (n*2>m || (4*n-m)<0)
            cout << "0\n";
        else 
            cout << ((4*n-m)/2)+1 << "\n";
    }
    return 0;
}
