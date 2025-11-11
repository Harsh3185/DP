#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

void solve() {
    ll n; cin >> n;
    vector<vector<char>> a(n , vector<char> (n));
    for(ll i = 0; i < n; i++) {
        for(char& c : a[i]) cin >> c;
    }

    vector<vector<ll>> dp(n , vector<ll> (n , 0));
    
    if(a[0][0] == '*' || a[n - 1][n - 1] == '*') {
        cout << "0\n";
        return;
    }

    dp[n - 1][n - 1] = 1;

    for(ll i = n - 1; i >= 0; i--) {
        for(ll j = n - 1; j >= 0; j--) {
            if(a[i][j] == '.') {
                if(i + 1 <= n - 1) dp[i][j] = (dp[i][j] + dp[i + 1][j]) % MOD;
                if(j + 1 <= n - 1) dp[i][j] = (dp[i][j] + dp[i][j + 1]) % MOD;
            }
        }
    }
    
    cout << dp[0][0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

/*
1) State:
   dp[i][j] = number of ways to go from cell (i, j) to (n-1, n-1).

2) Transition (computed bottom-right to top-left):
   If a[i][j] == '*': dp[i][j] = 0
   Else:
     dp[i][j] = ((i+1 < n ? dp[i+1][j] : 0) + (j+1 < n ? dp[i][j+1] : 0)) % MOD

   // Intuition: from (i, j) your next step (when walking forward) is either Down or Right,
   // so when filling dp backwards, you sum ways from the cells below and to the right.

3) Base case:
   dp[n-1][n-1] = 1  (only if end is free; code already early-returns 0 if start/end blocked)

4) Answer:
   dp[0][0]
*/
