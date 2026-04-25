#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, k, q;
int a[N], last[N], cnt[N];
int tree[4 * N];

void update(int node, int l, int r, int pos, int val) {
    if (l == r) {
        tree[node] += val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(2 * node, l, mid, pos, val);
    else update(2 * node + 1, mid + 1, r, pos, val);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return tree[node];

    int mid = (l + r) / 2;
    return query(2 * node, l, mid, ql, qr) +
           query(2 * node + 1, mid + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> a[i];

    unordered_map<int, vector<int>> pos;

    for (int i = 1; i <= n; i++) {
        pos[a[i]].push_back(i);
    }

    vector<int> bad(n + 2, 0);

    for (auto &p : pos) {
        auto &v = p.second;
        for (int i = k; i < (int)v.size(); i++) {
            bad[v[i]] = v[i - k];
        }
    }

    vector<vector<pair<int,int>>> queries(n + 1);

    cin >> q;
    int lastAns = 0;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l = (l + lastAns) % n + 1;
        r = (r + lastAns) % n + 1;
        if (l > r) swap(l, r);

        queries[r].push_back({l, i});
    }

    vector<int> res(q);

    for (int i = 1; i <= n; i++) {
        update(1, 1, n, i, 1);
        if (bad[i]) {
            update(1, 1, n, bad[i], -1);
        }

        for (auto &qq : queries[i]) {
            int l = qq.first;
            int id = qq.second;
            res[id] = query(1, 1, n, l, i);
            lastAns = res[id];
        }
    }

    for (int i = 0; i < q; i++) {
        cout << res[i] << "\n";
    }

    return 0;
}
