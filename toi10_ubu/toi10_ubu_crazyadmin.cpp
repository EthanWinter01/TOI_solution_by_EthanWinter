/*
CONTEST: 10th Thailand Olympiad in Informatics, 2014
HOST: Ubon Ratchathani University, Ubon Ratchathani
TASK: Crazy Admin (toi10_crazyadmin)
SOURCE: 
    https://beta.programming.in.th/tasks/toi10_crazyadmin
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 16/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M,O;
    cin >> M >> O;
    int maxU = 0;
    vector<int> U(O);
    for (int i=0; i<O; i++){
        cin >> U[i];
        maxU = max(maxU,U[i]);
    }
    if (M >= O){
        cout << maxU;
        return 0;
    }
    int left = 0;
    int right = 1e7;
    while (left < right){
        int mid = (left+right)/2;
        int temp = 0;
        int room = 0;
        for (auto u : U){
            if (temp+u > mid){
                temp = u;
                room++;
            } else {
                temp += u;
            }
        }
        room++;
        if (room > M)
            left = mid+1;
        else
            right = mid;
    }
    cout << left;
    return 0;
}