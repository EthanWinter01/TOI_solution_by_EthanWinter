/*
CONTEST: 11th Thailand Olympiad in Informatics, 2015
HOST: Prince Songkla University, Pattani Campus, Trang
TASK: Observatory (toi11_observatory)
TASK_SOURCE:
    https://beta.programming.in.th/tasks/toi11_observatory
LANG: C++
AUTHOR: Mr.Thanpisit Naowapradit
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 11/05/2023
*/

#include <bits/stdc++.h>
#define MAX 2002
using namespace std;
int M,N,K;
vector<vector<int>> grid(MAX,vector<int>(MAX,0));
vector<vector<int>> qsTriL(MAX,vector<int>(MAX,0));
vector<vector<int>> qsTriR(MAX,vector<int>(MAX,0));
vector<vector<int>> qsSqrL(MAX,vector<int>(MAX,0));
vector<vector<int>> qsSqrR(MAX,vector<int>(MAX,0));
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N >> K;
    for (int i=1; i<=M; ++i){
        for (int j=1; j<=N; ++j){
            cin >> grid[i][j];
            qsSqrR[i][j] = grid[i][j]+qsSqrR[i-1][j]+qsSqrR[i][j-1]-qsSqrR[i-1][j-1];
            qsTriR[i][j] = qsTriR[i-1][j-1]+qsSqrR[i][j]-qsSqrR[i-1][j];
        }
    }
    for (int i=1; i<=M; ++i){
        for (int j=N; j>=1; --j){
            qsSqrL[i][j] = grid[i][j]+qsSqrL[i-1][j]+qsSqrL[i][j+1]-qsSqrL[i-1][j+1];
            qsTriL[i][j] = qsTriL[i-1][j+1]+qsSqrL[i][j]-qsSqrL[i-1][j];
        }
    }
    int answer = INT_MIN;
    for (int i=1; i<=M; ++i){
        for (int j=1; j<=N; ++j){
            int left,right;
            left = right = INT_MIN;
            if (i-K>=0 && j-K>=0)
                right = qsTriR[i][j]-qsTriR[i-K][j-K]-qsSqrR[i][j-K]+qsSqrR[i-K][j-K];
            if (i-K>=0 && j+K<=N+1)
                left = qsTriL[i][j]-qsTriL[i-K][j+K]-qsSqrL[i][j+K]+qsSqrL[i-K][j+K];
            answer = max({answer,left,right});
        }
    }
    cout << answer;
    return 0;
}
