/*
CONTEST: 6th Thailand Olympiad in Informatics, 2010
HOST: Chaing Mai University, Chaing Mai
TASK: Dominoes
SOURCE:
    https://beta.programming.in.th/tasks/toi6_domino
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 18/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int n;
void dominoGeneration(int layer,vector<string> domino){
    if (layer==n){
        for (auto it : domino)
            cout << it << "\n";
        cout << "E\n";
    }
    if (layer>=n)
        return;
    domino.push_back("--");
    dominoGeneration(layer+1,domino);
    domino.pop_back();
    domino.push_back("||");
    dominoGeneration(layer+2,domino);
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string expression;
    cin >> n;
    vector<string> domino;
    dominoGeneration(0,domino);
    return 0;
}