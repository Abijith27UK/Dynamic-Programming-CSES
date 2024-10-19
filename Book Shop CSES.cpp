//Book Shop
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
    vector<int> price(n),pages(n);
    f(i,0,n){
        cin>>price[i];
    }
    f(i,0,n){
        cin>>pages[i];
    }
    int dp[n + 1][x + 1];
    memset(dp,0,sizeof(dp));
    f(i,0,n){
        f(j,1,x + 1){
            if(j - price[i] >= 0){
                dp[i + 1][j] = max( dp[i][j] , (dp[i][j - price[i]] + pages[i]) );
            }else{
                dp[i + 1][j] = dp[i][j];
            }
        }
    }
    cout<<dp[n][x];
}
