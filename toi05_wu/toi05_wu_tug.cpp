/*
CONTEST: 5th POSN - Olympiad in Informatics, 2008
HOST: Walailuk University, Nakhon Sri Thammarat
TASK: Tug of War (toi5_tug)
SOURCE:
    https://beta.programming.in.th/tasks/toi5_tug
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 25/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<long> team1(N),team2(N);
    for (auto &t1 : team1)
        cin >> t1;
    for (auto &t2 : team2)
        cin >> t2;
    sort(team1.begin(),team1.end());
    sort(team2.begin(),team2.end());
    long sum = 0;
    for (int i=0; i<N; i++){
        sum += abs(team1[i]-team2[i]);
    }
    cout << sum;
    return 0;
}
