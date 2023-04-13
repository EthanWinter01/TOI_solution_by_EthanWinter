/*
TASK: Treasure (toi3_treasure & 1016)
SOURCE:
    https://beta.programming.in.th/tasks/toi3_treasure
    https://beta.programming.in.th/tasks/1016
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus (PTN)
WRITTEN ON: 13/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double x = 0.0, y = 0.0;
    while (true){
        string T;
        cin >> T;
        if (T == "*")
            break;
        double dist = 0.0;
        string temp = "";
        for (int i=0; i<T.length(); i++){
            if (T[i]>='0' && T[i]<='9') {
                temp += T[i];
            } else {
                dist = stod(temp);
                if (T[i] == 'N' && i==T.length()-1){
                    y += dist;
                    break;
                } else if (T[i] == 'S' && i==T.length()-1){
                    y -= dist;
                    break;
                } else if (T[i] == 'E' && i==T.length()-1){
                    x += dist;
                    break;
                } else if (T[i] == 'W' && i==T.length()-1){
                    x -= dist;
                    break;
                } else if (T[i] == 'N' && T[i+1]=='E'){
                    dist = dist*(sqrt(2)/2);
                    x += dist;
                    y += dist;
                    break;
                } else if (T[i] == 'N' && T[i+1]=='W'){
                    dist = dist*(sqrt(2)/2);
                    x -= dist;
                    y += dist;
                    break;
                } else if (T[i] == 'S' && T[i+1]=='E'){
                    dist = dist*(sqrt(2)/2);
                    x += dist;
                    y -= dist;
                    break;
                } else if (T[i] == 'S' && T[i+1]=='W'){
                    dist = dist*(sqrt(2)/2);
                    x -= dist;
                    y -= dist;
                    break;
                }
            }
        }
    }
    double d = sqrt((x*x)+(y*y));
    printf("%.3f %.3f\n%.3f",x,y,d);
    return 0;
}
