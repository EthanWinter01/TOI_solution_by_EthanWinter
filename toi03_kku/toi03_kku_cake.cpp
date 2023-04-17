/*
CONTEST: 3rd POSN - Olympiad in Informatics, 2007
HOST: Khon Khaen University, Khon Khaen
TASK: Silly Bakery (toi3_cake & 1012)
SOURCE:
    https://beta.programming.in.th/tasks/toi3_cake
    https://beta.programming.in.th/tasks/1012
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
    int n;
    cin >> n;
    vector<int> cake(5);
    while (n--){
        int a,b,c,d,e;
        cin >> a >> b >> c >> d >> e;
        cake[0] += a;
        cake[1] += b;
        cake[2] += c;
        cake[3] += d;
        cake[4] += e;
    }
    cake[3] += cake[4]/2;
    cake[4] %= 2;
    cake[2] += cake[3]/2;
    cake[3] %= 2;
    cake[0] += cake[2]/2;
    cake[2] %= 2;
    if (cake[3] > cake[1]){
        cake[0]+=cake[1];
        cake[3]-=cake[1];
        cake[1] = 0;
    } else {
        cake[0]+=cake[3];
        cake[1]-=cake[3];
        cake[3] = 0;
    }
    double poundCount = 0.0;
    poundCount += (cake[1]*0.75);
    poundCount += (cake[2]*0.5);
    poundCount += (cake[3]*0.25);
    poundCount += (cake[4]*0.125);
    cake[0] += ceil(poundCount);
    cout << cake[0];
    return 0;
}

/* SIMPLIFY APPROACH DOWN HERE */

void optimizedSolution(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    double cake;
    while (n--){
        int a,b,c,d,e;
        cin >> a >> b >> c >> d >> e;
        cake += a;
        cake += b*0.75;
        cake += c*0.5;
        cake += d*0.25;
        cake += e*0.125;
    }
    cout << ceil(cake);
    return;
}
