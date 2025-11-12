#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e8;
const ll MOD = 1e9 + 7;

void solve() {
    
    ll n, k; cin >> n >> k;
    vector<ll> h(n);

    for(auto& x : h) cin >> x;

    vector<ll> dp(n , LLONG_MAX);

    dp[n - 1] = 0;

    for(ll i = n - 1; i >= 0; i--) {
        for(ll j = 1; j <= k; j++) {
            if(i + j >= n) break;
            dp[i] = min(dp[i] , abs(h[i + j] - h[i]) + dp[i + j]);
        }
    }

    cout << dp[0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}

/*
State:

Transition:
Base:

Answer:

Time:
*/
