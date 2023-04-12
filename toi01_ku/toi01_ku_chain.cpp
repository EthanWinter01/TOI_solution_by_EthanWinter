/*
CONTEST: 1st POSN - Olympiad in Informatics, 2005
HOST: Kasetsart University, Bangkok
TASK: Word Chain (toi1_chain & 1000)
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 11/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int L,N;
    cin >> L >> N;
    vector<string> word(N);
    for (int i=0; i<N; i++)
        cin >> word[i];
    for (int i=0; i<N-1; i++){
        int counter = 0;
        for (int j=0; j<L; j++){
            if (word[i][j]!=word[i+1][j])
                counter++;
        }
        if (counter>=3){
            cout << word[i];
            return 0;
        }
    }
    cout << word[N-1];
    return 0;
}