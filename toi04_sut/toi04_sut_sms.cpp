/*
CONTEST: 4th POSN - Olympiad in Informatics, 2008
HOST: Suranaree University of Technology, Nakhonratchasrima
TASK: SMS Thumb (toi4_sms & 1059)
SOURCE:
    https://beta.programming.in.th/tasks/toi4_sms
    https://beta.programming.in.th/tasks/1059
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 15/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
string sms = "";
vector<vector<int>> numpad = {{1,2,3},{4,5,6},{7,8,9}};
vector<string> text = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
void textConvertor(int n, int m){
    if (n==7 || n==9){
        (m%4==0)?m=3:m=m%4-1;
        sms+=text[n][m];
    } else {
        (m%3==0)?m=2:m=m%3-1;
        sms+=text[n][m];
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,S,M,r,c;
    cin >> N >> S >> M;
    (S%3 == 0)? c=2: c=S%3-1;
    r = ceil(S/3.0)-1;
    if (S!=1)
        textConvertor(numpad[r][c],M);
    while (--N){
        int H,V;
        cin >> H >> V >> M;
        r += V;
        c += H;
        if (numpad[r][c]==1){
            while (M-- && sms.length()>0)
                sms.erase(sms.end()-1);
        } else {
            textConvertor(numpad[r][c],M);
        }
    }
    if (sms.length()==0)
        cout << "null";
    else
        cout << sms;
    return 0;
}