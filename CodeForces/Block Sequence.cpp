#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e8;

void solve() {
    
    ll t; cin >> t;

    while(t--) {
        ll n; cin >> n;
        vector<ll> a(n);
        for(auto& x : a) cin >> x;

        vector<ll> dp(n , -1);

        dp[n - 1] = 1;

        for(ll i = n - 2; i >= 0; i--) {
            ll op1 = INF, op2 = INF;

            if(a[i] <= (n - i - 1)) op1 = i + a[i] + 1 > n - 1 ? 0 : dp[i + a[i] + 1];

            op2 = 1 + dp[i + 1];

            dp[i] = min(op1 , op2);
        }
        cout << dp[0] << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}

/*
1. State: minimum number of deletions required to make the sequence beautiful from i to n - 1.
2. Transistion: Either the element a[i] is length of block or a element

                dp[i] = min(Minimum number of deletions required for Block element , Minimum number of deletions required for normal element);
                
                1. Minimum number of deletions required for Block element is => Op1

                    if(a[i] <= (n - i - 1)){
                    Op1 = dp[i + a[i] + 1];
                    }
                    else {
                    Op1 = Inf
                    }

                2. Minimum number of deletions required for Normal element is => Op2

                    Op2 = 1 + dp[i + 1];

                dp[i] = min(Op1 , Op2);
3. Trivial Case: for dp[n - 1]

                if(dp[n - 1] = 0) {
                    dp[n - 1] = 0;
                }else {
                    dp[n - 1] = 1;
                }
4. Final State: dp[0]

*/


/*
    0 1 2 3 4 5 6 7
a = 3 3 4 5 2 6 5 2
n = 8

Block

for i = 4, a[i] = 2
    length of block = n - i - 1 => 8 - 4 - 1 = 3
    a[i] < length of block || 2 < 3   (only if a[i] <= (n - i - 1) can be a block element
                                        else infinity)
    So minimum number of deletions required for Block element is 
        if(a[i] <= (n - i - 1)){
        mnd = dp[i + a[i] + 1];
        }
        else {
        mnd = Inf
        }

Normal

for i = 3, a[i] = 5
    dp[4] = 1
    so,
    mnd = 1 + dp[i + 1]

Ex: 
0 1 2 3 4 5 6
3 3 4 5 2 6 1

for i = 0, a[i] = 3



*/
