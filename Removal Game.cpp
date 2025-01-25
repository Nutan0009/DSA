#include <iostream>
#include <vector>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    vector<long long> prefixSum(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + a[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i][i] = a[i];
    }
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            dp[i][j] = max(
                a[i] + (prefixSum[j + 1] - prefixSum[i + 1]) - dp[i + 1][j],  
                a[j] + (prefixSum[j] - prefixSum[i]) - dp[i][j - 1]          
            );
        }
    }
    cout << dp[0][n - 1] << endl;
}

int main() {
    solve();
    return 0;
}
