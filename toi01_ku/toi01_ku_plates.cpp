/*
TASK: Plates (toi1_plate & 1004)
TASK_SOURCE: 
    https://beta.programming.in.th/tasks/toi1_plate
    https://beta.programming.in.th/tasks/1004
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
    int Nc,Ns,c,s;
    cin >> Nc >> Ns;
    map<int,int> student;
    queue<int> classLine;
    vector<queue<int>> activeLine(Nc+1);
    for (int i=0; i<Ns; i++){
        cin >> c >> s;
        student.insert({s,c});
    }
    char T;
    while (true){
        cin >> T;
        if (T == 'X')
            break;
        if (T == 'E'){
            int x;
            cin >> x;
            if (activeLine[student[x]].empty())
                classLine.push(student[x]);
            activeLine[student[x]].push(x);
        }
        if (T == 'D'){
            cout << activeLine[classLine.front()].front() << "\n";
            activeLine[classLine.front()].pop();
            if (activeLine[classLine.front()].empty())
                classLine.pop();
        }
    }
    cout << "0";
    return 0;
}
