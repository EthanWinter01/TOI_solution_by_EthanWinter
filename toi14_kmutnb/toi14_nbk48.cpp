/*
CONTEST: 14th Thailand Olympiad in Informatics, 2018
HOST: King Mongkut's University of Technology, North Bangkok, Bangkok
TASK: NBK48 (toi14_nbk48) 
SOURCE: 
    https://beta.programming.in.th/tasks/toi14_nbk48
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 20/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,Q;
    cin >> N >> Q;
    vector<long long> doc(N+1,0);
    for (int i=1; i<=N; i++){
        cin >> doc[i];
        doc[i]+=doc[i-1];
    }
    for (int i=N-1; i>0; i--)
        doc[i] = min(doc[i],doc[i+1]);
    while (Q--){
        long long cash;
        cin >> cash;
        cout << upper_bound(doc.begin(),doc.end(),cash)-doc.begin()-1<< "\n";
    }
    return 0;
}
