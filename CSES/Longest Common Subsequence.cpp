#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e8;
const ll MOD = 1e9 + 7;

void solve() {
    
    ll n, m; cin >> n >> m;
    vector<ll> a(n) , b(m);

    for(auto& x : a) cin >> x;
    for(auto& x : b) cin >> x;

    vector<vector<ll>> dp(n + 1 , vector<ll> (m + 1 , 0));

    for(ll i = n - 1; i >= 0; i--) {
        for(ll j = m - 1; j >= 0; j--) {
            if(a[i] == b[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
            else dp[i][j] = max(dp[i + 1][j] , dp[i][j + 1]);
        }
    }

    vector<ll> ans;
    ll i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) { ans.push_back(a[i]); ++i; ++j; }
        else if (dp[i + 1][j] >= dp[i][j + 1]) ++i;
        else ++j;
    }

    cout << dp[0][0] << "\n";
    for(auto x : ans) cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}

/*
1. State:
   dp[i][j] = length of the longest common subsequence
              between subarrays a[i...n-1] and b[j...m-1].

2. Transition:
   if a[i] == b[j]:
       → We can include this element in the LCS.
       dp[i][j] = 1 + dp[i+1][j+1]
   else:
       → Either skip a[i] or skip b[j].
       dp[i][j] = max(dp[i+1][j], dp[i][j+1])

3. Base Case:
   dp[n][*] = 0  (when one array is exhausted)
   dp[*][m] = 0

4. Answer:
   dp[0][0] = length of LCS
   The reconstructed 'ans' gives one valid LCS sequence.
*/
