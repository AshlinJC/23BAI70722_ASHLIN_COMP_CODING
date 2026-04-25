#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = 0, r = 0;

        for (auto b : batteries) {
            r += b;  // total energy
        }

        r /= n; // upper bound

        long long ans = 0;

        while (l <= r) {
            long long mid = (l + r) / 2;

            long long total = 0;
            for (auto b : batteries) {
                total += min((long long)b, mid);
            }

            if (total >= mid * n) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};
