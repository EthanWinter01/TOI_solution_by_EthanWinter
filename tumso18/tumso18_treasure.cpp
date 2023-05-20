/*
CONTEST: Triam Udom, Mathematics and Science Olympiad, 2021
HOST: Triam Udom Suksa School
TASK: สมบัติล้ำค่า (tumso18_treasure)
SOURCE:
    https://beta.programming.in.th/tasks/tumso18_treasure
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
WRITTEN ON: 13/05/2023
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 98765431;
map<ll,ll> memo;
ll solve(ll n){
    if (memo.find(n)!=memo.end())
        return memo[n];
    ll half1 = n/2;
    ll half2 = n-half1+1;
    memo[n] = (solve(half1)*solve(half2)+solve(half1-1)*solve(half2-1))%mod;
    return memo[n];
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memo.insert({1,1});
    memo.insert({2,2});
    memo.insert({3,5});
    int t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        cout << (solve(n)+solve(n+1))%mod << "\n";
    }
    return 0;
}