#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& a) {
    int n = a.size();
    long long mx = *max_element(a.begin(), a.end());

    auto calc = [&](long long target) {
        long long odd = 0, even = 0;

        for (auto x : a) {
            long long diff = target - x;
            odd += diff % 2;
            even += diff / 2;
        }

        if (odd > even) {
            return odd * 2 - 1;
        } else {
            return max(odd * 2, even * 2);
        }
    };

    return min(calc(mx), calc(mx + 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        cout << solve(a) << "\n";
    }

    return 0;
}
