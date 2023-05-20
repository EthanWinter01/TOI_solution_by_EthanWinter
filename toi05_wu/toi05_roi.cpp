/*
CONTEST: 5th POSN - Olympiad in Informatics, 2008
HOST: Walailuk University, Nakhon Sri Thammarat
TASK: Return On Investment (toi5_roi)
SOURCE:
    https://beta.programming.in.th/tasks/toi5_roi
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 19/05/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int C;
    cin >> C;
    double minProfit = 1e9;
    int bookPrint, bookPrice;
    for (int i=1000; i<=15000; i+=500){
        for (int j=74; j<=144; ++j){
            double bookCount = 100-(i-1000)/500;
            double bookSold = (100-(0.8569*exp(0.09*(j-100))))*i/100;
            double income = bookSold*j;
            double cost = C+(i*bookCount);
            double profit = income-cost;
            if (profit > 0 && profit < minProfit){
                minProfit = profit;
                bookPrint = i;
                bookPrice = j;
            }
        }
    }
    printf("%d\n%d\n%.2lf", bookPrint, bookPrice, minProfit);
    return 0;
}
