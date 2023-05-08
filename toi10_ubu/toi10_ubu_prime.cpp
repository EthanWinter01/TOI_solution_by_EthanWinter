#include <bits/stdc++.h>
#define MAX 10000001
using namespace std;
vector<bool> isNotPrime(MAX,false); // true mean it is prime
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,index=0,answer=0;
    cin >> n;
    for (int i=2; i<MAX&&index<n; i++){
        if (isNotPrime[i]){
            continue;
        } else {
            answer = i;
            index++;
            for (int j=i; j<MAX; j+=i)
                isNotPrime[j] = true;
        }
    }
    cout << answer;
    return 0;
}