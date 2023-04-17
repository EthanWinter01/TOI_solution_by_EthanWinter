/*
CONTEST: 2nd POSN - Olympiad in Informatics, 2006
HOST: Burapha University, Chonburi
TASK: Bee (toi2_bee & 1007)
SOURCE: 
    https://beta.programming.in.th/tasks/toi2_bee
    https://beta.programming.in.th/tasks/1007
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus (PTN)
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 13/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> bee(25,1), workBee(25,0);
    bee[0] = 2;
    workBee[0] = 1;
    for (int i=1; i<25; i++){
        workBee[i] = 1+workBee[i-1]; 
        if (bee[i-1]-workBee[i-1]-1 > 0)
            workBee[i] += bee[i-1]-workBee[i-1]-1;
        bee[i] += workBee[i] + workBee[i-1];
    }
    while (true){
        int years;
        cin >> years;
        if (years == -1)
            break;
        cout << workBee[years] << " " << bee[years] << "\n";
    }
    return 0;
}
