/*
TASK: Segment (toi2_segment & 1009)
SOURCE:
    https://beta.programming.in.th/tasks/toi2_segment
    https://beta.programming.in.th/tasks/1009
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus (PTN)
WRITTEN ON: 17/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int A,B;
vector<string> grid(6);
int panelIntToInt(int r,int c){
    if (grid[r][c+1]==' ')
        return (grid[r+1][c]=='|')?4:1;
    if (grid[r+1][c+1]==' ')
        return (grid[r+1][c]=='|')?0:7;
    if (grid[r+1][c+2]=='|')
        if (grid[r+1][c]==' ')
            return (grid[r+2][c+2]=='|')?3:2;
        else
            return (grid[r+2][c]=='|')?8:9;
    return (grid[r+2][c]=='|')?6:5;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> A >> B;
    string buffer;
    getline(cin,buffer);
    for (int i=0; i<6; i++)
        getline(cin,grid[i]);
    long long a=0,b=0,digitA=pow(10,A-1), digitB=pow(10,B-1);
    for (int i=0; i<A*4; i+=4){
        a += panelIntToInt(0,i)*digitA;
        digitA /= 10;
    }
    for (int i=0; i<B*4; i+=4){
        b += panelIntToInt(3,i)*digitB;
        digitB /= 10;
    }
    cout << a+b;
    return 0;
}
