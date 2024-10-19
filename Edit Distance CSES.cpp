#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    ll a , b;   cin>>a>>b; //a power b
    ll ans = 1;
    while (b > 0) {
        if (b & 1){
            ans *= a;
        }
        a = a * a;
        b >>= 1;
    }
    cout<<ans;
}


