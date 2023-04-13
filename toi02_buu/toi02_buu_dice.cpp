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
    int N;
    cin >> N;
    while (N--){
        string R;
        cin >> R;
        int top=1,front=2,left=3,right=4,back=5,bottom=6;
        for (int i=0; i<R.length(); i++){
            if (R[i] == 'F'){
                swap(top,front);
                swap(back,bottom);
                swap(top,bottom);
            } else if (R[i] == 'B'){
                swap(top,back);
                swap(front,bottom);
                swap(bottom,top);
            } else if (R[i] == 'L'){
                swap(top,left);
                swap(top,right);
                swap(right,bottom);
            } else if (R[i] == 'R'){
                swap(top,right);
                swap(top,left);
                swap(left,bottom);
            } else if (R[i] == 'C'){
                swap(back,right);
                swap(back,left);
                swap(front,left);
            } else if (R[i] == 'D'){
                swap(back,left);
                swap(back,right);
                swap(front,right);
            }
        }
        cout << front << " ";
    }
    return 0;
}
