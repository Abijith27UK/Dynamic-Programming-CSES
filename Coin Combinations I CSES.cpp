//Coin Combinations I
//CSES DP
//Code by Abijith U K 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i,a,b) for ( ll i = a ; i < b ; i++ )
#define all(n) n.begin() , n.end()
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    ll n, x;    cin >> n >> x;
    vector<ll> c(n);
    f(i,0,n){
        cin>>c[i];
    }
    vector<ll> dp(x + 1 , 0);
    dp[0]=1;
    f(a,1,(x + 1)){
        f(i,0,n){
            if((a - c[i]) >= 0){
	            dp[a] += dp[a - c[i]];
	            dp[a] %= MOD;
            }
        }
    
    }
    cout << dp[x] ;
}