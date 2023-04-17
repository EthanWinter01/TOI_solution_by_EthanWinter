/*
CONTEST: 8th Thailand Olympiad in Informatics, 2012
HOST: Silapakorn University, Bangkok
TASK: Fighter (toi8_fighter & 1155)
SOURCE:
    https://beta.programming.in.th/tasks/toi8_fighter
    https://beta.programming.in.th/tasks/1155
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
    int P,h;
    cin >> P;
    int elife = P;
    int olife = P;
    P*=2;
    int estreak = 0;
    int ostreak = 0;
    while (P--){
        cin >> h;
        if (h%2==0){
            ostreak = 0;
            estreak++;
            if (estreak>=3)
                olife-=3;
            else
                olife--;
        } else {
            estreak = 0;
            ostreak++;
            if (ostreak>=3)
                elife-=3;
            else
                elife--;
        }
        if (elife <= 0){
            cout << "1\n" << h;
            return 0;
        }
        if (olife <= 0){
            cout << "0\n" << h;
            return 0;
        }
    }
}