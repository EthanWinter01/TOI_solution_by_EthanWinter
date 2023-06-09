/*
CONTEST: 2nd POSN - Olympiad in Informatics, 2006
HOST: Burapha University, Chonburi
TASK: Max Sequence (toi2_maxseq & 1005)
SOURCE:
    https://beta.programming.in.th/tasks/toi2_maxseq
    https://beta.programming.in.th/tasks/1005
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus (PTN)
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 16/04/2023
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
