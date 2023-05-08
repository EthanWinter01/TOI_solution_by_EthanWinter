/*
CONTEST: 13th Thailand Olympiad in Informatics, 2017
HOST: Mahidol Wittayanusorn & Mahidol University, Nakhon Pathom
TASK: Timer Switch (toi13_timerswitch)
SOURCE:
    https://beta.programming.in.th/tasks/toi13_timerswitch
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 08/05/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string str,check;
    cin >> n >> str;
    check = str+str;
    for (int i=1; i<=n; ++i){
        if (n%i==0 && str == check.substr(i,n)){
            cout << i;
            break;
        }
    }
    return 0;
}