/*
CONTEST: 7th Thailand Olympiad in Informatics, 2011
HOST: Naresuan University, Phitsanulok
TASK: Space (toi7_space & 1163)
SOURCE:
    https://beta.programming.in.th/tasks/toi7_space
    https://beta.programming.in.th/tasks/1163
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus (PTN)
SCHOOL: Phimanpittayasan School, Satun
WRITTEN: 13/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int d;
vector<string> answer;
void generateSpace(string str1, string str2, int index, int z1, int z2){
    if (index == d){
        if (abs(z1-z2)==1){
            str1+=" "+str2;
            answer.push_back(str1);
        }
    } else {
        str1[index] = '0';
        str2[index] = '0';
        generateSpace(str1,str2,index+1,z1+1,z2+1);
        str2[index] = '1';
        generateSpace(str1,str2,index+1,z1+1,z2);
        str1[index] = '1';
        generateSpace(str1,str2,index+1,z1,z2);
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> d;
    string str1, str2;
    str1.resize(d);
    str2.resize(d);
    generateSpace(str1,str2,0,0,0);
    sort(answer.begin(), answer.end());
    for (auto s : answer)
        cout << s << "\n";
    return 0;
}
