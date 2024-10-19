#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i,a,b) for ( ll i = a ; i < b ; i++ )
#define all(n) n.begin() , n.end()
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n;   cin>>n;
    vector<ll> dp(n + 1);
    dp[0] = 1 ;
    f(i,1,n + 1){
        f(j,1,7){
            if(i - j >= 0){
                dp[i] = ( dp [i - j] + dp[i] ) % MOD;
            }
        }
    }
    cout<<dp[n] ;
}