/*
CONTEST: 5th POSN - Olympiad in Informatics, 2008
HOST: Walailuk University, Nakhon Sri Thammarat
TASK: Love Key Decoder (toi5_lkd)
SOURCE:
    https://beta.programming.in.th/tasks/toi5_lld
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 20/05/2023
*/

#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
using namespace std;
vector<vector<pii>> adj(5,vector<pii>(12));
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,node=1;
    cin >> n;
    adj[1][0] = {1,0};
    adj[2][1] = {4,1};
    adj[3][0] = {2,1};
    adj[4][1] = {3,0};
    adj[1][11] = {2,1};
    adj[2][10] = {3,0};
    adj[3][11] = {1,0};
    adj[4][10] = {4,1};
    while (n--){
        string str,bits;
        int sum = 0;
        cin >> str;
        if (str.size() != 16)
            break;
        for (int i=0; i<16; i+=2){
            bits.push_back(adj[node][(str[i]-'0')*10 + str[i+1]-'0'].s + '0');
            node = adj[node][(str[i]-'0')*10 + str[i+1]-'0'].f;
        }
        for (int i=0; i<8; ++i)
            sum += pow(2,7-i)*(bits[i]-'0');
        cout << char(sum);
    }
    return 0;
}
