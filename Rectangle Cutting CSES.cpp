//Rectangle Cutting
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
    int a,b;    cin >> a>>b;
    vector<vector<int>> dp(510, vector<int>(510, INT_MAX));
    for(int i = 1; i <= max(a,b); ++i) {
        dp[i][i] = 0;
    }
    f(i,1,a + 1) {
        f(j,1,b + 1) {
            f(k,1,i) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }
            f(m,1,j) {
                dp[i][j] = min(dp[i][j], dp[i][m] + dp[i][j - m] + 1);
            }
        }
    }
    cout << dp[a][b];
}