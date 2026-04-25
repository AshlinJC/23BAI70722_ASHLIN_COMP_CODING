#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<long long, long long> events;

    for (int i = 0; i < n; i++) {
        long long l, r;
        cin >> l >> r;
        events[l]++;
        events[r + 1]--;
    }

    vector<long long> ans(n + 1, 0);

    long long prev = 0;
    long long cnt = 0;
    bool first = true;

    for (auto &[x, delta] : events) {
        if (!first) {
            long long len = x - prev;
            ans[cnt] += len;
        }
        cnt += delta;
        prev = x;
        first = false;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
