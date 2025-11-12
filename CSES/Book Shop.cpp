#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e8;

void solve() {
    
    int n, x; cin >> n >> x;
    vector<ll> h(n) , s(n);

    for(auto& x : h) cin >> x;
    for(auto& x : s) cin >> x;

    vector<vector<ll>> dp(x + 1 , vector<ll> (n + 1, 0));

    for(ll i = 1; i <= x; i++) {
        for(ll j = n - 1; j >= 0; j--) {
            if(i - h[j] >= 0) {
                dp[i][j] = max(dp[i][j] , s[j] + dp[i - h [ j]][j + 1]);
            }
            dp[i][j] = max(dp[i][j] , dp[i][j + 1]);
        }
    }

    cout << dp[x][0] << "\n";
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}

/*
1. State: dp[i][j] Maximum number of pages for price <= i from 0 to j index.
2. Transistion: dp[i][j] = max((s[j] + dp[i - h[j]][j + 1]) , dp[i][j + 1]) where i - h[j] >= 0 and j + 1 <= n - 1;
3. Base Case: dp[0][anything] = 0;
4. Final Case: dp[]
*/