#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> freq(8001, 0);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        vector<bool> possible(8001, false);

        // generate all subarray sums
        for (int i = 0; i < n; i++) {
            int sum = a[i];
            for (int j = i + 1; j < n; j++) {
                sum += a[j];
                if (sum > 8000) break;
                possible[sum] = true;
            }
        }

        int ans = 0;

        for (int x = 1; x <= 8000; x++) {
            if (possible[x]) {
                ans += freq[x];
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
