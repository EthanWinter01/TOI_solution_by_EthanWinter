/*
CONTEST: 4th POSN - Olympiad in Informatics, 2008
HOST: Suranaree University of Technology, Nakhonratchasrima
TASK: Logistics (toi4_logistics & 1063)
SOURCE:
    https://beta.programming.in.th/tasks/toi4_logistics
    https://beta.programming.in.th/tasks/1063
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
CENTER: Prince Songkla University, Pattani Campus
SCHOOL: Phimanpittayasan School, Satun
WRITTEN ON: 19/04/2023
*/

#include <bits/stdc++.h>
using namespace std;
struct ANSWER {
    char start,dest;
    double val;
};
double finalDist = 0;
vector<vector<int>> adj(28);
vector<vector<vector<double>>> cost(28,vector<vector<double>>(28));
vector<bool> visited(28,false);
vector<ANSWER> answer;
int getIndex(char c){
    if (c == 'X')
        return 0;
    if (c == 'Y')
        return 27;
    return c-'a'+1;
}
char getChar(int i){
    if (i == 0)
        return 'X';
    if (i == 27)
        return 'Y';
    return (char)(i+'a'-1);
}
double getMedian(int a, int b){
    sort(cost[a][b].begin(), cost[a][b].end());
    int sz = cost[a][b].size();
    if (sz%2 == 1)
        return cost[a][b][sz/2];
    else 
        return (cost[a][b][sz/2]+cost[a][b][sz/2-1])/2;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        char a,b;
        double dist;
        cin >> a >> b >> dist;
        int indexA = getIndex(a);
        int indexB = getIndex(b);
        adj[indexA].push_back(indexB);
        adj[indexB].push_back(indexA);
        cost[indexA][indexB].push_back(dist);
        cost[indexB][indexA].push_back(dist);
    }
    queue<int> Q;
    Q.push(0);
    visited[0] = true;
    while (!Q.empty()){
        int curr = Q.front();
        Q.pop();
        for (auto nextNode : adj[curr]){
            if (visited[nextNode])
                continue;
            Q.push(nextNode);
            visited[nextNode] = true;
            double dist = getMedian(curr,nextNode);
            finalDist += dist;
            answer.push_back({getChar(curr),getChar(nextNode),dist});
        }
    }
    if (visited[27]){
        for (auto ans : answer)
            printf("%c %c %.1f\n",ans.start,ans.dest,ans.val);
        printf("%.1f",finalDist);
    } else {
        printf("broken");
    }
    return 0;
}
