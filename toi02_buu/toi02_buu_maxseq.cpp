/*
TASK: Dice (toi2_dice & 1006)
SOURCE:
    https://beta.programming.in.th/tasks/toi2_dice
    https://beta.programming.in.th/tasks/1006
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus (PTN)
WRITTEN ON: 12/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,sum=0,maxSoFar=INT_MIN,sintemp,sindex,eindex;
    cin >> n;
    vector<int> arr(n+1,0);
    for (int i=1; i<=n; i++){
        cin >> arr[i];
        if (arr[i]>arr[i]+sum){
            sum = arr[i];
            sintemp = i;
        } else {
            sum += arr[i];
        }
        if (sum>maxSoFar){
            maxSoFar = sum;
            sindex = sintemp;
            eindex = i;
        }
    }
    if (maxSoFar > 0){
        for (int i=sindex; i <= eindex; i++)
            cout << arr[i] << " ";
        cout << "\n";
        cout << maxSoFar;
    } else {
        cout << "Empty sequence";
    }
    return 0;
}
