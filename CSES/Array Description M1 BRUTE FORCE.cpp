#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e8;
const ll MOD = 1e9 + 7;

void solve() {
    
    int n, m; cin >> n >> m;
    vector<ll> a(n);

    for(auto& x : a) cin >> x;
    
    vector<vector<ll>> dp(n , vector<ll> (m + 1, 0));
    
    if(a[n - 1] == 0) {
        for(ll i = 1; i <= m; i++) dp[n - 1][i] = 1;
    }else dp[n - 1][a[n - 1]] = 1;
    

    for(ll i = n - 2; i >= 0; i--) {
        if(a[i] != 0) {
            for(ll k = 1; k <= m; k++) {
                if(abs(a[i] - k) <= 1) dp[i][a[i]] = (dp[i][a[i]] + dp[i + 1][k]) % MOD;
            }
        }else {
            for(ll j = 1; j <= m; j++) {
                for(ll k = 1; k <= m; k++) {
                    if(abs(j - k) <= 1) dp[i][j] = (dp[i][j] + dp[i + 1][k]) % MOD;
                }
            }
        }
    }

    ll sum = 0;

    for(ll i = 1; i <= m; i++) sum = (sum + dp[0][i]) % MOD;

    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}

/*
1) State:
   dp[i][j] = number of valid arrays for the suffix [i..n-1] if we set a[i] = j (1 ≤ j ≤ m).

2) Transition:
   If a[i] == 0:
       dp[i][j] = sum over k in [1..m] with |j - k| ≤ 1 of dp[i+1][k], for all j in [1..m].
   Else (a[i] is fixed):
       dp[i][a[i]] = sum over k in [1..m] with |a[i] - k| ≤ 1 of dp[i+1][k].

3) Base:
   At i = n-1:
       If a[n-1] == 0: dp[n-1][j] = 1 for all j in [1..m];
       else: dp[n-1][a[n-1]] = 1.

4) Answer:
   sum_{j=1..m} dp[0][j] (mod MOD).
*/
