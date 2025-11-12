#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e8;
const ll MOD = 1e9 + 7;

void solve() {
    
    ll n; cin >> n;
    vector<vector<ll>> a(n);

    for(ll i = 0; i < n; i++) {
        ll x, y, z; cin >> x >> y >> z;
        a[i].push_back(x);
        a[i].push_back(y);
        a[i].push_back(z);
    }

    vector<vector<ll>> dp(n + 1, vector<ll> (3 , 0));

    for(ll i = n - 1; i >= 0; i--) {
        for(ll j = 0; j < 3; j++) {
            for(ll k = 0; k < 3; k++) {
                if(j != k) dp[i][j] = max(dp[i][j] , a[i][j] + dp[i + 1][k]);
            }
        }
    }

    ll mx = LLONG_MIN;
    for(auto x : dp[0]) mx = max(mx , x);

    cout << mx << "\n";
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
