#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i)
        cin >> coins[i];

    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int sum = 1; sum <= x; ++sum) {
        for (int coin : coins) {
            if (coin <= sum)
                dp[sum] = (dp[sum] + dp[sum - coin]) % MOD;
        }
    }
    cout << dp[x] << '\n';
}

int main() {
    solve();
    return 0;
}
