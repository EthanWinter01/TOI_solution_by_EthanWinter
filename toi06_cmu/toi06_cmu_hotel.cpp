/*
CONTEST: 6th Thailand Olympiad in Informatics, 2010
HOST: Chaing Mai University, Chaing Mai
TASK: Hotel
SOURCE:
    https://beta.programming.in.th/tasks/toi6_hotel
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
    int n;
    cin >> n;
    long long cost = 0;
    while (n>=9){
        n -= 15;
        cost+=3000;
    }
    while (n>=4){
        n -= 5;
        cost+=1500;
    }
    while (n>=2){
        n -= 2;
        cost+=800;
    }
    while (n>=1){
        n -= 1;
        cost+=500;
    }
    cout << cost;
    return 0;
}