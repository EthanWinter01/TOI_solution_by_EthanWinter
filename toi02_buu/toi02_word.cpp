/*
CONTEST: 2nd POSN - Olympiad in Informatics, 2006
HOST: Burapha University, Chonburi
TASK: Word (toi2_word & 1010)
SOURCE:
    https://beta.programming.in.th/tasks/toi2_word
    https://beta.programming.in.th/tasks/1010
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus (PTN)
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 17/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int m,n,k;
void wordChecker(string&word,vector<vector<char>>&grid){
    int len = word.length();
    bool isWord = false;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (grid[i][j]==word[0]){
                bool N=true,NE=true,NW=true,W=true,E=true,SE=true,S=true,SW=true;
                for (int temp=1; temp<len; temp++){
                    if (i-temp<0 || grid[i-temp][j]!=word[temp]) N = false;
                    if (i+temp>=m || grid[i+temp][j]!=word[temp]) S = false;
                    if (j-temp<0 || grid[i][j-temp]!=word[temp]) W = false;
                    if (j+temp>=n || grid[i][j+temp]!=word[temp]) E = false;
                    if ((i-temp<0||j-temp<0) || grid[i-temp][j-temp]!=word[temp]) NW = false;
                    if ((i-temp<0||j+temp>=n) || grid[i-temp][j+temp]!=word[temp]) NE = false;
                    if ((i+temp>=m||j-temp<0) || grid[i+temp][j-temp]!=word[temp]) SW = false;
                    if ((i+temp>=m||j+temp>=n) || grid[i+temp][j+temp]!=word[temp]) SE = false;
                }
                if (N || NE || NW || E || W || S || SE || SW){
                    cout<<i<<" "<<j<<"\n";
                    return;
                }
            }
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    vector<vector<char>> grid(m,vector<char>(n));
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++){
            cin >> grid[i][j];
            if (grid[i][j]>='A'&&grid[i][j]<='Z')
                grid[i][j] = tolower(grid[i][j]);
        }
    cin >> k;
    string word;
    while (k--){
        cin >> word;
        int len = word.length();
        bool foundWord = false;
        for (int i=0; i<len; i++)
            word[i] = tolower(word[i]);
        wordChecker(word,grid);
    }
    return 0;
}
