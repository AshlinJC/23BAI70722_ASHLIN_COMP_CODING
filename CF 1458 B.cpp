#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    int sumA = 0, sumB = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sumA += a[i];
        sumB += b[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(sumA + 1, -1));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            for (int s = 0; s <= sumA - a[i]; s++) {
                if (dp[j][s] != -1) {
                    dp[j + 1][s + a[i]] = max(dp[j + 1][s + a[i]], dp[j][s] + b[i]);
                }
            }
        }
    }

    cout << fixed << setprecision(10);

    for (int k = 1; k <= n; k++) {
        double ans = 0;
        for (int s = 0; s <= sumA; s++) {
            if (dp[k][s] != -1) {
                double val = min((double)s, (double)(dp[k][s] + sumB) / 2.0);
                ans = max(ans, val);
            }
        }
        cout << ans << " ";
    }

    cout << "\n";
    return 0;
}
