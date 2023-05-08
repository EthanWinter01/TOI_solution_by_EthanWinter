/*
CONTEST: 13th Thailand Olympiad in Informatics, 2017
HOST: Mahidol Wittayanusorn & Mahidol University, Nakhon Pathom
TASK: Cats (toi13_cats)
SOURCE:
    https://beta.programming.in.th/tasks/toi13_cats
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 04/05/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> cats(N);
    for (int i=0; i<N; ++i)
        cin >> cats[i];
    int left = 0;
    int right = INT_MAX;
    while (left < right){
        int mid = left+(right-left)/2;
        bool allpair = true;
        int p = -1;
        for (int i=0; i<N; ++i){
            if (cats[i]<=mid)
                continue;
            if (p == -1){
                p = cats[i];
            } else {
                if (cats[i]==p)
                    p = -1;
                else {
                    allpair = false;
                    break;
                }
            }
        }
        if (allpair)
            right = mid;
        else
            left = mid+1;
    }
    cout << left;
    return 0;
}
