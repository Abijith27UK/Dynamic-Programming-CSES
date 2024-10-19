//Grid Paths
//CSES DP
//Code by Abijith U K
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i,a,b) for ( ll i = a ; i < b ; i++ )
#define all(n) n.begin() , n.end()
#define vi  vector<ll>;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    ll N;   cin>>N;
    ll dp[N][N];
    char c[N][N];
    string val;
    f(i,0,N){
        cin>>val;
        f(j,0,N){
            c[j][i] = val[j];
            dp[j][i] = 0;
        }
    }
    dp[0][0] = 1;
    f(j,0,N) {
	    f(i,0,N) {
	        if (c[j][i] == '*'){
    		    dp[j][i] = 0;
    		}else{
        		if (j > 0){
        		    dp[j][i] += dp[j - 1][i];
        		    dp[j][i] %= MOD;
        		} 
        		if (i > 0){
        		    dp[j][i] += dp[j][i - 1];
        		    dp[j][i] %= MOD;
        		}
    		}
    	}
    }
    cout<<dp[N - 1][N - 1];
}