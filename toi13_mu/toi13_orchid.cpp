/*
CONTEST: 13th Thailand Olympiad in Informatics, 2017
HOST: Mahidol Wittayanusorn & Mahidol University, Nakhon Pathom
TASK: Orchid (toi13_orchid)
SOURCE:
    https://beta.programming.in.th/tasks/toi13_orchid
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 03/05/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,input;
    cin >> N;
    vector<int> answer;
    int left = 0;
    int right = N;
    for (int i=0; i<N; i++){
        cin >> input;
        int upper = upper_bound(answer.begin(),answer.end(),input)-answer.begin();
        if (answer.size() == upper || answer.back()<=input){
            answer.push_back(input);
        } else if (answer[0] > input){
            answer[0] = input;
        } else if (answer[upper] > input){
            answer[upper] = input;
        }
    }
    cout << N-answer.size();
    return 0;
}
