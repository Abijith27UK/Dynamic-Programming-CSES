//Money Sums
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
    int n;    cin >> n;
    vi coins(n);
    f(i,0,n){
        cin >> coins[i];
    }
    vector<bool> dp(100001, false);
    dp[0] = true;
    f(i,0,n) {
        for(int j = 100000; j >= coins[i]; j--) {
            if(dp[j - coins[i]])
                dp[j] = true;
        }
    }
    int distinct_sums = 0;
    for(bool can_obtain : dp) {
        if(can_obtain)
            distinct_sums++;
    }
    cout << distinct_sums - 1 << '\n';
    f(i,1,100001) {
        if(dp[i])
            cout << i << " ";
    }
}
