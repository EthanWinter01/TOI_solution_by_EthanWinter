/*
CONTEST: 8th Thailand Olympiad in Informatics, 2012
HOST: Silapakorn University, Bangkok
TASK: Sport (toi8_sport & 1156)
SOURCE:
    https://beta.programming.in.th/tasks/toi8_sport
    https://beta.programming.in.th/tasks/1156
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 16/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int k,a,b;
void resultGenerator(int win,int lost, vector<char> result){
    if (win==k || lost==k){
        for (auto r : result)
            cout << r << " ";
        cout << "\n";
    } else {
        result.push_back('W');
        resultGenerator(win+1,lost,result);
        result.pop_back();
        result.push_back('L');
        resultGenerator(win,lost+1,result);
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> a >> b;
    vector<char> result;
    resultGenerator(a,b,result);
    return 0;
}
