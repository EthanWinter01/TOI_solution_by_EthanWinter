#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 1e9+7;
ll bitPower(ll x, ll n){
    x %= mod;
    ll result = 1;
    while (n){
        if (n%2)
            result = (result*x)%mod;
        x = (x*x)%mod;
        n /= 2;
    }
    return result;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        ll n,a;
        cin >> n >> a;
        ll fm = bitPower(a*2-1,mod-2);
        ll answer = (bitPower(a*2,n)-1)*bitPower(a*2,n-1)%mod;
        answer = (answer*fm)%mod;
        cout << answer << "\n";
    }
    return 0;
}
