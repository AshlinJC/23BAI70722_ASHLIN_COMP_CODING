#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    int q;
    cin >> q;

    while (q--) {
        long long x;
        cin >> x;

        bool ok = false;

        for (int i = 0; i < n && !ok; i++) {
            for (int p = 0; p <= k && p * a[i] <= x; p++) {
                long long rem = x - p * a[i];
                int left = k - p;
              
                for (int j = 0; j < n; j++) {
                    if (rem % a[j] == 0 && rem / a[j] <= left) {
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
