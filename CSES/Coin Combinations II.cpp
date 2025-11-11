#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;
 
    vector<int> c(n);
    for (int &coin : c) cin >> coin;
 
    // State dp[i] -> number of ways to make sum of i
 
    // Transition -> 
 
    vector<int> dp(x + 1, 0);
    dp[0] = 1; 
 
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j - c[i] >= 0) {
                dp[i] = (dp[j - c[i]] + dp[i]) % MOD;
            }
        }
    }
 
    cout << dp[x] << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

/*
1. State: dp[i] => Minimum number of coins to construct sum x.
2. Transistion: dp[i] = 1 + min(dp[i - j]) where 1 <= i <= x and a[0] <= j <= a[n - 1]


3. Base Case: dp[0] = 0
4. Final Case: dp[n]
*/