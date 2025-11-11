#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

vector<ll> get_all_digits(ll x) {
    vector<ll> digits;
    if (x == 0) return {0}; 

    x = abs(x); 
    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }
    return digits;
}

void solve() {
    ll n; cin >> n;

    vector<ll> dp(n + 1, 1e9);

    dp[0] = 0;

    for(ll i = 1; i <= n; i++) {
        vector<ll> digits = get_all_digits(i);
        for(auto x : digits) {
            if(x != 0) {
                dp[i] = min(dp[i] , dp[i - x] + 1);
            }
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
1. State:
   dp[i] = Minimum steps to reduce i to 0 
            (by repeatedly subtracting one of its nonzero digits).

2. Transition:
   For every nonzero digit x of i:
       dp[i] = min(dp[i], dp[i - x] + 1);

   (We remove one digit x in one step and use the already computed dp[i - x].)

3. Base Case:
   dp[0] = 0

4. Answer:
   dp[n]
*/

