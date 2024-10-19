//Array Description
//CSES DP
//Code by Abijith U K
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db long double
#define str string

using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<ll>;
using vs = vector<str>;
#define pb push_back

#define f(i,a,b) for ( int i = a ; i < b ; i++ )
#define all(n) n.begin() , n.end()
const int MOD = 1e9 + 7;
 
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    int n,x;   cin>>n>>x;
    vector<int> a(n);
    f(i,0,n){
        cin>>a[i];
    }
    vector<vector<int>> dp(n,vector<int>(x + 1,0));
    if(a[0] != 0){
        dp[0][a[0]] = 1;
    }else{
        f(i,1,x + 1){
            dp[0][i] = 1;
        }
    }
    f(i,1,n) {
        if(a[i] == 0){
            f(j,1,x + 1){
                if ((j - 1) >= 1){
            	    dp[i][j] = ( dp[i][j] + dp[i - 1][j - 1] )%MOD;
            	}
                dp[i][j] = ( dp[i][j] + dp[i - 1][j] )%MOD;
            	if ((j + 1) <= x){
            	    dp[i][j] = ( dp[i][j] + dp[i - 1][j + 1] )%MOD ;
            	}
            }
        }else{
            if ((a[i] - 1) >= 1){
                dp[i][a[i]] = ( dp[i][a[i]] + dp[i - 1][a[i] - 1])%MOD;
            }
            dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i]])%MOD;
            if ((a[i] + 1) <= x){
            	 dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] + 1])%MOD ;
            }
        }
    }
    int ans = 0;
    f(j,0,x + 1) {
        ans += dp[n - 1][j];
        ans %= MOD;
    }
    cout << ans;
}
