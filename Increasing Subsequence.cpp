//Increasing Subsequence
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

class DSU {
public:
    vector<int> parent, size , rank;
    vector<long long> score, individual_score;
    vector<vector<int>> nodes;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n+1,0);
        size.resize(n + 1, 1);
        score.resize(n + 1, 0);
        individual_score.resize(n + 1, 0);
        nodes.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            nodes[i].push_back(i);
        }
    }
    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void UnionByRank(int u , int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_v == ulp_u) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void UnionBySize(int u, int v) {
        u = findUPar(u);
        v = findUPar(v);
        if (u == v) return;
        if (nodes[u].size() > nodes[v].size()) swap(u, v);
        for (int x : nodes[u]) {
            individual_score[x] += score[u] - score[v];
            nodes[v].push_back(x); // Merge smaller into larger
        }
        score[u] = 0;
        nodes[u].clear();
        parent[u] = v;
        size[v] += size[u];
    }
};

void solve(){
    int n; cin>>n;
    vector<int> a(n) , dp;
    // vector<int> inserted_at(n);
    f(i,0,n) cin>>a[i];
    f(i,0,n){
        if(dp.empty() || dp.back()<a[i]){
            dp.push_back(a[i]);
            // inserted_at[i] = dp.size();
        }else{
            auto it = lower_bound(dp.begin() , dp.end() , a[i]);
            *it = a[i];
            // inserted_at[i] = it - dp.begin() + 1;
        }
    }
    cout<<dp.size()<<endl;
    // int curr_len =  dp.size();
    // vector<int> LIS_seq;
    // for(int i = n-1 ; i>= 0 ; i--){
    //     if(inserted_at[i]==curr_len){
    //         LIS_seq.push_back(a[i]);
    //         curr_len--;
    //     }
    // }
    // reverse(LIS_seq.begin() , LIS_seq.end());
    // for(auto it : LIS_seq) cout<<it<<" ";
}

int32_t main() {
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    ll t=1 ; //cin>>t;
    while(t--){
	    solve();
    }
}
