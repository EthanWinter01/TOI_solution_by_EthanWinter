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