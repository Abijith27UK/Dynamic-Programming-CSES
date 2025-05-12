//Longest Common Subsequence
//CSES DP
//Code by Abijith U K
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define db long double
#define str string
 
using mpi = map<int,int>;
using mpl = map<ll,ll>;
using mpd = map<db,db>;
 
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
 
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<str>;
using vd = vector<db>;
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
 
#define f(i,a,b) for ( int i = a ; i < b ; i++ )
#define rf(i,a,b) for (ll i = b ; i > a; --i)
#define all(n) n.begin() , n.end()
#define r_all(n) n.rbegin() , n.rend()
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;
#define unique_sort(vec) sort(vec.begin(), vec.end()); vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
#define FILL(vec, value) fill(vec.begin(), vec.end(), value)
#define IOTA(vec, start) iota(all(vec), start)
#define endl "\n"
#define INF 1e18
const int MOD = 1e9 + 7;
 
ll pow(ll a , ll b){
    ll res = 1;
    while(b>0){
        if(b%2==1) res*=a;
        a *= a; b /= 2;
    }
    return res;
}
 
ll powerWithModulo(ll base, ll exponent, int mod) {
    ll result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}
 
void solve(){
    int n,m; cin>>n>>m;
    vi a(n) , b(m);
    f(i,0,n) cin>>a[i];
    f(i,0,m) cin>>b[i];
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    f(i,0,n){
        f(j,0,m){
            if(a[i]==b[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            }else{
                dp[i+1][j+1] = max(dp[i][j+1] , dp[i+1][j]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    int i = n, j = m;
    vi lcs;
    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            lcs.push_back(a[i-1]);
            i--; j--;
        }else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        }else{
            j--;
        }
    }
    reverse(all(lcs));
    for(auto it : lcs) cout<<it<<" ";
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    ll t=1 ; //cin>>t;
    while(t--){
	    solve();
    }
}