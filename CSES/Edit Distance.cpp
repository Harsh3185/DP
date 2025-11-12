#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e8;
const ll MOD = 1e9 + 7;

void solve() {
    
    string s1, s2; cin >> s1 >> s2;

    ll n = s1.size() , m = s2.size();
    vector<vector<ll>> dp(n + 1 , vector<ll> (m + 1 , 0));

    for(ll i = 0; i < n; i++) dp[i][m] = n - i;
    for(ll i = 0; i < m; i++) dp[n][i] = m - i;

    for(ll i = n - 1; i >= 0; i--) {
        ll op1 = LLONG_MAX, op2 = LLONG_MAX, op3 = LLONG_MAX;
        for(ll j = m - 1; j >= 0; j--) {
            if(s1[i] != s2[j]) {
                op1 = 1 + dp[i + 1][j + 1];
                op2 = 1 + dp[i + 1][j];
                op3 = 1 + dp[i][j + 1];

                dp[i][j] = min({op1 , op2 , op3});
            }else dp[i][j] = dp[i + 1][j + 1];
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
   dp[i][j] = Minimum number of operations needed to make string s1 from i to n - 1 and s2 from j to m - 1 equal.

2) Transition:
   If s1[i] == s2[j]:
       dp[i][j] = dp[i - 1][j - 1];
   Else:
     1. Replace => 1 + dp[i + 1][j + 1]
     2. Remove => 1 + dp[i + 1][j]
     3. Add => 1 + dp[i][j + 1]
       dp[i][j] = min({1 + dp[i + 1][j + 1] , 1 + dp[i + 1][j], 1 + dp[i][j + 1]})

3) Base:
    If s1 is empty (meaning i has reached n), and s2 is s2[j...m-1], you need to remove all m - j characters from s2. 
    So, dp[n][j] = m - j.
    same for dp[i][m] = n - i
    dp[n][m] = 0

4) Answer:
   dp[0][0]
*/
