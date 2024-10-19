//Counting Towers
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
    int t;  cin>>t;
    vector<vector<ll>> dp(1000010,vector<ll>(8 , 0));
        f(i,0,8){
            dp[2][i] = 1;
        }
        f(i,3,1000005) {
            dp[i][1] = ( dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][7] )%MOD;
            dp[i][2] = ( dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][7] )%MOD;
            dp[i][3] = ( dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][7] )%MOD;
            dp[i][4] = ( dp[i - 1][5] + dp[i - 1][6] + dp[i - 1][0] )%MOD;
            dp[i][5] = ( dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][7] )%MOD;
            dp[i][6] = ( dp[i - 1][5] + dp[i - 1][6] + dp[i - 1][0] )%MOD;
            dp[i][7] = ( dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][7] )%MOD;
            dp[i][0] = ( dp[i - 1][5] + dp[i - 1][6] + dp[i - 1][0] )%MOD;
        }
    while(t--){
        ll n;   cin>>n;
        if(n == 1){
            cout<<2<<'\n';
        }else if(n == 2){
            cout<<8<<'\n';
        }else{
            cout << (dp[n + 1][5] + dp[n + 1][6])%MOD << '\n';
        }
    }
}
