/*
CONTEST: 4th POSN - Olympiad in Informatics, 2008
HOST: Suranaree University of Technology, Nakhonratchasrima
TASK: Chromatie Key (toi4_key & 1062)
SOURCE:
    https://beta.programming.in.th/tasks/toi4_key
    https://beta.programming.in.th/tasks/1062
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 19/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int L,K;
    cin >> L >> K;
    string upperlock,lowerlock,key;
    cin >> upperlock >> lowerlock >> key;
    for (int i=0; i<L; i++)
        if (upperlock[i]<lowerlock[i])
            swap(upperlock[i],lowerlock[i]);
    for (int i=0; i<L; i++){
        for (int j=0; j<K; j++){
            if (key[j]>=lowerlock[i]&&key[j]<=upperlock[i])
                continue;
            else if (key[j]>upperlock[i])
                key[j] = upperlock[i];
            else if (key[j]<lowerlock[i])
                key[j] = lowerlock[i];            
        }
    }
    cout << key;
    return 0;
}
