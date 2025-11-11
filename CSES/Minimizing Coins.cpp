#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

void solve() {
    ll n, x; cin >> n >> x;
    vector<ll> c(n);
    for(auto& i : c) cin >> i;
    
    const ll INF = (ll)4e18;
    vector<ll> dp(x + 1, INF);

    dp[0] = 0;

    for(ll i = 1; i <= x; i++) {
        for(ll j = 0; j < n; j++) {
            if(i - c[j] >= 0 && dp[i - c[j]] != INF) dp[i] = min(dp[i] , dp[i - c[j]] + 1);
        }
    }
 
    
    cout << (dp[x] == INF ? -1 : dp[x]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

/*
1. State: dp[i] => Minimum number of coins to construct sum x using the available coins.
2. Transistion: if available coins are (1 , 5, 7);
                so dp[11] = 1 + min( dp[11-1] , dp[11- 5] , dp[11-7] );

    `           dp[i] = 1 + min(dp[i - c[j]]) where 1 <= i <= x and c[0] <= c[j] <= c[n - 1] and i - c[j] >= 0


3. Base Case: dp[0] = 0
4. Final Case: dp[x]
*/