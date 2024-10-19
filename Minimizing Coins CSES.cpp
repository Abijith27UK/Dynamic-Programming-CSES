//Minimizing Coins
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
    sort(all(c));
    vector<ll> dp(x + 1,MOD);
    dp[0]=0;
    f(a,1,(x + 1)){
        f(i,0,n){
            if((a - c[i]) >= 0){
	            dp[a] = min( (dp[a - c[i]] + 1) , dp[a] );
            }
        }
    
    }
    if(dp[x] == MOD){
        cout<<-1;
    }else{
        cout << dp[x] ;
    }
}