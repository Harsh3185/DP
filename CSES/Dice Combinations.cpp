#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    
    vector<ll> dp(n + 1, 0);

    dp[0] = 1; // Base case: 1 way to make sum 0 (by doing nothing)

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= 6; j++) {
            if (i - j >= 0)
                dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }

    cout << dp[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

/*
1️⃣ State Definition:
    dp[i] = number of ways to obtain a total sum of i using dice rolls (each roll gives 1–6).

2️⃣ Transition:
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]
    (taking modulo MOD)
    → dp[i] = (dp[i] + dp[i - j]) % MOD for j in [1, 6] and i - j >= 0

3️⃣ Base Case:
    dp[0] = 1
    (there’s exactly one way to make sum 0 — by choosing no dice)

4️⃣ Final Answer:
    dp[n]
    (number of ways to get total sum n)
*/
