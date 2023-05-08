/*
CONTEST: 3rd POSN - Olympiad in Informatics, 2007
HOST: Khon Khaen University, Khon Khaen
TASK: Filter (toi3_filter & 1014)
SOURCE:
    https://beta.programming.in.th/tasks/toi3_filter
    https://beta.programming.in.th/tasks/1014
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus (PTN)
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 13/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> filter(3004,0);
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int W,H,n;
    cin >> W >> H >> n;
    while (n--){
        int x,a;
        cin >> x >> a;
        for (int i=x; i<x+a&&i<3004; i++)
            filter[i]++;
    }
    int translucent = 0;
    int transparent = 0;
    for (int i=0; i<W; i++){
        if (filter[i]==1)
            translucent++;
        if (filter[i]==0)
            transparent++;
    }
    cout << transparent*H << " " << translucent*H;
    return 0;
}
