/*
TASK: Roman (toi1_roman & 1002)
TASK_SOURCE: https://beta.programming.in.th/tasks/toi1_roman
             https://beta.programming.in.th/tasks/1002
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
WRITTEN ON: 11/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> roman(5,0);
    for (int i=1; i<=n; i++){
        int num = i;
        while (num > 0){
            if (num>=100){
                num -= 100;
                roman[4]++;
            } else if (num >= 90){
                num -= 90;
                roman[4]++;
                roman[2]++;
            } else if (num >= 50){
                num -= 50;
                roman[3]++;
            } else if (num >= 40){
                num -= 40;
                roman[3]++;
                roman[2]++;
            } else if (num >= 10){
                num -= 10;
                roman[2]++;
            } else if (num >= 9){
                num -= 9;
                roman[2]++;
                roman[0]++;
            } else if (num >= 5){
                num -= 5;
                roman[1]++;
            } else if (num >= 4){
                num -= 4;
                roman[1]++;
                roman[0]++;
            } else if (num >= 1){
                num -= 1;
                roman[0]++;
            }
        }
    }
    for (auto i : roman)
        cout << i << " ";
    return 0;
}
