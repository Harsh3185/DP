#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

void solve() {
    ll n, x; cin >> n >> x;
    vector<ll> c(n);
    for(auto& i : c) cin >> i;

    vector<ll> dp(x + 1, 0);

    dp[0] = 1;

    for(ll i = 1; i <= x; i++) {
        for(ll j = 0; j < n; j++) {
            if(i - c[j] >= 0) dp[i] = (dp[i - c[j]] + dp[i]) % MOD;
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
1. State:
   dp[i] = number of ways to form sum i using the given coins.

2. Transition:
   For every coin c[j],
       if i - c[j] >= 0:
           dp[i] += dp[i - c[j]]
   (take modulo MOD each time)

   → dp[i] = Σ dp[i - c[j]]  for all coins c[j] ≤ i

3. Base Case:
   dp[0] = 1
   (There is exactly one way to make sum 0 — by choosing no coins.)

4. Final Answer:
   dp[x]
   (number of ways to form total sum x)
*/
