//Removing Digits
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

#define f(i,a,b) for ( ll i = a ; i < b ; i++ )
#define all(n) n.begin() , n.end()
const int MOD = 1e9 + 7;
 
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    ll N;   cin>>N;
    vi dp(N + 1);
    dp[0] = 0;
    f(i,1,N + 1){
        ll maxDigit = 0;
        ll tempNumber = i;
        while (tempNumber > 0) {
            ll digit = tempNumber % 10;
            maxDigit = max(maxDigit, digit);
            tempNumber /= 10;
        }
        ll z = i - maxDigit ;
        dp[i] = dp[i - maxDigit] + 1;
    }
    cout<<dp[N];
}
